import java.util.Scanner;
import java.util.Random;
import java.lang.Thread;

public class Tetris {
    
    private int b_R;
    private int b_C;
    private int gameOver;
    private int midPoint;
    private char [][] game_board;

    Scanner input = new Scanner(System.in);

    public Tetris(final int r_size,final int c_size)//two param consturctor create game board
    {
        b_R=r_size;
        b_C=c_size;
        game_board=new char [b_R+1][b_C];

        for(int i=0;i<b_R;i++)
            for(int j=0;j<b_C;j++)
                game_board[i][j]=' ';

        for(int i=0;i<b_C;i++)
            game_board[b_R][i]='#';
    }

    public int getGameOver(){
        return gameOver;
    }

    public void draw_Game_Board()// draw game board on the screen
    {
        for(int i=0;i<b_C+2;i++)
            System.out.print("#");
        System.out.print("\n");

        for(int i=0;i<b_R+1;i++)
        {
            System.out.print("#");
            for(int j=0;j<b_C;j++)
            {
                System.out.print(game_board[i][j]);
            }
            System.out.print("#\n");
        }
    }

    public int move_and_rotate(Tetromino othObj)//It rotates the object according to the selected direction and angle, 
    {                                           //and also moves the object according to the selected direction and number.
        Random rand = new Random();
        midPoint=(b_C/2)-1;
        int rotate_count,move_count,current_location;

        char [] r_d={'L','R'};
        char rotate_direct=r_d[rand.nextInt(2)];
        rotate_count=rand.nextInt(4);
       
        char move_direct=r_d[rand.nextInt(2)];
        move_count=rand.nextInt(midPoint);
        
        for(int i=0;i<rotate_count;i++)
            othObj.rotate_shape(rotate_direct);

        if(move_direct=='R') current_location=midPoint+move_count;
        else current_location=midPoint-move_count;

        return current_location;
    }

    public void addTetTop(final Tetromino othObj)
    {
        midPoint=(b_C/2)-1;//find midPoint of tetris board...

        for(int i=0;i<othObj.get_R();i++)//Add tetromino top center of the tetris table...
            for(int j=0;j<othObj.get_C();j++)
                game_board[i][j+midPoint]=othObj.getShape()[i][j];

        draw_Game_Board();

        for(int i=0;i<othObj.get_R();i++)
            for(int j=0;j<othObj.get_C();j++)
                game_board[i][j+midPoint]=' ';

    }

    public void addTetromino(final Tetromino othObj)
    {
        int location=move_and_rotate(othObj);//take given location of the tetro obj

        for(int i=0;i<othObj.get_R();i++)
            for(int j=0;j<othObj.get_C();j++)
                game_board[i][j+location]=othObj.getShape()[i][j];

        draw_Game_Board();

        for(int i=0;i<othObj.get_R();i++)
            for(int j=0;j<othObj.get_C();j++)
                game_board[i][j+location]=' ';
        
        for(int j=0;j<othObj.get_R();j++)
            if(game_board[othObj.get_C()][j+location] !=' ') gameOver=1; //if there is no space in the board then finish the game
        
        animate(location,othObj);
    }

    public void animate(final int location,Tetromino othObj)
    {
        int lower=0,m=0;
        int row=othObj.get_R();
        int col=othObj.get_C();

        int []lowcount={0,0,0,0};

        for(int i=0;i<row;i++)//Calculates how far the object can go down from each column
        {
            for(int j=0;j<col;j++)
            {
                if(othObj.getShape()[i][j] != ' ' && game_board[i+1][j+location] == ' ')
                {
                    do
                    {
                        lowcount[m]+=1; 
                    }while((i+lowcount[m]+1)!='#' && game_board[i+lowcount[m]][j+location] ==' ' );
                    m++;
                }
            }
        }

        int minlower=lowcount[0];
        for(int i=1;i<m;i++) //the value from each column is compared and the lowest one is chosen...
        {
            if(lowcount[i] !=0)
            {
                if(lowcount[i] <minlower)
                {
                    minlower=lowcount[i];
                }
            }
        }

        for(lower=0;lower<minlower;lower++) //lowers the object by the calculated value.
        {                               
            if(lower!=0)
            {
                for(int i=0;i<row;i++)
                    for(int j=0;j<col;j++)
                        game_board[i+lower-1][location+j]=' ';
            }

            for(int i=0;i<row;i++) //Add tetromino appropriate location...
                for(int j=0;j<col;j++)
                    if(othObj.getShape()[i][j] != ' ') game_board[i+lower][location+j]=othObj.getShape()[i][j];
                
            //System.out.print("\x1B[2J\x1B[H");
            draw_Game_Board();

            try {
                Thread.sleep(500); // sleep/stop a thread for 1 second
            } 
            catch(InterruptedException e){
               System.out.println("An Excetion occured: " + e);
            }
		
	
        }
    }
    
        
}
