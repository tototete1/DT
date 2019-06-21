#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int n,x,i,j;
int a[101],res,T[101][1000002];
int main()
{
    ifstream fi ("vitamin.inp");
    ofstream fo ("vitamin.out");
    fi >>n>>x;
    for (i=1; i<=n; i++)
    {
        fi >>a[i];
    }
    if (n==1)
        if (x%a[1]==0)
            fo <<x/a[1];
        else
            fo <<-1;
    else
    {
        for (i=0; i<n; i++)
        {
            for (j=0; j<=x; j++)
                T[i][j]=1e8;
        }
        T[0][x]=0;
        for (j=x; j>=0; j--)
        {
            for (i=0; i<n; i++)
            {
                if (j-a[i+1]>=0)
                {

                    T[min(i+1,n-1)][j-a[i+1]]=min(T[min(i+1,n-1)][j-a[i+1]],T[i][j]+1);
                }
                if (j-a[1]>=0)
                {
                    T[1][j-a[1]]=min(T[1][j-a[1]],T[i][j]+2);
                }
            }
        }
        res=1e8;
        for (i=0; i<n; i++)
        {
            res=min(res,T[i][0]);
        }
        if (res!=1e8)
            fo <<res;
        else
            fo <<-1;
    }
    return 0;
}
