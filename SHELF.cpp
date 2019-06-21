#include <iostream>
#include <fstream>
using namespace std;
int n,i,q;
long long  a[1000001],it[8*1000001];
void Build(int node,int l,int r)
{
    if (l==r) it[node]=a[l];
    else
    {
        int mid;
        mid =(l+r)/2;
        Build(2*node,l,mid);
        Build(2*node+1,mid+1,r);
        it[node]=it[2*node]+it[2*node+1];
    }
}
void Up(int node,int l,int r,int k,int v)
{
    if (l==r) it[node]=v;
    else
    {
        int mid=(l+r)/2;
        if (k<=mid) Up(node*2,l,mid,k,v);
        else Up(2*node+1,mid+1,r,k,v);
        it[node]=it[2*node]+it[2*node+1];
    }
}
long long Q(int node,int l,int r,int i,int j)
{
    long long  mid,s;
    if (r<i || j<l) return 0;
    if (i<=l && r<=j) return it[node];
    mid=(l+r)/2;
    s=Q(2*node,l,mid,i,j)+Q(2*node+1,mid+1,r,i,j);
    return s;
}
int main()
{
    ifstream fi ("SHELF.inp");
    fi >>n;
    for (i=1;i<=n;i++)
    {
        fi >>a[i];
    }
    ofstream fo ("SHELF.out");
    Build(1,1,n);
    fi >>q;
    while (q--)
    {
        fi >>i;
        fo <<min(Q(1,1,n,0,i-1),Q(1,1,n,i+1,n))<<" ";
        Up(1,1,n,i,a[i]+1);
        a[i]++;
    }
    return 0;
}
