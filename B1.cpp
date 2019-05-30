#include <iostream>

#include <cstring>
using namespace std;
int n,k,p,u,X[21];
long long int dp[21][180];
long long int rr(int idx,int sum){
    if (idx==0){
        if (sum==k)
        {
            u++;
            return 1;
        }
        else return 0;
    }
    long long int res=0;
    if (dp[idx][sum]!=-1)
    {

        for (int i=0;i<=9;i++)
        {
            if (u==p-1) X[idx]=i;
            if (sum+i==k) u++;
        }
        return dp[idx][sum];
    }
    int i;
    for (i=0;i<=9;i++){
        if (u+1==p){
            X[idx]=i;
            cout <<X[idx]<<" "<<idx<<endl;
        }
        res+=rr(idx-1,sum+i);
    }
    dp[idx][sum]=res;
    return res;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin >>n>>k>>p;
    long long int res=rr(n,0);
    cout <<res<<endl;
    for (int i=n;i>0;i--) cout <<X[i];
    return 0;
}
