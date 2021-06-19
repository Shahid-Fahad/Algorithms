///ShzFahad
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
vector<ll> d2;
vector<ll> d;
ll c = 0;
void div1(ll n)
{
    ll i, x = sqrt(n);
    for (i = 1; i <= x; i++)
    {
        if ((n % i) == 0)
        {
            if (n / i == i)
                d.push_back(i);
            else
            {
                d.push_back(i);
                d.push_back(n / i);
            }
        }
    }
}
void div2(ll n)
{
    ll i, x = sqrt(n);
    for (i = 1; i <= x; i++)
    {
        if ((n % i) == 0)
        {
            if (n / i == i)
                d2.push_back(i);
            else
            {
                d2.push_back(i);
                d2.push_back(n / i);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll x, y, k;
        cin >> x >> y >> k;
        ll a = x-k;
        ll b  = y-k;
        div1(a);
        div2(b);


        map<ll, ll> mp;
        for (ll i = 0; i<d.size(); i++)
        {

            mp[d[i]]++;
        }
        //cout << "HELLO" << endl;
        for (ll i = 0; i<d2.size(); i++)
        {
            mp[d2[i]]++;
        }
        vector<ll> v;

        for (auto it : mp)
        {
            if (it.second == 2&& x%it.first==k&&y%it.first==k)
                v.push_back(it.first);
        }
        if (v.size() == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << v.size();
            for (ll i = 0; i < v.size(); i++)
            {
                cout << v[i] << " ";
            }
            cout << endl;
        }
        d.clear();
        d2.clear();
    }
}
