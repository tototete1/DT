#include <iostream>
#include <fstream>
using namespace std;
int a,b,c,d,x1,x2,u,x3,t,x4,res;
int main()
{
    ofstream fo ("PAIRING.out");
    ifstream fi ("PAIRING.inp");
    fi >>a>>b>>c>>d;
    x1=a%2;
    x3=c%2;
    u=min(b,d);
    x2=b-u;
    x4=d-u;
    if (x1==x2 && x2==x3 && x3==0 && x3==x4) fo <<0;
    else
    {
        if (x4>0 && x1==1) x4--,x1--,res++;
        if (x4>0 && x3==1) x4--,x3=0,res++;
        if (x2>0 && x3==1) x2--,x3=0,res++;
        if (x2>0 && x1==1) x2--,x1--,res++;
        fo <<x1+x2+x3+x4+res;
        //cout <<x1<<" "<<x2<<" "<<x3<<" "<<x4<<" "<<res;
    }
    return 0;
}
