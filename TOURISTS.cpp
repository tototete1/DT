#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int n,i,u,ans,t;
int a[100001],res=1e9;
int main()
{
    ifstream fi ("TOURISTS.inp");
    fi >>n;
    for (i=1;i<=n;i++) fi >>a[i];
    sort(a+1,a+1+n);
    res=n;
    for (i=n;i>0;i--)
    {
        res=min(res,a[i]+n-i);
    }
    ofstream fo ("TOURISTS.out");
    fo <<res;
    return 0;
}
