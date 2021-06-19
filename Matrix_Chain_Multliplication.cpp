///ShzFahad
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
/// [a*b] x [b*c] -> cost = c and Dimention [a*c]
ll dp[1001][1001];
ll MCM(ll arr[],ll i, ll j)
{
    if(i>=j)
        return 0;
    if(dp[i][j]!=1)
        return dp[i][j];
    dp[i][j]=INT_MAX;
    ll tempans;
    for(ll k=i;k<j;k++)
    {
        tempans = MCM(arr,i,k) + MCM(arr,k+1,j) + ((arr[i-1]*arr[k]*arr[j]));
            dp[i][j] = min(dp[i][j],tempans);
    }
    return dp[i][j];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll arr[n+5];
    memset(dp,-1,sizeof(dp));
    for(ll i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    ll cost = MCM(arr,1,n-1);
    cout << cost << endl;

}

