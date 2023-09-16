#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int height(TreeNode *root){
        if(root == NULL) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    bool isBalanced(TreeNode *root) {
        if(root == NULL) return true;
        if(abs(height(root->left) - height(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);
    root->right->right->right = new TreeNode(7);
    cout<<s.isBalanced(root)<<endl;
    return 0;
}

/*---------------------------------------------------------------------------------------------------------------------------
TC: O(n) [n - no. of nodes] SC: O(h) [h - height of tree]

Intuition:
1. Simply traverse to find the depth of the tree and then go bottom up approach to find difference between the height of the 
left and right nodes of a root.
2. If there exist a root, and if there exist a child node return 1 or the summed-up value (if child's node also had child) 
from that side of the root and if no child node then return 0 from that side of the root.
3. Now calculate the height of the tree uptill that root node by taking the maximum of the value of left and right side of 
the tree and pass it to the upper root node (a root node has its own value 1).
[-So if there exist a child node on both side of that root node both child node will pass 1 and max of both will be 1, which 
will eventually be added to root node resulting height of tree upto that particular root will be 1 + 1(root's own value) = 2.
- So the value of that particular root node will becomes 2.
- And if this root is child to some other root node then the value 2 will be compared with the passed value of other root's 
other child and again maximum of both will be passed to the other root.]
4. At every root node, left side's height of the node will be compared with right side's height of the node and if the height
is greater than 1 means it is not a height-balanced tree.
5. In the end, we check whether both the sides left and right of the top most root is satisfing the condition of being 
balanced or not.
---------------------------------------------------------------------------------------------------------------------------*/
