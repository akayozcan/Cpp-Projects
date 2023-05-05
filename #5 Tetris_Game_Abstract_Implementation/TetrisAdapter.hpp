#ifndef TETRISADAPTER_H
#define TETRISADAPTER_H

#include "AbstractTetris.hpp"
using namespace ATC;

namespace TAC{

    template <class T>
    class TetrisAdapter : public AbstractTetris{
        public:
            TetrisAdapter();
            TetrisAdapter(const int &r_s,const int &c_s);
            ~TetrisAdapter();
            const AbstractTetris& operator=(const TetrisAdapter &oth);//assignment operator overloded

            //char *getArrBoard() const{return arrBoard;}
            void createTetrisBoard() override;
            const AbstractTetris& operator+=(const Tetromino& othObj) override;
            const void draw() const override;
            void animate(const int &location) override;
            void writeFile() override;
            void readFile() override;
            void lastMove() override;


        private:
            T * arrBoard;//T template array
            int a_row,a_col;
    };

}


#endif //TETRISADAPTER_H