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
		ll n,i,j;
		cin >> n >> i >> j;
		vector<ll>v,v1;
		ll s=0;
		for(ll k=0;k<n;k++)
		{
			ll x;
			cin >> x;
			v.push_back(x);
			s = s+x;
		}
		ll dif = j-i+1;
		ll nf = dif/n;
		ll ans = nf*s;
		ll k = dif-(n*nf);
		ll x = i%n;
		if(x==0)
		x=n-1;
		else
		x--;
		//cout << x << " X " << " " << k << " " << ans  << endl;
		ll s2=0;
		for(ll y=1;y<=k;y++,x++)
		{
			cout << v[x]  << " " << x <<  endl;
			s2 = s2 + v[x];
		}
		cout << ans+s2 << endl;

	}


}
