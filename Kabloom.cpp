#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int add(char a,char b)
{
    if(a=='R'&&b=='R')
    return 50;
    
    if(a=='R')
    {
       if(b=='A')return 20;
       if(b=='K')return 15;
       if(b=='Q')return 15;
       if(b=='J')return 15;
       if(b=='T')return 10;
        return b-'0';
    }
    
    if(b=='R')
    {
        if(a=='A')return 20;
        if(a=='K')return 15;
        if(a=='Q')return 15;
        if(a=='J')return 15;
        if(a=='T')return 10;
        return a-'0';
    }
    
    if(a=='A')return 20;
    if(a=='K')return 15;
    if(a=='Q')return 15;
    if(a=='J')return 15;
    if(a=='T')return 10;
    return a-'0';
}

int main()
{
char arr[2000][5];
char arr2[2000][5];
int n,i,j;
int matrixCount[2000][2000];

    cin >>n;
    while(n>0)
    {
        for(i=1;i<=n;i++)
            cin >> arr[i];
        for(i=1;i<=n;i++)
            cin >> arr2[i];
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                matrixCount[i][j]=max(matrixCount[i-1][j],matrixCount[i][j-1]);
                if(arr[i][0]==arr2[j][0]||arr[i][0]=='R'||arr2[j][0]=='R')
                matrixCount[i][j]=max(matrixCount[i][j],matrixCount[i-1][j-1]+add(arr[i][0],arr2[j][0]));
            }
        }
        cout<<matrixCount[n][n]*2<<endl;
        cin >> n;
   }
   return 0;
        
}


