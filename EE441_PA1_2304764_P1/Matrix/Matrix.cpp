template <int N>
Matrix<N>::Matrix(){
int i,j;

for(i=0;i<N;i++){
    for(j=0;j<N;j++){
        if(i==j){
            Matrix::data[i][j]=1;
        }
        else
           Matrix::data[i][j]=0;
    }
}

}

template <int N>
void Matrix<N>::display(){
int i,j;

for(i=0;i<N;i++){
    for(j=0;j<N;j++){
        cout<<Matrix::data[i][j]<<" ";
    }
    cout<<endl;
}

}
