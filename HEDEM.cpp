#include <iostream>

using namespace std;
long long int n,s,t;
int i,X[101];
int main()
{
    cin >>n;
    s=n;
    t=n;
    i=0;
    while (t>0){
        X[++i]=t%2;
        t/=2;
    }
    n=i;
    for (i=n;i>0;i--) cout <<X[i];cout <<endl;
    i=0;
    while (s>0){
        X[++i]=s%16;
        s/=16;
    }
    n=i;
    for (i=n;i>0;i--) cout <<X[i];
    return 0;
}
