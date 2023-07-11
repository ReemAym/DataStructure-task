#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),right(right) {}
};
class Solution {
public:
    bool IsMirror(TreeNode *root1,TreeNode *root2)
    {
        if(root1==NULL && root2==NULL)
            return true;

        if(root1!=NULL && root2!=NULL && root1->val==root2->val)
        {
            return(IsMirror(root1->right,root2->left) && IsMirror(root1->left,root2->right));
        }

        return false;
    }

    bool IsSymmitric(TreeNode *root)
    {
        return IsMirror(root,root);
    }
};

void test1()
{
    TreeNode *Node=new TreeNode(1,new TreeNode(2),new TreeNode(3));
    Solution s;

    if(s.IsSymmitric(Node))
        cout<<"Tree is symmitric\n";
    else
        cout<<"Tree is not symmitric\n";
}

void test2()
{
    TreeNode *Node=new TreeNode(1,new TreeNode(2),new TreeNode(2));
    Solution s;

    if(s.IsSymmitric(Node))
        cout<<"Tree is symmitric\n";
    else
        cout<<"Tree is not symmitric\n";
}

void test3()
{
    Solution s;
    TreeNode* root =new TreeNode(1);
    root->left =new TreeNode(2);
    root->right =new TreeNode(2);
    root->left->left =new TreeNode(3);
    root->left->right =new TreeNode(4);
    root->right->left =new TreeNode(4);
    root->right->right =new TreeNode(3);

    if(s.IsSymmitric(root))
        cout<<"Tree is symmitric\n";
    else
        cout<<"Tree is not symmitric\n";
}

void test4()
{
    Solution s;
    TreeNode* root =new TreeNode(5);
    root->left =new TreeNode(2);
    root->right =new TreeNode(2);
    root->left->left =new TreeNode(3);
    root->left->right =new TreeNode(4);
    root->right->left =new TreeNode(4);
    root->right->right =new TreeNode(2);

    if(s.IsSymmitric(root))
        cout<<"Tree is symmitric\n";
    else
        cout<<"Tree is not symmitric\n";
}

void test5()
{
    TreeNode *Node=new TreeNode(5,new TreeNode(5),new TreeNode(5));
    Solution s;

    if(s.IsSymmitric(Node))
        cout<<"Tree is symmitric\n";
    else
        cout<<"Tree is not symmitric\n";
}

int main() {

    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}
