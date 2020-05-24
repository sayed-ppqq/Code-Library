#include<bits/stdc++.h>
using namespace std;
#define  FIO        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  all(v)     v.begin(),v.end()
#define  rall(v)    v.rbegin(),v.rend()
#define  MEM(a,x)   memset(a,x,sizeof(a))
#define  pi         acos(-1.0)
#define  ll     long long
#define  pb     push_back
#define  mp     make_pair
#define  pii    pair< int,int >
#define  pll    pair< ll,ll >
#define  vii    vector< int >
#define  vll    vector< ll >
#define  vpi    vector< pii >
#define  vpl    vector<pll>
#define  MX     100005
#define  EPS    1e-12
#define  ss     second
#define  ff     first
int cases=1;
#ifdef ppqq
     #define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " is " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cerr.write(names, comma - names) << " is " << arg1 <<"  ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
const int inf=1e9;
int main()
{
   //freopen ("output.txt","w",stdout);
   //freopen ("input.txt","r",stdin);
    FIO;
    int n;
    cin>>n;
    vii v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vii seq(n+1,inf);
    seq[0]=-inf;
    int sz=-1;
    for(int i=0;i<n;i++)
    {
        int pos=upper_bound(all(seq),v[i])-seq.begin();
        if(seq[pos-1]<v[i] && v[i]<seq[pos])
        {
            seq[pos]=v[i];
            sz=max(sz,pos);
        }
    }
    for(int i=0;i<=n;i++)
    {
        if(seq[i]<inf && seq[i] > -inf)
             cout<<seq[i]<<endl;
    }
    cout<<sz<<endl;
}

