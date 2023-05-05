all: clear clean compile run

compile: Driver1.java Driver2.java Tetromino.java Tetris.java 
	@echo "Driver1 Compiling..."
	@javac Driver1.java
	@echo "Driver2 Compiling..."
	@javac Driver2.java


compilerun2: Driver2.java Tetromino.java Tetris.java
	@echo "Driver2 Compiling..."
	@javac Driver2.java
	@echo "Driver2 Running..."
	@java Driver2

compilerun1: Driver1.java Tetramino.java Tetris.java 
	@echo "Driver1 Compiling..."
	@javac Driver1.java
	@echo "Driver1 Running..."
	@java Driver1

run:
	@echo "Driver1 Running..."
	@java Driver1
	@echo "Driver2 Running..."
	@java Driver2
	

clear: 
	@clear

clean:
	rm -f *.class
