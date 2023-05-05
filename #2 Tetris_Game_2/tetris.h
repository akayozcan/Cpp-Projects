#ifndef TETRIS_H
#define TETRIS_H

#include <iostream>
#include <random>
#include <vector>
#include <unistd.h>
#include "tetris.h"
#include "tetromino.h"
using namespace std;


class Tetris{
    public:
        Tetris(){}
        Tetris(const int& r_size,const int& c_size);
        void add_tetrominos();
        void fit_tetrominos();
        void draw_tetris()const;
        const bool get_choise_input();
        Tetromino othClass;

    private:
        int row_size,col_size;
        vector<vector<char>> v_tetris;
        
};

#endif
