#include <iostream>
#include <random>
#include <vector>
#include <unistd.h>
#include "tetris.h"
#include "tetromino.h"
using namespace std;

Tetris::Tetris(const int& r_size,const int& c_size):row_size(r_size),col_size(c_size)
{
    v_tetris.resize(row_size,vector<char>(col_size, ' '));
    othClass.setBoardSizes(row_size,col_size);
}

void Tetris::draw_tetris()const{
    for(int i=0;i<col_size+2;i++) cout<<"#";
    cout<<endl;
    for(auto i : v_tetris){
        cout<<"#";
        for(auto j :i){
            cout<<j;
        }
        cout<<"#"<<endl; 
    }
    for(int i=0;i<col_size+2;i++) cout<<"#";
    cout<<endl;
}

const bool Tetris::get_choise_input(){
    vector<tetris>rand_arr{I,O,T,J,L,S,Z};
    char choice;
    bool r_val=true;
    srand(time(NULL));

    cout<<"Enter the tetromino type(R-Random ,Q-Quit):"<<endl;
    cin>>choice;
    if(choice=='R') othClass=Tetromino(rand_arr[rand()%7]);
    else if(choice=='Q') r_val=false;
    else othClass=Tetromino(static_cast<tetris>(choice));
    
    othClass.create_tetrominos();
    return r_val;
}

void Tetris::add_tetrominos(){
    int midPoint=(col_size/2)-1;
    for(int i=0;i<othClass.get_row();i++){
        for(int j=0;j<othClass.get_col();j++){
            v_tetris[i][j+midPoint]=othClass.vect_tetris[i][j];
        }
    }
    draw_tetris();
    for(int i=0;i<othClass.get_row();i++){
        for(int j=0;j<othClass.get_col();j++){
            v_tetris[i][j+midPoint]=' ';
        }
    }

}

void Tetris::fit_tetrominos(){
    int midPoint=(col_size/2)-1;
    int lower=0;
    int row_coord=othClass.getRCor();
    int col_coord=othClass.getCCor();
    int get_row=othClass.vect_tetris.size();
    int get_col=othClass.vect_tetris[0].size();
    
    while (lower != row_size-get_row)
    {   
        for(int i=0;i<get_row;i++){
            for(int j=0;j<get_col;j++){
                v_tetris[i+lower][j+col_coord]=' ';
            }
        }
        lower+=1;
        for(int i=0;i<get_row;i++){
            for(int j=0;j<get_col;j++){
                if(v_tetris[i+lower][j+col_coord] ==' ') v_tetris[i+lower][j+col_coord]=othClass.vect_tetris[i][j];
            }
        }
        cout << "\x1B[2J\x1B[H";
        draw_tetris(); 
        usleep(100000);
    }
}