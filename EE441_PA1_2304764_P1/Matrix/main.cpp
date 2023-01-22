#include <iostream>
#include "Matrix.h"
#include "math.h"

using namespace std;

template <int N>
Matrix<N> m_addition(Matrix<N>& A, Matrix<N>& B){
    int i;
    int j;
    Matrix<N> result_a;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
        result_a.m_setter(i,j,A.m_getter(i,j)+B.m_getter(i,j));
        }
    }
    return result_a;
}

template <int N>
Matrix<N> m_subtraction(Matrix<N>& A, Matrix<N>& B){
    int i;
    int j;
    Matrix<N> result_b;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
        result_b.m_setter(i,j,A.m_getter(i,j)-B.m_getter(i,j));
        }
    }
    return result_b;
}
template <int N>
Matrix<N> m_multiplication(Matrix<N>& A, Matrix<N>& B){
    int i;
    int j;
    int k;
    int sum=0;
    Matrix<N> result_c;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
                for(k=0;k<N;k++){
         sum+=A.m_getter(i,k)*B.m_getter(k,j);
        }
        result_c.m_setter(i,j,sum);
        sum=0;
        }
    }
    return result_c;
}
//
double m_determinant(Matrix<1>& A){
    return A.m_getter(0,0);
}
double m_determinant(Matrix<2>& A){
    return A.m_getter(0,0)*A.m_getter(1,1)-A.m_getter(0,1)*A.m_getter(1,0);
}
template <int N>
double m_determinant(Matrix<N>& A){
   int c,m,n,i,j;
   double det=0;
   double s=1;
   Matrix<N-1> result_d; // Every time recurved the loop value decrease by one
        // filling submatrix created from original matrix
        for(c=0;c<N;c++){
            m=0;
            n=0;
            for(i=0;i<N;i++){
                for(j=0;j<N;j++){
                  result_d.m_setter(i,j,0);
                  if(i!=0 && j!=c){
                    result_d.m_setter(m,n,A.m_getter(i,j));
                    if(n<(N-2)){
                        n++;
                    }
                    else{
                        n=0;
                        m++;
                    }
                  }
                }
            }
            det=det+s*(A.m_getter(0,c)*m_determinant(result_d));
            s=-1*s; // sign of the cofactor value ak changes in every loop
        }
return (det);
}

int main()
{
    double h=99;//Initial h value to use it for getter function
    double d=0;
    // First Matrix decleration with 4x4 initialized
    //Matrix<4> first;
   // cout<<"Hello World This is First Matrix"<<endl;
   // first.display();
    Matrix<5> A;
    Matrix<5> B;
    Matrix<3> C;
    C.m_setter(0,1,3);
    C.m_setter(1,2,4);
    C.m_setter(2,1,5);
    A.m_setter(0,1,3);
    A.m_setter(1,2,4);
    A.m_setter(3,1,5);
    A.m_setter(2,4,4);
    A.m_setter(2,8,5); // There will be no change
    A.m_setter(3,3,5);
    A.m_setter(0,4,5);
    A.m_setter(3,0,5);
    A.m_setter(4,2,8);
    B.m_setter(2,1,5);
    B.m_setter(3,3,5);
    B.m_setter(0,4,5);
    B.m_setter(3,0,5);
    B.m_setter(4,2,8);
    cout<<endl<<"Matrix A"<<endl<<endl;
    A.display();
    cout<<endl<<"Matrix B"<<endl<<endl;
    B.display();
    cout<<endl<<"h is equal to:"<<h<<endl;    // Initial h value to use it for getter function
    h=A.m_getter(2,2);//h will take=1
    cout<<"h is equal to:"<<h<<endl;;
    h=A.m_getter(2,9);//h will take=0
    cout<<"h is equal to:"<<h<<endl;;
    h=A.m_getter(2,4);//h will take=4
    cout<<"h is equal to:"<<h<<endl;;
    Matrix<5> result_a=m_addition<5>(A,B); // addition function
    cout<<endl<<"Matrix Addition A+B "<<endl<<endl;
    result_a.display();
    Matrix<5> result_b=m_subtraction<5>(A,B); // subtraction function
    cout<<endl<<"Matrix Subtraction A-B"<<endl<<endl;
    result_b.display();
    Matrix<5> result_c=m_multiplication<5>(A,B); // multiplication function
    cout<<endl<<"Matrix Multiplication AxB"<<endl<<endl;
    result_c.display();
    cout<<endl<<"Matrix A"<<endl<<endl;
    A.display();
    d=m_determinant<5>(A);                      // determinant
    cout<<endl<<"Matrix Determinant det(A):"<<d<<endl<<endl;

    return 0;
}
