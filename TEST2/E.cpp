#include <iostream>
#include <cstdio>

using namespace std;

int apple(int M, int N)
{
    if (M < 0)
        return 0;
    if (M == 0 || N == 1)
        return 1;
    return apple(M - N, N) + apple(M, N - 1);
}

int main()
{
    int t;
    int M, N;
    cin >> t;
    while (t--)
    {
        cin >> M >> N;
        cout << apple(M, N) << endl;
    }
    return 0;
}