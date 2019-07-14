#include "RubiksCube.h"


RubiksCube::RubiksCube() {
	for (int i = 0; 6 > i; i++) {
		for (int j = 0; 8 > j; j++) {
			surface[i][j] = Color(i);
		}
	}
}

RubiksCube::RubiksCube(array<array<Color, 8>, 6> surface): surface(surface){}

void RubiksCube::Rotate(Color surf, int dis) {
	assert(dis >= 0 && dis <= 3);

	if (dis == 2) {
		for (int i = 0; 3 > i; i++) {
			swap(surface[adjsurface[surf][0]][i], surface[adjsurface[surf][2]][i]);
			swap(surface[adjsurface[surf][3]][i], surface[adjsurface[surf][1]][i]);
		}
	}
	else if (dis == 3) {
		for (int j = 0; 3 > j; j++)
			for (int i = 0; 3 > i; i++) {
				swap(surface[adjsurface[surf][j]][i], surface[adjsurface[surf][(j + 1) % 4]][i]);
			}
	}
	else if (dis == 1) {
		for (int j = 3; 0 < j; j--)
			for (int i = 0; 3 > i; i++) {
				swap(surface[adjsurface[surf][j]][i], surface[adjsurface[surf][(j + 1) % 4]][i]);
			}
	}

	rotate(surface[surf].begin(), surface[surf].begin() + (8 - 2 * dis), surface[surf].end());

}

Color RubiksCube::GetColor(Color surf, int idx) {
	return surface[surf][idx];
}

bool RubiksCube::isCleared() {
	for (int i = 0; 6 > i; i++) {
		for (int j = 0; 8 > j; j++) {
			if (i != surface[i][j]) return false;
		}
	}

	return true;
}

bool RubiksCube::isValid() {
	return true;
}