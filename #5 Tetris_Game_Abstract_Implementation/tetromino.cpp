#include <iostream>
#include <random>
#include "tetromino.hpp"
using namespace std;

    int Tetromino::numberofmoves=0;

    Tetromino::Tetromino(tetris t):tet(t)//Tetromino one parameter constructor to take tetris enum ...
    {
        create_tetrominos();//create tetromino after called tetromino obj...
        numberofmoves++;
    }

    Tetromino::~Tetromino()//delete tetromino obj after finish its job...
    {   
        // for(int i=0;i<tet_row;i++)
        //     delete[] tetromino[i];
        // delete [] tetromino;
    }
    const Tetromino &Tetromino::operator=(const Tetromino &oth)
    {
        cout<<"operatpor= worked!"<<endl;
        tet_row=oth.getTetRow();
        tet_col=oth.getTetCol();

        tetromino=new char *[tet_row];
        for(int i=0;i<tet_row;i++)
            tetromino[i]=new char[tet_col];

        for(int i=0;i<tet_row;i++)
            for(int j=0;j<tet_col;j++)
                tetromino[i][j]=oth.tetromino[i][j];
        
        return *this;
    }

    void Tetromino::print_tetromino()const{//print tetrominoon the screen
        for(int i=0;i<tet_row;i++){
            for(int j=0;j<tet_col;j++){
                cout<<tetromino[i][j]; 
            }
            cout<<endl;
        }      
    }

    void Tetromino::create_arr(int row,int col){//create tetromino obj array dynamicaly ...
        tet_row=row;
        tet_col=col;

        tetromino=new char*[row];
        for(int i=0;i<row;i++)
            tetromino[i]=new char[col];

        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                tetromino[i][j]=' '; 
    }

    void Tetromino::rotatematrix(char direction){//rotate matrix left or right..
        int i,j;

        int k=0,m=0;

        char **temp=new char*[tet_col];//create dynamic temp array to hold rotated object...
        for(int i=0;i<tet_col;i++)
            temp[i]=new char[tet_row];


    	if(direction=='R'){ //Turn Right
            for (i = 0; i < tet_col; i++) {
    		    for (j = tet_row-1; j >= 0; j--) {
                    temp[k][m]=tetromino[j][i];
                    m++;
    		    }
                k++;
                m=0;
            }
    	}
        else{
            for (i = tet_col-1; i>=0; i--) {//Turn Left
    	        for (j = 0; j < tet_row; j++) {
                    temp[k][m]=tetromino[j][i];
                    m++;
    	        }
                k++;
                m=0;
    	    }
        }

        for(int i=0;i<tet_row;i++)//delete old tetromino object...
            delete[] tetromino[i];

        delete [] tetromino;

        tetromino=new char*[tet_col];//create new tetromino object with row and column of rotated object
        for(int i=0;i<tet_col;i++)
            tetromino[i]=new char[tet_row];


        for(int i=0;i<tet_col;i++) //tetromino=temp;
            for(int j=0;j<tet_row;j++)
                tetromino[i][j]=temp[i][j];


        for(int i=0;i<tet_col;i++)//delete temp object after assign tetromino...
            delete[] temp[i];

        delete [] temp;

        int temp1=tet_row;
        tet_row=tet_col;
        tet_col=temp1;

        numberofmoves++;
    }

    void Tetromino::create_tetrominos(){
        switch (getTetro())//Creates objects according to the enum parameter sent...
        {
            case I:
                create_arr(1,4);
                tetromino[0][0]='I',tetromino[0][1]='I',tetromino[0][2]='I',tetromino[0][3]='I';
                break;
            case O:
                create_arr(2,2);
                tetromino[0][0]='O',tetromino[0][1]='O',tetromino[1][0]='O',tetromino[1][1]='O';
                break;
            case T:
                create_arr(2,3);
                tetromino[0][0]='T',tetromino[0][1]='T',tetromino[0][2]='T',tetromino[1][1]='T';
                break;
            case J:
                create_arr(3,2);
                tetromino[0][1]='J',tetromino[1][1]='J',tetromino[2][0]='J',tetromino[2][1]='J';
                break;
            case L:
                create_arr(3,2);
                tetromino[0][0]='L',tetromino[1][0]='L',tetromino[2][0]='L',tetromino[2][1]='L';
                break;

            case S:
                create_arr(2,3);
                tetromino[0][1]='S',tetromino[0][2]='S',tetromino[1][0]='S',tetromino[1][1]='S';
                break;
            case Z:
                create_arr(2,3);
                tetromino[0][0]='Z',tetromino[0][1]='Z',tetromino[1][1]='Z',tetromino[1][2]='Z';
                break;
        }
    }
