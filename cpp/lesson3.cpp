#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    int H, W;
    cin >> H >> W;
    int S[H + 1][W + 1];
    char s;
    for (int i = 1; i < H + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            cin >> s;
            if (s == '#')
            {
                S[i][j] = 0;
            }
            else
            {
                S[i][j] = 1;
            }
        }
    }
    int L[H + 2][W + 2], R[H + 2][W + 2];
    for (int i = 1; i < H + 1; i++)
    {
        L[i][0] = 0;
        R[i][W + 1] = 0;
        for (int j = 1; j < W + 1; j++)
        {

            L[i][j] = S[i][j];
            if (S[i][j] == 0)
            {
                L[i][j] = 0;
            }
            else
            {
                L[i][j] += L[i][j - 1];
            }
            R[i][W + 1 - j] = S[i][W + 1 - j];
            if (S[i][W + 1 - j] == 0)
            {
                R[i][W + 1 - j] = 0;
            }
            else
            {
                R[i][W + 1 - j] += R[i][W + 2 - j];
            }
        }
    }
    int U[H + 2][W + 2], D[H + 2][W + 2];
    for (int j = 1; j < W + 1; j++)
    {
        U[0][j] = 0;
        D[H + 1][j] = 0;
        for (int i = 1; i < H + 1; i++)
        {

            U[i][j] = S[i][j];
            if (S[i][j] == 0)
            {
                U[i][j] = 0;
            }
            else
            {
                U[i][j] += U[i - 1][j];
            }
            D[H + 1 - i][j] = S[H + 1 - i][j];
            if (S[H + 1 - i][j] == 0)
            {
                D[H + 1 - i][j] = 0;
            }
            else
            {
                D[H + 1 - i][j] += D[H + 2 - i][j];
            }
        }
    }
    int ans = 0;
    int val;
    for (int i = 1; i < H + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            val = R[i][j] + L[i][j] + U[i][j] + D[i][j] - 3;
            ans = max(ans, val);
        }
    }
    cout << ans << endl;
}

int main()
{
    Solve();
    return 0;
}