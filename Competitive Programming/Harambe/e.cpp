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
		string s;
		cin >> s;
		bool last = false, ans = false;
		for(int i = 0 ; i < s.size() ; i++){
			if(s[i] == '?')
				continue;
			if(last and s[i] == 'U')
				ans = true;
			if(s[i] == 'M')
				last = true;
		}
		if(ans)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return(0);
}