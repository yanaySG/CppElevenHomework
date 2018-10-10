
#include "matrix.h"
#include <chrono>

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
   try{
      if (argc > 1)
        N=std::stoi(argv[1]);
    }
    catch (std::invalid_argument iaex) { }
   
   std::cout << "Creating matrixes A,B and C of size N = " << N << std::endl << std::endl;
   
   Matrix A = Matrix(N,N,gen_rand(N*N));
   Matrix B = Matrix(N,N,gen_rand(N*N));
   Matrix C = Matrix(N,N,gen_rand(N*N));
   
   auto start1 = std::chrono::high_resolution_clock::now();

   Matrix D = A*B+C;
  
   auto end1 = std::chrono::high_resolution_clock::now();

   std::cout << "Calculated matrix D = A*B+C." << N << std::endl;
  
   std::cout << "Diagonal of matrix D = " << D.diag() << std::endl<< std::endl;
   auto end = std::chrono::high_resolution_clock::now();
   
   std::chrono::duration<double> diff1 = end1-start1;
   std::chrono::duration<double> diff = end-start;
   std::cout << "(calculation time: " << diff1.count() << "s.)" << std::endl;
   std::cout << "(total time: " << diff.count() << "s.)" << std::endl;

   return 0;
}