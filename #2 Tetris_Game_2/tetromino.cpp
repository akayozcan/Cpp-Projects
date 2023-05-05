#include <iostream>
#include <random>
#include <vector>
#include <unistd.h>
#include "tetromino.h"
#include "tetris.h"
using namespace std;

int obj_count=0;
int right_count=0;
int counter=0;
int row_of_board,col_of_board;

vector<vector<char>> vecex;

void Tetromino::calculate_point(){//Calculates how many points there are to get the best fit 
                                    // according to the directions of the objects and creates the object with the highest score.
    vector<float>point_array{0.,0.,0.,0.};//to hold points of rotated objects
    float touchObj=5.,floor=5.1,empty=-5.;//convenient point value for best_fit
    int space_size=0;
    vector<vector<char>> temp_vecex=vecex;

    for(int k=0;k<4;k++){//calculates the bestfit suitability of objects rotated 0 90 180 270 degrees
        
        for(int i=0;i<vect_tetris.size();i++){
            for(int j=0;j<vect_tetris[0].size();j++){
                vecex[row_of_board-vect_tetris.size()+i][j+right_count]=vect_tetris[i][j];
            }
        }

        for(int i=1;i<vect_tetris.size();i++){
            if(vect_tetris[i][0] != ' '){
                if(right_count!=0 && vecex[i+row_of_board-vect_tetris.size()][right_count-1] ==' ') space_size++;
            }
        }
        if(space_size>=2) point_array[k]=100;

        for(int i=0;i<vect_tetris.size();i++){
            if(vect_tetris[i][0] != ' '){
                if(right_count!=0 && vecex[i+row_of_board-vect_tetris.size()][right_count-1] !=' ') point_array[k]+=touchObj;
            }                                                                                      //it calculates how many times object touch another object 
        }                                                                                          //and add points...
        for(int j=0;j<vect_tetris[0].size();j++){
            if(vect_tetris[vect_tetris.size()-1][j] != ' '){
                if(vecex[row_of_board-1][right_count+j] !=' ') point_array[k]+=floor;//calculates touch on floor
                else point_array[k]+=empty;//if there is an empty space between two objejts substruct 5 point...
            }
        }
        vecex.clear();
        vecex=temp_vecex;
        space_size=0;
        rotatematrix();
    }
    int max=0,index;
    for(int k=0;k<4;k++){
        if(max<point_array[k]){ 
            max=point_array[k];
            index=k;
        }
    }

    for(int i=0;i<index;i++) rotatematrix();//returns the object with the highest score
}

void Tetromino::setBoardSizes(int r,int c){//it take row and col of the board and create board vector...
    row_of_board=r;
    col_of_board=c;
    vecex.resize(row_of_board,vector<char> (col_of_board,' '));
}

void Tetromino::print_bestfit()const{//Prints the objects selected as bestfit to the screen.
    for(vector<char> vec : vecex){
        for(auto j :vec){
            cout<<j;
        }
        cout<<endl;
    }
    cout<<"print_bestfit worked"<<endl;
}

void Tetromino::bestfit(){//creates a new Tetris board and plays the game on this board.                    
    int space_size=0;   //It calls the bestfit states via this function, controls them, and creates the bestfit on this table.
                        //Then it sends the coordinates of the bjes to add to our actual tetris vector.
    if(getTetro()!=Z || obj_count !=0){
        calculate_point();
       
        for(int i=1;i<vect_tetris.size();i++){
            if(vect_tetris[i][0] != ' '){
                if( obj_count!=0 && vecex[i+row_of_board-vect_tetris.size()][right_count-1] ==' ') space_size++;
            }
        }
        if(obj_count!=0 && space_size>=2 && vecex[row_of_board-1][right_count]==' '){
            for(int i=0;i<vect_tetris.size();i++){
                for(int j=0;j<vect_tetris[0].size();j++){
                    vecex[row_of_board-vect_tetris.size()+i][j+right_count-1]=vect_tetris[i][j];
                }
            }
            row_cor=row_of_board-vect_tetris.size();
            col_cor+=right_count-1;
            right_count+=vect_tetris[0].size()-1;
        }
        else{
            for(int i=0;i<vect_tetris.size();i++){
                for(int j=0;j<vect_tetris[0].size();j++){
                    vecex[row_of_board-vect_tetris.size()+i][j+right_count]=vect_tetris[i][j];
                }
            }
            row_cor=row_of_board-vect_tetris.size();
            col_cor+=right_count;
            right_count+=vect_tetris[0].size();
        }
    }
    else{ 
        //cout<<"Seconf If"<<endl;
        for(int i=0;i<vect_tetris.size();i++){
            for(int j=0;j<vect_tetris[0].size();j++){
                vecex[row_of_board-vect_tetris.size()+i][j+col_of_board-vect_tetris[0].size()]=vect_tetris[i][j];
            }
        }
        row_cor=row_of_board-vect_tetris.size();
        col_cor=col_of_board-vect_tetris[0].size();
    }
    obj_count++;
    //cout<<"2.bestfit worked"<<endl;
}

void Tetromino::rotatematrix(){//rotate matrix left or right..
    int i,j;
    int k=0,m=0;
    
    int column = vect_tetris[0].size();
    int row = vect_tetris.size();
    vector<vector<char>> temp(column, vector<char> (row));
    
	for (i = 0; i < column; i++) {
		for (j = row-1; j >= 0; j--) {
            temp[k][m]=vect_tetris[j][i];
            m++;
		}
        k++;
        m=0;
	}
    
    vect_tetris.clear();
    vect_tetris=temp;//keeps the new version of the rotated vector
}

void Tetromino::print_tetrominos()const{//print tetrominos on the screen
    for(vector<char> col : vect_tetris){
        for(auto j :col){ //range loop
            cout<<j;
        }
        cout<<endl;
    }
    cout<<endl;
}

void Tetromino::create_tetrominos(){
    switch (Tetromino::getTetro())//Creates objects according to the enum parameter sent...
    {
        case I:
            vect_tetris={{'I','I','I','I'}};
            break;
        case O:
            vect_tetris={{'O','O'},{'O','O'}};
            break;
        case T:
            vect_tetris={{'T','T','T'},{' ','T',' '}};
            break;
        case J:
            vect_tetris={{' ','J'},{' ','J'},{'J','J'}};
            break;
        case L:
            vect_tetris={{'L',' '},{'L',' '},{'L','L'}};
            break;
        case S:
            vect_tetris={{' ','S','S'},{'S','S',' '}};
            break;
        case Z:
            vect_tetris={{'Z','Z',' '},{' ','Z','Z'}};
            break;
    }
    r_size=vect_tetris.size();
    c_size=vect_tetris[0].size();
}