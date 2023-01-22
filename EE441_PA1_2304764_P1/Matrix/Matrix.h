#include <iostream>
#include "math.h"

using namespace std;

template <int N>
class Matrix
{
private:
    double data[N][N];
public:
    int const SIZE = N;
    //a constructor for identity matrix creation
    Matrix();
    //a setter matrix to get rows and columns
    void m_setter(int r, int c,double newset_value);
    //a getter matrix to get rows and columns
    double m_getter(int r, int c) const;
    //Addition matrix to add different two matrixes
    void display();
    };

// Constructor matrix initialize matrix as an identity matrix
template <int N>
Matrix<N>::Matrix(){
int i,j;
// this loops fill 1 only whenever i=J
for(i=0;i<N;i++){
    for(j=0;j<N;j++){
        if(i==j){
            data[i][j]=1;
        }
        else
           data[i][j]=0;
    }
}
}
//Setter Matrix to set an element of matrix
template <int N>
void Matrix<N>::m_setter(int r,int c,double newset_value){
    // Checker whether given indices are correct or not
    if((r<N)&(r>=0)&(c>=0)&(c<N)){
       data[r][c]=newset_value;
    }

}
//getter Matrix to get an element from matrix
template <int N>
double Matrix<N>::m_getter(int r,int c) const{
    double g;
    // Checker whether given indices are correct or not
    if((r<N)&(r>=0)&(c>=0)&(c<N)){
           g=data[r][c];
           return g;
    }
    else {
        cout<<endl<<"Wrong Usage of Indices"<<endl;
    }
}

// Display Matrix
template <int N>
void Matrix<N>::display(){
int i,j;

for(i=0;i<N;i++){
    for(j=0;j<N;j++){
        cout<<data[i][j]<<" ";
    }
    cout<<endl;
}
}



