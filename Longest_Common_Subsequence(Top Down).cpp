///ShzFahad
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
ll dp[1001][1001];
ll LCS(string x,string y,ll n,ll m)
{
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            if(x[i-1]==y[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
              dp[i][j] = max((dp[i-1][j]),(dp[i][j-1]));
        }
    }
    return dp[n][m];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string x,y;
    cin >> x >> y;
    ll n = x.size();
    ll m = y.size();
    cout << LCS(x,y,n,m) << endl;

}

