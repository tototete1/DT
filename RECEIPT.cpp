#include <iostream>
#include <fstream>
using namespace std;
int n,m,i,j;
long long int s[100001],a[100001];
int main()
{
    ifstream fi ("RECEIPT.inp");
    fi >>n>>m;
    for (i=1;i<=m;i++)
    {
        fi >>a[i];
        s[i]=a[i]-a[i-1];
    }
    //for (i=1;i<=m;i++) cout <<s[i]<<" ";
    int j=1,sl=a[1];
    ofstream fo ("RECEIPT.out");
    for (i=1;i<=n;i++)
    {
        while (s[j]==0) j++;
        fo <<j<<" ";
        s[j]--;

    }
    return 0;
}
