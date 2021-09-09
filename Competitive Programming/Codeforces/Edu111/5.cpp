#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, t, a[100005];
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
    t = 1;
	while( t-- ){
		ll k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<vector<pair<ll,ll> > > dp(k, vector<pair<ll,ll> > (k, mp(0, 0)));
		if(s[0] != '?')
			for(int j = 0 ; j < k ; j++)
				for(int l = 0 ; l < k ; l++){
					if(l == s[0]-'a'){
						dp[j][l].ss += 1;
						dp[j][l].ff = 1;
					}
					else
						dp[j][l].ss = 0;
				}
		else		
			for(int j = 0 ; j < k ; j++){
				// assume that j will be placed at i
					 for(int m = 0 ; m < k ; m++){
					 	if(j == m){
					 		dp[j][m].ss = 1;
					 		dp[j][m].ff = 1;
					 	}
					 }
			}

		for(int i = 1 ; i < n ; i++){
			vector<vector<pair<ll,ll> > > temp(k, vector<pair<ll,ll> > (k, mp(0, 0)));
			temp = dp;
			if(s[i] != '?'){
				for(int j = 0 ; j < k ; j++)
					for(int l = 0 ; l < k ; l++){
						if(l == s[i]-'a'){
							dp[j][l].ss += 1;
							dp[j][l].ff = max(dp[j][l].ff, dp[j][l].ss);
						}
						else
							dp[j][l].ss = 0;
					}
			}
			else{
				for(int j = 0 ; j < k ; j++){
					// assume that j will be placed at i
					for(int l = 0 ; l < k ; l++){
						 for(int m = 0 ; m < k ; m++){
						 	if(j == m){
						 		dp[l][m].ss = temp[l][m].ss+1;
						 		dp[l][m].ff = max(temp[l][m].ss, dp[l][m].ff);
						 	}
						 }
					}
				}
			}

			for(int j = 0 ; j < k ; j++){
				for(int l = 0 ; l < k ; l++)
					cout << dp[j][l].ff << " " << dp[j][l].ss << endl;
				cout << endl;
			}

		}
		ll ans = 0;
		for(int i = 0 ; i < k ; i++){
			ll temp = INT_MAX;
			for(int j = 0 ; j < k ; j++)
				temp = min(temp, dp[i][j].ff);
			ans = max(ans, temp);
		}
		cout << ans << endl;
	}
	return(0);
}