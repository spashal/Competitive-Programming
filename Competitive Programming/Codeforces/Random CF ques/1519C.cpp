#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005];
vector< ll > adj[200005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}
#define pb push_back
#define ss second
#define ff first
#define fs first.second
#define fff first.first
#define sss second.second
#define sf second.first
#define mp make_pair
void printar(vector< ll > ar, ll l, ll r){
	for(int i = l ; i < r ; i++)
		cout << ar[i] << " ";
	cout << endl;
}
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
      cin >> n;
      vector< ll > temp1(n), temp2(n);
      for(int i = 0 ; i < n ; i++)
		cin >> temp1[i];            
      for(int i = 0 ; i < n ; i++)
      	cin >> temp2[i];
      for(int i = 0 ; i < n ; i++)
      	adj[temp1[i]].pb(temp2[i]);
      vector< vector< ll > > sums(n + 1);
      vector< ll > ans(n+1, 0);
      for(int i = 1 ; i <= n ; i++){
            if(adj[i].size() == 0)
                  continue;
            sums[i].resize(adj[i].size(), 0);
            sort(adj[i].begin(), adj[i].end(), greater< int > ());
            sums[i][0] = adj[i][0];
            for(int j = 1 ; j < adj[i].size() ; j++)
                  sums[i][j] = sums[i][j-1] + adj[i][j];
            for(int j = 1 ; j <= adj[i].size() ; j++){
                  ans[j] += sums[i][adj[i].size() - (adj[i].size() % j) - 1];
            }      
      }
      for(int i = 1 ; i <= n ; i++){
            cout << ans[i] << " ";
            adj[i].clear();
      }
      cout << endl;
    }
    return(0);
}