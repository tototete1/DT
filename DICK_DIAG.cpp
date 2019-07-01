#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
char s[101];
int i,m,n,u;
int main()
{
    ifstream fi ("DICK_DIAG.inp");
    fi >>s;
    m=strlen(s);
    i=0;
    while (i<m)
    {
        if (s[i]=='(')
        {
            u++;
            n=max(n,u);
        }
        if (s[i]==')')
        {
            u--;
        }
        i++;
    }
    int a[200][200];
    memset(a,0,sizeof(a));
    i=1;
    int j=n;
    while (i<=m)
    {
        if (s[i-1]=='(')
        {
            a[j][i]=1;
            //cout <<j<<" "<<i<<endl;
            a[j][i+1]=max(0,a[j][i+1]);
            a[j][i-1]=max(0,a[j][i-1]);
            a[j-1][i]=max(0,a[j-1][i]);
            a[j+1][i]=max(0,a[i+1][j]);
            if (i!=m) j=j-(s[i]=='(');

        }
        if (s[i-1]==')')
        {
            a[j][i]=2;
            a[j][i+1]=max(0,a[j][i+1]);
            a[j][i-1]=max(0,a[j][i-1]);
            a[j-1][i]=max(0,a[j-1][i]);
            a[j+1][i]=max(0,a[i+1][j]);
            if (i!=m) j=j+(s[i]==')');
        }
        i++;
    }
    ofstream fo ("DICK_DIAG.out");
    #define y 92
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (a[i][j]==0) fo <<".";
            if (a[i][j]==1) fo <<"/";
            if (a[i][j]==2) fo <<(char) y;
        }
        fo <<endl;
    }
    return 0;
}
