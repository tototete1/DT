#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int n,i,vt,d;
struct data
{
    int vt,a;
};
bool cmp(data x,data y){ return x.a<y.a;}
data a[100001];
int main()
{
    ifstream fi ("PLAYER.inp");
    ofstream fo ("PLAYER.out");
    fi >>n;
    for (i=1;i<=n;i++){
        fi >>a[i].a;
        if (a[i].a==1) vt=i;
    }
    for (i=1;i<n;i++){
        if (a[i].a==n && a[i+1].a==1);
        else
        {
            if (a[i].a==a[i+1].a-1);
            else
            {
                fo <<"YES"<<endl<<i+1;
                return 0;
            }
        }
    }
    fo <<"NO";
    return 0;
}
