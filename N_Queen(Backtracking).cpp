#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;
ll board[10+5][10+5];
bool ispossible(ll r,ll c)
{
    for(ll i=r-1;i>=0;i--)
    {
        if(board[i][c]==1)
            return false;
    }
    for(ll i=r-1,j=c-1;i>=0&&j>=0;i--,j--)
    {
        if(board[i][j]==1)
            return false;
    }
    for(ll i=r-1,j=c+1;i>=0&&j<n;i--,j++)
    {
        if(board[i][j]==1)
            return false;
    }

    return true;

}
void Nqueen(ll r)
{
    if(r==n)
    {
        for(ll i=0;i<n;i++)
        {

            for(ll j=0;j<n;j++)
            {
                cout << board[i][j] <<  " ";
            }
            cout << endl;
        }
            cout << endl;
        return;
    }
    else
    {

            for(ll j=0;j<n;j++)
            {
                if(ispossible(r,j))
                {
                    board[r][j]=1;
                    Nqueen(r+1);
                    board[r][j]=0;
                }
            }

        return;
    }

}
int main()
{
    cin >> n;
    memset(board,0,sizeof(board));
    Nqueen(0);
}
