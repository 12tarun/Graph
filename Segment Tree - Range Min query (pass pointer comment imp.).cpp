#include<bits/stdc++.h>
using namespace std;
int *constructST(int arr[],int n);
int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        	cin>>A[i];
        int Q;
        cin>>Q;
        int *segTree = constructST(A,N);
        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    } 
}

int constructing(int st, int nd, int arr[], int tr[], int pos)
{
    if(st==nd)
    {
        tr[pos] = arr[st];
        return tr[pos];
    }
       
    int mid = (st+nd)/2;
    tr[pos] = min(constructing(st,mid,arr,tr,pos*2),constructing(mid+1,nd,arr,tr,(pos*2)+1));
    return tr[pos];      
}


int *constructST(int arr[],int n)
{
    int st = 0;
    int nd = n-1;
    int *tr = new int[(4*n)+2];    //way of returning pointer dynamic size
    int x = constructing(st,nd,arr,tr,1);
    return tr;
}
 
int findMin(int st[],int ss,int se,int qs,int qe,int pos)
{
    int mid = (ss+se)/2;
    if(ss>=qs && qe>=se)
    {
        return st[pos];
    }
    else if(se<qs || qe<ss)
    {
        return INT_MAX;
    }
    else
    {
        return min(findMin(st,ss,mid,qs,qe,pos*2),findMin(st,mid+1,se,qs,qe,(pos*2)+1));
    }
}
 
int RMQ(int st[], int n, int a, int b)
{
    int ss = 0;
    int se = n-1;
    return findMin(st,ss,se,a,b,1);
} 
