
///ShzFahad
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
vector<ll> v[2005];
ll vis[2005];
ll col[2005];
bool bpt(ll n, ll c)
{
    vis[n] = 1;
    col[n] = c;

    for (ll i = 0; i < v[n].size(); i++)
    {
        ll child = v[n][i];

        if (vis[child] == 0)
        {
            if (c == 1)
            {
                if (bpt(child, 0) == false)
                    return false;
            }
            else
            {
                if (bpt(child, 1) == false)
                    return false;
            }
        }
        else
        {
            if (col[n] == col[child])
                return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    for (ll tc = 1; tc <= t; tc++)
    {

        for (ll i = 0; i < 2005; i++)
        {

            col[i] = 0;
            vis[i] = 0;
            v[i].clear();
        }
        ll n, e;
        cin >> n >> e;
        for (ll i = 1; i <= e; i++)
        {
            ll x, y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        cout << "Scenario #" << tc << ":" << endl;
        bool ans, f = false;
        for (ll i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                bool ans = bpt(i, 1);
                if (ans == 0)
                {
                    cout << "Not Biparted" << endl;
                    f = true;
                    break;
                }
            }
        }

        if (f == false)
            cout << "Biparted" << endl;
    }
}
