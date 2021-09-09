#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005];
vector< ll > adj[100005];
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
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
	for(int i = 1 ; i <= t ; i++){
		int r, c;
		cin >> r >> c;
		priority_queue<pair<int,pair<int,int> > > pq;
		vector<vector<int> > matrix(r, vector<int> (c, 0));
		for(int j = 0 ; j < r ; j++)
			for(int k = 0 ; k < c ; k++){
				cin >> matrix[j][k];
				pq.push(mp(matrix[j][k], mp(j, k)));
			}
		vector<vector<bool> > vis(r, vector<bool> (c, false));
		int ans = 0;
		while(!pq.empty()){
			pair<int, int> cur = pq.top().ss;
			pq.pop();
			if(vis[cur.ff][cur.ss])
				continue;
			vis[cur.ff][cur.ss] = true;
			for(int j = 0 ; j < 4 ; j++){
				int x = cur.ff+dx[j], y = cur.ss + dy[j];
				if(x >= 0 and x < r and y >= 0 and y < c and !vis[x][y]){
					if(matrix[x][y] < matrix[cur.ff][cur.ss]){
						ans += matrix[cur.ff][cur.ss] - matrix[x][y] - 1;
						matrix[x][y] = matrix[cur.ff][cur.ss] - 1;
						pq.push(mp(matrix[x][y], mp(x, y)));
					}
				}
			}
		}
		cout << "Case #" << i << ": " << ans << endl;
	}
	return(0);
}