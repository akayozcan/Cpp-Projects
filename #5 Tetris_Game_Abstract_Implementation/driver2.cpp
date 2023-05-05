#include "TetrisVector.hpp"
#include "AbstractTetris.hpp"
#include "TetrisArray1D.hpp"
#include "TetrisAdapter.cpp"
#include "tetromino.hpp"

using namespace ATC;
using namespace TAC;
using namespace T1DARR;
using namespace TVC;

int main(){

    int row,col;//for take input about row and column of tetris board
    char selection;


    cout<<"Enter the size of row and column of the Tetris board:"<<endl;//take input from user
    cin>>row>>col;
    cout<<"Enter the type of the Tetris class (V for vector, 1 for array1D, A for adaptor)"<<endl;
    cin>>selection;

    AbstractTetris *AbsTet;

    switch (selection)
    {
        case 'V':
            AbsTet=new TetrisVector(row,col);//Call Tetris Vector constructor
            break;
        
        case '1':
            AbsTet=new TetrisArray1D(row,col);//Call Tetris Vector Array 1D constructor
            break;

        case 'A':
            int choise;
            cout<<"Please select Adapter Type:"<<endl;
            cout<<"[1].Vector"<<endl;
            cout<<"[2].Basic_string"<<endl;
            cout<<"[3].Deque"<<endl;
            cin>>choise;

            switch (choise)
            {
                case 1:
                    AbsTet=new TetrisAdapter< vector< char > > (row,col);//Call TetrisAdaptor - vector<char>  constructor
                    break;

                case 2:
                    AbsTet=new TetrisAdapter< basic_string< char> > (row,col);//Call TetrisAdaptor - basic_string< char>  constructor
                    break;

                case 3:
                    AbsTet=new TetrisAdapter< deque< char > > (row,col);   //Call TetrisAdaptor - deque< char >   constructor         
                    break;
            }                                                   
            break;

        default:
            cerr<<"Wrong selection!"<<endl;
            break;
    }



    while(AbsTet->getGameOver() != 1 && AbsTet->get_choise_input() != false) //exits the loop when these conditions are satisfied
    {
        *(AbsTet)+=AbsTet->tetClass;//add tetromino object to tetris board...
    }

    delete AbsTet; // free allocated field of ABstractTetris

    
    return 0;
}
