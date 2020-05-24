#include<bits/stdc++.h>
using namespace std;
#define  FIO        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  all(v)     v.begin(),v.end()
#define  ll     long long
#define  ld     long double
#define  pb     push_back
#define  pii    pair< int,int >
#define  pll    pair< ll,ll >
#define  vii    vector< int >
#define  vll    vector< ll >
#define  vss    vector< string >
#define  vdd    vector< double >
#define  vpi    vector< pii >
#define  vpl    vector< pll >
#define  vvi    vector< vii >
#define  vvl    vector< vll >
#define  MX     1000000000
#define  INF    10000000000000000
#define  EPS    1e-12
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
int main()
{
    FIO;
    sieve();
    int t;
    cin>>t;
    cout<<t;
    while(t--)
    {
        int n;
        cin>>n;
        vii v(3);
        int cc=0;
        int k=0;
        int divisor = 1;
  for (int i = 0; primes[i]*primes[i]<=n; i++) {
    if (n % primes[i] == 0) {
            cc++;
      int cnt = 0;
      while (n % primes[i] == 0) {
        n /= primes[i];
        cnt++;
        v[k]*=primes[i];
      }
      k++;
    }
  }
  if(n) v[k]=n;
  if(cc==3)
  {
      cout<<"YES\n";
      for(int i=0;i<3;i++) cout<<v[i];
  }
  else cout<<"NO\n";

    }
}


