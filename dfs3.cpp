// Same question 2 with simpler implementation
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
int a[N+2][N+2];
bool vis[N+2][N+2];
ll s;
int dir[][2]={{1,0},{0,1},{-1,0},{0,-1}};      // the direction we can move from the current node

ll dfs(int i,int j)
{
    if(a[i][j]==0)                            // we can't move over 0
        return 0;
        
    if(!vis[i][j])
    {
        vis[i][j]=true;
        rep(d,0,4)
        {
            dfs(i+dir[d][0],j+dir[d][1]);     // here (i+dir[d][0],j=dir[d][1]) are indices of nodes in all four directions
        }
        s+=a[i][j];
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

    ll ans=-INF;
    rep(i,1,n+1)
    {
        rep(j,1,n+1)
        {
            if(a[i][j]!=0)
            {
                s=0;
                dfs(i,j);
                ans=max(ans,s);
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
