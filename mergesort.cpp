#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void merge(int arr[],int l,int mid, int u)
{
    int n1=mid-l+1;
    int n2=u-mid;
    int a[n1];
    int b[n2];
    for(int i=0;i<n1;i++)
        a[i]=arr[l+i];
    for(int i=0;i<n2;i++)
        b[i]=arr[mid+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
            arr[k++]=a[i++];
        else
            arr[k++]=b[j++];
    }
    while(i!=n1)
        arr[k++]=a[i++];
    while(j!=n2)
        arr[k++]=b[j++];
}
void mrgsrt(int arr[],int l, int u)
{
    if(l<u)
    {
        int mid=(l+u)/2;
        mrgsrt(arr,l,mid);
        mrgsrt(arr,mid+1,u);
        merge(arr,l,mid,u);
    }
}
int main()
{
    int t=1;
    //cin>>t;
    while(t--)
    {
        int a[]={23,42,4,34,4};
        mrgsrt(a,0,4);
        for(int i=0;i<5;i++)
        {
            cout<<a[i]<<" ";
        }
    }
    return 0;
}
