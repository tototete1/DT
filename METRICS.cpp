#include <bits/stdc++.h>
using namespace std;
long long n,i,j,x,u,m;
struct data
{
    int s,vt;
};
data f[100001],d[100001];
bool cmp(data a,data b) {return a.s<b.s;}
long long a[100001],b[100001],vt[100001];
long long int s=0;
int main()
{
    ifstream fi ("METRICS.inp");
    fi >>n;
    for (i=1;i<=n;i++) fi >>a[i],f[i].s=a[i],f[i].vt=i;
    fi >>m;
    for (i=1;i<=m;i++) fi >>b[i],d[i].s=b[i],d[i].vt=i;
    sort(d+1,d+1+m,cmp);

    for (i=1;i<=m;i++) vt[i]=vt[i-1]+d[i].vt;
    for (i=1;i<=n;i++)
    {
        int da=1,c=m,vt1=0,g;
        do
        {
            g=(da+c)/2;
            if (a[i]>=d[g].s)
            {
                da=g+1;
                vt1=g;
            }
            else c=g-1;
        }while (da<=c);
        s=s+(a[i]*vt1-a[i]*(m-vt1))*i+(-a[i]*(vt[vt1])+a[i]*(vt[m]-vt[vt1]));
    }
    sort(f+1,f+1+n,cmp);
    for (i=1;i<=n;i++) vt[i]=vt[i-1]+f[i].vt;
    for (i=1;i<=m;i++)
    {
        int da=1,c=n,vt1=0,g;
        do
        {
            g=(da+c)/2;
            if (b[i]>f[g].s)
            {
                da=g+1;
                vt1=g;
            }
            else c=g-1;
        }while (da<=c);
        //cout <<vt1<<endl;
        s=s-(b[i]*vt1-b[i]*(n-vt1))*i-(-b[i]*(vt[vt1])+b[i]*(vt[n]-vt[vt1]));
    }
    ofstream fo ("METRICS.out");
    fo <<s;
    return 0;
}
