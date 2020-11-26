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
		int k;
		cin >> n >> k;
		string a, b;
		cin >> a >> b;
		vector< ll > A(26, 0), B(26, 0);
		for(int i = 0 ; i < n ; i++){
			A[a[i] - 'a']++;
			B[b[i] - 'a']++;
		}
		for(int i = 0 ; i < 25 ; i++){
			if( A[i] < B[i] )
				continue;
			A[i + 1] += ((A[i] - B[i]) / k) * k;
			A[i] -= ((A[i] - B[i]) / k) * k;
		}
		bool flag = false;
		for(int i = 0 ; i < 26 ; i++){
			if( A[i] != B[i] )
				flag = true;
		}
		if( flag )
			cout << "NO\n";
		else
			cout << "Yes\n";
	}	
	return(0);
}