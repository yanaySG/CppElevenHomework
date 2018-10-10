
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
   auto start = std::chrono::high_resolution_clock::now();

   
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
   
   auto start1 = std::chrono::high_resolution_clock::now();

   Matrix D = A*B+C;
  
   auto end1 = std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> diff1 = end1-start1;
   std::cout << "Expression calculation time: " << diff1.count() << "s." << std::endl;
   
   std::cout << "Diag of Matrix D = A*B+C" << std::endl;
   std::cout << D.diag() << std::endl;
  
  
   auto end = std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> diff = end-start;
   std::cout << "Total time: " << diff.count() << "s." << std::endl;

   return 0;
}