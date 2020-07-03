#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, k, t;
vector< int > ar;
int a[200005];
string s;
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ){ cin >> a[i];if( a[i] ) ar.push_back(i);}
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> t;
	while( t-- ){
		cin >> n >> k;
		cin >> s;
		for( int i = 0 ; i < n ; i++)
			a[i] = s[i] - '0';
		for(int i = 0 ; i < n ; i++){
			if( a[i] == 1 )
				ar.push_back(i);
		}
		int m = 0;
		sort(ar.begin(), ar.end());
		int ans = 0;
		for(int i = 1 ; i < ar.size() ; i++)
			if(ar[i] - ar[i-1] - 1 > k){
				ans += (ar[i] - ar[i-1] - 1 - k) / (k + 1);
			}
		for(int i = 0 ; i < n ; i++){
			if( a[i] == 1 )
				break;
			m++;
		}
		ans += m / (k + 1);
		m = 0;
		if( !ar.empty() )
		for(int i = n - 1 ; i > -1 ; i--){
			if( a[i] )
				break;
			m++;
		}
		ans += m / (k + 1);
		if( (int)ar.size() == 0 )
			cout << 1 + (n-1)/(k+1) << endl;
		// else if( (int)ar.size() == n & n == 1 )
		// 	cout << "1" << endl;
		else
			cout << ans << endl;
		ar.clear();
		s.clear();
		for(int i = 0 ; i < n ; i++)
			a[i] = 0;
	}
	return(0);
}