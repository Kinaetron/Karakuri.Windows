#pragma once
#include "SystemIncludes.h"
#include <cstdint>
#include <exception>

namespace Karakuri
{
	class Timer
	{
	public:
		Timer()
		{
			if (!QueryPerformanceCounter(&_lastTime)) {
				throw std::exception();
			}

			if (!QueryPerformanceFrequency(&_ticksPerSecondOnMachine)) {
				throw std::exception();
			}

			// Set to 1/10th of a second (1,000,000 ticks)
			_maxDelta = static_cast<uint64_t>(_ticksPerSecondOnMachine.QuadPart / 10);

			_totalTicks = 0;
			_elapsedTicks = 0;
			_leftOverTicks = 0;

			_frameCount = 0;
			_framesPerSecond = 0;
			_framesThisSecond = 0;
			_machineSecondCounter = 0;

			_targetFrameRate = 60;
		}

		// Expected ticks per second from the Windows OS
		static constexpr uint64_t TicksPerSecond = 10000000;

		double GetElapsedSeconds() const noexcept { return TicksToSeconds(_elapsedTicks); }
		double GetTotalSeconds() const noexcept { return TicksToSeconds(_totalTicks); }

		uint32_t GetFrameCount() const noexcept { return _frameCount; }
		uint32_t GetFramesPerSecond() const noexcept { return _framesPerSecond; }
		void SetTargetFrameRate(int targetFrameRate) noexcept { _targetFrameRate  = targetFrameRate; }

		static constexpr double TicksToSeconds(uint64_t ticks) noexcept { return static_cast<double>(ticks) / TicksPerSecond; }
		static constexpr uint64_t SecondsToTicks(double seconds) noexcept { return static_cast<uint64_t>(seconds * TicksPerSecond); }

		template<typename TUpdate>
		void Update(const TUpdate& update)
		{
			LARGE_INTEGER currentTime;

			if (!QueryPerformanceCounter(&currentTime)) {
				throw std::exception();
			}

			uint64_t timeDelta = static_cast<uint64_t>(currentTime.QuadPart - _lastTime.QuadPart);

			_lastTime = currentTime;
			_machineSecondCounter += timeDelta;


			if (timeDelta > _maxDelta) {
				timeDelta = _maxDelta;
			}

			timeDelta *= TicksPerSecond;
			timeDelta /= static_cast<uint64_t>(_ticksPerSecondOnMachine.QuadPart);

			uint32_t lastFrameCount = _frameCount;
			uint64_t targetElapsedTicks = TicksPerSecond / _targetFrameRate;

			if (static_cast<uint64_t>(std::abs(static_cast<int64_t>(timeDelta - targetElapsedTicks))) < TicksPerSecond / 4000) {
				timeDelta = targetElapsedTicks;
			}

			_leftOverTicks += timeDelta;

			while (_leftOverTicks >= targetElapsedTicks)
			{
				_totalTicks += targetElapsedTicks;
				_elapsedTicks = targetElapsedTicks;
				_leftOverTicks -= targetElapsedTicks;
				_frameCount++;

				update();
			}

			if (_frameCount != lastFrameCount) {
				_framesThisSecond++;
			}

			if (_machineSecondCounter >= static_cast<uint64_t>(_ticksPerSecondOnMachine.QuadPart))
			{
				_framesPerSecond = _framesThisSecond;
				_framesThisSecond = 0;
				_machineSecondCounter %= static_cast<uint64_t>(_ticksPerSecondOnMachine.QuadPart);
			}
		}


	private:

		uint64_t _maxDelta;
		LARGE_INTEGER _lastTime;
		LARGE_INTEGER _ticksPerSecondOnMachine;

		uint64_t _totalTicks;
		uint64_t _elapsedTicks;
		uint64_t _leftOverTicks;

		uint32_t _frameCount;
		uint32_t _framesPerSecond;
		uint32_t _framesThisSecond;
		uint64_t _machineSecondCounter;

		int _targetFrameRate;
	};
}