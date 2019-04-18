#include <iostream>
#include <fstream>
using namespace std;
long long int n,m,i,j;
long long int gt[21],a[21],cx[21];
int main()
{
    ifstream fi ("HOANVI.inp");
    fi >>n>>m;
    gt[0]=1;
    for (i=1;i<=n;i++)
    {
        gt[i]=gt[i-1]*i;
        cx[i]=true;
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
            if (cx[j]==1)
            {
                if (gt[n-i]<m) m=m-gt[n-i];
                else break;
            }
        cx[j]=0;
        a[i]=j;
    }
    ofstream fo ("HOANVI.out");
    for (i=1;i<=n;i++) fo <<a[i]<<" ";
    return 0;
}
