#include <bits/stdc++.h>

using namespace std;

void merge_sort(int a[],int n)
{
    
    int mid=n/2;
    if(n>1)
        merge_sort(a,mid),merge_sort(a+mid,n-mid);
    
    int b[n];
    int i=0,j=mid,in=0;
    while(i<mid && j<n)
    {
        if(a[i]<a[j])b[in++]=a[i++];
        else b[in++]=a[j++];
    }
    while(i<mid)b[in++]=a[i++];
    while(j<n)b[in++]=a[j++];
    for(int i=0;i<n;i++)a[i]=b[i];
}

int main()
{
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    
    merge_sort(a,n);
    
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
}
