#ifndef Solver_H
#define Solver_H

#include "RubiksCube.h"
#include <limits.h>
#include <vector>
#include <set>
#include <map>
#define INF INT_MAX / 2

struct Way {
	Color surf;
	int rot;
	Way():rot(0){}
	Way(Color surf, int rot) : surf(surf), rot(rot){}
};

class Solver
{
	typedef pair<__uint128_t, uint32_t> Hash;
	RubiksCube initialCube;
	
	map<Hash, int> lowerBound;

	int upperBound = 4; // God's number is 20

public:

	void Init(const RubiksCube& initialCube);

	Hash Encode(const RubiksCube& cube);

	int Estimate(const RubiksCube& cur);

	int DFS(RubiksCube cur, int depth, vector<Way>& history);

	vector<Way> Solve();
	
};

#endif