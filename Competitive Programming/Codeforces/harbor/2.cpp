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


int fun(string s, string t, int i, int j, int can, vector<vector<vector<int> > > &ans){
	// cout << i << " " << j << endl;
	
	if(j != t.size() and (i >= s.size() or i < 0 or j < 0 or s[i] != t[j])){
		// ans[i][j][can] = -1;
		return -1;
	}
	// cout << "1 ##" << endl;
	if(i >= 0 and i <= s.size() and j >= 0 and j <= t.size() and ans[i][j][can] != 0)
		return ans[i][j][can];
	// cout << "2##" << endl;
	if(j == t.size()){
		return 1;
	}
	
	if(can > 0 and fun(s, t, i+1, j+1, 1, ans) > 0){
		ans[i][j][can] = 1;
		return 1;
	}
	else if(fun(s, t, i-1, j+1, 0, ans) > 0){
		ans[i][j][can] = 1;
		return 1;
	}
	ans[i][j][can] = -1;
	return -1;
}


	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		string s, t;
		cin >> s;
		cin >> t;
		vector<vector<vector<int> > > ans(s.size()+5, vector< vector<int> > (t.size() + 5, vector<int> (2, 0)));

		n = s.size();
		bool found = false;
		for(int i = 0 ; i < n ; i++){
			if(fun(s, t, i, 0, 1, ans) > 0){
				cout << "Yes\n";
				found = true;
				break;
			}
			// cout << endl;
		}
		if(!found)
			cout << "No\n";
	}
	return(0);
}