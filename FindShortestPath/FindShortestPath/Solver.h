#pragma once

#include "RubiksCube.h"
#include <vector>
#include <set>
#include <map>

struct Way {
	Color surf;
	int dis;
};

class Solver
{
	RubiksCube initialCube;
	
	map<unsigned long long int, int> lower_bound;

	int upper_bound = INT_MAX;


	void Init(const RubiksCube& initialCube);

	unsigned long long int Encode(const RubiksCube& cube);

	int Estimate(const RubiksCube& cur);

	void DFS(RubiksCube cur, int depth, vector<Way>& history);

	vector<Way> Solve();
	
};

