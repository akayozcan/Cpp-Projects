#include <iostream>
#include <random>
#include "tetris.hpp"
#include "tetromino.hpp"

using namespace std;
using namespace NTetris;
using namespace NTetromino;

int main(){
    
    int row,col;//for take input about row and column of tetris board
    cout<<"Enter the size of row of the Tetris board:"<<endl;
    cin>>row;
    cout<<"Enter the size of column of the Tetris board:"<<endl;
    cin>>col;
    Tetris *tetris1=new Tetris(row,col);//create tetris object

    while(tetris1->getGameOver() != 1 && tetris1->get_choise_input() != false){//exits the loop when these conditions are satisfied
        *(tetris1)+=tetris1->othClass;//add tetromino object to tetris board...
    }
    cout<<"Game is Over!"<<endl;

    delete tetris1;
    
    return 0;
}
