///Bismillahir Rahmanir Rahim
//ShzFahad
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define ff first
#define ss second
struct S
{
    int l, r, i;
};
ll lim = 320;
bool operator<(S const &a, S const &b)
{
    ll lb = a.l / lim, rb = b.l / lim;
    if (lb == rb)
    {
        if (lb % 2 == 1)
            return a.r > b.r;
        else
            return a.r < b.r;
    }
    else
        return lb < rb;
}
vector<S> v;
ll mxf = -1e18;
int arr[100005];
int freq[200005], freq2[200005];
void add(ll n)
{
    ll pf = freq[arr[n]];
    freq[arr[n]]++;
    ll cf = freq[arr[n]];
    freq2[pf]--;
    freq2[cf]++;
    mxf = max(mxf, cf);
}
void err(ll n)
{
    ll pf = freq[arr[n]];
    freq[arr[n]]--;
    ll cf = freq[arr[n]];
    freq2[pf]--;
    freq2[cf]++;
    if(cf<mxf)
    while(freq2[mxf]==0)
    {
        mxf--;
    }
}
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
        while (cin >> n)
        {
            mxf = -1e18;
            if (n == 0)
                break;
            cin >> q;
            v.clear();
            mem(freq,0),mem(freq2,0);
            ll pl=1e5;
            for (ll i = 0; i < n; i++)
            {
                cin >> arr[i];
                arr[i]+=pl;
            }
            for (int i = 0; i < q; i++)
            {
                int x, y;
                cin >> x >> y;
                v.pb({x-1, y-1, i});
            }
            sort(all(v));
            ll l = 0, r = -1;
            ll ans[q+5];
            for (ll i = 0; i < q; i++)
            {
                ll rl = v[i].l, rr = v[i].r;

                while (rl < l)
                    add(--l);
                while (r < rr)
                    add(++r);
                while (rl > l)
                    err(l++);
                while (rr < r)
                    err(r--);
                ans[v[i].i]=mxf;
            }
            for(ll i=0;i<q;i++)
            cout<< ans[i] << endl;

        }
    }
}
