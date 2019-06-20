#include <iostream>
#include <fstream>
using namespace std;
int n,i;
int a[100002],td[100002];
int main()
{
    ifstream fi ("DEXTERITY.inp");
    ofstream fo ("DEXTERITY.out");
    fi >>n;
    for (i=1; i<=n; i++)
    {
        fi >>a[i];
        td[i]=2;
    }
    a[n+1]=-1;
    for (i=1; i<=n; i++)
    {
        if (td[i]>0)
        {
            if (a[i+1]>a[i+2] && a[i+1]>a[i])
            {
                if (td[i]>=1 && td[i+1]>=1)
                {
                    swap(a[i],a[i+1]);
                    td[i]--,td[i+1]--;
                    swap(td[i],td[i+1]);
                }
                /*for (int j=1;j<=n;j++) cout <<a[j]<<" ";
                cout <<endl;
                for (int j=1;j<=n;j++) cout <<td[j]<<" ";
                cout <<endl;
                cout <<endl;*/
                continue;
            }
            if (a[i+2]>a[i+1] && a[i+2]>a[i])
            {
                if (td[i]>=1 && td[i+1]>=1 && td[i+2]==2)
                {
                    swap(a[i],a[i+2]);
                    swap(a[i+1],a[i+2]);
                    td[i+2]=0, td[i]--,td[i+1]--;
                    swap(td[i],td[i+2]);
                    swap(td[i+1],td[i+2]);
                   /* for (int j=1;j<=n;j++) cout <<a[j]<<" ";
                    cout <<endl;
                    for (int j=1;j<=n;j++) cout <<td[j]<<" ";
                    cout <<endl;
                    cout <<endl;*/
                    continue;
                }
                if (td[i]>=1 && td[i+1]>=1 && td[i+1]==1)
                {
                    if (a[i+1]>a[i])
                    {
                        swap(a[i],a[i+1]);
                        td[i+1]--,td[i]--;
                        swap(td[i+1],td[i]);
                        /*for (int j=1;j<=n;j++) cout <<a[j]<<" ";
                        cout <<endl;
                        for (int j=1;j<=n;j++) cout <<td[j]<<" ";
                        cout <<endl;
                        cout <<endl;*/
                        continue;
                    }
                    else
                    {
                        swap(a[i+1],a[i+2]);
                        td[i+2]--,td[i+1]--;
                        swap(td[i+2],td[i+1]);
                        /*for (int j=1;j<=n;j++) cout <<a[j]<<" ";
                        cout <<endl;
                        for (int j=1;j<=n;j++) cout <<td[j]<<" ";
                        cout <<endl;
                        cout <<endl;*/
                        continue;
                    }
                }
            }
        }
        /*for (int j=1;j<=n;j++) cout <<a[j]<<" ";
        cout <<endl;
        for (int j=1;j<=n;j++) cout <<td[j]<<" ";
        cout <<endl;
        cout <<endl;*/
    }
    for (i=1; i<=n; i++)
        fo <<a[i]<<" ";
    return 0;
}
