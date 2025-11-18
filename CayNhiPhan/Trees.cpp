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

bool PerfectTree(Node *root)
{
    queue<pair<Node *, int>> q;
    q.push({root, 1});
    int leafLV = -1;

    while (!q.empty())
    {
        auto [p, lv] = q.front();
        q.pop();

        bool hasLeft = (p->left != NULL);
        bool hasRight = (p->right != NULL);

        if (hasLeft != hasRight)
            return false;

        if (!hasLeft && !hasRight)
        {
            if (leafLV == -1)
                leafLV = lv;
            else if (leafLV != lv)
                return false;
        }

        if (p->left != NULL)
            q.push({p->left, lv + 1});
        if (p->right)
            q.push({p->right, lv + 1});
    }
    return true;
}
bool FullTree(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();

        bool hasleft = (p->left != NULL);
        bool hasright = (p->right != NULL);

        if (hasleft != hasright)
            return false;

        if (hasleft)
            q.push(p->left);
        if (hasright)
            q.push(p->right);
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--)
    {
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
        cout << FullTree(root) << endl;
    }
}