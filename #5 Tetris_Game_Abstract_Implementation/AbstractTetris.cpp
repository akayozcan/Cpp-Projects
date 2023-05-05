#include "AbstractTetris.hpp"

namespace ATC{

    AbstractTetris::AbstractTetris(const int &r_size,const int& c_size)//constructor two param
    {
         setBoardSize(r_size,c_size);
    }


    void AbstractTetris::setBoardSize(const int &r_size,const int &c_size)
    {
        if(r_size <= 0 || c_size <= 0)
        {
            cout<<"Wrong board size values...!"<<endl;
            exit(1);
        }
        board_row = r_size;
        board_col = c_size;
    }

    int AbstractTetris::move_and_rotate()   //It rotates the object according to the selected direction and angle,                                      
    {                                       //and also moves the object according to the selected direction and number. 
        char rotate_direct,move_direct;     
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
            tetClass.rotatematrix(rotate_direct);

        if(move_direct=='R') current_location=midPoint+move_count;
        else current_location=midPoint-move_count;//calculated new loacation

        return current_location;
    } 

    const bool AbstractTetris::get_choise_input() //It creates the tetromino object by taking the tetromino value from the user.
    {                                                   

        tetris *tetarr=new tetris[7]{I,O,T,J,L,S,Z};
        char choice;
        bool r_val=true;
        srand(time(NULL));

        cout<<"Enter the tetromino type(I, O, T, J, L, S, Z ,R-Random ,Q-Quit):"<<endl;
        cin>>choice;
        if(choice=='R') tetClass=Tetromino(tetarr[rand()%7]);
        else if(choice=='Q') r_val=false;
        else tetClass=Tetromino(static_cast<tetris>(choice));

        delete [] tetarr;

        return r_val;
    }

}