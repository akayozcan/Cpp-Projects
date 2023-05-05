all: clear clean compile run
clear: 
	@clear

compile: main.cpp PFArray.cpp
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@g++ main.cpp PFArray.cpp -o program

run:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@echo "================================================================================="
	./program
	@echo "================================================================================="
	@echo "Completed tests...."

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f program
	
