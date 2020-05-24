#include<bits/stdc++.h>
using namespace std;
#define  FIO        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  all(v)     v.begin(),v.end()
#define  rall(v)    v.rbegin(),v.rend()
#define MEM(a,x)    memset(a,x,sizeof(a))
#define pi          acos(-1.0)
#define  ll     long long
#define  pb     push_back
#define  mp     make_pair
#define  pii    pair< int,int >
#define  pll    pair< ll,ll >
#define  vii    vector< int >
#define  vll    vector< ll >
#define  vpi    vector< pii >
#define  MX     100005
#define  EPS    1e-12
#define  ss     second
#define  ff     first
#define ppqq
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
int v[100005];
const int inf=200000;
int tree[400005];
void build(int node,int s,int e)
{
    if(s==e) tree[node]=v[s-1];
    else
    {
        int mid=(s+e)/2;
        build(2*node,s,mid);
        build((2*node)+1,mid+1,e);
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}
int query(int node,int s,int e,int l,int r)
{
    if(e<l || s>r) return inf;
    if(s>=l && e<=r) return tree[node];
    int mid=(s+e)/2;
    return min(query(2*node,s,mid,l,r),query(2*node+1,mid+1,e,l,r));
}
void update(int node,int s,int e,int pos,int value)
{
    if(s==e) tree[node]=value;
    else
    {
        int mid=(s+e)/2;
        if(pos<=mid) update(2*node,s,mid,pos,value);
        else update(2*node+1,mid+1,e,pos,value);
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}
int main()
{
//   freopen ("output.txt","w",stdout);
//   freopen ("input.txt","r",stdin);
    FIO;

    cin>>t;
    debug(t);
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        build(1,1,n);
        cout<<"Case "<<cases++<<":"<<endl;
        while(q--)
        {
            int lft,rgt;
            cin>>lft>>rgt;
            cout<<query(1,1,n,lft,rgt)<<endl;
        }
    }
}
