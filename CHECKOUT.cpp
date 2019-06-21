#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main()
{
    ifstream fi ("checkout.inp");
    ofstream fo ("checkout.out");
    fo.precision(12);
    double d, a1, a2, v, t,a,DELTA,x1;
    fi >> d >> a1 >> a2 >> v >> t;
    double u=(d-(v*v)/(2*a1)-(v*v)/(2*a2))/v;
    if (u>=t)
        fo <<fixed<<v/a1+v/a2+u;
    else
    {
        a=1/(2*a1)+1/(2*a2);
        DELTA=t*t+4*a*(d);
        x1=(-t+sqrt(DELTA))/(2*a);

        fo << fixed << x1/a1+x1/a2+t;
    }
    return 0;
}
