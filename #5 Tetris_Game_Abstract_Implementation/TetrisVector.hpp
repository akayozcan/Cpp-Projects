#ifndef TETRIS_VECTOR_HPP
#define TETRIS_VECTOR_HPP

#include "AbstractTetris.hpp"

using namespace ATC;

namespace TVC{

    class TetrisVector : public AbstractTetris{
        public:
            TetrisVector();
            TetrisVector(const int &r_s,const int &c_s);
            ~TetrisVector();

            vector < vector <char> > getVtet() const {return v_tet_board;} 
            void createTetrisBoard() override;
            const TetrisVector& operator+=(const Tetromino& othObj) override;
            const void draw() const override;
            void animate(const int &location) override;
            void writeFile() override;
            void readFile() override;
            void lastMove() override;


        private:
            int v_row,v_col;
            vector < vector <char> > v_tet_board;
    };

}

#endif //TETRISVECTOR_HPP