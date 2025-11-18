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

void levelOrder(Node *root)
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
void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void posOrder(Node *root)
{
    if (root == NULL)
        return;
    posOrder(root->left);
    posOrder(root->right);
    cout << root->data << " ";
}
void spiralOrder(Node *root)
{
    if (!root)
        return;

    stack<Node *> s1;
    stack<Node *> s2;

    s1.push(root);

    vector<int> res;

    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            Node *node = s1.top();
            s1.pop();
            res.push_back(node->data);
            if (node->right)
                s2.push(node->right);
            if (node->left)
                s2.push(node->left);
        }
        while (!s2.empty())
        {
            Node *node = s2.top();
            s2.pop();
            res.push_back(node->data);
            if (node->left)
                s1.push(node->left);
            if (node->right)
                s1.push(node->right);
        }
    }

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    Node *root = NULL;
    while (n--)
    {
        int n1, n2;
        char c;
        cin >> n1 >> n2 >> c;
        if (root == NULL)
            root = new Node(n1);
        insert(root, n1, n2, c);
    }
    levelOrder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    posOrder(root);
    cout << endl;
    spiralOrder(root);
}