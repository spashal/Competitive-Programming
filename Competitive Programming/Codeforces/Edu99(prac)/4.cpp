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
		ll x;
		cin >> n >> x;
		vector< ll > ar(n, 0), ans(n, 0);
		for(int i = 0 ; i < n ; i++)
			cin >> ar[i];
		// ar.pb(x);
		sort(ar.begin(), ar.end());

		vector< vector< ll > > in(n, vector< ll > (n, 0)), sample(n, vector< ll > (n, 0));
		//constructing a n*n matrix with rows having all possible arrays
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++){
				if( i != j )
					in[i].pb(ar[j]);
				else
					in[i].pb(x);
				sample[i] = in[i];
				sort(in[i].begin(), in[i].end());
			}

		//now we need to find the minimum no. of swaps need per array
		for(int i = 0 ; i < n ; i++){
			ll tempex = x;
			vector< ll > oc(n, 0);
			oc = ar;
			for(int j = 0 ; j < n ; j++){
				if( in[i][j] != sample[i][j] ){
					ll index;
					for(int k = j + 1 ; j < n ; j++)
						if( sample[i][j] == sample[i][k] ){
							index = k;
							break;
						}
					sample[i][j] += sample[i][index];
					sample[i][index] = sample[i][j] - sample[i][index];
					sample[i][j] -= sample[i][index];
					ans[i]++;
				}
			}
		}
		sort(ans.begin(), ans.end());
		bool flag = false;
		for(int i = 0 ; i < n - 1 ; i++)
			if( ar[i] > ar[i + 1] )
				flag = true;
		if( flag )
			cout << "0"
	}
	return(0);
}