///ShzFahad
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--)
    {

        ll n,k;
        cin >> n >> k;
        vector<ll>v;
        for(ll i=0;i<n;i++)
        {
            ll x;
            cin >> x;
            v.push_back(x);
        }
        ll mx = INT_MIN;
        ll i=0,j=0,sum=0;
        while(j<v.size())
        {
            if(j-i+1<k)
            {
                sum = sum+v[j];
                j++;
            }n
            else if(j-i+1==k)
            {
                sum = sum + v[j];
                mx = max(sum,mx);
                sum = sum - v[i];
                i++;
                j++;
            }
        }
        cout << mx << endl;
    }

}

