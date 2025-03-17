#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct N
{
    int l, r;
    int c;
    int m;
    int p;
    struct N *lf, *rg;
} N;

int g;

int calcC(int l, int r, int n)
{
    if (l == 0)
        return r - 1;
    else if (r == n + 1)
        return n - l;
    else
        return (r - l) / 2;
}

void upd(N *n)
{
    if (!n)
        return;
    n->m = n->c;
    if (n->lf && n->lf->m > n->m)
        n->m = n->lf->m;
    if (n->rg && n->rg->m > n->m)
        n->m = n->rg->m;
}

N *createN(int l, int r, int n)
{
    N *nNode = (N *)malloc(sizeof(N));
    nNode->l = l;
    nNode->r = r;
    nNode->c = calcC(l, r, n);
    nNode->m = nNode->c;
    nNode->p = rand();
    nNode->lf = nNode->rg = NULL;
    return nNode;
}

N *treapI(N *root, N *nNode)
{
    if (!root)
        return nNode;
    if (nNode->l < root->l)
    {
        root->lf = treapI(root->lf, nNode);
        if (root->lf->p > root->p)
        {
            N *lNode = root->lf;
            root->lf = lNode->rg;
            lNode->rg = root;
            upd(root);
            upd(lNode);
            return lNode;
        }
    }
    else
    {
        root->rg = treapI(root->rg, nNode);
        if (root->rg->p > root->p)
        {
            N *rNode = root->rg;
            root->rg = rNode->lf;
            rNode->lf = root;
            upd(root);
            upd(rNode);
            return rNode;
        }
    }
    upd(root);
    return root;
}

N *treapD(N *root, int l, int r)
{
    if (!root)
        return NULL;
    if (root->l == l && root->r == r)
    {
        if (!root->lf)
        {
            N *tmp = root->rg;
            free(root);
            return tmp;
        }
        else if (!root->rg)
        {
            N *tmp = root->lf;
            free(root);
            return tmp;
        }
        else
        {
            if (root->lf->p > root->rg->p)
            {
                N *lNode = root->lf;
                root->lf = lNode->rg;
                lNode->rg = root;
                upd(root);
                upd(lNode);
                lNode->rg = treapD(lNode->rg, l, r);
                upd(lNode);
                return lNode;
            }
            else
            {
                N *rNode = root->rg;
                root->rg = rNode->lf;
                rNode->lf = root;
                upd(root);
                upd(rNode);
                rNode->lf = treapD(rNode->lf, l, r);
                upd(rNode);
                return rNode;
            }
        }
    }
    else if (l < root->l)
    {
        root->lf = treapD(root->lf, l, r);
    }
    else
    {
        root->rg = treapD(root->rg, l, r);
    }
    upd(root);
    return root;
}

N *treapF(N *root, int x)
{
    if (!root)
        return NULL;
    if (root->l < x && x < root->r)
        return root;
    if (x <= root->l)
        return treapF(root->lf, x);
    else
        return treapF(root->rg, x);
}

void freeT(N *root)
{
    if (!root)
        return;
    freeT(root->lf);
    freeT(root->rg);
    free(root);
}

bool validC(N *nNode, int x, int n)
{
    int l = nNode->l, r = nNode->r;
    if (l == 0)
    {
        return (x == 1);
    }
    if (r == n + 1)
    {
        return (x == n);
    }
    int g = r - l;
    if (g % 2 == 0)
    {
        int c = (l + r) / 2;
        return (x == c);
    }
    else
    {
        int c = (l + r) / 2;
        return (x == c || x == c + 1);
    }
}

bool simulate(int n, int *p)
{
    g = n;
    if (n == 1)
    {
        return (p[1] == 1);
    }
    if (p[1] != 1 && p[1] != n)
        return false;

    N *root = NULL;
    N *init = createN(0, n + 1, n);
    root = treapI(root, init);

    if (p[1] == 1)
    {
        root = treapD(root, 0, n + 1);
        if ((n + 1) - 1 > 1)
        {
            N *newI = createN(1, n + 1, n);
            root = treapI(root, newI);
        }
    }
    else
    {
        root = treapD(root, 0, n + 1);
        if (n - 0 > 1)
        {
            N *newI = createN(0, n, n);
            root = treapI(root, newI);
        }
    }

    for (int k = 2; k <= n; k++)
    {
        int s = p[k];
        N *iNode = treapF(root, s);
        if (!iNode)
        {
            freeT(root);
            return false;
        }
        if (root->m != iNode->c)
        {
            freeT(root);
            return false;
        }
        if (!validC(iNode, s, n))
        {
            freeT(root);
            return false;
        }
        int l = iNode->l, r = iNode->r;
        root = treapD(root, l, r);
        if (s - l > 1)
        {
            N *lI = createN(l, s, n);
            root = treapI(root, lI);
        }
        if (r - s > 1)
        {
            N *rI = createN(s, r, n);
            root = treapI(root, rI);
        }
    }

    freeT(root);
    return true;
}

int main()
{
    int t;
    if (scanf("%d", &t) != 1)
        return 1;
    srand((unsigned)time(NULL));

    for (int tc = 0; tc < t; tc++)
    {
        int n;
        if (scanf("%d", &n) != 1)
            return 1;
        int pArr = (int)malloc((n + 1) * sizeof(int));
        int p = (int)malloc((n + 1) * sizeof(int));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &pArr[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            int person = pArr[i];
            p[person] = i;
        }
        bool possible = simulate(n, p);
        printf("%s\n", possible ? "YES" : "NO");
        free(pArr);
        free(p);
    }
    return 0;
}
