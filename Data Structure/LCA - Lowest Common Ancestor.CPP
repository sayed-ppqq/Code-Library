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
vii adj[300005];
int parent[300005];
int depth[300005],n;
int spars_table[300005][10];

void dfs(int u,int p)
{
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if(v!=p)
        {
            parent[v]=u;
            depth[v]=depth[u]+1;
            dfs(v,u);
        }
    }
}

void create_spars_table()
{
    MEM(spars_table,-1);
    for(int i=1;i<=n;i++)
    {
        ///2^0 POSITION IS ACTUALLY PARENT NODE
        spars_table[i][0]=parent[i];
    }
    for(int i=1;(1<<i)<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int u=spars_table[j][i-1];
            if(u!=-1)
            spars_table[j][i]=spars_table[u][i-1]; ///2^N=(2^N-1 OF 2^N-1 POSITION)
        }
    }
}
int lca(int u,int v)
{
    if(depth[u]!=depth[v])
    {
        ///LEVEL_UP
        if(depth[v]>depth[u]) swap(u,v);
        int dif=depth[u]-depth[v];
        while(dif>0)
        {
        int log=log2(dif);
        u=spars_table[u][log];
        dif-=(1<<log);
        }
    }
    if(u==v) return u;
    int log=0;
    while(1)
    {
        ///SETTING_LOG_VALUE
        int next=log+1;
        if((1<<next)>n) break;
        log++;
    }
    for(int i=log;i>=0;i--)
    {
        ///FINAL_COUNTING
        if(spars_table[u][i]!=-1 && spars_table[u][i]!=spars_table[v][i])
        {
            u=spars_table[u][i];
            v=spars_table[v][i];
        }
    }
    return parent[u];
}

int main()
{
   //freopen ("output.txt","w",stdout);
   //freopen ("input.txt","r",stdin);
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int m;
            cin>>m;
            for(int j=0;j<m;j++)
            {
                int x;
                cin>>x;
                adj[i].pb(x);
                adj[x].pb(i);
            }
        }
        parent[1]=1;
        dfs(1,1);
        create_spars_table();
        int q;
        cin>>q;
        vii ans;
        while(q--)
        {
            int u,v;
            cin>>u>>v;
            ans.pb(lca(u,v));
        }
        cout<<"Case "<<cases++<<":"<<endl;
        for(auto it: ans) cout<<it<<endl;
        MEM(depth,0);
        MEM(parent,0);
        for(int i=0;i<1005;i++) adj[i].clear();
    }

}
