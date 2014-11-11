/*
 * common.h
 *
 *  Created on: Sep 27, 2014
 *      Author: Zikai Alex Wen
 */
#ifndef PMC_COMMON_H_
#define PMC_COMMON_H_

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cassert>

#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <stdexcept>

#include <boost/lexical_cast.hpp>

/*BTC Dependent Headers*/
#include "util.h"
#include "utilstrencodings.h"
#include "uint256.h"
#include "hash.h"
#include "random.h"
#include "version.h"
#include "serialize.h"



namespace PMC {

/// Macros & typedef structure
#define RUN_PMCLFBYTE 1000000 //1 MB
#define RUN_PMCLFNUM  8
#define RUN_PMCDEPTH  3
#define RUN_FPSLFBYTE 1024
#define RUN_FPSLFNUM  1024
#define RUN_FPSLFSELECT 1
#define RUN_FPSLFREVEAL 1  //TODO beta satisfy the security requirement

#define ALL_CONST RUN_PMCLFNUM
#define SUBSET_CONST RUN_PMCLFNUM/2
#define CHALNG_CONST 2

#define HEAD 0
#define FINE 0
#define SAME 0
#define INVALID_ERR -1
#define PTNULL_ERR -2
#define MALLOC_ERR -3
#define FILE_ERR -4

static uint256 db_rootdigest("9261080d5dc4e8d2eedc69847a0486c18236efbf06e153d73b89b07359f13d81");

/**
 * A random oracle lies within [0,max]
 * INPUT hashvalue as a seed
 * OUTPUT a random number ranged [0,max]
 */
inline size_t getRandByHash(const uint256& hashvalue, const size_t max){
	return hashvalue.GetLow64() % max;
}

/**
 * Convert an array of unsigned char to the vector form
 * INPUT pointer to the built-in array, the length of the array
 * OUTPUT the vector form of an array
 */
std::vector<unsigned char>* newByteVec(unsigned char* a_pointer, size_t a_length);

/**
 * Prints the unchar array in Hex form
 * INPUT unchar array and its length
 */
void printHex(const unsigned char* ucstr, const size_t length);

/**
 * Returns string in Hex form
 * REF http://stackoverflow.com/questions/3381614/c-convert-string-to-hexadecimal-and-vice-versa
 * !!!! Not fully tested
 */
std::string stringToHex(const std::string& input);

/**
 * Returns true if the value is even
 * INPUT a size_t value; OUTPUT true if it's even
 * !!!! An inline method
 */
template<typename T>
inline bool isEven(T v) {
	return ((v % 2) == 0 ? true : false);
}

/**
 * Computes u[i] := H_0(pk||i_inl) mod num_all
 */
size_t computeU_i(uint256 pk, size_t i_inl, size_t num_all);

/**
 * Computes H(inputs) mod num_sub
 */
size_t computeI_inL(std::string inputs, size_t num_sub);

/**
 * Computes r[i] := computeStoreU_i(computeChlngU_i())
 */
size_t computeR_i(uint256 pk, std::string inputs, size_t num_sub,
		size_t num_all);

}

#endif /*PMC_COMMON_H_*/
