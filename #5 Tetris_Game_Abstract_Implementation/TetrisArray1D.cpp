#include "TetrisArray1D.hpp"


namespace T1DARR{

    TetrisArray1D::TetrisArray1D():AbstractTetris()
    {
        //intentionaly empty
    }

    TetrisArray1D::TetrisArray1D(const int &r_s,const int &c_s):AbstractTetris(r_s,c_s),a_row(r_s),a_col(c_s)
    {
        createTetrisBoard();
    }

    TetrisArray1D::~TetrisArray1D()
    {
        if(arrBoard != nullptr)
        {
            delete [] arrBoard;
            arrBoard=nullptr;
        }    
    }

    const TetrisArray1D &TetrisArray1D::operator=(const TetrisArray1D &oth)
    {
        a_row=oth.a_row;
        a_col=oth.a_col;

        arrBoard=new char[a_row*a_col];

        for(int i=0;i<a_row*a_col;i++)
            arrBoard[i]=oth.arrBoard[i];

        return *this;
    }

    void TetrisArray1D::createTetrisBoard()
    {
        int size1D=(getB_Row()+1)*getB_Col();
        int k=0;
        arrBoard=new char[size1D];

        for(int i=0;i<size1D-getB_Col();i++,k++)
            arrBoard[i]=' ';

        for(int i=0;i<getB_Col();i++)
            arrBoard[k+i]='#';
    }

    const void TetrisArray1D::draw() const
    {   
        for(int i=0;i<getB_Col()+2;i++)
            cout<<'#';
        cout<<endl;

        for(int i=0;i<getB_Row()+1;i++)
        {
            cout<<"#";
            for(int j=0;j<getB_Col();j++)
            {
                cout<<arrBoard[i*getB_Col()+j];
            }
            cout<<"#"<<endl;
        }
    }

    const TetrisArray1D &TetrisArray1D::operator+=(const Tetromino& othObj)
    {
        int location;
        int r_cls=tetClass.getTetRow(),c_cls=tetClass.getTetCol();

        midPoint=(getB_Col()/2)-1;

        for(int i=0;i<othObj.getTetRow();i++)//Add tetromino top center of the tetris table...
            for(int j=0;j<othObj.getTetCol();j++)
                arrBoard[i*getB_Col() + j +midPoint]=othObj.getTetromino()[i][j];

        draw();

        for(int i=0;i<r_cls;i++)
            for(int j=0;j<c_cls;j++)
                arrBoard[i*getB_Col() + j +midPoint]=' ';

        location=move_and_rotate();

        for(int i=0;i<othObj.getTetRow();i++)
            for(int j=0;j<othObj.getTetCol();j++)
                arrBoard[i*getB_Col() + j +location]=othObj.getTetromino()[i][j];

        for(int j=0;j<c_cls;j++){
            if(arrBoard[r_cls*getB_Col() + j + location] != ' ') gameOver=1;       

        }

        draw();
        animate(location);

        return *this;
    }

    void TetrisArray1D::animate(const int &location)
    {
        int lower=0,m=0;
        int row=tetClass.getTetRow();
        int col=tetClass.getTetCol();

        int *lowcount=new int[4]{0,0,0,0};

        for(int i=0;i<row;i++)//Calculates how far the object can go down from each column
        {
            for(int j=0;j<col;j++)
            {                                               
                if(tetClass.getTetromino()[i][j] != ' ' && arrBoard[(i+1)*getB_Col() +j + location] == ' ')
                {
                    do
                    {
                        lowcount[m]+=1; 
                    }while(arrBoard[(i+lowcount[m])*getB_Col()+j+location] == ' ');
                    m++;
                }
            }
        }

        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                arrBoard[i*getB_Col() + j + location]=' ';


        int minlower=lowcount[0];
        for(int i=1;i<m;i++)    //the value from each column is compared and the lowest one is chosen...
        {
            if(lowcount[i] !=0){
                if(lowcount[i] <minlower){
                    minlower=lowcount[i];
                }
            }
        }

        for(int lower=0;lower<minlower;lower++)//lowers the object by the calculated value.
        {
            if(lower!=0)
            {
                for(int i=0;i<row;i++)
                    for(int j=0;j<col;j++)
                        arrBoard[(i+lower-1)*getB_Col() + j + location]=' ';

            }

            for(int i=0;i<row;i++)//Add tetromino appropriate location...
                for(int j=0;j<col;j++)
                    if(tetClass.getTetromino()[i][j] != ' ') arrBoard[(i+lower)*getB_Col() + j + location]=tetClass.getTetromino()[i][j];                   


            cout << "\x1B[2J\x1B[H";
            draw();
            usleep(250000);

        }
        delete [] lowcount;//delete dynamicly allocated space in the heap...

    }

    void TetrisArray1D::writeFile()
    {
        ofstream myfile;
        myfile.open("text.txt",ios::out);

        if (myfile.is_open())
        {
            for(int i=0;i<getB_Col()+2;i++)
                myfile<<'#';
            myfile<<endl;

            for(int i=0;i<getB_Row()+1;i++)
            {
                myfile<<"#";
                for(int j=0;j<getB_Col();j++)
                {
                    myfile<<arrBoard[i*getB_Col()+j];
                }
                myfile<<"#"<<endl;
            }

        }

        myfile.close();
    }

    void TetrisArray1D::readFile()
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

    void TetrisArray1D::lastMove()
    {
        tetClass.print_tetromino();
    }

}