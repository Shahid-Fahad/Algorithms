#include<bits/stdc++.h>
using namespace std;

#define lim 10001
#define len 15000
int fibo[lim][len];
void fib()
{
    int i,j,k;
    fibo[0][0] = 0;
    fibo[1][0] = 1;
    fibo[2][0] = 1;

    for(i=3; i<lim; i++)
    {
        for(j=0; j<len; j++)
        {
            fibo[i][j] = fibo[i][j] + fibo[i-1][j] + fibo[i-2][j]; ///globaly all are 0

            if(fibo[i][j]>=10)
            {
                fibo[i][j+1] = fibo[i][j]/10;
                fibo[i][j] = fibo[i][j]%10;
            }
        }
    }

}
int main()
{
    fib();
    int n;
    while(cin >> n)
    {
        int i;
        for(i=len-1; i>0; i--)
        {
            if(fibo[n][i]!=0)
                break;
        }

        for(; i>=0; i--)
            cout << fibo[n][i];

        cout << endl;
    }
}
