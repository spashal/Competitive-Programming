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
    vector< bool > prime(1e7+1, true);
    vector< bool > parent(1e7+1, false);
    for(int i = 2 ; i < 1e7+1 ; i++){
    	if(prime[i]){
    		if(i*2 < 1e7)
    			parent[i*2] = true;
    		for(int j = i*2 ; j < 1e7+1 ; j += i){
    			prime[j] = false;
    		}
    	}
    }
    parent[4] = false;
    int count = 0;
    vector< int > dp(1e7+1, 0);
    for(int i = 2 ; i < 1e7+1 ; i++){
    	if(prime[i])
    		count++;
    	else if(parent[i])
    		count--;
    	dp[i] = count;
    }
	while( t-- ){
		cin >> n;
		cout << dp[n] << "\n";
	}
	return(0);
}