import java.util.Scanner;
import java.util.Random;
public class Driver2{

    public static void main(String args[])
    {
        Scanner input=new Scanner(System.in);

        Tetromino tetromino=new Tetromino();
        //for take input about row and column of tetris board

        System.out.println("Enter the size of row of the Tetris board:");
        int row=input.nextInt();
        System.out.println("Enter the size of column of the Tetris board:");
        int col=input.nextInt();

        Tetris tetris1=new Tetris(row,col);
        boolean r_val=true;
        do{           

            Random rand = new Random();
            char [] tetros={'I','O','T','J','L','S','Z'};
            
            System.out.println("Enter the tetromino type( I,O,T,J,L,S,Z,R-Random,Q-Quit):");
            char choice = input.next().charAt(0);
    
            if(choice=='R') tetromino=new Tetromino(tetros[rand.nextInt(6)+1]); 
            else if(choice=='Q') r_val=false;
            else tetromino=new Tetromino(choice);

            tetris1.addTetTop(tetromino);
            tetris1.addTetromino(tetromino);

        }while(tetris1.getGameOver() != 1 || r_val !=true);

        System.out.println("Game is over!");

        input.close();
    }
}
