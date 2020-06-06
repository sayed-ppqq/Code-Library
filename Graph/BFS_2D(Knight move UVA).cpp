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

int knignt_movesX[8]={1,-1,1,-1,2,2,-2,-2};
int knight_movesY[8]={2,2,-2,-2,1,-1,1,-1};

int vis[10][10],dist[10][10];

void bfs(int x,int y)
{
    debug(x,y);
    vis[x][y]=1;
    dist[x][y]=0;
    queue<pii> q;
    q.push(mp(x,y));
    while(!q.empty())
    {
        pii p=q.front();
        q.pop();
        for(int i=0;i<8;i++)
        {
            int xx=p.ff+knignt_movesX[i];
            int yy=p.ss+knight_movesY[i];
            if(xx>=0 && yy>=0 && xx<8 && yy<8 && vis[xx][yy]==0)
            {
                vis[xx][yy]=1;
                dist[xx][yy]=dist[p.ff][p.ss]+1;
                q.push(mp(xx,yy));
            }
        }
    }
}
int main()
{
   //freopen ("output.txt","w",stdout);
   //freopen ("input.txt","r",stdin);
    FIO;
    string a,b;
    while(cin>>a>>b)
    {
        int x=a[0]-'a';
        int y=a[1]-'1';
        bfs(x,y);
        cout<<"To get from "<<a<<" to "<<b<<" takes "<<dist[b[0]-'a'][b[1]-'1']<<" knight moves."<<endl;
        MEM(dist,0);
        MEM(vis,0);
    }
}
