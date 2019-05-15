
// https://atcoder.jp/contests/tenka1-2019-beginner/tasks/tenka1_2019_d
#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 998244353;
void add(int64_t &a, int64_t b)
{
    a = (a + b) % MOD;
}
void mul(int64_t &a, int64_t b)
{
    a = (a * b) % MOD;
}

int main()
{
    int N, A[300];
    cin >> N;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        sum += A[i];
    }
    const int MX = 300 * 300;
    static int64_t dp[301][MX + 301], sub[301][MX + 301];
    dp[0][0] = 1;
    sub[0][0] = 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= MX; j++)
        {
            add(dp[i + 1][j + A[i]], dp[i][j]);
            add(dp[i + 1][j], 2 * dp[i][j]);
            add(sub[i + 1][j + A[i]], sub[i][j]);
            add(sub[i + 1][j], sub[i][j]);
        }

    int64_t ng = 0;
    for (int j = (sum + 1) / 2; j <= MX; j++)
        add(ng, dp[N][j]);
    if (sum % 2 == 0)
        add(ng, MOD - sub[N][sum / 2]);
    mul(ng, 3);

    int64_t ans = 1;
    for (int i = 0; i < N; i++)
        mul(ans, 3);
    add(ans, MOD - ng);
    cout << ans << endl;
    return 0;
}

/*
// https://atcoder.jp/contests/diverta2019/tasks/diverta2019_e

#include <bits/stdc++.h>
const int INF = 1e9, MOD = 1e9 + 7;
const long long LINF = 1e18;
using namespace std;
#define int long long
//template
std::vector<int> dpa(1234567, 0), dpb(1234567, 1), memo(1234567, 0);
int pw(int n, int k)
{
    int res = 1;
    while (k)
    {
        if (k & 1)
            res *= n;
        res %= MOD;
        n *= n;
        n %= MOD;
        k >>= 1;
    }
    return res;
}
//main
signed main()
{
    int N;
    cin >> N;
    std::vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    int now = 0, zco = 0;
    for (int i = 0; i < N; i++)
    {
        now ^= v[i];
        if (now == 0)
            zco++;
        else
        {
            // dpbは、..0....now.....(0)の時のnowに至るまでの[0,now,0,now,,,]の通り数
            // dpaは、..0....now.....0..の時の後ろの0に至るまでの累積の[0,now,0,now,,]の通り数
            dpb[now] += dpa[now] * (zco - memo[now]);
            dpb[now] %= MOD;
            dpa[now] += dpb[now];
            dpa[now] %= MOD;
            memo[now] = zco;
        }
    }
    if (now)
        cout << dpb[now] << endl;
    else
    {
        int ans = 0;
        for (int i = 0; i < 1234567; i++)
            ans += dpa[i];
        cout << (ans + pw(2, zco - 1)) % MOD << endl;
    }
}

*/

/*

#include <iostream>

using namespace std;

int main()
{
    int c = 1;
    int *b = &c; //特に値が入っていなかったのでｃを
    int &a = c;
    //値の表示
    cout << c << endl;
    cout << *b << endl;
    cout << a << endl;
    //アドレス表示
    cout << &c << endl;
    cout << b << endl;
    cout << &a << endl;

    a = 34;
    cout << c << endl;
    cout << *b << endl;
    cout << a << endl;
}

*/