#include <bits/stdc++.h>
using namespace std;

const int MODULO = 998244353;
const int MAXEXP = 400005;
long long powerArray[MAXEXP];

void computePowers()
{
    powerArray[0] = 1;
    for (int i = 1; i < MAXEXP; i++)
    {
        powerArray[i] = (powerArray[i - 1] * 2LL) % MODULO;
    }
}

struct Data
{
    int length;
    int sumX;
    int sumY;
    int calc1;
    int calc2;
    int start;
    int end;
};

Data createData(int val)
{
    Data d;
    d.length = 1;
    d.sumX = val % MODULO;
    d.sumY = val % MODULO;
    d.calc1 = 0;
    d.calc2 = 0;
    d.start = val;
    d.end = val;
    return d;
}

Data mergeData(const Data &A, const Data &B)
{
    Data res;
    res.length = A.length + B.length;
    res.start = A.start;
    res.end = B.end;
    res.sumX = ((long long)A.sumX * powerArray[B.length] + B.sumX) % MODULO;
    res.sumY = (A.sumY + (long long)B.sumY * powerArray[A.length]) % MODULO;
    res.calc1 = ((long long)A.calc1 + B.calc1 + (long long)A.sumX * B.sumY) % MODULO;
    res.calc2 = ((long long)A.calc2 + B.calc2 + (long long)A.end * B.start) % MODULO;
    return res;
}

struct TreeNode
{
    pair<int, int> identifier;
    int value;
    int priority;
    TreeNode *left, *right;
    Data aggregate;
    TreeNode(int v, int id) : value(v)
    {
        identifier = {v, id};
        priority = rand();
        left = right = nullptr;
        aggregate = createData(v);
    }
};

void updateNode(TreeNode *node)
{
    if (!node)
        return;
    Data current = createData(node->value);
    if (node->left)
    {
        current = mergeData(node->left->aggregate, current);
    }
    if (node->right)
    {
        current = mergeData(current, node->right->aggregate);
    }
    node->aggregate = current;
}

void split(TreeNode *root, pair<int, int> key, TreeNode *&left, TreeNode *&right)
{
    if (!root)
    {
        left = right = nullptr;
        return;
    }
    if (root->identifier < key)
    {
        split(root->right, key, root->right, right);
        left = root;
        updateNode(left);
    }
    else
    {
        split(root->left, key, left, root->left);
        right = root;
        updateNode(right);
    }
}

TreeNode *merge(TreeNode *A, TreeNode *B)
{
    if (!A || !B)
        return A ? A : B;
    if (A->priority > B->priority)
    {
        A->right = merge(A->right, B);
        updateNode(A);
        return A;
    }
    else
    {
        B->left = merge(A, B->left);
        updateNode(B);
        return B;
    }
}

void insert(TreeNode *&root, TreeNode *node)
{
    if (!root)
    {
        root = node;
        return;
    }
    if (node->priority > root->priority)
    {
        split(root, node->identifier, node->left, node->right);
        root = node;
        updateNode(root);
    }
    else
    {
        if (node->identifier < root->identifier)
            insert(root->left, node);
        else
            insert(root->right, node);
        updateNode(root);
    }
}

void erase(TreeNode *&root, pair<int, int> key)
{
    if (!root)
        return;
    if (root->identifier == key)
    {
        TreeNode *temp = merge(root->left, root->right);
        delete root;
        root = temp;
    }
    else if (key < root->identifier)
    {
        erase(root->left, key);
        updateNode(root);
    }
    else
    {
        erase(root->right, key);
        updateNode(root);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    computePowers();
    int testCases;
    cin >> testCases;
    srand((unsigned)time(0));
    while (testCases--)
    {
        int size, queries;
        cin >> size >> queries;
        vector<int> elements(size);
        TreeNode *root = nullptr;
        for (int i = 0; i < size; i++)
        {
            cin >> elements[i];
            TreeNode *newNode = new TreeNode(elements[i], i);
            insert(root, newNode);
        }
        int result = (root ? (root->aggregate.calc1 + root->aggregate.calc2) % MODULO : 0);
        cout << result << "\n";
        for (int i = 0; i < queries; i++)
        {
            int index, value;
            cin >> index >> value;
            index--;
            erase(root, {elements[index], index});
            elements[index] = value;
            TreeNode *newNode = new TreeNode(value, index);
            insert(root, newNode);
            result = (root->aggregate.calc1 + root->aggregate.calc2) % MODULO;
            cout << result << "\n";
        }
        function<void(TreeNode *)> cleanup = [&](TreeNode *node)
        {
            if (!node)
                return;
            cleanup(node->left);
            cleanup(node->right);
            delete node;
        };
        cleanup(root);
    }
    return 0;
}