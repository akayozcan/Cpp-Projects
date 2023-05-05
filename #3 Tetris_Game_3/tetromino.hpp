#ifndef TETROMINO_HPP
#define TETROMINO_HPP


namespace NTetromino{
    
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
            Tetromino(tetris t);//one parameter constructor...Parameter is enum type...
            ~Tetromino();

            tetris getTetro() const{return tet;}
            int getTetRow() const {return tet_row;}
            int getTetCol() const {return tet_col;}

            void create_tetrominos();//according to random selection ,this function creat tetrominos object...
            void print_tetromino()const;//print tetromino objects on the screen
            void rotatematrix(char direction);//rotate matrix left or right..
            char **getTetromino()const{return tetromino;}//return tetromino array...

        private:
            tetris tet;
            int tet_row,tet_col;
            char **tetromino;
            void create_arr(int row,int col);
    };  

}
#endif //TETROMINO_H