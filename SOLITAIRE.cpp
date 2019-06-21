#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int n,i,d,trc,res,j;
int a[100001];
int main()
{
    ifstream fi ("solitaire.inp");
    fi >>n;
    for (i=1;i<=n;i++) fi >>a[i];
    sort(a+1,a+1+n);
    for (i=1;i<=n;i++){
        if (a[i]%2==0) trc=0;
        else trc=1;
        d=1;
        for (j=i+1;j<=n;j++){
            if (trc==1 && a[j]%2==0) d++,trc=0;
            if (trc==0 && a[j]%2!=0) d++,trc=1;
        }
        res=max(res,d);
    }
    ofstream fo ("solitaire.out");
    fo <<res;
    return 0;
}
