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
    t = 1;
	while( t-- ){
		cin >> n;
		ari;
		vector< int > yet(n, 0);
		yet[0] = a[0];
		vector< int > ones, emp;
		if(a[0])
			ones.pb(0);
		else
			emp.pb(0);
		for(int i = 1 ; i < n ; i++){
			yet[i] = yet[i - 1] + a[i];
			if(a[i])
				ones.pb(i);
			else
				emp.pb(i);
		}
		vector< vector< ll > > dp(ones.size(), vector< ll > (emp.size(), (ll)(1e11)));
		for(int i = 0 ; i < ones.size() ; i++)
			for(int j = i ; j < emp.size() ; j++){
				if(i == 0){
					if(j > 0)
						dp[i][j] = min(dp[i][j-1], llabs(ones[i]-emp[j]));
					else
						dp[i][j] = llabs(ones[i]-emp[j]);
					continue;
				}
				dp[i][j] = min(dp[i][j-1], dp[i-1][j-1] + llabs(ones[i]-emp[j]));
			}
		ll mini = 1e11;
		if(ones.size() == 0)
			cout << "0" << endl;
		else{
			for(int i = 0 ; i < emp.size() ; i++)
				mini = min(mini, dp[ones.size() - 1][i]);
			cout << mini << endl;
		}
	}
	return(0);
}