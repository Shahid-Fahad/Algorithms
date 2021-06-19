///ShzFahad
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
void insertion_sort(ll n,ll arr[])
{
    for(ll i=2;i<=n;i++)
    {
        ll key = arr[i];
        ll j=i-1;
        while(arr[j]>key&&j>=1)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll arr[n+5];
    for(ll i=1;i<=n;i++)
    {
        cin >> arr[i];
    }
    insertion_sort(n,arr);
    for(ll i=1;i<=n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

}

