/*
Given array a of n integers.given q queries and in each query given l and r print sum of arrays element from l to r(l and r inclusive)
constraints 
1<=n<=10^5
1<= a[i]  <= 10^9
1<=Q <= 10^5
1=<l,r<=10^5
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,ps[10001],ar[10001],n,i;
    cin>>n;
    for(i=0;i<n;i++) 
    cin>>ar[i];
    for(i=1;i<=n;i++) 
    ps[i]=ps[i-1]+ar[i-1];
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        cout<<ps[r]-ps[l-1]<<endl;
    }
}