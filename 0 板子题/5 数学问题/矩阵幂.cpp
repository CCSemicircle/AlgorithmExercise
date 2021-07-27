#include<iostream>

using namespace std;

const int MAXN=11;

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

Matrix FastExp(Matrix a,int n, int k){
    Matrix ans(n,n); // row和col相等
    // 初始化为单位矩阵
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j){
                ans.matrix[i][j] = 1;
            }else{
                ans.matrix[i][j] = 0;
            }
        }
    }
    while(k){
        if(k % 2 == 1){
            ans = Multiple(ans, a);
        }
        a = Multiple(a, a);
        k /= 2;
    }
    return ans;
}

int main(){
    int n,k;
    while(cin>>n>>k){
        Matrix p(n,n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>p.matrix[i][j];
            }
        }
        Matrix ans = FastExp(p, n, k);
        Print(ans);
    }
    return 0;
}