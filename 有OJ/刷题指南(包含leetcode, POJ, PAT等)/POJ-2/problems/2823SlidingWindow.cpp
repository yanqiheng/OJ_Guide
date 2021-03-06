#include<iostream>
#include<stdio.h>
#include<deque>
using namespace std;
deque<int> qmin;
deque<int> qmax;
void insert(deque<int> &q,int x,int max_huh)
{
    if(max_huh)
    {
        while(!q.empty() && x> q.back()) q.pop_back();
        q.push_back(x);
    }
    else{
        while(!q.empty() && x < q.back()) q.pop_back();
        q.push_back(x);
    }
}
void remove(deque<int> &q,int x)
{
    if(!q.empty() && x==q.front()) q.pop_front();
}
int A[1000000];
int main()
{
    int n,k,x;
    
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",A+i);
    
    if(k>n) k=n;
    for(int i=0;i<k;i++)
        insert(qmin,A[i],0);
    printf("%d",qmin.front());
    for(int i=k;i<n;i++)
    {
        
        remove(qmin,A[i-k]);
        insert(qmin,A[i],0);
        printf(" %d",qmin.front());
    }
    printf("\n");
    for(int i=0;i<k;i++)
        insert(qmax,A[i],1);
    printf("%d",qmax.front());
    for(int i=k;i<n;i++)
    {
        
        remove(qmax,A[i-k]);
        insert(qmax,A[i],1);
        printf(" %d",qmax.front());
    }
    printf("\n");
    return 0;
}
