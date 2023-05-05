#include "TetrisVector.hpp"

namespace TVC{


    TetrisVector::TetrisVector() : AbstractTetris(){
        //Intentionally empty.
    }

    TetrisVector::TetrisVector(const int &r_s,const int &c_s):AbstractTetris(r_s,c_s),v_row(r_s),v_col(c_s)
    {
        createTetrisBoard();
    }

    TetrisVector::~TetrisVector()
    {

    }

    void TetrisVector::createTetrisBoard()
    {
        v_tet_board.resize( getB_Row()+1 , vector<char>( getB_Col() ,' ' ));

        for(int i=0;i<getB_Col();i++)
            v_tet_board[getB_Row()][i]='#';

    }

    const TetrisVector& TetrisVector::operator+=(const Tetromino& othObj)
    {
        int location;
        midPoint=(getB_Col()/2)-1;//find midPoint of tetris board...
    
        for(int i=0;i<othObj.getTetRow();i++)//Add tetromino top center of the tetris table...
            for(int j=0;j<othObj.getTetCol();j++)
                v_tet_board[i][j+midPoint]=othObj.getTetromino()[i][j];

        draw();

        for(int i=0;i<tetClass.getTetRow();i++)
            for(int j=0;j<tetClass.getTetCol();j++)
                v_tet_board[i][j+midPoint]=' ';

        location=move_and_rotate();//take given location of the tetro obj

        for(int i=0;i<othObj.getTetRow();i++)
            for(int j=0;j<othObj.getTetCol();j++)
                v_tet_board[i][j+location]=othObj.getTetromino()[i][j];

        for(int j=0;j<tetClass.getTetCol();j++){
            if(v_tet_board[tetClass.getTetRow()][j+location] !=' ') gameOver=1; 
        }

        draw();
        animate(location);

        return *this;
    }

    const void TetrisVector::draw() const
    {
        for(int i=0;i<getB_Col()+2;i++)
            cout<<'#';

        cout<<endl;
        for(auto row : v_tet_board)
        {
            cout<<"#";
            for(auto col : row)
            {
                cout<<col;
            }
            cout<<"#"<<endl;
        }

    }

    void TetrisVector::animate(const int &location)
    {
        int lower=0,m=0;
        int row=tetClass.getTetRow();
        int col=tetClass.getTetCol();

        int *lowcount=new int[4]{0,0,0,0};

        for(int i=0;i<row;i++)//Calculates how far the object can go down from each column
        {
            for(int j=0;j<col;j++)
            {
                if(tetClass.getTetromino()[i][j] != ' ' && v_tet_board[i+1][j+location] == ' ')
                {
                    do
                    {
                        lowcount[m]+=1; 
                    }while(v_tet_board[i+lowcount[m]][j+location] ==' ');
                    m++;
                }
            }
        }

        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                v_tet_board[i][j+location]=' ';


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
                        v_tet_board[i+lower-1][location+j]=' ';
                    }
                }
            }

            for(int i=0;i<row;i++){//Add tetromino appropriate location...
                for(int j=0;j<col;j++){
                    if(tetClass.getTetromino()[i][j] != ' ') v_tet_board[i+lower][location+j]=tetClass.getTetromino()[i][j];
                }
            }
            cout << "\x1B[2J\x1B[H";
            draw();
            usleep(250000);

        }
        delete [] lowcount;//delete dynamicly allocated space in the heap...
    }

    void TetrisVector::writeFile()
    {
        cout<<"Write file worked!"<<endl;
        ofstream myfile;
        myfile.open("text.txt",ios::out);

        if (myfile.is_open())
        {
            for(int i=0;i<getB_Col()+2;i++)
                myfile<<'#';
            myfile<<endl;

            for(auto row : v_tet_board)
            {
                myfile<<"#";
                for(auto col : row)
                {
                    myfile<<col;
                }
                myfile<<"#"<<endl;
            }  
        }
        myfile.close();
    }

    void TetrisVector::readFile()
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

    void TetrisVector::lastMove()
    {
           tetClass.print_tetromino();
    }
}