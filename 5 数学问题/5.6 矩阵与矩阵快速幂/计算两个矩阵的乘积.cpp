#include<iostream>

using namespace std;

const int MAXN=3;

struct Matrix{
    int row, col;
    int matrix[MAXN][MAXN];
    Matrix(int r,int c):row(r),col(c){}
};

void Print(Matrix m){
    for(int i=0;i<m.row;i++){
        for(int j=0;j<m.col;j++){
            cout<<m.matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

Matrix Multiple(Matrix a, Matrix b){
    Matrix ans(a.row, b.col);
    for(int i=0;i<a.row;i++){
        for(int j=0;j<b.col;j++){
            ans.matrix[i][j] = 0;
            for(int k=0;k<a.col;k++){
                ans.matrix[i][j]  += a.matrix[i][k]*b.matrix[k][j];
            }
        }
    }
    return ans;
}

int main(){
    Matrix a(2,3),b(3,2);
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            cin>>a.matrix[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            cin>>b.matrix[i][j];
        }
    }
    Matrix ans = Multiple(a, b);
    Print(ans);
    return 0;
}