#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef struct BiNode
{
    char data;
    struct BiNode *lchild = NULL, *rchild = NULL;
} * BiTree;
const int maxn = 30;
char p[maxn], m[maxn];

BiTree Create(int i, int j, int k)
{
    BiTree root = new BiNode;
    root->data = p[k];
    if (i == j)
        return root;
    int t = i;
    while (m[t] != p[k])
        t++;
    if (t - 1 >= i)
        root->lchild = Create(i, t - 1, k + 1);
    if (t + 1 <= j)
        root->rchild = Create(t + 1, j, k + t - i + 1);
    return root;
}

void PostOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    putchar(T->data);
}

int main()
{
    while (scanf("%s %s", p, m) == 2)
    {
        int len = strlen(p);
        BiTree T = new BiNode;
        T = Create(0, len - 1, 0);
        PostOrderTraverse(T);
        putchar('\n');
    }
    return 0;
}