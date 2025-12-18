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

ll Cnt = 0;
void number_of_node(Node *root)
{
    if (root == nullptr)
        return;
    // if (root->left != nullptr)
    number_of_node(root->left);
    number_of_node(root->right);
    ++Cnt;
}
// cout << Cnt << endl;

int altCount(Node *root)
{
    if (root == nullptr)
        return 0;
    // return 1 + altCount(root->left) + altCount(root->right);
    int l = altCount(root->left);
    int r = altCount(root->right);
    return 1 + l + r;
}

int main()
{
    Node *root = take_input();
    // level_order(root);
    number_of_node(root);
    cout << Cnt << endl;
    Cnt = 0;
    cout << altCount(root);

    return 0;
}
// Alhamdulillah