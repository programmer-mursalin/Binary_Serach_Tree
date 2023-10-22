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
node *convertBst(int a[], int n, int l, int r)
{
    if (l > r)
    {
        return NULL;
    }
    int mid = (l + r) / 2;
    node *root = new node(a[mid]);
    node *leftRoot = convertBst(a, n, l, mid - 1);
    node *rightRoot = convertBst(a, n, mid + 1, r);
    root->left = leftRoot;
    root->right = rightRoot;
    return root;
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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    node *root = convertBst(a, n, 0, n - 1);
    levelorder(root);
}