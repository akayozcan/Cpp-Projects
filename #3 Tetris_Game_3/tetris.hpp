#ifndef TETRIS_HPP
#define TETRIS_HPP

#include <iostream>
#include <random>
#include "tetromino.hpp"
using namespace std;
using namespace NTetromino;

namespace NTetris{

    class Tetris{
        public:
            Tetris(){}//No parameter constructor
            Tetris(const int& r_size,const int& c_size);//Two parameter constructor...
            ~Tetris();//Destructor
            Tetris& operator+=(const Tetromino& othObj);//with += operator overloding it can be added tetromino obj to tetboard...
            int move_and_rotate();//move and rotate the obj...
            void draw_tetris_board()const;//print tetris board on the screan..
            void lower_tetrominos(const int &location);//animate tetromino by lowering
            const bool get_choise_input();//Ask user which tetromino...
            int getBoardRow()const{return board_row;}//return board row 
            int getBoardCol()const{return board_col;}//return board col 
            int getGameOver()const{return gameOver;}//return gameover
            char**getTetBoard()const{return tet_board;}//return tetris board
            Tetromino othClass;//

        private:
            int board_row,board_col,midPoint;
            int gameOver;
            char** tet_board;
    };

}
#endif //TETRIS_H