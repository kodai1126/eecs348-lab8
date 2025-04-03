all: matrix_operations

matrix_operations: src/main.cpp src/matrix_operations.cpp
	g++ -o matrix_operations src/main.cpp src/matrix_operations.cpp

clean:
	rm -f matrix_operations
