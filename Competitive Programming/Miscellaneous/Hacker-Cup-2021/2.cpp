#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t;
vector< ll > adj[26];
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
	
void fun(int c, vector<int> &tr, int costYet){
	for(int i = 0 ; i < adj[c].size() ; i++)
		if(true){
			if(tr[adj[c][i]] == -1)
				tr[adj[c][i]] = costYet+1;
			else if(tr[adj[c][i]] > costYet+1){
				tr[adj[c][i]] = min(tr[adj[c][i]], costYet+1);
			}
			else
				continue;
			fun(adj[c][i], tr, costYet+1);
		}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	for(int kk = 1 ; kk <= t ; kk++){
		string s, a, b;
		int k;
		cin >> s >> k;
		for(int i = 0 ; i < k ; i++){
			string ak;
			cin >> ak;
			adj[ak[0]-'A'].pb(ak[1]-'A');
		}
		n = s.size();

		vector<vector<int> > transition(n, vector<int> (26, -1));

		for(int i = 0 ; i < n ; i++)
			transition[i][s[i]-'A'] = 0;

		for(int i = 0 ; i < n ; i++){
			map<pair<int,int>,bool> vis;
			fun(s[i]-'A', transition[i], 0);
		}

		int ans = 10000000;
		for(int i = 0 ; i < 26 ; i++){
			int cost = 0, ctr = 0;
			for(int j = 0 ; j < n ; j++){
				if(transition[j][i] >= 0)
					cost += transition[j][i];
				else
					ctr++;
			}
			if(ctr == 0)
				ans = min(ans, cost);
		}

		if(ans == 10000000)
			ans = -1;

		cout << "Case #" << kk << ": " << ans << endl;
		for(int i = 0 ; i < 26 ; i++)
			adj[i].clear();
	}
	return(0);
}