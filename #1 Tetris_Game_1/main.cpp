#include <iostream>
#include <random>
#include <vector>
#include "tetromino.h"
using namespace std;


int main(){//I,O,T,J,L,S,Z
    Tetromino tetI(I),tetO(O),tetT(T),tetJ(J),tetL(L),tetS(S),tetZ(Z);//create tetrominos object
    vector<Tetromino> tetrominos{tetI,tetO,tetT,tetJ,tetL,tetS,tetZ};//add them together in the tetrominos vector
    vector<int> array;//creat an array to fill inside with random numbers
    vector<vector<char>> vecex(4,vector<char>(40));//vecex is 2D vector and hold bestfit objects 
    for(int i=0;i<4;i++){//initiliaze vecex array with space character
        for(int j=0;j<40;j++){
            vecex[i][j]=' ';
        }
    }

    int count_of_tet;
    
    cout<<"How many tetrominos?"<<endl;
    cin>>count_of_tet;
    srand(time(NULL));

    for(int i=0;i<count_of_tet;i++){
        array.push_back(rand()%6);
    }
    cout<<array.size()<<endl;
    cout<<"What are the types?"<<endl;
    print_tetrominos_name(array);
    
    cout<<endl<<"Your tetrominos:"<<endl;
    for(int i=0;i<count_of_tet;i++){
        tetrominos[array[i]].create_tetrominos();
    }

    for(int i=0;i<count_of_tet;i++){
        vecex=filltable(tetrominos[array[i]],vecex);
    }
    cout<<"Horizontally best-fit tetrominos:"<<endl;
    print_bestfit(vecex);
 
    return 0;
}

