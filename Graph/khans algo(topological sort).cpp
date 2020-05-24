#include<bits/stdc++.h>
using namespace std;
#define  FIO        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define  all(v)     v.begin(),v.end()
#define MEM(a,x)    memset(a,x,sizeof(a))
#define One(x)      __builtin_popcount(x)
#define Unique(v)    v.erase(unique(v.begin(),v.end()),v.end())
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

///******************************************START******************************************
int vis[105];
vii graph[105];
stack<int>st;
void dfs(int x)
{

    vis[x]=true;

    for(int i=0;i<graph[x].size();i++)
    {

        int u=graph[x][i];

        if(vis[u]==false)
        {

            dfs(u);
        }
    }

    st.push(x);

}
int main()
{
//   freopen ("output.txt","w",stdout);
//   freopen ("input.txt","r",stdin);
//    FIO;
    int q;
    while(cin>>q)
    {
//        MEM(vis,0);
        vii indegree;
        indegree.resize(q);
        for(int i=0;i<105;i++)
            graph[i].clear();
        map<string,int>m1;
        map<int,string>m2;
        for(int i=1;i<=q;i++)
        {
            string s;
            cin>>s;
            m1[s]=i;
            m2[i]=s;

        }
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            string x,y;
            cin>>x>>y;
            graph[m1[x]].pb(m1[y]);
            indegree[m1[y]]++;
        }
        queue<int> qu;
        for(int i=1;i<=q;i++)
        {
            if(indegree[i]==0) qu.push(i);
        }
        vii order;
        int c=0;
        while(!qu.empty())
        {
            int u=qu.front();
            qu.pop();
            order.pb(u);
            for(int i=0;i<graph[u].size();i++)
            {
                int v=graph[u][i];
                indegree[v]--;
                if(indegree[v]==0) qu.push(v);
            }
            c++;
        }
        if(c!=n)
        {
            cout<<"cycle";
            return 0;
        }
        cout<<"Case #"<<cases++<<": Dilbert should drink beverages in this order: ";
        int sz=order.size();
        for(int i=0;i<sz;i++)
        {
            cout<<m2[order[i]];
            if(i!=sz-1) cout<<" ";
        }
        cout<<"."<<endl;
    }
}

