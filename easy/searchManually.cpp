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

bool searchManually(node *root, int val)
{
    if (root == NULL)
    {

        return false;
    }
    node *cur = root;
    while (cur != NULL)
    {
        if (cur->val > val)
        {
            cur = cur->left;
        }
        else if (cur->val < val)
        {
            cur = cur->right;
        }
        else
        {
            return true;
        }
    }
    return false;
}
int main()
{
    node *root = input_tree();

    int val;
    cin >> val;
    if (searchManually(root, val))
    {
        cout << "FOUND" << endl;
    }
    else
    {
        cout << "NOT found";
    }
}