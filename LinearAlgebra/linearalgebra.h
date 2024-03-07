/*
* This library is not intended to use by anyone other than myself (Daniel de Brito), 
* it will not be particularly fast, sice it uses c++ only, nor will it be tremendously functional.
* It serves simply as a learning project and I will be reinventing the wheel a lot here.
*/

#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

class Matrix {
    // Initial implementation is based on vectors, should use pointers in the future
    private:
        unsigned long m_columns;
        unsigned long m_rows;
        std::vector<std::vector<double>> m_matrix;

    public:
        Matrix(int rows, int columns); // Constructor takes two arguments, the amount of rows and the amount of columns. Initializes the matrix with zeroes.
        Matrix(int rows, int columns, double initial);
        Matrix(const Matrix& m);

        // Getters and setters
        void printMatrix();
        int rows() {return m_rows;}
        int columns() {return m_columns;}
        void setValues(); // Sets values for each cell in the matrix
        void setElementValue(int pos_i, int pos_j, double value);

        // End getters and setters

        // Operator overloads for basic matrix operations
        Matrix operator+(const Matrix m); // Matrix addition
        Matrix operator-(const Matrix m); // Matrix subtraction
        void operator*(const double n); // Multiplication by scalar
        Matrix operator*(const Matrix m); // Matrix multiplication
        void operator=(Matrix other); // Assigns one matrix to another
        std::vector<double> operator[](int pos); // Subscript operator allows access to member matrix withou explicit getter method
        // End operator overloads 


};

class Vector {
    private:
        double* v_vector;
        int v_sz;

        static double dotProduct(Vector& u, Vector& v);

    public:

        Vector(int size);
        Vector(int size, double initial);
        int size() {return v_sz;}
        void printVector();
        static void printVector(Vector v);
        void setValue(int pos, double value) {v_vector[pos] = value;}
        // Operator overloads
        void operator=(Vector other); // Assigns one vector to another (copy)
        double operator[](int pos); // Subscript operator allows access to member vector without an explicit getter method
        double operator*(Vector other); // Overloads the * operator to perform dot products
        Vector operator*(double a); // Multiplies the vector by a scalar a
        Vector operator+(Vector other); // Overloads the + operator to perform vector addition
        Vector operator-(Vector other); // Overloads the - operator to perform vector subtraction
        // End operator overloads
};

void gaussianEliminate(Matrix& A, Vector& b); // Performs gaussian elimination on a linear system Ax=b

std::vector<double> solveSystem(Matrix& A, Vector& x, Vector& b); // Solves a linear system Ax=b, returns a vector

void echelon(Matrix& A); // Changes a matrix into its echelon form
