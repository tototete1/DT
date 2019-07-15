#include <bits/stdc++.h>

using namespace std;
long long int a[100001];
long long int n,k,m;
vector <int> ke[100001];
void bfs()
{
    queue <int> q;
    int u,i,v;
    q.push(1);
    memset(a,-1,sizeof(a));
    a[1]=0;
    while (!q.empty())
    {
        u=q.front();
        q.pop();
        for (i=0;i<ke[u].size();i++)
        {
            v=ke[u][i];
            if (a[v]==-1)
            {
                a[v]=a[u]+1;
                q.push(v);
            }
        }
    }
}
bool tinh(long long int x)
{
    long long i,s=0;
    for (i=2;i<=n;i++) s=s+x/a[i];
    if (s>=k) return true;
    else return false;
}
int main()
{
    ifstream fi ("TRANS.inp");
    ofstream fo ("TRANS.out");
    long long int i,u,v,o=0,d,c,g,vt;
    fi >>n>>m>>k;
    for (i=1;i<=m;i++)
    {
        fi >>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    bfs();
    d=1,c=k;
    do
    {
        g=(d+c)/2;
        if (tinh(g)) c=g-1,vt=g;
        else d=g+1;
    }while (d<=c);
    fo <<vt;
    return 0;
}
