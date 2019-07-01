#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int a[100001];
int main()
{
    int n,i,day,res=0;
    ifstream fi ("GARDENING.inp");
    fi >>n;
    for (i=1;i<=n;i++) fi >>a[i];
    sort(a+1,a+1+n,greater<int> ());
    for (i=1;i<=n;i++)
    {
        day=a[i]+i-1;
        res=max(res,day);
    }
    ofstream fo ("GARDENING.out");
    fo <<res;
    return 0;
}
