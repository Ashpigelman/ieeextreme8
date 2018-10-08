#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    double answer;
    double p[1000] ;
    cin >> n;
    while(n >= 0)
    {
        if(n==0)break;
        answer=0;
        for(int i=1; i<n; i++)
            cin>>p[i];
        double now = 1;
        double answer = 1;
        for(int i=n-1;i>=1;i--)
        {
            now /= p[i];
            answer += now;
        }
        
        cout << (int)(answer+0.5) << endl;
        cin>> n;
    }
    return 0;
}