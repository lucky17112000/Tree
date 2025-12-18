// Bismillah
//* binery_tree_implement.cpp   16-12-2025  20:17:20
//* Artist: Asaduzzaman Alamin
#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *take_input()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = nullptr;
    else
        root = new Node(val);
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();
        int l, r;
        cin >> l >> r;
        Node *left;
        Node *right;
        if (l == -1)
            left = nullptr;
        else
            left = new Node(l);
        if (r == -1)
            right = nullptr;
        else
            right = new Node(r);
        f->left = left;
        f->right = right;

        if (f->left != nullptr)
            q.push(f->left);
        if (f->right != nullptr)
            q.push(f->right);
    }
    return root;
}

void level_order(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        cout << f->val << " ";

        if (f->left != nullptr)
            q.push(f->left);
        if (f->right != nullptr)
            q.push(f->right);
    }
}

int main()
{
    Node *root = take_input();
    level_order(root);

    return 0;
}
// Alhamdulillah