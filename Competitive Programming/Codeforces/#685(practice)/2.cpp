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
		int q, l, r;
		cin >> n >> q;
		string s;
		cin >> s;
		for(int i = 0 ; i < q ; i++){
			cin >> l >> r;
			bool flag1 = false, flag2 = false;
			for(int j = 0 ; j < l - 1 ; j++)
				if( s[j] == s[l - 1] )
					flag1 = true;
			for(int j = r ; j < n ; j++)
				if( s[j] == s[r - 1] )
					flag2 = true;
			if( flag1 or flag2 )
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return(0);
}