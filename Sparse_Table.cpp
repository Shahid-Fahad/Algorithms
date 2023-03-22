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
        ll table[24][n + 5];
        ll arr[n + 5];
        for (ll i = 0; i < n; i++)
        {
            cin >> table[0][i];
            arr[i] = table[0][i];
        }
        for (ll k = 1; (1 << k) <= n; k++)
        {
            ll len = 1 << (k - 1);
            for (ll i = 0; i + (1 << k) <= n; i++)
            {
                table[k][i] = min(table[k - 1][i], table[k - 1][i + len]);
            }
        }
        while (q--)
        {
            ll l, r;
            cin >> l >> r;
            l--,r--;
            ll len = r - l + 1;
            ll k = log2(len);
            cout << min(table[k][l], table[k][r - (1 << k) + 1]) << endl;
        }
    }
}