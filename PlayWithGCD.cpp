#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 100005;
const int mod = 1000000007;

int add(int x,int y)
{
    x+=y;
    if(x >= mod)
        x-=mod;
    return x;
}
int gcd(int x,int y)
{
    if(y==0)
        return x;
    return gcd(y,x%y);
}

int main()
{
    int n;
    int p[maxn],arr[maxn], sol[maxn];
    vector<int> v;
    map<int,int> hmap;
    long long two[maxn];
    cin >> n;
    for(int i=1; i<=n ; i++)
    {
        cin >> p[i];
        v.push_back(p[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=0; i<v.size(); i++)
        hmap[v[i]]=i;
    for(int i=1; i<=n ;i++)
        arr[hmap[p[i]]]++;
    two[0]=1;
    for(int i=1; i<=n ;i++)
        two[i]=two[i-1]*2%mod;
    for(int i=0; i<v.size() ;i++)
    {
        for(int j=1; j<=10000; j++)
            sol[gcd(j,v[i])]=add(sol[gcd(j,v[i])],1*(two[arr[i]]-1)*sol[j]%mod);
        sol[v[i]]=add(sol[v[i]],(two[arr[i]]-1));
    }
    int m;
    cin >> m;
    for(int i=1;i<=m;i++)
    {
        int x;
        cin >> x;
        cout << sol[x] << endl;
    }
    
    return 0;
}
