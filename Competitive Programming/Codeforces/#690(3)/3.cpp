#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, ans[105];
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
    for(int i = 0 ; i < 51 ; i++)
    	ans[i] = 1e15;
    for(ll mask = 0 ; mask < (1 << 9) ; mask++){
    	ll sum = 0;
    	ll val = 0;
    	// cout << mask << " hey \n";
    	for(int i = 1 ; i < 10 ; i++)
    		if( (mask & (1 << (i - 1))) > 0 ){
    			// cout << "i is " << i << "\n";
    			sum += i;
    			val *= 10;
    			val += i;
    		}
    	ans[sum] = min(ans[sum], val);
    }
    cin >> t;
	while( t-- ){
		cin >> n;
		if( ans[n] == 1e15 )
			cout << "-1\n";
		else
		cout << ans[n] << endl;
	}
	return(0);
}