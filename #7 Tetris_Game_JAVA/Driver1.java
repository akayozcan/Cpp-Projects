public class Driver1 {
    
    public static void main(String args[]){

        Tetromino tet1=new Tetromino('I');
        Tetromino tet2=new Tetromino('O');
        Tetromino tet3=new Tetromino('J');
        Tetromino tet4=new Tetromino('L');
        Tetromino tet5=new Tetromino('S');
        Tetromino tet7=new Tetromino('T');

        System.out.println("# Tetrominos 4 created ! #");
        System.out.println("Created tetrominos 4 printing...");
        tet4.printShape();

        System.out.println("# Right Rotate Worked! #");
        tet4.rotate_shape('R');
        tet4.printShape();

        System.out.println("# Left Rotate Worked! #");
        tet4.rotate_shape('L');
        tet4.rotate_shape('L');
        tet4.printShape();

        System.out.println("----------------------------------------");

        System.out.println("# Row:10 Col:10 Tetris Game Board Created #");
        Tetris tetris1=new Tetris(10, 10);
        tetris1.draw_Game_Board();

        System.out.println("# I,O,J,L,S,T Objects adding randomly to the Game Board! #");
        tetris1.addTetromino(tet1);
        tetris1.addTetromino(tet2);
        tetris1.addTetromino(tet3);
        tetris1.addTetromino(tet4);
        tetris1.addTetromino(tet5);
        tetris1.addTetromino(tet7);

        tetris1.draw_Game_Board();

        System.out.println("----------------------------------------");

        System.out.println("# Row:10 Col:10 Tetris Game Board Created #");
        Tetris tetris2=new Tetris(10, 10);

        System.out.println("# O Objects adding 3 times to the Game Board! #");
        tetris2.addTetromino(tet2);
        tetris2.addTetromino(tet2);
        tetris2.addTetromino(tet2);

        tetris2.draw_Game_Board();

    }
}
