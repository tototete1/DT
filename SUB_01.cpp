#include <bits/stdc++.h>
#define in long long

using namespace std;
in n,i,d,c,g,vt,vt1,m,vt2,hoho,hehe,oooo,eeee;
in a[200001],b[200001],f[200001];
int main()
{
    freopen("SUB_01.inp","r",stdin);
    freopen("SUB_01.out","w",stdout);
    cin >>n;
    for (i=1; i<=n; i++)
    {
        cin >>a[i];
        if (a[i]==0)
            hoho++;
        else
            hehe++;
    }
    b[1]=a[1];
    vt1=1;
    for (i=2; i<=n; i++)
    {
        d=1,c=vt1,vt=0;
        do
        {
            g=(d+c)/2;
            if (a[i]>=b[g])
                vt=g,d=g+1;
            else
                c=g-1;
        }
        while (d<=c);
        if (vt<=vt1)
        {
            b[vt+1]=a[i];
            if (vt==vt1)
                vt1++;
        }
    }
    cin >>m;
    for (i=1; i<=m; i++)
    {
        cin >>a[i];
        if (a[i]==0) oooo++;
        else eeee++;
    }
    f[1]=a[1];
    vt2=1;
    for (i=2; i<=m; i++)
    {
        d=1,c=vt2,vt=0;
        do
        {
            g=(d+c)/2;
            if (a[i]>=f[g])
                vt=g,d=g+1;
            else
                c=g-1;
        }
        while (d<=c);
        if (vt<=vt2)
        {
            f[vt+1]=a[i];
            if (vt==vt2)
                vt2++;
        }
    }
    in haha=0,hihi=0,hichic=0,huhu=0;
    for (i=1; i<=vt1; i++)
    {
        //cout <<b[i]<<" ";
        if (b[i]==0)
            haha++;
        else
            hihi++;
    }
    //cout <<haha<<" "<<hihi<<endl;
    for (i=1; i<=vt2; i++)
    {
        //cout <<f[i]<<" ";
        if (f[i]==0)
            huhu++;
        else
            hichic++;
    }
    //cout <<(long long) min(haha,huhu)+min(hihi,hichic);
    //hoho la so 0 day n ban dau
    //hehe la so 1 day n ban dau
    //oooo la so 0 day m ban dau
    //eeee la so 1 day n ban dau
    //haha la so 0 day n tang dai nhat
    //hihi la so 1 day n tang dai nhat
    //huhu la so 0 day m tang dai nhat
    //hichic la so 1 day m tang dai nhat
    cout <<min(haha,huhu)+min(hihi,hichic);
    return 0;
}
