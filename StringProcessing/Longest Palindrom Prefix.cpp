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
class KMP
{
    public:
    vii LPS_Table(string pat)
    {
        vii lps(pat.size());
        int index=0;
        for(int i=1;i<pat.size();)
        {
            if(pat[i]==pat[index])
            {
                lps[i]=index+1;
                i++;
                index++;
            }
            else
            {
                if(index!=0) index=lps[index-1];
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps;
    }

    ll kmp(string text,string pattern)
    {
        ll cnt=0;
        vii lps;
        lps=LPS_Table(pattern);
        int i=0,j=0;
        while(i<text.size())
        {
            if(text[i]==pattern[j])
            {
                i++;
                j++;
            }
            else
            {
                if(j!=0) j=lps[j-1];
                else i++;
            }
            if(j==pattern.size())
            {
                cnt++;
                j=lps[j-1];
            }
        }

        return cnt;
    }

    int longest_palindrome_prefix_size(string s)
    {
        ///link: https://leetcode.com/problems/shortest-palindrome/discuss/60204/using-kmps-lps-longest-prefix-suffix-computation-to-solve-in-linear-on-time
        string rev=s;
        reverse(all(rev));
        s+='#';
        s+=rev;
        vii lps(s.size(),0);
        int index=0;
        for(int i=1;i<s.size();)
        {
            if(s[i]==s[index])
            {
                lps[i]=index+1;
                i++;
                index++;
            }
            else
            {
                if(index)
                {
                    index=lps[index-1];
                }
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
        /// after KMP's LPS pre-processing, the last index of the LPS array will contain the longest palindrome prefix' length!
        return lps[lps.size()-1];
    }
};
KMP obj;
int main()
{
   //freopen ("output.txt","w",stdout);
   //freopen ("input.txt","r",stdin);
    FIO;
    string s;
    cin>>s;
    cout<<obj.longest_palindrome_prefix_size(s);
}

