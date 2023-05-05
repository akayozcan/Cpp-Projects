#ifndef TETROMINO_H
#define TETROMINO_H

#include <iostream>
#include <random>
#include <vector>
using namespace std;

typedef enum tetrominos{I,O,T,J,L,S,Z}tetris;
int counter=0;

class Tetromino{
    public:
        Tetromino(tetris t):tet(t){}//one parameter constructor...Parameter is enum type...
        int getTetro()const{return tet;}
        void create_tetrominos();//according to random selection ,this function creat tetrominos object...
        void print_tetrominos()const;//print tetromino objects on the screen
        void rotatematrix(int choise);//rotate matrix left or right..
        vector<vector<char>> vect_tetris;//vector hold tetrominos object

    private:
        tetris tet;
        int right=1,left=0;
};

void Tetromino::rotatematrix(int choise){
    int i,j;
    int k=0,m=0;

    int column = vect_tetris[0].size();
    int row = vect_tetris.size();
    vector<vector<char>> temp(column, vector<char> (row));
    if(choise == right){//rotate tetrominos right
	    for (i = 0; i < column; i++) {
	    	for (j = row-1; j >= 0; j--) {
                temp[k][m]=vect_tetris[j][i];
                m++;
	    	}
            k++;
            m=0;
	    }
    }
    else{//rotate tetrominos left
	    for (i = column-1; i>=0; i--) {
	    	for (j = 0; j < row; j++) {
                temp[k][m]=vect_tetris[j][i];
                m++;
	    	}
            k++;
            m=0;
	    }
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
    print_tetrominos();
}


void print_bestfit(vector<vector<char>> vecex){//Prints the objects selected as bestfit to the screen.
    for(vector<char> vec : vecex){
        for(auto j :vec){
            cout<<j;
        }
        cout<<endl;
    }
}

bool canFitFunction(vector<vector<char>> vecex,Tetromino& TObj){//Function that checks whether tetromino objects match, 
                                                                //returns false if there is a space between them
    int space_count=0;
    if(TObj.getTetro()==Z || TObj.getTetro()==S){
        for(int j=0;j<counter-1;j++){
            if(vecex[3][j] == ' ') space_count++;
        }
    }
    else{
        for(int j=0;j<counter;j++){
            if(vecex[3][j] == ' ') space_count++;
        }
    }
    
    if(space_count==0) {return true;}
    else{
        TObj.rotatematrix(1);//if objects doesn't match ,it call rotatematrix functiond and return 90 degree to object..
        counter-=TObj.vect_tetris[0].size();
        return false;
    }
}

vector<vector<char>> filltable(Tetromino& Tobj,vector<vector<char>> vecex){//function that combines objects and keeps them in a single array
    bool can_fit;
    vector<vector<char>> temp_vecex1;//Aim to temp function is if this object doesnt fit conveient way ,then it returns first vector.
    temp_vecex1=vecex;
    do{
        for(int i=vecex.size()-1;i>=vecex.size()-Tobj.vect_tetris.size();i--){//fill vector
            for(int j=0;j<Tobj.vect_tetris[0].size();j++){
                vecex[i][j+counter]=Tobj.vect_tetris[i-(vecex.size()-Tobj.vect_tetris.size())][j];
            }
        }

        counter+=Tobj.vect_tetris[0].size();
        can_fit= canFitFunction(vecex,Tobj);
        if((can_fit==false)){
            vecex=temp_vecex1;
        }
        else if((counter-1)>0 && vecex[2][counter]==' ' && vecex[3][counter-1]==' '){//if there is space betwen two object,it combine them and fill the blanks...
            vecex=temp_vecex1;
            counter-=Tobj.vect_tetris[0].size();
            for(int i=vecex.size()-1;i>=vecex.size()-Tobj.vect_tetris.size();i--){
                for(int j=0;j<Tobj.vect_tetris[0].size();j++){
                    if(vecex[i][j+counter-1]==' ' && vecex[2][counter]==' ' && vecex[3][counter-1]==' ')
                        vecex[i][j+counter-1]=Tobj.vect_tetris[i-(vecex.size()-Tobj.vect_tetris.size())][j];
                }
            }
        }   
    }
    while(!can_fit);
    
    return vecex;
}

void print_tetrominos_name(vector<int> v_name){//print selection objects name on the scree.
    for(auto k:v_name){
        if(k==I) cout<<"I"<<endl;
        else if(k==O) cout<<"O"<<endl;
        else if(k==T) cout<<"T"<<endl;
        else if(k==J) cout<<"J"<<endl;
        else if(k==L) cout<<"L"<<endl;
        else if(k==S) cout<<"S"<<endl;
        else if(k==Z) cout<<"Z"<<endl;
    }
}
#endif