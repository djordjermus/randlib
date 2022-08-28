#include <time.h>
#include <math.h>
#pragma once
namespace randlib {
	class random final {
	public:
		using u64 = unsigned long long;
		using i64 = signed long long;
		using f64 = double;

		static constexpr u64 x = 12;
		static constexpr u64 y = 25;
		static constexpr u64 z = 27;
		static constexpr u64 m = 2685821657736338717ULL;

		// Starting seed is initialized to time(0)
		inline random() :
			_seed(time(0)) {}
		// Starting seed is initialized to given value
		inline random(u64 seed) :
			_seed(seed) {}

		// Generates a pseudo-random unsigned 64 bit integer in range [from, from + range)
		inline u64 range(u64 from, u64 range) {
			return from + (generate() % range);
		}
		// Generates a pseudo-random unsigned 64 bit integer in range [0, range)
		inline u64 range(u64 range) {
			return random::range(0ull, range);
		}
		// Generates a pseudo-random signed 64 bit integer in range [from, from + range)
		inline i64 range(i64 from, i64 range) {
			return from + (generate() % range);
		}
		// Generates a pseudo-random signed 64 bit integer in range [0, range)
		inline i64 range(i64 range) {
			return random::range(0ll, range);
		}
		// Generates a pseudo-random double in range [from, from + range)
		inline f64 range(f64 from, f64 range) {
			return from + fmod(generate() * 0.0000000000000001, range);
		}
		// Generates a pseudo-random double in range [0, range)
		inline f64 range(f64 range) {
			return random::range(0.0, range);
		}

		// Sets the new seed
		inline void setSeed(u64 seed) {
			_seed = seed;
		}

	private:
		inline u64 generate() {
			u64 ret = _seed;
			ret ^= ret << x;
			ret ^= ret >> y;
			ret ^= ret << z;
			return _seed = ret;
		}

		u64 _seed;
	};
}