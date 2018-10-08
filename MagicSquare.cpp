#include <cmath>
#include <iostream>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int matrix[601][601];
    vector<int> res;
    int n;
    int countDig=0;

    cin >> n;
    for(int i=0; i < n ; i++)
    {
        for(int j=0; j < n ; j++)
        {
            cin >> matrix[i][j];
        }
    }
    
    //diag:
    for(int i=0; i<n ; i++)
    {
        countDig +=matrix[i][i];
    }
    
    //colunum:
    for(int i=n-1; i >=0 ; i--)
    {
        int sumCol=0;
        for(int j=0 ; j < n ; j++)
        {
            sumCol += matrix[j][i];
        }
        if(countDig != sumCol )
            res.push_back(-i-1);
    }
    
    //antidiag;
    int sumAntiDig=0;
    for(int i=0; i<n ; i++)
    {
        sumAntiDig +=matrix[i][n-i-1];
    }
    if(countDig != sumAntiDig)
        res.push_back(0);
    
    //row:
    for(int i=0; i<n ; i++)
    {
        int sumRow=0;
        for(int j=0 ; j<n ; j++)
        {
            sumRow += matrix[i][j];
        }
        if(countDig != sumRow)
            res.push_back(i+1);
    }
    
    cout << res.size()<<endl;
    
    for(int i=0; i<res.size() ; i++)
        cout<< res[i] << endl;
    
    
    return 0;
}