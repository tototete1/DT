#include <iostream>
#include <fstream>
using namespace std;
long long n,i,j,m=1;
long long gt[21],cx[21],a[21];
int main()
{
    ifstream fi ("NUMHV.inp");
    fi >>n;
    for (i=1;i<=n;i++) fi >>a[i];
    gt[0]=1;
    for (i=1;i<=n;i++) gt[i]=gt[i-1]*i;

    for (i=1;i<=n;i++)
    {
        for (j=1;j<a[i];j++)
        {
            if (!cx[j])
            {
                m=m+gt[n-i];
            }
        }
        cx[a[i]]=1;
    }
    ofstream fo ("NUMHV.out");
    fo <<m;
    return 0;
}
