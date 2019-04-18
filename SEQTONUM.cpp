#include <iostream>
#include <fstream>
using namespace std;
long long n,k,m,i,j;
long long vt[61],b[61],a[61],th[61][61],x[61];
int main()
{
    ifstream fi ("SEQTONUM.inp");
    fi >>n>>k;
    for (i=1;i<=n;i++)
    {
        fi >>a[i];
    }
    for (i=1;i<=k;i++) fi >>b[i];
    for (i=1;i<=n;i++) vt[i]=i;
    for (i=0;i<=n;i++)
    {
        th[i][i]=1;
        th[i][0]=1;
        for (j=0;j<i;j++) th[i][j]=th[i-1][j-1]+th[i-1][j];
    }
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++) if (a[vt[i]]<a[vt[j]]) swap(vt[i],vt[j]);
    for (i=1;i<=k;i++)
    {
        for (j=1;j<=n;j++)
        {
            if (vt[j]>b[i-1] && n-vt[j]>=k-i)
                if (a[vt[j]]!=b[i]) m=m+th[n-vt[j]][k-i];
                else break;

        }
        b[i]=vt[j];
    }
    ofstream fo ("SEQTONUM.out");
    fo <<m+1;
    return 0;
}
