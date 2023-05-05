#ifndef TETROMINO_H
#define TETROMINO_H

#include <iostream>
#include <random>
#include <vector>
#include <unistd.h>

using namespace std;

enum tetris{//enum represent objects type
    I = 'I',
    O = 'O',
    T = 'T',
    J = 'J',
    L = 'L',
    S = 'S',
    Z = 'Z'
};

class Tetromino{
    public:
        Tetromino(){}
        Tetromino(tetris t):tet(t){}//one parameter constructor...Parameter is enum type...
        tetris getTetro()const{return tet;}
        void create_tetrominos();//according to random selection ,this function creat tetrominos object...
        void print_tetrominos()const;//print tetromino objects on the screen
        void rotatematrix();//rotate matrix left or right..
        void print_bestfit()const;//print bestfit vector on the screen...
        void calculate_point();//Calculates how many points there are to get the best fit 
                               // according to the directions of the objects and creates the object with the highest score.
        int get_row()const{return r_size;}//return count of row of object
        int get_col()const{return c_size;}//return count of column of object
        int getRCor()const{return row_cor;}//return bestfit coordinat-row
        int getCCor()const{return col_cor;}
        void setBoardSizes(int r,int c);//it take row and col of the board and create board vector...
        void bestfit(/*const int board_row,const int board_col*/);
        vector<vector<char>> vect_tetris;//vector hold tetrominos object

    private:
        tetris tet;
        int row_cor=0,col_cor=0;
        int r_size,c_size;
        int right=1,left=0;
};  


#endif
