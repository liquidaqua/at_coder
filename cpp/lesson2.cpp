#include <bits/stdc++.h>
using namespace std;

// https://atcoder.jp/contests/abc125/tasks/abc125_c
void Solve01()
{
    int n;
    cin >> n;
    vector<int> gcd_left(n + 1), gcd_right(n + 1);
    vector<int> v(n + 1);

    for (int i = 1; i < n + 1; i++)
    {
        cin >> v[i];
    }
    gcd_left[1] = v[1];
    gcd_right[n] = v[n];
    for (int i = 2; i < n + 1; i++)
    {
        gcd_left[i] = __gcd(gcd_left[i - 1], v[i]);
    }
    for (int i = n - 1; i >= 1; i--)
    {
        gcd_right[i] = __gcd(gcd_right[i + 1], v[i]);
    }
    int m = max(gcd_left[n - 1], gcd_right[2]);
    for (int i = 2; i < n; i++)
    {
        m = max(m, __gcd(gcd_left[i - 1], gcd_right[i + 1]));
    }

    cout << m << endl;
}

// https://atcoder.jp/contests/abc125/tasks/abc125_d
void Solve02()
{
    int n;
    cin >> n;
    long long a[n + 1], dp[n + 1][2];
    dp[0][0] = 0, dp[0][1] = -1e10;
    for (int i = 1; i < n + 1; i++)
        cin >> a[i];
    for (int i = 1; i < n + 1; i++)
    {
        dp[i][0] = max((dp[i - 1][0] + a[i]), (dp[i - 1][1] - a[i]));
        dp[i][1] = max((dp[i - 1][0] - a[i]), (dp[i - 1][1] + a[i]));
        // cout << dp[i][0] << " " << dp[i][1] << endl;
    }
    cout << dp[n][0];
}

// https://atcoder.jp/contests/diverta2019/tasks/diverta2019_e
void Solve03()
{
    int n;
    cin >> n;
    vector<int> s(n + 1), cnt_zero(n + 1);
    s[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> s[i];
        s[i] ^= s[i - 1];
        if (s[i] == 0)
            cnt_zero[i]++;
    }
    long long dp[n + 1][2];
    if (s[n] != 0)
    {
        dp[0][0] = 1, dp[0][1] = 0;
        for (int i = 1; i < n + 1; i++)
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
            if (s[i] == 0)
            {
                dp[i][0] += dp[i - 1][1];
            }
            else if (s[i] == s[n])
            {
                dp[i][1] += dp[i - 1][0];
            }
            cout << dp[i][0] << " " << dp[i][1] << endl;
        }
    }
    cout << dp[n][1] << endl;
}

int main()
{
    Solve03();
}