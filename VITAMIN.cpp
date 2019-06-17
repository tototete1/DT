#include <iostream>

using namespace std;
int n,x,i,j,u,c;
long long int s[101],f[101][1000001];
int main()
{
    cin >>n>>x;
    for (i=1;i<=n;i++){
        cin >>c;
        s[i]=s[i-1]+c;
    }
    u=1;
    for (i=1;i<=x;i++)
    {
        if (i%s[1]==0) f[1][i]=u,u+=2;
    }
    for (i=2;i<=n;i++)
    {
        for (j=1;j<=x;j++)
        {
            if (j<s[i]) f[i][j]=f[i-1][j];
            if (j==s[i]) f[i][j]=i;
            if (j>s[i])
            {
                if (f[i-1][j-s[i]]!=0){

                    f[i][j]=f[i-1][j-s[i]]+i+1;
                    if (i==2 && j==12) cout <<"AAA";
                }
            }
        }
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=x;j++) cout <<f[i][j]<<" ";
        cout <<endl;
    }
    long long int res=1e18;
    for (i=1;i<=n;i++){
        if (f[i][x]!=0){
            res=min(res,f[i][x]);
        }
    }
    if (res==1e18) cout <<-1;
    else cout <<res;
    return 0;
}
