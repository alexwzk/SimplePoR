#ifndef PERMACN_DEALER_H
#define PERMACN_DEALER_H

#include "merkle.h"

#include <fstream>

class DEALER {
private:

	MERKLE *mktreePt = nullptr;
	std::string pubkey;
	size_t num_subset = SUBSET_CONST, num_all = ALL_CONST;
	std::vector<size_t> uarray_pk;
	std::vector<PATH*> pathPts;
	bool can_update = false;

	/**
	 * createSubset - generates the S_{pk}
	 * Input - nothing; Output - 0 is success, otherwise -1 means not ready yet (no new key);
	 * Affect - updates subset_pk, path_set and set is_ready as false
	 */
	int createSubset();

public:

	/**
	 * DEALER 1st constructor - computes the Merkle tree of the entire dataset
	 * Input - the file path; Output - void; Affect - initialise the merkle_tree
	 */
	DEALER(std::string filenamePt);

	/**
	 * DEALER destructor
	 */
	~DEALER();

	/**
	 *	createSource - setup the permacoin for a participant
	 *	Input - an array of char which is the public key;
	 *	Output - a set of file segments and their Merkle proofs (path list);
	 *	Affect - all private data except the merkle_tree;
	 */
	std::vector<PATH*> createSource(std::string usr_pubkey);

	//TODO: copy and assignment functions
};

#endif
