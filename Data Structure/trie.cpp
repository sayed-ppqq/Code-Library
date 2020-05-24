#include<bits/stdc++.h>
using namespace std;
#define  FIO        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  all(v)     v.begin(),v.end()
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
struct node
{
    bool endpoint;
    node *next[27+1];
    node()
    {
        endpoint=false;
        for(int i=0;i<26;i++)
        {
            next[i]=NULL;
        }
    }
};
node *root;
void insert ( string s )
{
    node *cur=root;
    for(int i=0;i<s.size();i++)
    {
        int id=s[i]-'a';
        if(cur->next[id] == NULL)
            cur->next[id] = new node();
        cur=cur->next[id];
    }
    cur->endpoint=true;
}
bool search ( string s )
{
    node *cur = root;
    for(int i=0;i<s.size();i++)
    {
        int id=s[i]-'a';
        if(cur->next[id] == NULL)
            return false;
        cur=cur->next[id];
    }
    return cur->endpoint;
}
void del ( node *cur )
{
    for(int i=0;i<26;i++)
    {
        if(cur->next[i])
            del(cur->next[i]);
    }
    delete ( cur );
}
int main()
{
   //freopen ("output.txt","w",stdout);
   //freopen ("input.txt","r",stdin);
    FIO;
    root = new node();
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        insert(s);
    }
    int q;
    cin>>q;
    while(q--)
    {
        string s;
        cin>>s;
        cout<<search(s);
    }
}

