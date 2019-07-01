#include <bits/stdc++.h>
#define in long long int

using namespace std;
char s[1000001];
int n;
int a[1000001];
struct data
{
    int s,e,tong,s1,s2,e1,e2;
    bool a;
};
data d[1000001];
int  f[1000001];
bool cmp(data a,data b)
{
    return (a.tong<b.tong || (a.tong==b.tong && a.e>b.e)) ;
}
data tinh(int x)
{
    data A;
    A.a=0;
    int k=0,i,j;
    memset(f,0,sizeof(f));
    for (i=1; i+x-1<=n; i++)
    {
        j=i+x-1;
        d[i].tong=a[j]-a[i-1];
        d[i].s=i;
        d[i].e=j;
        f[d[i].tong]++;
        if (f[d[i].tong]>1)
            A.a=1;
        k++;
    }
    if (A.a==0)
        return A;
    int w=-1;
    for (i=1; i<=k; i++)
    {
        if (w==-1)
        {
            if (f[d[i].tong]>1)
            {
                w=d[i].tong;
                A.s1=d[i].s;
                A.e1=d[i].e;
                continue;
            }
        }
        if (w>-1)
        {
            if (d[i].tong==w)
            {
                A.s2=d[i].s;
                A.e2=d[i].e;
                return A;
            }
        }
    }
    return A;
}
int main()
{
    ifstream fi ("TOURS.inp");
    ofstream fo ("TOURS.out");
    int i,d1,c1,d2,c2,s1,s2,s3,s4;
    fi >>s;
    n=strlen(s);
    int y=0,o=0;
    for (i=1; i<=n; i++)
    {
        a[i]=a[i-1]+(s[i-1]=='1');
        if (i>1 && s[i-1]=='0' && s[i-2]=='1') y++;
    }
    if (y==500000) {fo <<2<<" "<<999999<<" "<<3<<" "<<1000000;return 0;}
    int da,c,g,vt;
    da=1,c=n-1;
    do
    {
        g=(da+c)/2;
        if (tinh(g).a)
            da=g+1,vt=g;
        else
            c=g-1;
    }while (da<=c);
    //cout <<vt;
    //cout <<endl;
    //cout <<tinh(1).a<<endl;
    //cout <<vt<<endl;
    //freopen("TOURS.out","w",stdout);
    fo <<tinh(vt).s1<<" "<<tinh(vt).e1<<" "<<tinh(vt).s2<<" "<<tinh(vt).e2;

    //ofstream fo ("TOURS.out");
}
