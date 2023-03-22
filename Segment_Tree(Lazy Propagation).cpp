///Bismillahir Rahmanir Rahim
//ShzFahad
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define ff first
#define ss second
ll arr[200005], st[1000005], lazy[1000005];
void build(ll si, ll ss, ll se)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return;
    }
    ll mid = (ss + se) / 2;
    build(2 * si, ss, mid);
    build(2 * si + 1, mid + 1, se);
    st[si] = st[2 * si] + st[2 * si + 1];
}
void update(ll si, ll ss, ll se, ll qs, ll qe, ll val)
{
    if (lazy[si] != 0)
    {
        ll dx = lazy[si];
        lazy[si] = 0;
        st[si] += (dx * (se - ss + 1));
        if (ss != se)
        {
            lazy[2 * si] += dx;
            lazy[2 * si + 1] += dx;
        }
    }
    if (se < qs || qe < ss)
        return;
    else if (qs <= ss && qe >= se)
    {
        ll dx = val;
        st[si] += (dx * (se - ss + 1));
        if (ss != se)
        {
            lazy[2 * si] += dx;
            lazy[2 * si + 1] += dx;
        }
        return;
    }
    ll mid = (ss + se) / 2;
    update(2 * si, ss, mid, qs, qe, val);
    update(2 * si+1, mid+1, se, qs, qe, val);
 
    st[si]=st[2*si]+st[2*si+1];
}
ll query(ll si,ll ss,ll se,ll qs,ll qe)
{
    if (lazy[si] != 0)
    {
        ll dx = lazy[si];
        lazy[si] = 0;
        st[si] += (dx * (se - ss + 1));
        if (ss != se)
        {
            lazy[2 * si] += dx;
            lazy[2 * si + 1] += dx;
        }
    }
    if (se < qs || qe < ss)
        return 0;
    else if (qs <= ss && qe >= se)
    {
        return st[si];
    }
    ll mid = (ss + se) / 2;
    return query(2 * si, ss, mid, qs, qe)+query(2 * si+1, mid+1, se, qs, qe);
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
        int n, q;
        cin >> n >> q;
        for (ll i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        build(1,1,n);
        while(q--)
        {
            int tp;
            cin>>tp;
            if(tp==1)
            {
                ll l,r,val;
                cin>>l>>r>>val;
                update(1,1,n,l,r,val);
            }
            else
            {
                ll k;
                cin>>k;
                cout << query(1,1,n,k,k) << endl;
            }
        }
    }
}
