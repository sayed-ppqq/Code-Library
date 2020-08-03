#include<bits/stdc++.h>
using namespace std;

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
int ara[100000],K,sum,ans[100000],q,n;
struct Query
{
    int L,R,idx;
    bool operator < (const Query &other) const {
        int block_own=L/K;
        int block_other=other.L/K;

        if(block_other==block_own) return R<other.R;
        else return block_own<block_other;
    }
}query[100000];

void add(int idx)
{
    sum+=ara[idx];
}
void remove(int idx)
{
    sum-=ara[idx];
}
void MO()
{
    sort(query,query+q);
    int L=0,R=-1;
    for(int i=0;i<q;i++)
    {
        while(R<query[i].R) add(++R);
        while(L<query[i].L) remove(L++);
        while(R>query[i].R) remove(R++);
        while(L>query[i].L) add(--L);
        ans[query[i].idx]=sum;
    }
}
int main()
{
    cin>>n;
    K=sqrt(n);
    for(int i=0;i<n;i++) cin>>ara[i];

    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>query[i].L>>query[i].R;
        query[i].idx=i;
    }

    MO();

    for(int i=0;i<q;i++) cout<<ans[i]<<" ";
}
