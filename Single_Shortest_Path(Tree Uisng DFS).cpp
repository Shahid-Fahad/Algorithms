///ShzFahad
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    while (cin >> n)
    {
        vector<ll> v;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            v.push_back(x);
        }
        ll sum = 0;
        for (ll i = 0; i < v.size(); i++)
        {
            ll ti, mx = 0;
            if (v.size() == 2)
            {
                cout << sum + max(v[0], v[1]) << endl;
                break;
            }
            for (ll j = 1; j < v.size() - 1; j++)
            {
                ll ans = v[j - 1] * v[j + 1];
                if (ans > mx)
                {
                    ti = j;
                    mx = ans;
                }
            }
            v.erase(v.begin() + ti, v.begin() + ti + 1);
            sum = sum + mx;
            i = -1;
        }
    }
}
