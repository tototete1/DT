#include <iostream>
#include <fstream>
#include <bits/std
using namespace std;
int n,m;
const int u=1001/2+1,v=1001/2+1;
int a[1001][1001],a1[u][v],a2[u][v],a3[u][v],a4[u][v];long long int f[u][v];
long long  check(int x[u][v],int y[u][v],int z[u][v],int w[u][v])
{
    long long int i,j,ans=0,res;
    for (i=1; i<=n/2+(n%2!=0); i++)
    {
        for (j=1; j<=m/2+(m%2!=0); j++)
        {
            res=0;
            if (n%2!=0 && m%2!=0)
            {
                if (i!=n/2+1 && j!=m/2+1)
                {
                    if (x[i][j]!=y[i][j]) res++;
                    if (x[i][j]!=z[i][j]) res++;
                    if (x[i][j]!=w[i][j]) res++;
                    f[i][j]=min(f[i][j],res);
                }
                else
                {
                    bool h=0;
                    if (x[i][j]!=y[i][j]) h=1;
                    if (x[i][j]!=z[i][j]) h=1;
                    if (x[i][j]!=w[i][j]) h=1;
                    if (h==1) res++;
                    f[i][j]=min(f[i][j],res);
                }
            }
            if (n%2!=0 && m%2==0)
            {
                if (i!=n/2+1)
                {
                    if (x[i][j]!=y[i][j]) res++;
                    if (x[i][j]!=z[i][j]) res++;
                    if (x[i][j]!=w[i][j]) res++;
                    f[i][j]=min(f[i][j],res);
                    ans+=res;
                }
                else
                {
                    bool h=0;
                    if (x[i][j]!=y[i][j]) h=1;
                    if (x[i][j]!=z[i][j]) h=1;
                    if (x[i][j]!=w[i][j]) h=1;
                    if (h==1) res++;
                    f[i][j]=min(f[i][j],res);
                }
            }
            if (n%2==0 && m%2!=0)
            {
                if (j!=m/2+1)
                {
                    if (x[i][j]!=y[i][j]) res++;
                    if (x[i][j]!=z[i][j]) res++;
                    if (x[i][j]!=w[i][j]) res++;
                    f[i][j]=min(f[i][j],res);
                }
                else
                {
                    bool h=0;
                    if (x[i][j]!=y[i][j]) h=1;
                    if (x[i][j]!=z[i][j]) h=1;
                    if (x[i][j]!=w[i][j]) h=1;
                    if (h==1) res++;
                    f[i][j]=min(f[i][j],res);
                }
            }
            if (n%2==0 && m%2==0)
            {
                if (x[i][j]!=y[i][j]) res++;
                if (x[i][j]!=z[i][j]) res++;
                if (x[i][j]!=w[i][j]) res++;
                f[i][j]=min(f[i][j],res);
            }
        }
    }
    return ans;
}
int main()
{
    ifstream fi ("MATRIX.inp");
    int i,j;
    fi >>n>>m;
    for (i=1;i<=n/2+(n%2!=0);i++)
    {
        for (j=1;j<=m/2+(m%2!=0);j++) f[i][j]=9;
    }
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=m; j++)
            fi >>a[i][j];
    }
    ofstream fo ("MATRIX.out");
    for (i=1; i<=n/2+(n%2!=0); i++)
    {
        for (j=1; j<=m/2+(m%2!=0); j++)
        {
            a1[i][j]=a[i][j];
        }
    }
    for (i=n/2+1; i<=n; i++)
    {
        for (j=1; j<=m/2+(m%2!=0); j++)
        {
            //      cout <<n/2+1-i+n/2+1<<" ";
            a2[n/2+(n%2!=0)-(i-n/2-1)][j]=a[i][j];
        }
    }
    //cout <<endl;
    //cout <<endl;
    for (i=1; i<=n/2+(n%2!=0); i++)
    {
        for (j=m/2+1; j<=m; j++)
        {
            a3[i][m/2+(m%2!=0)-(j-m/2-1)]=a[i][j];
        }
    }
    for (i=n/2+1; i<=n; i++)
    {
        for (j=m/2+1; j<=m; j++)
        {
            //cout <<i<<" "<<j<<endl;
            //cout <<n/2+(n%2!=0)+1-(i-n/2-(n%2!=0))<<" "<<m/2+(m%2!=0) +1-(j-m/2-(m%2!=0))<<" ";
            a4[n/2+(n%2!=0)-(i-n/2-1)][m/2+(m%2!=0)-(j-m/2-1)]=a[i][j];
        }
        //    cout <<endl;
    }
    //cout <<endl;
    /*for (i=1; i<=n/2+(n%2!=0); i++)
    {
        for (j=1; j<=m/2+(m%2!=0); j++)
        {
            cout <<a1[i][j]<<" ";
        }
        cout <<endl;
    }
    cout <<endl;
    for (i=1; i<=n/2+(n%2!=0); i++)
    {
        for (j=1; j<=m/2+(m%2!=0); j++)
        {
            cout <<a2[i][j]<<" ";
        }
        cout <<endl;
    }
    cout <<endl;
    for (i=1; i<=n/2+(n%2!=0); i++)
    {
        for (j=1; j<=m/2+(m%2!=0); j++)
        {
            cout <<a3[i][j]<<" ";
        }
        cout <<endl;
    }
    cout <<endl;
    for (i=1; i<=n/2+(n%2!=0); i++)
    {
        for (j=1; j<=m/2+(m%2!=0); j++)
        {
            cout <<a4[i][j]<<" ";
        }
        cout <<endl;
    }*/
    long long int r[5],s=0;
    r[1]=check(a1,a2,a3,a4);
    r[2]=check(a2,a1,a3,a4);
    r[3]=check(a3,a1,a2,a4);
    r[4]=check(a4,a1,a2,a3);
    for (i=1;i<=n/2+(n%2!=0);i++)
    {
        for (j=1;j<=m/2+(m%2!=0);j++) s+=f[i][j];
    }
    fo <<s;
    return 0;
}
