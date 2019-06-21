#include <iostream>
#include <fstream>
using namespace std;
int i,s,haha,huhu,n;
int a[53],sl[12];
int main()
{
    for (i=2;i<=11;i++)
        sl[i]=4;
    sl[10]=4*4;
    ifstream fi ("G21.inp");
    fi >>n;
    ofstream fo ("G21.out");
    for (i=1;i<=n;i++)
    {
        fi >>a[i];
        sl[a[i]]--;
        s+=a[i];
    }
    if (s>=21){ fo <<"STOP";return 0;}
    if (s<=21-11) fo <<"DRAW";
    else{
        for (i=2;i<=11;i++){
            if (s+i<=21) haha+=sl[i];
            else huhu+=sl[i];
        }
    if (haha>=huhu) fo <<"DRAW";
    else fo <<"STOP";
    }
    return 0;
}
