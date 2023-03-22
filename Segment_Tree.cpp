///Bismillahir Rahmanir Rahim
//ShzFahad
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define ff first
#define ss second
ll Tree[300005];
ll arr[100005];
void init(ll node,ll b,ll e)
{
    if(b==e)
    {
        Tree[node]=arr[b];
        return;
    }
    ll l = 2*node;
    ll r = 2*node+1;
    ll m = (b+e)/2;
    init(l,b,m);
    init(r,m+1,e);
    Tree[node]=Tree[l]+Tree[r];
}
ll query(ll node,ll b,ll e,ll i,ll j)
{
    if(b>j||e<i)
    return 0;
    if(i<=b&&e<=j)
    return Tree[node];
    ll l = 2*node;
    ll r = 2*node+1;
    ll m = (b+e)/2;
    ll p1 = query(l,b,m,i,j);
    ll p2 = query(r,m+1,e,i,j);
    return p1+p2;
}
void update(ll node,ll b,ll e,ll i,ll val)
{
    if(b>i||e<i)
    return;
    if(b==e)
    {
        Tree[node]=val;
        return;
    }
    ll l=2*node;
    ll r=2*node+1;
    ll m = (b+e)/2;
    update(l,b,m,i,val);
    update(r,m+1,e,i,val);
    Tree[node]=Tree[l]+Tree[r];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1,tc=0;
    cin >> t;
    while(t--)
    {
        cout << endl;
        mem(Tree,0);
        ll n,q;
        cin >> n >> q;
        for(ll i=1;i<=n;i++)
        {
            cin >> arr[i];
            update(1,1,n,i,arr[i]);
        }
        //init(1,1,n);
        while(q--)
        {
            ll tp;
            cin >> tp;
            if(tp==1)
            {
                ll i;
                cin >> i;
                i++;
                cout << arr[i] << endl;
                update(1,1,n,i,0);
                arr[i]=0;
            }
            else if(tp==2)
            {
                ll i,v;
                cin >> i >> v;
                i++;
                ll val = arr[i]+v;
                update(1,1,n,i,val);
                arr[i]=val;
            }
            else
            {
                ll l,r;
                cin >> l >> r;
                l++,r++;
                cout << query(1,1,n,l,r) << endl;
            }

        }

    } 
}
