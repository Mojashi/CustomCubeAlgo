#include "Solver.h"

void Solver::Init(const RubiksCube &initialCube){
    this->initialCube = initialCube;
}

Solver::Hash Solver::Encode(const RubiksCube &cube){
    Hash ret;
    int curpos = 0;
    for(int i = 0; 6 > i; i++){
        for(int j = 0; 8 > j; j++){
            if(curpos >= 30)
                ret.second |= (cube.GetColor(Color(i),j) << (curpos - 30));
            else
                ret.first |= (cube.GetColor(Color(i),j) << curpos);

            curpos += 3;
        }
    }
}

int Solver::Estimate(const RubiksCube &cur){
    return 0;
}

int Solver::DFS(RubiksCube cur, int depth, vector<Way> &history){

    if(cur.isCleared()){
        return 0;
    }

    Hash curhash = Encode(cur);

    if(lowerBound.count(curhash)){
        if(depth + lowerBound[curhash] >= upperBound){
            return INF;
        }
    }

    lowerBound[curhash] = INF; //ban re-reaching

    int bestnofw = INF;
    vector<Way> bestNxWay;
    Way bestWay;

    for(int surf = 0; 6 > surf; surf++){
        for(int rot = 1; 4 > rot; rot++){
            cur.Rotate(Color(surf), rot);

            vector<Way> buf;
            int nofw = DFS(cur, depth + 1, buf);
            if(bestnofw > nofw){
                bestWay = Way(Color(surf), rot);
                swap(bestNxWay, buf);
                bestnofw = nofw;
            }

            cur.Rotate(Color(surf), 4 - rot);
        }
    }

    lowerBound[curhash] = bestnofw;

    bestNxWay.push_back(bestWay);
    history = bestNxWay;
    
    return bestnofw + 1;
}

vector<Way> Solver::Solve(){
    vector<Way> ret;
    DFS(initialCube, 0, ret);
    return ret;
}