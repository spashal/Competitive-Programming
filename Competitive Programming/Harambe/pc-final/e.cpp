#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, aa[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> aa[i];
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
		ari;
		vector<ll> po(32, 0);
		ll yeti = 1;
		for(int i = 0 ; i < 32 ; i++){
			po[i] = yeti;
			yeti *= 2;
		}
		vector<int> a(n);
		for(int i = 0 ; i < n ; i++)
			a[i] = aa[i];
		ll factor = 1;
		vector<vector<int> > odd(n, vector<int> (31, 0)), even(n, vector<int> (31, 0));
		for(int i = 0 ; i < 31 ; i++){
			factor *= 2;
			int yet = 0;
			if(a[0]%2){
				yet++;
				odd[0][i] = 1;
			}
			else
				even[0][i] = 1;
			a[0] /= 2;
			for(int j = 1 ; j < n ; j++){
				odd[j][i] = odd[j-1][i];
				even[j][i] = even[j-1][i];
				if(a[j]%2){
					yet++;
				}
				if(yet%2)
					odd[j][i]++;
				else
					even[j][i]++;
				a[j] /= 2;
			}
		}
		ll mod = 1e9+7;
		ll ans = 0;
		vector<ll> count(31, 0);
		for(int j = 0 ; j < 31 ; j++)
			if(aa[0]&(1<<j))
				count[j]++;
			for(int j = 0 ; j < 31 ; j++){
		for(int i = 1 ; i < n ; i++){
				if(count[j] % 2)
					ans = (ans + ((even[n-1][j]-even[i-1][j])*po[j])%mod)%mod;
				else
					ans = (ans + ((odd[n-1][j]-odd[i-1][j])*po[j])%mod)%mod;
				if(aa[i] & po[j])
					count[j]++;
			}
		}
		for(int i = 0 ; i < 31 ; i++){
			if(count[i]%2)
				ans = (ans + (odd[n-1][i])*((ll)(1<<i))%mod)%mod;
			else
				ans = (ans + (odd[n-1][i])*((ll)(1<<i))%mod)%mod;
		}
		cout << ans << endl;
	}
	return(0);
}