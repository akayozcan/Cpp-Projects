#ifndef ABSTRACT_TETRIS_HPP
#define ABSTRACT_TETRIS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <fstream>
#include <unistd.h>
#include "tetromino.hpp"

using namespace std;

namespace ATC{

    class AbstractTetris{
        public:
            AbstractTetris(){}//No parameter constructor
            AbstractTetris(const int& r_size,const int& c_size);//Two parameter constructor...
            virtual ~AbstractTetris(){};//Destructor
            virtual void createTetrisBoard()=0;//pure virtual - create tetris board
            virtual const AbstractTetris& operator+=(const Tetromino& othObj)=0; //pure virtual - add tetromino on the board
            virtual const void draw() const=0; //pure virtual - print table on the screen
            virtual void animate(const int &location)=0; //pure virtual - lower tetromino on the board
            virtual void readFile()=0;
            virtual void writeFile()=0;
            virtual  void lastMove()=0;

            int move_and_rotate();//move and rotate the obj...
            const bool get_choise_input();//Ask user which tetromino...

            void setBoardSize(const int &r_size,const int &c_size); 
            int getGameOver()const{return gameOver;}
            int getB_Row()const{return board_row;}//return board row 
            int getB_Col()const{return board_col;}//return board col

            Tetromino tetClass;

        protected:
            int midPoint,gameOver;

        private:
            int board_row,board_col;
    };

}


#endif //ABSTRACT_HPP