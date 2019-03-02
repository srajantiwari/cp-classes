// Find the largest value in the subtree and the value attached to node, for every node in the tree.
// Input
// First line contains number of nodes "n"
// Second line contains "n" space seperated integers, values attached to each node
// Third line contains single integer "m" representing number of edges in graph
// Next "m" lines represent node "a" is connected to "b"

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

const int N=10;        // maximum number of nodes which can be inserted
vector <int> adj[N];  // stores our graph
ll w[N];               // stores the value connected to each node
ll ans[N];             // stores the answer for every node
bool vis[N];           // stores whether the node is visited or not

ll dfs(int a)          // returns the maximum value found in the subtree of the node
{
    for(auto i : adj[a])
    {
        if(!vis[i])
        {
            vis[i]=true;
            ans[a]=max(ans[a],dfs(i));
        }
    }
    ans[a]=max(ans[a],w[a]);
    return ans[a];
}

int main()
{
    int n;cin>>n;
    rep(i,1,n+1)
    {
        cin>>w[i];
    }

    int m;cin>>m;
    rep(i,0,m)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
    }

    dfs(1);

    rep(i,1,n+1)
    {
        cout<<ans[i]<<" ";
    }
}


// Example
// Input
// 7
// 5 2 2 7 1 8 3
// 6
// 1 2
// 1 3
// 2 4
// 2 5
// 2 6
// 3 7
// Output
// 8 8 3 7 1 8 3
