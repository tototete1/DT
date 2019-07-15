#include <bits/stdc++.h>
#define BASES 37
using namespace std;
int m,n,mod,vip=0,p=0,oo=0,res=0;
int a[31][31],h[31][31],d[31],w[1001],e[31];
long long int po[1001],Hash[101],ha;char s[21],t[151];
void sub2()
{
    int i,j;
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=m; j++)
        {
            if (a[i][j]!=0)
            {
                if (i==1 && j==1)
                    h[i][j]=1;
                else
                    h[i][j]=(h[i-1][j]+h[i][j-1])%mod;
            }
        }
    }
    ofstream fo ("WGAME.OUT");
    fo <<h[n][m];
}
long long int Get(int i,int j)
{
    return Hash[j]-Hash[i-1]*po[j-i+1];
}
long long Backtrack(int x,int y,int ww)
{
    if (x==1 && y==1 && oo<=ww)
    {
        int j,i,u=1;
        oo++;
        j=0;
        p++;
        //cout <<e[2]<<" ";
        e[p]=a[1][1];
        //cout <<Hash[0]<<endl;
        for (i=1; i<=n+m-1; i++)
        {
            Hash[i]=Hash[i-1]*BASES+e[i];
            //cout <<Hash[i]<<" ";
        }
        //cout <<endl;
        //cout <<po[3]<<endl;
        //cout <<ha<<" "<<Get(2,4);
        for (i=1;i<=n+m-1;i++)
            if (ha==Get(i,vip+i-1)) {j=true;break;}
        int i1=1,i2=n+m-1;
        while (i1<=i2)
        {
            if (e[i1]==e[i2]) i1++,i2--;
            else break;
        }
        if (i1<=i2) i=false;
        else i=true;
        //cout <<"3: ";

        //system("pause");
        p--;
        //cout <<i<<endl;
        //cout <<i<<" "<<j<<endl;
        //if (i==true && j==true)
        //{for (int we=1;we<=n+m-1;we++) cout <<e[we]<<" ";
        //cout <<endl;
        //system("pause");}
        if (i==true && j==true)
        {
            res=(res+1)%mod;
            //cout <<"AAA";
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (x==1 && y==1 && oo>ww)
        return 0;
    if (x>1 || y>1)
    {
        //cout <<x<<" "<<y;
        //system("pause");
        if (x>1 && a[x-1][y]!=0)
        {
            p++;
            e[p]=a[x][y];

            Backtrack(x-1,y,ww);
            p--;
        }
        if (y>1 && a[x][y-1]!=0)
        {
            p++;
            e[p]=a[x][y];
            Backtrack(x,y-1,ww);
            p--;
        }
    }
}
void sub1()
{
    long long int pW[11][11],i,j;
    memset(pW,0,sizeof(pW));
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=m; j++)
            if (a[i][j]!=0)
            {
                if (i==1 && j==1)
                    pW[1][1]=1;
                else
                    pW[i][j]=pW[i-1][j]+pW[i][j-1];
            }
    }
    po[0]=1;
    for (i=1;i<=vip;i++) ha=ha*BASES+s[i-1]-'a'+1;
    for (i=1;i<=n+m-1;i++) po[i]=po[i-1]*BASES;
    int ww=pW[n][m];
    Backtrack(n,m,ww);
    ofstream fo ("WGAME.out");
    fo<<res%mod;
}
long long int su3[31][31][31][31];
int xk[2]={0,1},yk[2]={1,0};
long long int ressub3(int x,int y,int z,int tt)
{
    int i,j,x1,z1,y1,tt1;
    if (z<x || tt<y) return 0;
    if (su3[x][y][z][tt]!=-1) return su3[x][y][z][tt];
    su3[x][y][z][tt]=0;
    for (i=0;i<2;i++)
    {
        for (j=0;j<2;j++){
            x1=x+xk[i],y1=y+yk[i];
            z1=z-xk[j],tt1=tt-yk[j];//
            if (x1<=n && z1<=n && y1<=m && tt1<=m)
            {
                if (a[x1][y1]!=0 && a[z1][tt1]!=0 && a[x1][y1]==a[z1][tt1])
                {
                    su3[x][y][z][tt]=(su3[x][y][z][tt]+ressub3(x1,y1,z1,tt1))%mod;
                }
            }
        }
    }
    return (su3[x][y][z][tt])%mod;
}
void sub3()
{
    int i,j;
    memset(su3,-1,sizeof(su3));
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) su3[i][j][i][j]=1;
    ofstream fo ("WGAME.out");
    fo <<ressub3(1,1,n,m);
}
long long int ressub4(int x,int y,int z,int tt)
{
    int i,j,x1,z1,y1,tt1;
    if (z<x || tt<y) return 0;
    if (su3[x][y][z][tt]!=-1) return su3[x][y][z][tt];
    su3[x][y][z][tt]=0;
    for (i=0;i<2;i++)
    {
        for (j=0;j<2;j++){
            x1=x+xk[i],y1=y+yk[i];
            z1=z-xk[j],tt1=tt-yk[j];//
            if (x1<=n && z1<=n && y1<=m && tt1<=m)
            {
                if (a[x1][y1]!=0 && a[z1][tt1]!=0 && a[x1][y1]==a[z1][tt1])
                {
                    su3[x][y][z][tt]=(su3[x][y][z][tt]+ressub3(x1,y1,z1,tt1))%mod;
                }
            }
        }
    }
    return (su3[x][y][z][tt])%mod;
}
void sub4()
{
    int i,j;
    memset(su3,-1,sizeof(su3));
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) su3[i][j][i][j]=1;
    ofstream fo ("WGAME.out");
    fo <<ressub4(1,1,n,m);
}
int main()
{
    ifstream fi ("WGAME.inp");
    int i,j,pro=0,oz=0;

    fi >>n>>m>>mod;
    fi >>s;
    for (i=1; i<=n; i++)
    {
        fi >>t;
        for (j=1; j<=m; j++)
        {
            if (t[j-1]=='#')
                a[i][j]=0;
            else
            {
                a[i][j]=t[j-1]-'a'+1;
                w[a[i][j]]++,oz++;
            }
        }
    }
    vip=strlen(s);
    for (i=1; i<=vip; i++)
        d[i]=s[i-1]-'a'+1;
    if (n<=10 && m<=10)
      {sub1();return 0;}
    if (n<=30 && m<=30)
    {
        //cout <<oz<<" "<<w[a[1][1]];
        if (oz!=w[a[1][1]])
        {
            if (a[1][1]==d[1]) sub3();
            else sub4();
        }
        else sub2();

    }

    return 0;
}
