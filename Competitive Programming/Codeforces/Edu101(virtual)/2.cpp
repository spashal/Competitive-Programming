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
		vector< ll > i1, i2, ans;
		ll aaa;
		for(int i = 0 ; i < n ; i++){
			cin >> aaa;
			i1.pb(aaa);
		}
		cin >> m;
		for(int i = 0 ; i < m ; i++){
			cin >> aaa;
			i2.pb(aaa);
		}
		vector< ll > presum1(n, 0), presum2(m, 0);

		for(int i = 0 ; i < n ; i++){
			ll cursum = 0;
			presum1[i] = 0;
			for(int j = i ; j < n ; j++){
				cursum += i1[j];
				presum1[i] = max(presum1[i], cursum);
			}
		}

		for(int i = 0 ; i < m ; i++){
			ll cursum = 0;
			presum2[i] = 0;
			for(int j = i ; j < m ; j++){
				cursum += i2[j];
				presum2[i] = max(presum2[i], cursum);
			}
		}

		ll one = 0, two = 0;
		while( one < n and two < m ){
			if( presum1[one] > presum2[two] ){
				ans.pb(i1[one]);
				one++;
			}
			else{
				ans.pb(i2[two]);
				two++;
			}
		}
		while( one < n ){
			ans.pb(i1[one]);
			one++;
		}
		while( two < m ){
			ans.pb(i2[two]);
			two++;
		}
		ll maxi = 0, sum = 0;
		for(int i = 0 ; i < ans.size() ; i++){
			sum += ans[i];
			// cout << ans[i] << " ";
			maxi = max(sum, maxi);
		}
		cout << maxi << endl;
	}
	return(0);
}