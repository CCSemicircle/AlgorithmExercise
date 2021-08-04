// 核心代码模式

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型
     */
    int maxValue;
    
    int maxSubPathSum(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftSum = max(maxSubPathSum(root->left),0);
        int rightSum= max(maxSubPathSum(root->right),0);
        // 更新最大分支和，因为最大分支和不一定是根结点与其左右分支
        // 所以对于每一个根结点都要计算 左右子结点+根结点 是否大于当前最大值
        if(root->val + leftSum+rightSum > maxValue){
            maxValue = root->val + leftSum + rightSum;
        }
        // 肯定带上根结点的值，否则在左右子结点的递归中就已经替换了最大值
        return root->val +max(leftSum,rightSum);
    }
    
    int maxPathSum(TreeNode* root) {
        // write code here
        maxValue=INT_MIN;
        maxSubPathSum(root);
        return maxValue;
    }
};