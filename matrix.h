
#include <iostream>
#include <random>
#include <vector>

using namespace std;

/** DECLARATION   ******************************/

#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
    
    private:
        int C;
        int R;
        double* B;
    
    public:
        Matrix();
        Matrix(int , int );
        Matrix(int , int , double* );
        Matrix(const Matrix &);
        Matrix(Matrix &&);

        int rows() const { return R; }
        int cols() const { return C; }
        double* buffer() const {return B;}
        void setbuffer(const double* buff);
        void print();
        double diag();

        
        double operator() (int) const;
        double operator() (int, int ) const;
        bool operator() (int, int ,double);
        Matrix& operator= (Matrix&& );
        Matrix& operator= (const Matrix& );
        Matrix operator+ (const Matrix&);
        Matrix operator* (const Matrix&);
        
    
    };

#endif
