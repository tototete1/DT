#include <iostream>
#include <cstring>
using namespace std;
int x,y;
int x1[9],y1[9];
char s[6];
int main()
{
    cin >>x>>y;
    x1[0]=x,y1[0]=y;
    x1[1]=x,y1[1]=y-1;
    x1[2]=x,y1[2]=y+1;
    x1[3]=x+1,y1[3]=y;
    x1[4]=x-1,y1[3]=y;
    x1[5]=x-1,y1[5]=y+1;
    x1[6]=x+1,y1[6]=y+1;
    x1[7]=x-1,y1[7]=y-1;
    x1[8]=x+1,y1[8]=y-1;
    cin >>s;
    x=0,y=0;
    for (int i=0;i<=8;i++){
            if (x==x1[i] && y==y1[i]) cout <<0<<endl;
        }
    for (int i=0;i<strlen(s);i++){
        if (s[i]=='D') y--;
        if (s[i]=='U') y++;
        if (s[i]=='L') x--;
        if (s[i]=='R') x++;
        for (int j=0;j<=8;j++){
            if (x==x1[j] && y==y1[j]) cout <<i+1<<endl;
        }
    }
    return 0;
}
