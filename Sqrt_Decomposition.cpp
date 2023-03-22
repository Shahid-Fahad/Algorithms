///Bismillahir Rahmanir Rahim
//ShzFahad
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1, tc = 0;
    //cin >> t;
    while (t--)
    {
        //tc++;case_(tc);
        ll n, q;
        cin >> n >> q;
        ll arr[n + 5];
        ll lim = sqrt(n) + 1;
        ll b[lim + 5] = {0};
        for (ll i = 0; i < n; i++)
            cin >> arr[i];
        for (ll i = 0; i < n; i++)
        {
            b[i / lim] += arr[i];
        }
        while (q--)
        {
            ll l, r, sum = 0;
            cin >> l >> r;
            l--, r--;
            ll lb = (l / lim);
            ll rb = (r / lim);
            if (lb == rb)
            {
                for (ll i = l; i <= r; i++)
                    sum += arr[i];
            }
            else
            {
                for (ll i = l; i < ((lb + 1) * lim); i++)
                    sum += arr[i];
                for (ll i = lb + 1; i < rb; i++)
                    sum += b[i];
                for (ll i = ((rb - 1) * lim) + lim; i <= r; i++)
                    sum += arr[i];
            }
 
            cout << sum << endl;
        }
    }
}