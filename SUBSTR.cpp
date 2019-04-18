#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
long long int m,k,n;
char s[21];
int cx[21];
long long int ch(int x,int y)
{
    long long i,r[21];
    r[0]=1;
    for (i=1;i<=y;i++) r[i]=r[i-1]*i;
    return (r[y]/r[y-x]);
}
int main()
{
    ifstream fi ("SUBSTR.inp");
    ofstream fo ("SUBSTR.out");
    int i,j;
    fi >>m>>k;
    fi >>s;
    n=strlen(s);
    int w=n;
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            if (s[i]<s[j])
                swap(s[i],s[j]);

    for (i=1;i<=n;i++) cx[i]=1;
    for (i=1; i<=m; i++)
    {
        for (j=1; j<=n; j++)
        {
            if (cx[j]==1)
            {
                if (ch(m-i,w-1)<k)
                    k=k-ch(m-i,w-1);
                else break;
                //cout <<k<<" ";
            }
        }
        //cout <<endl;
        fo <<s[j-1];
        cx[j]=0;
        w=w-1;
    }
    return 0;
}
