#include<iostream>
#include<string>

using namespace std;

struct TreeNode{
    char data;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode(char ch):data(ch),leftChild(NULL),rightChild(NULL){}
};

// 输入为先序遍历字符串，考虑用先序遍历建树
TreeNode* Build(int& position, string str){
    char ch = str[position++];
    if(ch == '#'){
        return NULL;
    }
    TreeNode* root = new TreeNode(ch);
    root->leftChild = Build(position, str);
    root->rightChild = Build(position,str);
    return root;
}

// 中序遍历
void InOrder(TreeNode* root){
    if(root == NULL){
        return;
    }
    InOrder(root->leftChild);
    printf("%c ",root->data);
    InOrder(root->rightChild);
}


int main(){
    string str;
    while(getline(cin,str)){
        int position=0;
        // 注意引用参数需要提前定义变量
        TreeNode* root = Build(position, str);
        InOrder(root);
        printf("\n");
    }
    return 0;
}