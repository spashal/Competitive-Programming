#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t;
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
int cur[1001], a[1001], cov[1001][1001], v[1001];
void printar(vector< ll > ar, ll l, ll r){
	for(int i = l ; i < r ; i++)
		cout << ar[i] << " ";
	cout << endl;
}
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    	cin >> a[i] >> v[i];
    for(int i = 0 ; i < n ; i++)
    	for(int j = 0 ; j < n ; j++)
    		cin >> cov[i][j];
  	for(int i = 0 ; i < 11 ; i++){
  		for(int j = 0 ; j < n ; j++){
  			ll temp = 0;
  			if( a[j] < cur[j] )
  				continue;
  			for(int k = 0 ; k < n ; k++)
  				temp += cov[j][k] * cur[k];
  			temp += cur[j] * 2 * cov[j][j] + cov[j][j];
  			if( v[j] - temp > 0 )
  				cur[j]++;
  		}
  	}
  	for(int i = 0 ; i < n ; i++)
  		cout << cur[i] << " ";
  	cout << endl;
	return(0);
}