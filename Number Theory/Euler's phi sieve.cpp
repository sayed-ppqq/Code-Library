#include<bits/stdc++.h>
using namespace std;
#define  FIO        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  all(v)     v.begin(),v.end()
#define pi     acos(-1.0)
#define  ll     long long
#define  pb     push_back
#define  pii    pair< int,int >
#define  pll    pair< ll,ll >
#define  vii    vector< int >
#define  vll    vector< ll >
#define  vpi    vector< pii >
#define  MX     100005
#define  INF    10000000000000000
#define  EPS    1e-12
#define  ss     second
#define  ff     first
int phi[MX];
phiSieve()
{
    for(int i=1;i<=MX;i++)
    {
        phi[i]=i;
    }
    for(int p=2;p<=MX;p++)
    {
        if(phi[p]==p)
        {
            for(int k=p;k<=MX;k+=p)
            {
                phi[k]-=phi[k]/p;
            }
        }
    }
    for(int i=1;i<=MX;i++)
        cout<<phi[i]<<" ";
}
int main()
{
    FIO;
    phiSieve();
}
