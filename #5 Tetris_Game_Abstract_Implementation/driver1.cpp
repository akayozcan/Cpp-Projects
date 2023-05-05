#include "TetrisVector.hpp"
#include "AbstractTetris.hpp"
#include "TetrisArray1D.hpp"
#include "TetrisAdapter.cpp"
#include "tetromino.hpp"

using namespace ATC;
using namespace TAC;
using namespace T1DARR;
using namespace TVC;


void testDriver(AbstractTetris *AbsTet);
void testFile(AbstractTetris * AbsTet);

int main(){

    int row=10,col=10;//for take input about row and column of tetris board
    char selection;

    AbstractTetris *AbsTet;

    cout<<"# TESTING TETRISVECTOR #\n"<<endl;
    AbsTet=new TetrisVector(row,col);
    testDriver(AbsTet);
    testFile(AbsTet);
    cout<<"-------------------------------------"<<endl;

    cout<<"# TESTING TETRISARRAY1D #\n"<<endl;
    AbsTet=new TetrisArray1D(row,col);
    testDriver(AbsTet);
    testFile(AbsTet);
    cout<<"-------------------------------------"<<endl;

    cout<<"# TESTING ADAPTER / vector #\n"<<endl;
    AbsTet=new TetrisAdapter< vector< char > > (row,col);
    testDriver(AbsTet);
    cout<<"-------------------------------------"<<endl;

    cout<<"# TESTING TETRISARRAY1D / basic_string #\n"<<endl;
    AbsTet=new TetrisAdapter< basic_string< char> > (row,col);
    testDriver(AbsTet);
    cout<<"-------------------------------------"<<endl;

    cout<<"# TESTING TETRISARRAY1D /deque #\n"<<endl;
    AbsTet=new TetrisAdapter< deque< char > > (row,col);
    testDriver(AbsTet);
    cout<<"-------------------------------------"<<endl;

    delete AbsTet;

    return 0;
}


void testDriver(AbstractTetris *AbsTet){

    Tetromino tetro1(I);
    Tetromino tetro2(O);

    cout<<"Adding I Object..."<<endl;
    cout<<"Operator += and animate function working..."<<endl;
    AbsTet->tetClass=tetro1;
    AbsTet->operator+=(tetro1);
    cout<<"Last Move:"<<endl;
    AbsTet->lastMove();
    cout<<"Count of moves:"<<endl;
    cout<<AbsTet->tetClass.getNumOfMove()<<endl;

    cout<<"\n\nAdding O Object..."<<endl;
    cout<<"Operator += and animate function working..."<<endl;
    AbsTet->tetClass=tetro2;
    AbsTet->operator+=(tetro2);
    cout<<"Last Move:"<<endl;
    AbsTet->lastMove();
    cout<<"Count of moves:"<<endl;
    cout<<AbsTet->tetClass.getNumOfMove()<<endl;


}

void testFile(AbstractTetris * AbsTet){
    cout<<"TESTING WRITING AND READING FROM FILE WORKING..."<<endl;
    cout<<"Write function worked!"<<endl;
    AbsTet->writeFile();
    cout<<"Read function worked!"<<endl;
    AbsTet->readFile();;
}   
