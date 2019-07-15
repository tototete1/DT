#include <fstream>
#include <iostream>
using namespace std;
int n,i,jmax,j;
long long int a[1001],s[1001],ans;
int main()
{
    ifstream fi ("PRIZES.inp");
    fi >>n;
    for (i=1;i<=n;i++) fi >>a[i];
    s[1]=a[1];
    ans=s[1];
    s[0]=0;
    for (i=2;i<=n;i++)
    {
        jmax=0;
        for (j=1;j<i;j++)
        {
            if (a[i]>a[j] && s[j]>s[jmax]) jmax=j;
        }
        s[i]=s[jmax]+a[i];
        ans=max(ans,s[i]);
    }
    ofstream fo ("PRIZES.out");
    fo <<ans;
    return 0;
}
