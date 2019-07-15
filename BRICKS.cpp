#include <bits/stdc++.h>

using namespace std;
unsigned long long int g,y,s,d,c,mid,m,n;
int main()
{
    freopen("BRICKS.inp","r",stdin);
    freopen("BRICKS.out","w",stdout);
    cin >>g>>y;
    s=(g+4)/2;
    long long p=g+y;
    d=1,c=s/2;
    do
    {
       mid=(d+c)/2;
       m=mid;
       n=s-m;
       if (m>p/n) c=mid-1;
       else d=mid+1;
    }while (!(m==p/n && p%n==0));
    cout <<m<<" "<<n;
    return 0;
}
