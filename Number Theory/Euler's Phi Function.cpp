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
bool marked[MX+5];
vll primes;
void sieve()
{
   marked[0]=marked[1]=true;
   primes.pb(2);
   for(int i=3;i*i<MX;i+=2)
   {
       if(!marked[i])
       {
           for(int j=i*i;j<=MX;j+=i*2)
               marked[j]=true;
       }
   }
   for(int i=3;i<=MX;i+=2)
   {
       if(!marked[i])
        primes.pb(i);
   }
}
int euler_phi(int n)
{
    int ret=n;
    for(int i=0;primes[i]*primes[i]<=n;i++)
    {
        if(n%primes[i]==0)
        {
            while(n%primes[i]==0)
            {
                n/=primes[i];
            }
            ret-=ret/primes[i];
        }
    }
    if(n>1) ret-=ret/n;
    return ret;
}
int main()
{
    FIO;
    int t;
    sieve();
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int ans=euler_phi(n);
    cout<<ans<<endl;
    }
}
