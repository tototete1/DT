#include <iostream>
#include <fstream>
using namespace std;
int n,b,i;
int a[100001],c[100001];
int main()
{
    ifstream fi ("DOWNLOAD.inp");
    ofstream fo ("DOWNLOAD.out");
    fi >>n>>b;
    for (i=1;i<=n;i++){
        fi >>a[i];
    }
    for (i=1;i<=n;i++){
        c[i]=a[i]/b;
        if (b>a[i]) c[i]+=(b%a[i]!=0);
        else c[i]+=(a[i]%b!=0);
        c[i]=max(c[i],1);
    }
    int u=c[1]-1;
    long long int  res=c[1];
    for (i=2;i<=n;i++)
    {
        res+=min(u,c[i]);
    }
    fo <<res;
    return 0;
}
