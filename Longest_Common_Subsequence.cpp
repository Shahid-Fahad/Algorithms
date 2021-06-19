///ShzFahad
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
ll dp[1001][1001];

ll LCS(string x, string y, ll n, ll m)
{
    if (n == 0 || m == 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[m][n];
    if (x[n - 1] == y[m - 1])
        return dp[m][n] = 1 + LCS(x, y, n - 1, m - 1);
    else
    {
        return dp[m][n] = max((LCS(x, y, n, m - 1)), (LCS(x, y, n - 1, m)));
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    string x, y;
    while (n--)
    {
        char k;
        cin >> k;
        x.push_back(k);
    }
    while (m--)
    {
        char k;
        cin >> k;
        y.push_back(k);
    }
    memset(dp, -1, sizeof(dp));
    cout << LCS(x, y, x.size(), y.size()) << endl;
}
