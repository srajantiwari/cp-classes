// Find the maximum sum of connected components in a (n x n) matrix given that you never move over "0".
// Input
// First line contains a single integer n representing number of rows and columns in n
// Next n lines contains n space seperated integers resprenting values of node

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define mem(dp,a)           memset(dp,a,sizeof dp)
#define rep(i,a,b)          for(int i=a;i<b;i++)
#define repb(i,a,b)         for(ll i=a;i>=b;i--)
#define f(n)                for (ll i=0;i<n;i++)
#define pb(x)               push_back(x)
#define mp(x,y)             make_pair(x,y)
#define tr(c,it)            for(auto const & it : c)
#define xlr8                ios_base::sync_with_stdio(false);cin.tie(NULL)
#define sz(c)               (c).size()
#define all(c)              (c).begin(),(c).end()
#define sl(a)               scanf("%lld",&a);
#define TH                  1000
#define F                   first
#define S                   second
ll MOD=pow(10,9)+7;
ll INF=1e18+10;

const int N=10;
int a[N+2][N+2];     // matrix
bool vis[N+2][N+2];  // stores whether node is visted or not
ll s;                // sum which can be achieved for a connected component

ll dfs(int i,int j)
{
    if(a[i][j]==0)          // We can't move over 0
        return 0;
        
    if(!vis[i-1][j])        // if node left to current node is not visited then visit it
    {
        vis[i-1][j]=true;   // change visted state from unvisited to visited
        dfs(i-1,j);         // start visiting nodes connected to this node
        s+=a[i-1][j];       // add the value of the current node to the answer for current connected component
    }
    
    if(!vis[i+1][j])        // if node above current node is not visited then visit it
    {
        vis[i+1][j]=true;
        dfs(i+1,j);
        s+=a[i+1][j];
    }
    
    if(!vis[i][j+1])        // if node below the current node is not visited then visit it
    {
        vis[i][j+1]=true;
        dfs(i,j+1);
        s+=a[i][j+1];
    }
    
    if(!vis[i][j-1])        // if node right to current node is not visited then visit it
    {
        vis[i][j-1]=true;
        dfs(i,j-1);
        s+=a[i][j-1];
    }
}

int main()
{
    int n;cin>>n;
    rep(i,1,n+1)
    {
        rep(j,1,n+1)
        cin>>a[i][j];
    }

    ll ans=-INF;                  // answer to the problem
    rep(i,1,n+1)
    {
        rep(j,1,n+1)
        {
            if(a[i][j]!=0)
            {
                s=0;              // every we find a non zero element we consider it as a new connected component, hence s=0
                dfs(i,j);         // visit it if unvisited
                ans=max(ans,s);   // ans will be the maximum of all the connected components' values
            }
        }
    }
    cout<<ans<<endl;
}

/*
Input
4
1 0 2 3
0 5 1 0
9 0 0 3
2 4 0 2

Output
15
*/
