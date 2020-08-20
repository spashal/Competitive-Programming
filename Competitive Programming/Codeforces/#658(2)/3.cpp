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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		string a, b;
		int cur = 0, k = 0;
		cin >> a >> b;
		string c = a;
		vector< int > ans;
		for(int i = n - 1 ; i >= 0 ; i--){
			if( i == 0 ){
				if( a[i] != b[i] )
					ans.pb(0);
				break;
			}
			if( k % 2 ){
				if( c[cur - i] == '0' )
					a[i] = '1';
				else
					a[i] = '0';
			}
			else if( k > 0 ){

				if( c[cur + i] == '0' )
					a[i] = '0';
				else
					a[i] = '1';
			}
			if( a[i] != b[i] ){
				if( a[0] == b[i] ){
					ans.pb(0);
					ans.pb(i);
					k++;
					if( k % 2 )
						cur += i;
					else
						cur -= i;
					a[i] = b[i];
					// cout << "1 " << ans.back() + 1 << endl;
				}
				else{
					ans.pb(i);
					k++;
					if( k % 2 )
						cur += i;
					else
						cur -= i;
					if( a[i] == '0' )
						a[0] = '1';
					else
						a[0] = '0';
					a[i] = b[i];
					// cout << ans.back() + 1 << endl;
				}
			}
			// cout << a << endl << b << endl << endl;
		}
		cout << ans.size() << " ";
		if( ans.size() > 0 ){
			for(int i = 0 ; i < ans.size() ; i++)
				cout << ans[i] + 1 << " ";
		}
			cout << endl;
	}
	return(0);
}