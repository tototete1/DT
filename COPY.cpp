#include <bits/stdc++.h>

using namespace std;
long long int n,m,i;
long long int s,a[1000001];
int main()
{
    ifstream fi ("COPY.inp");
    ofstream fo ("COPY.out");
    fi >>n>>m;
    for (i=1;i<=n;i++) fi >>a[i];
    sort(a+1,a+1+n);
    s=0,i=0;
    while (s+a[i+1]<=m && i+1<=n)
    {
        i++;
        s+=a[i];
    }
    fo <<i;
    return 0;
}
