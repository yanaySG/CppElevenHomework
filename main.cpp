
#include "matrix.h"

/**  GENERATE RANDNUMS (NORM DIST WITH MEAN=2.5 & STD) ***************************/
double* gen_rand(int N) 
{
    
    double* dist = new double[N]{};
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::normal_distribution<> dis(2.5, 5.0);
    for (int i = 0;i < N; ++i) {

        *(dist+i)=dis(gen);
    }
    
    return dist;
}

/** MAIN HERE ******************************/
int main(int argc, char *argv[])
{
   
        
   int N=2;
   if (argc > 1)
      N=std::stoi(argv[1]);
   
   Matrix A = Matrix(N,N,gen_rand(N*N));
   Matrix B = Matrix(N,N,gen_rand(N*N));
   Matrix C = Matrix(N,N,gen_rand(N*N));
   
   //std::cout << "Matrix A" << std::endl;
   //A.print();
   //std::cout << "Matrix B" << std::endl;
   //B.print();
   //std::cout << "Matrix C" << std::endl;
   //C.print();
   
   //std::cout << "Matrix D = A*B+C" << std::endl;
   Matrix D = A*B+C;
   //D.print();
  
   std::cout << "Diag of Matrix D = A*B+C" << std::endl;
   std::cout << D.diag() << std::endl;
  
   return 0;
}