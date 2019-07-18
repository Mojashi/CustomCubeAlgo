#include "RubiksCube.h"
#include "Solver.h"

#include <cstdio>

int main(){
    RubiksCube cube;

    cube.Rotate(Color::Red, 1);
    cube.Rotate(Color::Blue, 2);
    cube.Rotate(Color::Green, 3);
    
    Solver solver;
    solver.Init(cube);

    vector<Way> ans(solver.Solve());

    

    printf("num of way : %d\n", ans.size());

    for(auto itr : ans){
        printf("surf:%s rot:%d\n", ColorName[itr.surf].c_str(), itr.rot);
    }   
    
    return 0;
}