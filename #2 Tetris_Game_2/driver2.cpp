#include <iostream>
#include <random>
#include <vector>
#include <unistd.h>
#include "tetromino.h"
#include "tetris.h"
using namespace std;


int main(){
    bool temp;
    int row,col;//for take input about row and column of tetris board
    cout<<"Enter the size of row of the Tetris board:"<<endl;
    cin>>row;
    cout<<"Enter the size of column of the Tetris board:"<<endl;
    cin>>col;
    Tetris tetris1(row,col);
    
    while(tetris1.get_choise_input()==true){//if user doesn't enter Q for quit,then it returns true value...Loop will be continiue..
        tetris1.othClass.bestfit();//it controls if tetrominos objects bestfit or not...
        tetris1.add_tetrominos();//Add choisen tetrominos middle of the table... 
        usleep(500000);
        tetris1.fit_tetrominos();//tetromino lowers it to the most convenient location. 
        //if(right_count>col) exit(1);
    }

    return 0;
}
