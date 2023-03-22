///Bismillahir Rahmanir Rahim
//ShzFahad
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define ff first
#define ss second
#define mem(a, b) memset(a, b, sizeof(a))
#define all(qz) qz.begin(), qz.end()
vector<ll> v[10005];
ll low[10005], tin[10005], vis[10005], timer = 1;
ll cp=0;
stack<ll> st;
ll com[10005];
void dfs(ll n,ll p)
{
    vis[n] = 1;
    tin[n] = low[n] = timer++;
    st.push(n);
    for (auto child : v[n])
    {
        if(child==p)continue;
        if (vis[child] == 1)
        {
            low[n] = min(low[n], tin[child]);
        }
        else
        {
            dfs(child,n);
            low[n] = min(low[n], low[child]);
        }
    }
    if (tin[n] == low[n])
    {
        cp++;
        while (st.size()>0)
        {
            ll k = st.top();
            com[k]=cp;
            st.pop();
            if (k == n)
            break;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1, tc = 0;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        mem(vis, 0),cp=0;
        for (ll i = 0; i < n; i++)
            v[i].clear();
        for (ll i = 0; i < m; i++)
        {
            ll x, y;
            cin >> x >> y;
            v[x].pb(y);
            v[y].pb(x);
        }
        dfs(0,-1);
        ll deg[10005]={0};
        for(ll i=0;i<n;i++)
        {
            ll x=i;
            for(auto y:v[i])
            {
                if(com[x]!=com[y])
                {
                    deg[com[x]]++;
                    deg[com[y]]++;
                }
            }
        }
        ll cnt=0;
        for(ll i=1;i<=cp;i++)
        if(deg[i]==2)
        cnt++;
        cout<< (cnt+1)/2 <<endl;
    }
}

