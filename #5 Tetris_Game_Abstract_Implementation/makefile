all: clear clean compile1 run1 clean compile2 run2
clear: 
	@clear

compile1: driver1.cpp AbstractTetris.cpp TetrisVector.cpp TetrisArray1D.cpp TetrisAdapter.cpp tetromino.cpp
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@g++ driver1.cpp AbstractTetris.cpp  TetrisVector.cpp TetrisArray1D.cpp TetrisAdapter.cpp tetromino.cpp -o Tetris

run1:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@echo "================================================================================="
	./Tetris
	@echo "================================================================================="
	@echo "Completed tests...."

compile2: driver2.cpp AbstractTetris.cpp TetrisVector.cpp TetrisArray1D.cpp TetrisAdapter.cpp tetromino.cpp
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@g++ driver2.cpp AbstractTetris.cpp TetrisVector.cpp TetrisArray1D.cpp TetrisAdapter.cpp tetromino.cpp -o tetris

run2:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@echo "================================================================================="
	./tetris
	@echo "================================================================================="
	@echo "Completed tests...."

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f Tetris
	@rm -f tetris
