///Bismillahir Rahmanir Rahim
//ShzFahad
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define pb push_back
#define ff first
#define ss second

template <typename T> using oset = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using omap = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct S{
    ll n,p,i;
};
bool operator>(S const&a,S const&b)
{
    if(a.n==b.n)
    {
        if(a.p==b.p)
        return a.i<b.i;
        else
        return a.p<b.p;
    }
    else
    return a.n>b.n;
}
ll arr[100005],arr2[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1,tc=0;
    //cin >> t;
    while(t--)
    {
        //tc++;case_(tc);
        ll n,m;
        cin>>n>>m;
        oset<S>os;
        while(m--)
        {
            ll tp,pn;
            cin>>tp>>pn;
            ll a = arr[tp],b=arr2[tp];
            if(arr[tp]>0)
            os.erase({a,b,tp});
            arr[tp]++,arr2[tp]+=pn;
            os.insert({a+1,b+pn,tp});
            cout<< os.order_of_key({arr[1],arr2[1],1})+1 <<endl;
        }
    } 
}
