#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int val;
    node *left;
    node *right;
    node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
node *input_tree()
{
    int rootValue;
    cin >> rootValue;
    if (rootValue == -1)
    {
        return NULL;
    }
    node *root = new node(rootValue);
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *p = q.front();
        q.pop();
        int left, right;
        cin >> left;
        if (left == -1)
        {
            p->left = NULL;
        }
        else
        {
            p->left = new node(left);
            q.push(p->left);
        }
        cin >> right;
        if (right == -1)
        {
            p->right = NULL;
        }
        else
        {
            p->right = new node(right);
            q.push(p->right);
        }
    }
    return root;
}
void insert(node *&root, int x)
{
    if (root == NULL)
    {
        root = new node(x);
    }
    if (x < root->val)
    {
        if (root->left == NULL)
        {
            root->left = new node(x);
        }
        else
        {
            insert(root->left, x);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = new node(x);
        }
        else
        {
            insert(root->right, x);
        }
    }
}
void levelorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *p = q.front();
        q.pop();
        cout << p->val << endl;
        if (p->left != NULL)
        {
            q.push(p->left);
        }
        if (p->right != NULL)
        {
            q.push(p->right);
        }
    }
}

int main()
{
    node *root = input_tree();
    int x;
    cin >> x;
    insert(root, x);
    levelorder(root);
}