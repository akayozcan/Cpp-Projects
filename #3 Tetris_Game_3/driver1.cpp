#include <iostream>
#include <random>
#include "tetris.hpp"
#include "tetromino.hpp"

using namespace std;
using namespace NTetris;
using namespace NTetromino;

int main(){
    Tetromino tetromino1(I);
    tetromino1.create_tetrominos();
    cout<<"Create tetrominos I worked!"<<endl;
    cout<<"Created tetrominos I printing..."<<endl<<endl;
    tetromino1.print_tetromino();

    cout<<"Right Rotate Worked!"<<endl;
    tetromino1.rotatematrix('R');
    tetromino1.print_tetromino();

    cout<<"Left Rotate Worked!"<<endl;
    tetromino1.rotatematrix('L');
    tetromino1.print_tetromino();
    cout<<"--------------------------------------------------"<<endl;
    
    Tetris *tetris1=new Tetris(10,9);
    cout<<"Get_choise_input() function working..."<<endl;
    tetris1->get_choise_input();
    cout<<"operator+= function working..."<<endl;
    cout<<"Inside this function ;"<<endl;
    cout<<"=> move_and_rotate() function working..."<<endl;
    cout<<"=> lower_tetrominos() function working..."<<endl;
    cout<<"=> draw_tetris_board() function working..."<<endl;
    *(tetris1)+=tetris1->othClass;
    
    cout<<endl<<endl;

}
