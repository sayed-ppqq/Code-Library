#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define  FIO        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  all(v)     v.begin(),v.end()
#define  rall(v)    v.rbegin(),v.rend()
#define  MEM(a,x)   memset(a,x,sizeof(a))
#define  bug        cout<<"bug"<<endl;
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
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset=tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

void Fileio(){freopen ("output.txt","w",stdout);freopen ("input.txt","r",stdin);}
inline ll powr(int n,int o){ll a=1;for(int i=0;i<o;i++)a*=n;return a;}
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
int bitree[100005],n;

void update(int idx,int val)
{
    while(idx<=n)
    {
        bitree[idx]+=val;
        idx+= idx&(-idx);   ///finding which index will get effected bcz of prev idx
    }
}

int query(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=bitree[idx];
        idx-= idx&(-idx);   ///finding indexes which covers the range
    }
    return sum;
}
int main()
{
    FIO;
    cin>>n;
    vii v(n+1);

    for(int i=1;i<=n;i++) cin>>v[i];

    for(int i=1;i<=n;i++) update(i,v[i]);

    cout<<query(5)<<endl;

    update(2,-8);

    cout<<query(5)<<endl;
}
