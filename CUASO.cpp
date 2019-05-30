#include <iostream>

using namespace std;
int ptx[1001],pty[1001],tdx[1001],tdy[1001],ttx[1001],tty[1001],pdy[1001],pdx[1001];
bool check(int u,int v){
    if (ptx[u]>=ttx[v] && ptx[u]<=ptx[v] && pty[u]>=pty[v] && pty[u]<=pdy[v]) return true;
    return false;
}
int main()
{
    int n,i,j;
    cin >>n;
    for (i=1;i<=n;i++) cin >>ttx[i]>>tty[i]>>pdx[i]>>pdy[i];
    for (i=1;i<=n;i++){
        tdx[i]=ttx[i];
        tdy[i]=pdy[i];
        ptx[i]=pdx[i];
        pty[i]=tty[i];
    }
    for (i=1;i<=n;i++)
        for (j=i+1;j<=n;j++) if (check(i,j)) cout <<i<<" "<<j<<endl;
    return 0;
}
