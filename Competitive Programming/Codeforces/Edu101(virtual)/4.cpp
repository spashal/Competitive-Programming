#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, ans[200005], len[200005];
// vector< ll > adj[100005];
vector< bool > included;
// bool included[200005];
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

void fun(ll h){
	queue< ll > q;
	q.push(h);
	while( !q.empty() ){
		ll b = q.front();
		q.pop();
		ll a = ans[b];
		for(int i = (a - 1) * b + 1 ; i <= a * b and i < 200001 ; i++){
			if( included[i] )
				continue;
			if( i > 200001 )
				return;
			// cout << i << " & ";
			ans[i] = b;
			len[i] = len[b] + 1;
			// for(int j = 0 ; j < an[b].size() ; j++)
				// an[i].pb(an[b][j]);
			// an[i].pb(mp(i, b));
			included[i] = true;
			q.push(i);
			// if( i > 20 )
				// return;
		}
	}
}
	
int main(){
	included.resize(200005, false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    ans[1] = 0;
    ans[2] = 2;
    len[2] = 1;
    // len[3] = 2;
    // ans[3] = 2;
    fun(2);
    ans[4] = 3;
    len[4] = len[3] + 1;
    fun(4);
    // for(int i = 2 ; i < 200001 ; i++)
    	// if( !included[i] ){
			// fun(i);
			// included[i] = true;
			// ans[i] = 2;
			// len[i] = len[(int)ceil((float)i/(float)2)] + 1;    		
    	// }
	while( t-- ){
		cin >> n;
		ll temp1 = n;
		ll temp2 = ans[n];
		cout << n - 3 + len[n] << endl;
		for(int i = 2 ; i <= n - 1 ; i++)
			if( i != ans[n] )
				cout << i << " " << i + 1 << endl;
		for(int i = 0 ; i < len[n] ; i++){
			if( temp1 > temp2 ){
				cout << n << " " << ans[n] << endl;
				temp1 = ceil((float)temp1 / temp2);
			}
			else{
				cout << ans[n] << " " << n << endl;
				temp2 = ceil((float)temp2 / temp1);
			}
		}
	}
	return(0);
}