#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *Insert(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);
    if (val < root->data)
        root->left = Insert(root->left, val);
    else
        root->right = Insert(root->right, val);
    return root;
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int n, x;
        Node *root = NULL;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            root = Insert(root, x);
        }
        cout << "Test #" << i << ": ";
        postOrder(root);
        cout << endl;
    }
}
