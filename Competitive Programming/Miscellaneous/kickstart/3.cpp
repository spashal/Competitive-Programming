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
    ll tests = t;
    cin >> m;
	while( t-- ){
		long double w, e;
		cin >> w >> e;
		string ans;
		vector< vector< vector <long double> > > dp(61, vector< vector<long double> > (61, vector< long double> (61, 0)));
		char move[61][61][61];
		ld maxyet = 0.0;
		pair<int, pair<int,int> > details = mp(-1, mp(-1, -1));
		dp[1][0][0] = dp[0][1][0] = dp[0][0][1] = ((ld)1/3)*(w+e);
		for(int total = 2 ; total <= 60 ; total++){
			for(int p = 0 ; p <= total ; p++)
				for(int r = 0 ; r <= total - p ; r++){
					int s = total - p - r;
					ld Total = (ld)total, P = (ld)p, R = (ld)r, S = (ld)s;
					if(p > 0){
						if(dp[p][r][s] < dp[p-1][r][s] + max((ld)0, (S-1))/(Total-1)*w + max((ld)0, (R-1))/(Total-1)*e){
							dp[p][r][s] = dp[p-1][r][s] + max((ld)0, (S-1))/(Total-1)*w + max((ld)0, (R-1))/(Total-1)*e;
							move[p][r][s] = 'P';
						}
					}
					if(r > 0){
						if(dp[p][r][s] < dp[p][r-1][s] + max((ld)0, (P-1))/(Total-1)*w + max((ld)0, (S-1))/(Total-1)*e){
							dp[p][r][s] = dp[p][r-1][s] + max((ld)0, (P-1))/(Total-1)*w + max((ld)0, (S-1))/(Total-1)*e;
							move[p][r][s] = 'R';
						}
					}
					if(s > 0){
						if(dp[p][r][s] < dp[p][r][s-1] + max((ld)0, (R-1))/(Total-1)*w + max((ld)0, (P-1))/(Total-1)*e){
							dp[p][r][s] = max(dp[p][r][s], dp[p][r][s-1] + max((ld)0, (R-1))/(Total-1)*w + max((ld)0, (P-1))/(Total-1)*e);
							move[p][r][s] = 'S';
						}
					}
					if(total == 60){
						if(maxyet < dp[p][r][s]){
							maxyet = dp[p][r][s];
							details = mp(p, mp(r, s));
						}
					}
				}
			
		}
		ld sum = 60;
		while(sum){
			sum--;
			if(move[details.ff][details.sf][details.sss] == 'R'){
				details.sf -= 1;
				ans.pb('R');
			}
			else if(move[details.ff][details.sf][details.sss] == 'P'){
				details.ff -= 1;
				ans.pb('P');
			}
			else{
				details.sss -= 1;
				ans.pb('S');
			}
		}
		reverse(ans.begin(), ans.end());
		cout << "Case #" << tests-t << ": " << ans << endl;
	}
	return(0);
}