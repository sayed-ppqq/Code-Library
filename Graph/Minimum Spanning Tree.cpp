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
struct info
{
    int u,v,w;
};
vector<info> graph;
int par[MX];
bool cmp(const info&a,const info&b)
{
    if(a.w<b.w) return true;
    return false;
}
int find_set(int v)
{
    if(v==par[v]) return v;
    return par[v]=find_set(par[v]);
}

int MST(int n)
{
    for (int i = 1; i <= n; i++)
        par[i] = i;
    sort(all(graph),cmp);
    int sum=0,cnt=0;
    for(int i=0;i<graph.size();i++)
    {
        int a=find_set(graph[i].u);
        int b=find_set(graph[i].v);
        if(a!=b)
        {
            par[a]=b;
            cnt++;
            sum+=graph[i].w;
        }
        if(cnt==n-1) break;
    }
    return sum;
}

int main()
{
   //freopen ("output.txt","w",stdout);
   //freopen ("input.txt","r",stdin);
    FIO;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        info temp;
        temp.u=u;
        temp.v=v;
        temp.w=w;
        graph.pb(temp);
    }
    cout<<MST(n);
}
