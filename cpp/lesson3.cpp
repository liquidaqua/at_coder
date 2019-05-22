#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    int s;
    cin >> s;
    int s01, s23;
    s01 = s / 100;
    s23 = s % 100;
    if ((1 <= s01 <= 12) && (1 <= s23 <= 12))
    {
        cout << "hello";
    }
}

int main()
{
    Solve();
    return 0;
}