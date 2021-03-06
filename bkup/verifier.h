#ifndef PERMACN_VERIFIER_H
#define PERMACN_VERIFIER_H

#include "fps.h"
#include "ticket.h"

#include <fstream>

class VERIFIER {
private:
	std::string puzzle_id;
	unsigned char* root_digestPt;
	TICKET* tic_verifyPt;
	int i_ink = CHALNG_CONST;
	size_t num_subset = SUBSET_CONST, num_all = ALL_CONST;

public:

	/**
	 * 1st constructor
	 * INTPUT a root digest of the Merkle tree,
	 * 	      a file path from which the ticket info is read
	 */
	VERIFIER(std::string root_file, std::string tic_file);

	/**
	 * Destructor: deletes root and tic_verify
	 */
	~VERIFIER();

	/**
	 * Get the puzzle id
	 * OUTPUT fine
	 */
	int getPuzzleID(std::string puz_id);

	/**
	 * Return the puzzle id
	 */
	std::string returnPuzzleID();

	/**
	 * Verify all challenged segments stored in tic_verify->mkproofs
	 * OUTPUT true if all matched otherwise false
	 */
	bool verifyAllChallenges();
};

#endif
