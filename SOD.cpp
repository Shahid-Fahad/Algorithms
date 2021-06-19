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
vector<long long int>prime;
bool mark[1000001];
void sieve(ll n)
{
    ll i,j;
    prime.clear();
    mark[0]=true;
    mark[1]=true;
    mark[2]=false;
    prime.push_back(2);
    for(i=4; i<=n; i+=2)
        mark[i]=true;
    ll sqrtn = sqrt(n);
    for(i=3; i<=sqrtn; i=i+2)
    {
        if(mark[i]==false)
        {
            for(j=i*i; j<=n; j+=2*i)
                mark[j]=true;
        }
    }
    for(ll i=3;i<=n;i=i+2)
        if(mark[i]==false)
        prime.push_back(i);

}
ll SOD(ll n)
{
    ll x = sqrt(n);
    ll sod=1;
    for(ll i=0;i<prime.size()&&prime[i]<=x;i++)
    {
        if(n%prime[i]==0)
        {
            ll tmp=1;
            ll pw=1;
            while(n%prime[i]==0)
            {
                n = n/prime[i];
                pw = pw*prime[i];
                tmp = tmp+pw;
            }
           sod = sod*tmp;
           x = sqrt(n);
        }
    }
    if(n>1)
    {
            sod = sod*(1+n);
    }
    return sod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve(1000005);
    ll n;
    cin >> n;
    cout << SOD(n) << endl;
}
