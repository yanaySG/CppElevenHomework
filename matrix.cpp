#include "matrix.h"
/** IMPLEMENTATION   ******************************/

Matrix::Matrix() : C{0}, R{0}, B{nullptr} 
{ }

Matrix::Matrix(int rows, int cols) : C{cols}, R{rows}, B{new double[cols*rows]{}}
{ }

Matrix::Matrix(int rows, int cols, double* b) : C{cols}, R{rows}, B{new double[cols*rows]{}}
{ 
  
    for (int i = 0; i<rows*cols; i++) 
        *(B+i) = *(b+i);
    
}

Matrix::Matrix( const Matrix & m) : C{m.C}, R{m.R}, B{new double[m.R*m.C]}
{
    copy(m.B, m.B + m.R*m.C, B);
}

Matrix::Matrix(Matrix && m) :C{m.C}, R{m.R}, B{m.B}
{
    m.C = 0;
    m.R = 0;
    m.B = nullptr;
}

Matrix& Matrix::operator= (Matrix&& m){
    swap(C,m.C);
    swap(R,m.R);
    swap(B,m.B);

    return *this;
}

Matrix& Matrix::operator= (const Matrix& m){
    double* aux = new double[m.C*m.R]{};
    copy(m.B,m.B+m.C*m.R,aux);
    delete B;
    B = aux;
    C = m.C;
    R = m.R;
    return *this;
}


bool Matrix::operator() (int row, int col, double val) {
    if (B==nullptr)
        return false;
    B[row*C+col] = val; 
    return true;
}

double Matrix::operator() (int v)  const{
    if(B!=nullptr)
        return B[v]; 
}

double Matrix::operator() (int row, int col) const{
    if (B!=nullptr)
        return B[row*C+col]; 
}


Matrix Matrix::operator+ (const Matrix& m){
    if (R!=m.rows() && C!=m.cols())
        return Matrix();
        
    double* b = new double[R*C];
    
    for(int i=0;i<R*C;i++)
    
        *(b+i) = m(i)+*(B+i);
        
    return Matrix(R,C,b);
}


Matrix Matrix::operator* (const Matrix& m){
    if (C!=m.rows())
        return Matrix();
        
    double* b = new double[R*m.cols()];
    Matrix rM = Matrix(R,m.cols());
    
    for(int r=0;r<R;r++) 
        for(int c=0;c<m.cols();c++) 
        {
            double sum = 0;
            int ri = 0;
            int ci = 0;
            for (; ci != C; ++ri && ++ci)
            {
                sum +=  (*this)(r,ci) * m(ri,c);
            }
                
            rM(r,c,sum);   
        
        }
            
    return rM;
}

void Matrix::print(){
    
    cout << "(rows:" << R << " cols:" << C << ")" << endl;
    for (int r=0;r<R;r++){
        for (int c=0;c<C;c++){
            cout << (*this)(r,c) << "  " ;
        }
        cout << endl;
    }
    
    cout << endl;
}

double Matrix::diag(){
      if (C==R){
            double sum = 0;
            int r = 0;
            int c = 0;
            
            for (; c != C; ++r && ++c)
            {
                sum +=  (*this)(r,c);
            }
        return sum;
      }
}

