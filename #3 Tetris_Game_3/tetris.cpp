#include <iostream>
#include <random>
#include <unistd.h>
#include "tetris.hpp"
#include "tetromino.hpp"
using namespace std;

namespace NTetris{
    Tetris::Tetris(const int& r_size,const int& c_size):board_row(r_size),board_col(c_size),gameOver(0)
    {
        tet_board=new char*[board_row+1]; //With the operation of the tetris consturcter,
        for(int i=0;i<board_row+1;i++)    // it creates dynamic the game board and initializes the whole as space.
            tet_board[i]=new char[board_col];

        for(int i=0;i<board_row;i++)
            for(int j=0;j<board_col;j++)
                tet_board[i][j]=' ';
        for(int i=0;i<board_col;i++)
            tet_board[board_row][i]='#';
    }

    Tetris::~Tetris(){//dynamically deletes the field after the game is over

        for(int i=0;i<board_row+1;i++)
            delete[] tet_board[i];
        delete [] tet_board;

    }

    void Tetris::lower_tetrominos(const int &location){//Lowers the tetromino object as far as it can go.
        int lower=0,m=0;
        int row=othClass.getTetRow();
        int col=othClass.getTetCol();

        int *lowcount=new int[4]{0,0,0,0};

        for(int i=0;i<row;i++)//Calculates how far the object can go down from each column
        {
            for(int j=0;j<col;j++)
            {
                if(othClass.getTetromino()[i][j] != ' ' && tet_board[i+1][j+location] == ' ')
                {
                    do
                    {
                        lowcount[m]+=1; 
                    }while((i+lowcount[m]+1)!='#' && tet_board[i+lowcount[m]][j+location] ==' ' );
                    m++;
                }
            }
        }

        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                tet_board[i][j+location]=' ';


        int minlower=lowcount[0];
        for(int i=1;i<m;i++){//the value from each column is compared and the lowest one is chosen...
            if(lowcount[i] !=0){
                if(lowcount[i] <minlower){
                    minlower=lowcount[i];
                }
            }
        }

        for(int lower=0;lower<minlower;lower++){//lowers the object by the calculated value.
            if(lower!=0){
                for(int i=0;i<row;i++){
                    for(int j=0;j<col;j++){
                        tet_board[i+lower-1][location+j]=' ';
                    }
                }
            }

            for(int i=0;i<row;i++){//Add tetromino appropriate location...
                for(int j=0;j<col;j++){
                    if(othClass.getTetromino()[i][j] != ' ') tet_board[i+lower][location+j]=othClass.getTetromino()[i][j];
                }
            }
            cout << "\x1B[2J\x1B[H";
            draw_tetris_board();
            usleep(250000);

        }
        delete [] lowcount;//delete dynamicly allocated space in the heap...
    }

    int Tetris::move_and_rotate(){      //It rotates the object according to the selected direction and angle, 
        char rotate_direct,move_direct;//and also moves the object according to the selected direction and number.
        int rotate_count,move_count,current_location;

        cout<<"Enter rotate direction(L-left,R-right):";
        cin>>rotate_direct;
        do{
            cout<<"Enter rotation count(0-0 degre,1-90 degre,2-180 degre,3-270 degre):";
            cin>>rotate_count;
        }while(rotate_count>3 || rotate_count<0);

        cout<<"Enter move direction(L-left,R-right):";
        cin>>move_direct;
        do{
            cout<<"Enter move count:";
            cin>>move_count;
        }while(move_count>midPoint || move_count<0);

        for(int i=0;i<rotate_count;i++)//rotate object
            othClass.rotatematrix(rotate_direct);

        if(move_direct=='R') current_location=midPoint+move_count;
        else current_location=midPoint-move_count;//calculated new loacation

        return current_location;
    }

    void Tetris::draw_tetris_board()const{//print tetris board on the screen..
        for(int i=0;i<getBoardCol()+2;i++)
            cout<<"#";
        cout<<endl;

        for(int i=0;i<getBoardRow()+1;i++){
            cout<<"#";
            for(int j=0;j<getBoardCol();j++){
                cout<<tet_board[i][j];
            }
            cout<<"#"<<endl;
        }
        cout<<endl;
    }

    Tetris& Tetris::operator+=(const Tetromino& othObj){////with += operator overloding it can be added tetromino obj to tetboard...
        int location;
        midPoint=(board_col/2)-1;//find midPoint of tetris board...

        for(int i=0;i<othObj.getTetRow();i++)//Add tetromino top center of the tetris table...
            for(int j=0;j<othObj.getTetCol();j++)
                tet_board[i][j+midPoint]=othObj.getTetromino()[i][j];


        draw_tetris_board();

        for(int i=0;i<othClass.getTetRow();i++)
            for(int j=0;j<othClass.getTetCol();j++)
                tet_board[i][j+midPoint]=' ';

        location=move_and_rotate();//take given location of the tetro obj

        for(int i=0;i<othObj.getTetRow();i++)
            for(int j=0;j<othObj.getTetCol();j++)
                tet_board[i][j+location]=othObj.getTetromino()[i][j];

        for(int j=0;j<othClass.getTetCol();j++){
            if(tet_board[othClass.getTetRow()][j+location] !=' ') gameOver=1; 
        }

        draw_tetris_board();
        lower_tetrominos(location);

        return *this;
    }

    const bool Tetris::get_choise_input(){//It creates the tetromino object by taking the tetromino value from the user.
        tetris *tetarr=new tetris[7]{I,O,T,J,L,S,Z};
        char choice;
        bool r_val=true;
        srand(time(NULL));

        cout<<"Enter the tetromino type(R-Random ,Q-Quit):"<<endl;
        cin>>choice;
        if(choice=='R') othClass=Tetromino(tetarr[rand()%7]);
        else if(choice=='Q') r_val=false;
        else othClass=Tetromino(static_cast<tetris>(choice));

        delete [] tetarr;

        return r_val;
    }
}