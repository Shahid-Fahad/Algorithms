#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll sb=0;
void printbinary(ll n)
{
    sb=0;
    ll f=0;
    ll dec=0;
    for(ll i=63; i>=0; i--)
    {
        ll x = (n>>i)&1;
        if(x)
        {
            dec += (1<<i);
            sb++;
        }
        if(sb>0)
            f++;
        if(f)
        cout << x;
    }
    cout << "\nDecimal " << dec << endl;
    if(f==0)
        cout << 0;
    cout << endl;
    cout << "Set Bits " << sb << endl;
}
ll chk(ll n,ll i)///Checks if ith bit is set or not
{
    ll x = n & (1<<i);
    if(x)
        cout << i << "th bit is set\n";
    else
        cout << i << "th bit is not set\n";
}
void makeset(ll &n,ll i)
{
    n = n|(1<<i); ///Makes ith Bit Set(1)
}
void makeunset(ll &n,ll i)///Makes ith Bit Unset(0)
{
    n = n&(~(1<<i));
}
void toggle(ll &n,ll i)///Makes 1 -> 0 and 0 -> 1
{
    n = n^(1<<i);
}
/// __builtin_popcountll(n)  counts set bit
int main()
{
    ll n,i;
    cin >> n >> i;
    printbinary(n);
    toggle(n,i);
    printbinary(n);
    cout<< __builtin_popcountll(n) << endl;
}
