///ShzFahad
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
void bignum_mul(string s1,string s2)
{
    ll i,j;
    ll i_n1=0;
     ll i_n2=0;
    vector<ll>res(s1.size()+s2.size(),0);
    for(i=s1.size()-1;i>=0;i--)
    {
        ll carry =0;
        ll n1 = s1[i]-48;
        i_n2=0;
        for(j=s2.size()-1;j>=0;j--)
        {
            ll n2 = s2[j]-48;

            ll sum = (n1*n2) + res[i_n1+i_n2] + carry;

            carry = sum/10;

            res[i_n1+i_n2] = sum%10;

            i_n2++;
        }
        if(carry>0)
        res[i_n1+i_n2]+=carry;

        i_n1++;
    }
    ll f=0;
    for(i=res.size()-1;i>=0;i--)
    {
        if(res[i]>0)
        f++;
        if(f>0)
        cout << res[i];
    }
    if(f==0)
    cout << 0 << endl;
    else
    {
        cout << endl;
    }
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string x,y;
    while(cin >> x >> y)
    {
         if((x[0]!='-'||y[0]!='-')&&(x[0]=='-'||y[0]=='-'))
        {
            cout << '-';
        }
        if(x[0]=='-'&&y[0]=='-')
        {
            x = x.substr(1);
            y = y.substr(1);
        }
        else if(x[0]=='-')
        {
            x = x.substr(1);
        }
        else if(y[0]=='-')
        {
            y = y.substr(1);
        }
        bignum_mul(x,y);
    
    }

}
