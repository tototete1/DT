#include <iostream>
#include <cstring>
#define VO_CUNG 2000000000
using namespace std;
long long a[27][27],j,b,i,test,w,n,m,t,k,cx[125];
char s,c,r[27];
int main()
{
    for (i=0; i<=26; i++)
    {
        a[i][0]=1;
        for (j=1; j<=i; j++)
            if (a[i-1][j-1]*i<=VO_CUNG)
                a[i][j]=a[i-1][j-1]*i;
            else
                a[i][j]=VO_CUNG;
    }
    cin >>test;
    while (test--)
    {
        cin >>n>>m;
        cin >>s;

        if (s=='W')
        {
            cin >>k;
            if (k>a[n][m])
            {
                cout <<"Incorrect data"<<endl;
            }
            else
            {
                w=n;
                for (i=97; i<97+n; i++)
                    cx[i]=1;
                for (i=1; i<=m; i++)
                {
                    for (j=97; j<97+n; j++)
                    {
                        if (cx[j]!=0)
                        {
                            if (a[w-1][m-i]<k)
                                k=k-a[w-1][m-i];
                            else
                                break;
                        }
                    }
                    w--;
                    c=j;
                    cx[j]=0;
                    cout <<c;
                }
                cout <<endl;
            }
        }
        else
        {
            int tam=0;
            cin >>r;
            t=strlen(r);
            for (i=0;i<t;i++)
            {
                for (j=97;j<97+n;j++)
                {
                    c=j;
                    if (r[i]==c)
                    {
                        tam++;
                        break;
                    }
                }
                for (j=i+1;j<t;j++) if (r[i]==r[j]) tam++;
            }
            if (tam!=t) cout <<"Incorrect data"<<endl;
            else
            {
                for (i=97;i<97+n;i++) cx[i]=1;
                w=1;
                k=0;
                for (i=0;i<t;i++)
                {
                    for (j=97;j<97+n;j++)
                    {
                        c=j;
                        if (c<r[i] && cx[j]==1)
                        {
                            k=k+a[n-w][t-i-1];
                        }
                    }
                    w++;
                    cx[r[i]]=0;
                }
                cout <<k+1<<endl;
            }

        }
    }
    return 0;
}
