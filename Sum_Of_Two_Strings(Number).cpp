#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define Yes cout<<"Yes"<<endl
#define yes cout<<"yes"<<endl
#define No cout<<"No"<<endl
#define NO cout<<"NO"<<endl
#define no cout<<"no"<<endl
#define YES cout<<"YES"<<endl
#define asort(x) sort((x).begin(),(x).end())
#define rsort(x) reverse(x.begin(),x.end())
#define ll long long
#define deciset(x) cout <<setprecision(x) <<fixed;
#define endl "\n"
#define pb emplace_back
#define mp make_pair
#define PI 2*acos(0.0)
#define boost ios::sync_with_stdio(false);cin.tie(0)
ll a,b,c;
bool ok(ll x)
{
     ll lagbe=(x / a);
     ll arolagbe = (x / b);
     if(arolagbe == 0) return false;
     else
    return lagbe*arolagbe >=c ;
}
ull bs()
{
    ll low=-1,high=1;
    while( !ok(high) ) high*=2;
    //cout<<high<<endl;
    while(low < high - 1)
    {
       ll mid=(low+high) / 2;
       //cout<<low<<" "<<high<<endl;
        ll lagbe=(mid / a);
        ll arolagbe = (mid / b);
        if(lagbe*arolagbe >= c ) high=mid;
        else low=mid;
    }
    return high;
}

void solve()
{
    cin>>a>>b>>c;
    cout<<bs()<<endl;




}
int main()
{

    boost;
    ll t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
}
