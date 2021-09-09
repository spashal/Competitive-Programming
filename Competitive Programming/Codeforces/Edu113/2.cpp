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
	while( t-- ){
		cin >> n;
		string s;
		cin >> s;
		vector<int> win;
		for(int i = 0 ; i < n ; i++)
			if(s[i] == '2')
				win.pb(i);
		if(win.size() == 1 or win.size() == 2)
			cout << "NO" << endl;
		else{
			cout << "YES\n";
			vector<vector<char> > ans(n, vector<char> (n, '='));
			if(win.size() > 2){
				for(int i = 0 ; i < win.size()-1 ; i++){
					ans[win[i]][win[i+1]] = '+';
					ans[win[i+1]][win[i]] = '-';
				}
				ans[win[win.size()-1]][win[0]] = '+';
				ans[win[0]][win[win.size()-1]] = '-';
			}
			for(int i = 0 ; i < n ; i++)
				ans[i][i] = 'X';
			for(int i = 0 ; i < n ; i++){
				for(int j = 0 ; j < n ; j++)
					cout << ans[i][j];
				cout << endl;
			}
		}
	}
	return(0);
}