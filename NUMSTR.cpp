#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
using namespace std;
long long int n,i,m,k=1,j;
long long int cx[21],a[21];
char s[21],t[21];
int main()
{
    ifstream fi ("NuMstR.inp");
    fi >>s;
    n=strlen(s);
    fi >>t;
    m=strlen(t);
    sort(s,s+n);
    for (i=1;i<=n;i++) cx[i]=true;
    a[m]=1;
    for (i=m-1;i>=1;i--) a[i]=a[i+1]*(n-i);
    for (i=1;i<=m;i++)
    {
        for (j=1;j<=n && t[i-1]>s[j-1];j++)
            if (cx[j]==true) k=k+a[i];
        cx[j]=false;

    }
    ofstream fo ("NUMSTr.OUt");
    fo <<k;
    return 0;
}
