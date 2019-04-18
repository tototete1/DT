#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
using namespace std;
int n,x,u,k,m,M;
int d[21],gt[21],b[21];
char c[21],s[21],w[21];
long long int tinh(int r)
{
    int i,s=1;
    for (i=0; i<=k; i++)
    {
        if (i!=r)
            s=s*gt[d[i]];
        else
            s=s*gt[d[i]-1];
    }
    return s;
}
int main()
{
    ofstream fo ("HVSTR.out");
    ifstream fi ("HVSTR.inp");
    int i,j;
    fi >>s;
    fi >>m;
    memcpy(c,s,sizeof(s));
    memcpy(w,s,sizeof(s));
    n=strlen(s);
    sort(s,s+n);
    sort(w,w+n);
    gt[0]=1;
    for (i=1; i<=20; i++)
        gt[i]=gt[i-1]*i;
    //tim vi tri
    {
        x=0;
        k=0,d[0]=1;
        for (i=1; i<n; i++)
        {
            if (w[i]==w[i-1])
                b[k]++;
            else
            {
                k++;
                b[k]=1,w[k]=w[i];
            }
        }
        for (i=0;i<n;i++)
        {
            for (j=0;j<=k;j++)
            {
                if (w[j]<c[i])
                {
                    M=M+gt[n-i]/tinh(j);
                }
                else break;
            }
            b[j]--;
        }
        cout <<M+1;
    }
    //tim cau hinh
    {
        x=0;
        k=0,d[0]=1;
        for (i=1; i<n; i++)
        {
            if (s[i]==s[i-1])
                d[k]++;
            else
            {
                k++;
                d[k]=1,s[k]=s[i];
            }
        }

        for (i=1; i<=n; i++)
        {
            for (j=0; j<=k; j++)
            {
                if (d[j]!=0)
                {
                    if (gt[n-i]/tinh(j)<m)
                    {
                        m=m-gt[n-i]/tinh(j);
                    }
                    else
                    {
                        d[j]--;
                        break;
                    }
                }
            }
            fo <<s[j];
        }
    }
    return 0;
}
