#include<iostream>

using namespace std;

struct TreeNode{
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode(int d):data(d),leftChild(NULL),rightChild(NULL){}
};

TreeNode* Insert(TreeNode* root, int x, int father){
    // 注意下面一定都是同一组判断条件
    if(root == NULL){
        printf("%d\n",father);
        root = new TreeNode(x);
    }else if(x < root->data) {
        root->leftChild = Insert(root->leftChild,x,root->data);
    }
    else{
        root->rightChild = Insert(root->rightChild,x,root->data);
    }
    return root;
}

int main(){
    int n;
    while(cin>>n){
        TreeNode* root = NULL;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            root = Insert(root,temp,-1);
        }
    }
    return 0;
}