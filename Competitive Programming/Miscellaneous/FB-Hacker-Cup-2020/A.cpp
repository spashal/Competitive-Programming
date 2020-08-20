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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	for(int r = 1 ; r <= t ; r++){
		cin >> n;
		string a, b;
		cin >> a >> b;
		vector< string > ans(n, string(n, 'N'));
		string t1, t2;
		for(int i = 0 ; i < n - 1 ; i++){
			if( a[i + 1] == 'Y' and b[i] == 'Y')
				t1.pb('Y');
			else
				t1.pb('N');
		}
		for(int i = 0 ; i < n - 1 ; i++){
			if( a[i] == 'Y' and b[i + 1] == 'Y' )
				t2.pb('Y');
			else
				t2.pb('N');
		}
		for(int i = 0 ; i < n ; i++){
			for(int j = i ; j < n - 1 ; j++)
				if( t1[j] == 'Y' )
					ans[i][j + 1] = 'Y';
				else
					break;
			for(int j = i - 1 ; j >= 0 ; j--)
				if( t2[j] == 'Y' )
					ans[i][j] = 'Y';
				else
					break;
			ans[i][i] = 'Y';
		}
		cout << "Case #" << r << ":" << endl;
		for(int i = 0 ; i < n ; i++)
			cout << ans[i] << endl;
	}
	return(0);
}