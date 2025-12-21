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

Node *buildBST(int a[], int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    Node *root = new Node(a[mid]);
    root->left = buildBST(a, start, mid - 1);
    root->right = buildBST(a, mid + 1, end);
    return root;
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void posorder(Node *root)
{
    if (root == NULL)
        return;
    posorder(root->left);
    posorder(root->right);
    cout << root->data << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        Node *root = buildBST(a, 0, n - 1);
        posorder(root);
        cout << endl;
    }
}
