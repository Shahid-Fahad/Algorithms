
///ShzFahad
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
vector<ll>v[1000005];
ll vis[100005];
void dfs(ll n)
{
  vis[n]=1;
  for(ll i=0;i<v[n].size();i++)
  {
      ll child = v[n][i];
      cout << "Test " << child << " " << vis[child] << endl;
      if(vis[child]==0)
        dfs(child);
    else
        cout << "tobe " << child << endl;
  }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,e;
    cin >> n >> e;
    for(ll i=1;i<=e;i++)
    {
        ll x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    ll cng=0;
    for(ll i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
            cng++;
        }
    }
    cout << cng << endl;
}

