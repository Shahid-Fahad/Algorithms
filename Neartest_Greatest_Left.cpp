///ShzFahad
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll arr[n], i;
    stack<ll> s;
    vector<ll> v;
    for (i = 0; i < n; i++)
        cin >> arr[i];
    for (i = 0; i <n; i++)
    {
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else if (s.size() > 0 && s.top() > arr[i])
        {
            v.push_back(s.top());
        }
        else if (s.size() > 0 && s.top() <= arr[i])
        {
            while (s.size() > 0 && s.top() <= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else if (s.size() > 0 && s.top() > arr[i])
            {
                v.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }

    for(i=0;i<n;i++)
    {
        cout << arr[i] << " " << v[i] << endl;
    }
}

