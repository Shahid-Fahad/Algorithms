///ShzFahad
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
void Merge(ll l,ll m,ll r,ll arr[])
{
    ll n1 = m-l+1;
    ll n2 = r-m;
    ll L[n1],R[n2];
    for(ll i=0; i<n1; i++)
        L[i]=arr[l+i];
    for(ll j=0; j<n2; j++)
        R[j] = arr[m+1+j];
    ll i=0,j=0,k=l;
    while(i<n1&&j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k] = L[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }

}
void mergesort(ll arr[],ll l,ll r)
{
    if(l>=r)
        return;
    ll m = l+(r-l)/2;

    mergesort(arr,l,m);
    mergesort(arr,m+1,r);

    Merge(l,m,r,arr);

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll arr[n+5];
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    mergesort(arr,0,n-1);
    for(ll i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

}


