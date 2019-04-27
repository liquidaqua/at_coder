#include <iostream>
using namespace std;

int main()
{
    int n;
    std::string s;
    cin >> n >> s;
    int b_cnt = 0;
    int w_cnt = 0;
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '#' & flag == true)
        {
            flag = false;
            b_cnt = 0;
        }
        if (s[i] == '.')
        {
            b_cnt++;
        }
    }
    flag = true;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '.' & flag == true)
        {
            flag = false;
            w_cnt = 0;
        }
        if (s[i] == '#')
        {
            w_cnt++;
        }
    }
    std::cout << min(b_cnt, w_cnt);

    return 0;
}