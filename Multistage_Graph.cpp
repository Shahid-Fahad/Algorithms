///Bismillahir Rahmanir Rahim
//ShzFahad
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pll pair<ll,ll>
#define vp vector<pair<ll,ll>>
#define pb push_back
#define ff first
#define ss second
#define case(tc) cout << "Case " << tc << ": " << endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define all(qz) qz.begin(),qz.end()
#define rall(qz) qz.rbegin(),qz.rend()

#define pi acos(-1.0)
#define tani(a) atan(a)/(pi/180)
#define sini(a) asin(a)/(pi/180)
#define cosi(a) cos(a)/(pi/180)
#define cos(a)  cos(a*pi/180)
#define sin(a)  sin(a*pi/180)
#define tan(a)  tan(a*pi/180)
const ll mod=1e9+7;

#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define dbg cout << "EKHANE" << endl;

ll Pow(ll c,ll d){return d==0? 1:c*pow(c,d-1);}
ll gcd(ll a,ll b) {return b==0? a:gcd(b,a%b);}
ll lcm(ll a,ll b) {return ((a*b)/gcd(a,b));}

ll egcd(ll a,ll b,ll &x,ll &y){if(b==0){x=1;y=0;return a;}ll x1,y1;ll gcd=egcd(b,a%b,x1,y1);x=y1;y=x1-y1*(a/b);return gcd;}
ll bigMod(ll a,ll b){a%=mod;ll res=1;while(b>0){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}

inline ll MOD(ll a){ return (a%mod + mod) %mod ; }
inline ll modAdd(ll a,ll b){ return MOD( MOD(a) + MOD(b) ) ; }
inline ll modSub(ll a,ll b){ return MOD( MOD(a) - MOD(b) ) ; }
inline ll modMul(ll a,ll b){ return MOD( MOD(a) * MOD(b) ) ; }
inline ll modInv(ll a){ return bigMod(a,mod-2) ; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,e;
    cin >> n >> e;
    ll adj[n][n];
    ll cost[n+5],d[n+5],p[n+5];
    memset(adj,0,sizeof(adj));
    for(ll i=0;i<e;i++)
    {
        ll x,y,z;
        cin >> x >> y >> z;
        adj[x][y]=z;
    }
    cost[n-1]=0;
    d[n]=n;
    for(ll i=n-2;i>=0;i--)
    {
        ll mn=1e18;
        for(ll k=i+1;k<=n;k++)
        {
            if(adj[i][k]!=0&&adj[i][k]+cost[k]<mn)
            {

                mn = adj[i][k]+cost[k];
                d[i]=k;
            }

        }

        cost[i]=mn;

    }
    cout << cost[0] << endl;


}

