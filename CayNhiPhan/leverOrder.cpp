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

void makeNode(Node *root, int n1, int n2, char c)
{
    if (c == 'L')
        root->left = new Node(n2);
    else if (c == 'R')
        root->right = new Node(n2);
}
void insert(Node *root, int n1, int n2, char c)
{
    if (root == NULL)
        return;
    if (root->data == n1)
        makeNode(root, n1, n2, c);
    else
    {
        insert(root->left, n1, n2, c);
        insert(root->right, n1, n2, c);
    }
}
void leverOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        cout << p->data << " ";
        if (p->left != NULL)
            q.push(p->left);
        if (p->right != NULL)
            q.push(p->right);
    }
}

void solve()
{
    int n;
    cin >> n;
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int n1, n2;
        char c;
        cin >> n1 >> n2 >> c;
        if (root == NULL)
            root = new Node(n1);
        insert(root, n1, n2, c);
    }
    leverOrder(root);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--)
    {
        solve();
        cout << endl;
    }
}