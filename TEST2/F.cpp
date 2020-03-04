#include <iostream>
#include <cstring>

using namespace std;

bool IsSwap(char *pszStr, int nBegin, int nEnd)
{
    for (int i = nBegin; i < nEnd; i++)
        if (pszStr[i] == pszStr[nEnd])
            return false;
    return true;
}

void perm(char A[], int start, int end) //A是要排列的数组，start、end表示对A[start]与A[end]之间的元素进行全排列
{
    if (start == end)
    {
        for (int i = 0; i <= end; i++)
            putchar(A[i]);
        putchar('\n');
    }
    else
    {

        for (int i = start; i <= end; i++)
        {
            if (IsSwap(A, start, i)) //添加的判断语句，判断是否相等
            {
                swap(A[i], A[start]);
                perm(A, start + 1, end);
                swap(A[i], A[start]);
            }
        }
    }
}
int main()
{
    char A[205];
    cin >> A;
    perm(A, 0, strlen(A) - 1);
    return 0;
}