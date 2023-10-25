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
void insert(node *&root, int val)
{
    node *newNode = new node(val);
    if (root == NULL)
    {
        root = newNode;
        return;
    }
    node *curr = root;
    node *pare = NULL;
    while (curr != NULL)
    {
        if (newNode->val < curr->val)
        {
            pare = curr;
            curr = curr->left;
        }
        else
        {

            pare = curr;
            curr = curr->right;
        }
    }
    if (newNode->val < pare->val)
    {
        pare->left = newNode;
    }
    else
    {
        pare->right = newNode;
    }
}
void print(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *p = q.front();
        q.pop();
        cout << p->val << " ";
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
        cout << endl;
    }
}
int main()
{
    node *root = NULL;
    insert(root, 7);
    insert(root, 4);
    insert(root, 6);
    insert(root, 2);
    insert(root, 5);
    print(root);
}