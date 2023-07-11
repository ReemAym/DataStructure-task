#include <iostream>
using namespace std;

template<class T>
class Node
{
public:
    T root;
    Node *left;
    Node *right;
    Node() : root(0), left(nullptr), right(nullptr) {}
    Node(int x) : root(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : root(x), left(left),right(right) {}
    void flip(Node<T>* node)
    {

        if(node== nullptr)
            return ;

        else
        {
            Node<T> *temp;

            flip(node->right);
            flip(node->left);

            temp= node->left;
            node->left=node->right;
            node->right=temp;
        }
    }

    void flip()
    {

            Node<T> *temp;

            flip(right);
            flip(left);

            temp= left;
            left=right;
            right=temp;

    }


    void preorder( Node<T> *node)
    {
        if(node== nullptr)
            return ;

        cout<<node->root<<" ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node<T> *node)
    {
        if(node== nullptr)
            return ;

        inorder(node->left);
        cout<<node->root<<" ";
        inorder(node->right);
    }

    void postorder(Node<T> *node)
    {
        if(node== nullptr)
            return ;

        postorder(node->left);
        postorder(node->right);
        cout<<node->root<<" ";
    }
};




void test1()
{

    Node<int> *root=new  Node<int>(1,new  Node<int>(2),new  Node<int>(3));
    root->flip(root);
    root->inorder(root);
}

void test2()
{

    Node<char> *root=new  Node<char>('a',new  Node<char>('b'),new  Node<char>('c'));
    root->flip();
    root->postorder(root);
}

void test3()
{

    Node<char> *root = new Node<char>('a');
    root->left = new Node<char>('b');
    root->right = new Node<char>('c');
    root->left->left = new Node<char>('d');
    root->left->right = new Node<char>('e');
    root->right->left = new Node<char>('f');
    root->right->right = new Node<char>('g');
    root->flip(root->left);
    root->postorder(root);
}

void test4()
{

    Node<int> *root = new Node<int>(1);
    root->left = new Node<int>(2);
    root->right = new Node<int>(3);
    root->left->left = new Node<int>(3);
    root->left->right = new Node<int>(4);
    root->right->left = new Node<int>(5);
    root->right->right = new Node<int>(2);

    root->flip(root->right);
    root->postorder(root);
}

void test5()
{

    Node<int> *root = new Node<int>(1);
    root->left = new Node<int>(2);
    root->right = new Node<int>(3);

    root->flip(root);
    root->preorder(root);
}

int main() {

    test1();
    cout<<endl;
    test2();
    cout<<endl;
    test3();
    cout<<endl;
    test4();
    cout<<endl;
    test5();
    return 0;
}
