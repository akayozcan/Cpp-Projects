all: clear clean compile run
     
clear: 
	@clear

compile: drive1.cpp dayofyear.cpp
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@g++ drive1.cpp dayofyear.cpp -o program
	
	

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
	

