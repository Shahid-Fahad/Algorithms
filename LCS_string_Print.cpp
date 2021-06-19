///ShzFahad
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
ll dp[1001][1001];
string LCS(string x,string y,ll n, ll m)
{
    string ans="";
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
           if(x[i-1]==y[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
            {
                dp[i][j]  = max(dp[i][j-1],dp[i-1][j]);
            }
        }

    }
    ll i=n,j=m;
    while(i>0&&j>0)
    {
        if(x[i-1]==y[j-1])
            {
                ans = ans+x[i-1];
                i--;
                j--;
            }
        else
        {
            if(dp[i][j-1]>dp[i-1][j])
            {
                j--;
            }
            else
                i--;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string x,y;
    cin >> x >> y;
    string ans = LCS(x,y,x.size(),y.size());
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
}

