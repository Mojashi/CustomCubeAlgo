#ifndef RubiksCube_H
#define RubiksCube_H

#include <array>
#include <assert.h>
#include <algorithm>
using namespace std;

enum Color {
	Yellow, Orange, Green, Red, Blue, White, None
};
string ColorName[] = {"Yellow", "Orange", "Green", "Red", "Blue", "White", "None"};

const Color adjsurface[6][4] = {
	{Orange, Green,Red,Blue},
	{White, Green,Yellow,Blue},
	{Orange, White, Red, Yellow},
	{Yellow, Green, White, Blue},
	{Orange, Yellow, Red, White},
	{Red, Green, Orange, Blue}
};

const int adjidx[6][12] = {
	{1,0,7,1,0,7,1,0,7,1,0,7},
	{1,0,7,7,6,5,5,4,3,3,2,1},
	{3,2,1,7,6,5,3,2,1,3,2,1},
	{5,4,3,7,6,5,1,0,7,3,2,1},
	{7,6,5,7,6,5,7,6,5,3,2,1},
	{5,4,3,5,4,3,5,4,3,5,4,3}
};

enum Surface {
	Back, Left, Up, Right, Down, Front
};

class RubiksCube
{
	array<array<Color, 8>, 6> surface;

public:
	RubiksCube();
	RubiksCube(array<array<Color, 8>, 6> surface);

	void Rotate(Color surf, int dis);

	Color GetColor(Color surf, int idx) const;

	bool isCleared() const;

	bool isValid() const;

};
#endif
