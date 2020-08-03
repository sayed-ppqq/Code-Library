#include<bits/stdc++.h>
using namespace std;

///ref: http://www.shafaetsplanet.com/?p=3416

///******************************************START******************************************

int ara[100000],segment[100000],n;

void preprocess()
{
    int seg_size=sqrt(n),cur_seg=-1;
    for(int i=0;i<n;i++)
    {
        if(i%seg_size==0) cur_seg++;
        segment[cur_seg]+=ara[i];
    }
}
///0 based
int query(int l,int r)
{
    int seg_size=sqrt(n),sum=0;

    ///loop until first complete segment
    while(l<r && l%seg_size!=0)
    {
        sum+=ara[l];
        l++;
    }

    ///loop for all complete segment
    while(l+seg_size<=r)
    {
        int cur_seg=l/seg_size;
        sum+=segment[cur_seg];
        l+=seg_size;
    }

    ///after all complete segment extra part
    while(l<=r)
    {
        sum+=ara[l];
        l++;
    }
    return sum;
}
///0 based
void update(int idx,int val)
{
    int seg_size=sqrt(n);
    segment[idx/seg_size]-=ara[idx];
    segment[idx/seg_size]+=val;
    ara[idx]=val;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>ara[i];

    preprocess();

    cout<<query(0,3)<<endl;
    update(0,2);
    cout<<query(0,3);
}
