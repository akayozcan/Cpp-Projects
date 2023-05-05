
public class Tetromino {

    private char objType;
    private int _R;
    private int _C;
    private char [][] tetShape;

    public Tetromino()//no param const
    {
        //intentionaly empty
    }

    public Tetromino(char T)//one param const
    {
        objType=T;
        create_Tetrominos();
    }

    public void setType(char type)
    {
        objType=type;
    }

    public char getType()
    {
        return objType;
    }

    public int get_R()
    {
        return _R;
    }


    public int get_C()
    {
        return _C;
    }

    public char[][] getShape()
    {
        return tetShape;
    }

    private void create_shape(int row,int col)//create tetromino obj given row and col size...
    {
        _R=row;
        _C=col;

        tetShape = new char[_R][_C];
        
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                tetShape[i][j]=' ';
    } 

    public void rotate_shape(char direction)//rotate tetromino object given direction
    {
        int i,j,k=0,m=0;

        char [][] temp=new char[_C][_R];

    	if(direction=='R') //Turn Right
        { 
            for (i = 0; i < _C; i++)
            {
    		    for (j = _R-1; j >= 0; j--)
                {
                    temp[k][m]=tetShape[j][i];
                    m++;
    		    }
                k++;
                m=0;
            }
    	}
        else{
            for (i = _C-1; i>=0; i--) //Turn Left
            {
    	        for (j = 0; j < _R; j++) 
                {
                    temp[k][m]=tetShape[j][i];
                    m++;
    	        }
                k++;
                m=0;
    	    }
        }

        tetShape=null;
        tetShape=new char[_C][_R];

        for(i=0;i<_C;i++) //tetromino=temp;
            for(j=0;j<_R;j++)
                tetShape[i][j]=temp[i][j];

        temp=null;

        int temp1=_R;
        _R=_C;
        _C=temp1;
    }
    
    public void printShape()
    {
        for(int i=0;i<_R;i++)
        {
            for(int j=0;j<_C;j++)
            {
                System.out.print(tetShape[i][j]); 
            }
            System.out.printf("\n");
        }  
    }

    public void create_Tetrominos()
    {
        switch (getType())//Creates objects according to the enum parameter sent...
        {
            case 'I':
                create_shape(1,4);
                tetShape[0][0]='I';
                tetShape[0][1]='I';
                tetShape[0][2]='I';
                tetShape[0][3]='I';
                break;
            case 'O':
                create_shape(2,2);
                tetShape[0][0]='O';
                tetShape[0][1]='O';
                tetShape[1][0]='O';
                tetShape[1][1]='O';
                break;
            case 'T':
                create_shape(2,3);
                tetShape[0][0]='T';
                tetShape[0][1]='T';
                tetShape[0][2]='T';
                tetShape[1][1]='T';
                break;
            case 'J':
                create_shape(3,2);
                tetShape[0][1]='J';
                tetShape[1][1]='J';
                tetShape[2][0]='J';
                tetShape[2][1]='J';
                break;
            case 'L':
                create_shape(3,2);
                tetShape[0][0]='L';
                tetShape[1][0]='L';
                tetShape[2][0]='L';
                tetShape[2][1]='L';
                break;

            case 'S':
                create_shape(2,3);
                tetShape[0][1]='S';
                tetShape[0][2]='S';
                tetShape[1][0]='S';
                tetShape[1][1]='S';
                break;
            case 'Z':
                create_shape(2,3);
                tetShape[0][0]='Z';
                tetShape[0][1]='Z';
                tetShape[1][1]='Z';
                tetShape[1][2]='Z';
                break;
        }
    }
}
