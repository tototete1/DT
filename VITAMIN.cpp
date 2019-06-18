#include <iostream>
#include <fstream>
using namespace std;
int n,x,i,j,u,c,m;
long long int s[101],f[101][1000001],t[1000001];
int main()
{
    ifstream fi ("VITAMIN.inp");
    fi >>n>>x;
    for (i=1; i<=n; i++)
    {
        fi >>c;
        s[i]=s[i-1]+c;
    }
    int w=c;
    u=1;
    for (j=1;j<=x;j++)
    {
        if (j%s[1]==0) f[1][j]=u,u+=2;
    }
    t[1]=s[n];
    i=1;
    while (t[i]+w<=x){
        i++;
        t[i]=t[i-1]+w;
    }
    m=i;
    w=s[n];
    int haha=n;
    int e=2;
    for (i=2;i<=n;i++){
        for (j=1;j<=x;j++){
            if (i!=n){
                f[i][j]=f[i-1][j];
                if (j==s[i]) f[i][j]=i;
                if (j>s[i])
                {
                    if (f[i-1][j-s[i]]!=0) f[i][j]=f[i-1][j-s[i]]+i+1;
                }
            }
            if (i==n){
                f[i][j]=f[i-1][j];
                if (j==s[i]) f[i][j]=i,w+=c,haha++;
                if (j>s[i]){
                    if (j%w==0) f[i][j]=haha,haha++,e++,w+=c;
                    else{
                        int r=e;
                        if (j==14) cout <<r<<endl;
                        d=1,c=n-1;
                        do
                        {
                            g=(d+c)/2;
                            if (t[r])
                        }
                        //if (j==8) cout <<t[r]<<endl;
                        if (f[i-1][j-t[r]]!=0) f[i][j]=f[i-1][j-t[r]]+i+r;
                    }
                }
            }
        }
    }
    for (i=1;i<=n;i++){
        for (j=1;j<=x;j++) cout <<f[i][j]<<" ";
        cout <<endl;}
    return 0;
}
