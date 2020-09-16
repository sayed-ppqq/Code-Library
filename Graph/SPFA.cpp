#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define  FIO        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  Fileio     freopen("output.txt","w",stdout);freopen("input.txt","r",stdin);
#define  all(v)     v.begin(),v.end()
#define  rall(v)    v.rbegin(),v.rend()
#define  MEM(a,x)   memset(a,x,sizeof(a))
#define  SZ(v)      v.size()
#define  nl         "\n"
#define  bug        cout<<"bug"<<nl;
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

inline ll powr(int a,int b){ll res=1;while(b){if(b&1) res*=a;a*=a;b/=2;}return res;}
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

///Problem : LJ-1074

int inf=INT_MAX/3;
int A[205],dis[205],modify[205];
bool vis[205],in[205];
vector<pair<int,int>> adj[205];

int cube(int x) { return x*x*x; }

void dfs(int u)
{
    vis[u]=true;
    for(auto it: adj[u])
    {
        if(!vis[it.ff]) dfs(it.ff);
    }
}

void SPFA(int src,int n)
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=inf;
        modify[i]=0;
        vis[i]=false;
        in[i]=false;
    }

    queue<int> q;
    q.push(src);
    in[src]=true;
    modify[src]++;
    dis[src]=0;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        in[u]=false;
        for(auto it: adj[u])
        {
            if(vis[it.ff]) continue;
            if(dis[it.ff]>dis[u]+it.ss)
            {
                dis[it.ff]=dis[u]+it.ss;
                if(!in[it.ff])
                {
                    q.push(it.ff);
                    in[it.ff]=true;
                    modify[it.ff]++;
                    if(modify[it.ff]>n) //negative cycle found
                        dfs(it.ff);  //mark all node which is under this negative cycle
                }
            }
        }
    }
}

void CLR(int n)
{
    for(int i=0;i<n+2;i++)
    {
        adj[i].clear();
        A[i]=0;
    }
}
int main()
{
    int t,n,m,q;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&A[i]);
        scanf("%d",&m);

        for(int i=0,x,y,w;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            w=cube(A[y]-A[x]);
            adj[x].pb({y,w});
        }

        SPFA(1,n);

        printf("Case %d:\n",cases++);
        scanf("%d",&q);
        while(q--)
        {
            int k;
            scanf("%d",&k);
            if(dis[k]<3 || vis[k] || dis[k]==inf) printf("?\n");
            else printf("%d\n",dis[k]);
        }
        CLR(n);
    }
}
