#ifndef TETRISARRAY_HPP
#define TETRISARRAY_HPP

#include "AbstractTetris.hpp"

using namespace ATC;

namespace T1DARR{

    class TetrisArray1D : public AbstractTetris{
        public:
            TetrisArray1D();
            TetrisArray1D(const int &r_s,const int &c_s);
            ~TetrisArray1D();
            const TetrisArray1D &operator=(const TetrisArray1D &oth);

            char *getArrBoard() const{return arrBoard;}
            void createTetrisBoard() override;
            const TetrisArray1D& operator+=(const Tetromino& othObj) override;
            const void draw() const override;
            void animate(const int &location) override;
            void writeFile() override;
            void readFile() override;
            void lastMove() override;


        private:
            char * arrBoard;
            int a_row,a_col;
    };

}

#endif //TETRISARRAY_HPP