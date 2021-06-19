///Works Fine Upto 92
#include<bits/stdc++.h>
using namespace std;

long long int fib(long long int n) {
  long double phi = (1 + sqrt(5)) / 2;
  return round(pow(phi, n) / sqrt(5));
}
int main ()
{
  long long int n;
  cin >> n;
  cout << fib(n) << std::endl;
  return 0;
}

