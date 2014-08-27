#ifndef ZKARRAY_H
#define ZKARRAY_H

#include <array>
#include <algorithm>

namespace ZK {

template<class C, size_t N>
class ARRAY: public std::array<C, N> {
public:

	/**
	 * assign the c-style array to a standard array
	 * Input - the head of c-array and its length
	 * Affect - values of this object
	 */
	int assign(C *pt, size_t len) {
		int bound = std::min(N, len);
		for (size_t i = 0; i < bound; i++) {
			(*this)[i] = pt[i];
		}
		return (bound - N);
	}

	/**
	 * Override the input stream for zk::array class
	 */
	friend std::istream& operator>>(std::istream& input, ARRAY& ary) {
		for (size_t i = 0; i < N; i++) {
			input >> ary[i];
		}
		return input;
	}
	/**
	 * Override the output stream for zk::array class
	 */
	friend std::ostream& operator<<(std::ostream& output, const ARRAY& ary) {
		for (size_t i = 0; i < N; i++) {
			output << ary[i] << " ";
		}
		return output;
	}

};

}

#endif