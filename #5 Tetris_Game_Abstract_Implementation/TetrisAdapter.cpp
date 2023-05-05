#include "TetrisAdapter.hpp"

namespace TAC{

    template <class T>
    TetrisAdapter<T>::TetrisAdapter():AbstractTetris()//no param constructor
    {
        //intentionaly empty
    }

    template <class T>
    TetrisAdapter<T>::TetrisAdapter(const int &r_s,const int &c_s):AbstractTetris(r_s,c_s)//two param consturctor
    {
        createTetrisBoard();
    }

    template <class T>
    TetrisAdapter<T>::~TetrisAdapter()//destrutor free arrBoard dynmaci arrya
    {
        if(arrBoard != nullptr)
        {
            delete [] arrBoard;
            arrBoard=nullptr;
        }  
    }

    template <class T>
    const void TetrisAdapter<T>::draw() const //draw tetris board on the screen
    {
        for(int i=0;i<getB_Col()+2;i++)
            cout<<'#';
        cout<<endl;

        for(int i=0;i<getB_Row()+1;i++)
        {
            cout<<"#";
            for(int j=0;j<getB_Col();j++)
            {
                cout<<arrBoard[i][j];
            }
            cout<<"#"<<endl;
        }
    }


    template <class T>
    void TetrisAdapter<T>::createTetrisBoard()
    {
        arrBoard=new T[getB_Row()+1];

        for(int i=0;i<getB_Row();i++)
        {
            arrBoard[i].resize(getB_Col());
            for(int j=0;j<getB_Col();j++){
                arrBoard[i][j]=' ';
            }
        }
        arrBoard[getB_Row()].resize(getB_Col());

        for(int i=0;i<getB_Col();i++)
            arrBoard[getB_Row()][i]='#';

    }


    template <class T>
    const AbstractTetris& TetrisAdapter<T>::operator=(const TetrisAdapter &oth)
    {
        a_row=oth.a_row;
        a_col=oth.a_col;

        arrBoard=new T[a_row*a_col];

        for(int i=0;i<a_row*a_col;i++)
            arrBoard->at(i)=oth.arrBoard[i];

        return *this;
    }

    template <class T>
    const AbstractTetris& TetrisAdapter<T>::operator+=(const Tetromino &oth)//Add tetromino to tetris board ,and move-rotate-animate the tetromino
    {
        int location;
        midPoint=(getB_Col()/2)-1;//find midPoint of tetris board...
    
        for(int i=0;i<oth.getTetRow();i++)//Add tetromino top center of the tetris table...
            for(int j=0;j<oth.getTetCol();j++)
                arrBoard[i][j+midPoint]=oth.getTetromino()[i][j];

        draw();

        for(int i=0;i<tetClass.getTetRow();i++)
            for(int j=0;j<tetClass.getTetCol();j++)
                arrBoard[i][j+midPoint]=' ';

        location=move_and_rotate();//take given location of the tetro obj

        for(int i=0;i<oth.getTetRow();i++)
            for(int j=0;j<oth.getTetCol();j++)
                arrBoard[i][j+location]=oth.getTetromino()[i][j];

        for(int j=0;j<tetClass.getTetCol();j++){
            if(arrBoard[tetClass.getTetRow()][j+location] !=' ') gameOver=1; 
        }

        draw();
        animate(location);

        return *this;
    }

    template <class T>
    void TetrisAdapter<T>::animate(const int &location)//lowers tetromino top to bottom
    {

        int lower=0,m=0;
        int row=tetClass.getTetRow();
        int col=tetClass.getTetCol();

        int *lowcount=new int[4]{0,0,0,0};

        for(int i=0;i<row;i++)//Calculates how far the object can go down from each column
        {
            for(int j=0;j<col;j++)
            {
                if(tetClass.getTetromino()[i][j] != ' ' && arrBoard[i+1][j+location] == ' ')
                {
                    do
                    {
                        lowcount[m]+=1; 
                    }while(arrBoard[i+lowcount[m]][j+location] ==' ');
                    m++;
                }
            }
        }

        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                arrBoard[i][j+location]=' ';


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
                        arrBoard[i+lower-1][location+j]=' ';
                    }
                }
            }

            for(int i=0;i<row;i++){//Add tetromino appropriate location...
                for(int j=0;j<col;j++){
                    if(tetClass.getTetromino()[i][j] != ' ') arrBoard[i+lower][location+j]=tetClass.getTetromino()[i][j];
                }
            }
            cout << "\x1B[2J\x1B[H";
            draw();
            usleep(250000);

        }
        delete [] lowcount;//delete dynamicly allocated space in the heap...
    }


    template <class T>
    void TetrisAdapter<T>::writeFile()
    {
        // ofstream myfile;
        // myfile.open("text.txt",ios::out);

        // if (myfile.is_open())
        // {
        //     for(int i=0;i<getB_Col()+2;i++)
        //         myfile<<'#';
        //     myfile<<endl;

        //     for(auto row : arrBoard)
        //     {
        //         myfile<<"#";
        //         for(auto col : row)
        //         {
        //             myfile<<col;
        //         }
        //         myfile<<"#"<<endl;
        //     }  
        // }

        // myfile.close();
    }

    template <class T>
    void TetrisAdapter<T>::readFile()//Read from file...
    {
        string line;
        ifstream myfile;
        myfile.open("text.txt",ios::in);

        if (myfile.is_open())
        {   
            while (getline(myfile, line)) 
                cout<<line<<endl;   
        }
        myfile.close();
    }



    template <class T> //print last move
    void TetrisAdapter<T>::lastMove()
    {
        tetClass.print_tetromino();
    }

}