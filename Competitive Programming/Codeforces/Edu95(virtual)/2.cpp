#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[105];
bool fixa[105], taken[105];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define bri for( int i = 0 ; i < n ; i++ ) cin >> fixa[i];
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
		cin >> n;
		vector< ll > b(n + 1, -1e6);
		ari;
		bri;
		ll sum = 0;
		for(int i = 0 ; i < n ; i++){
			taken[i] = 0;
			sum += a[i];
		}
		a[n] = 1e6;
		bool flag = false;
		for(int i = n - 1 ; i >= 0 ; i--){
			if( fixa[i] ){
				sum -= a[i];
				b[i] = a[i];
				continue;
			}
			ll mini = n;
			for(int j = 0 ; j < n ; j++)
				if( !fixa[j] and !taken[j] and sum - a[j] >= 0 and a[mini] > a[j] )
					mini = j;
			if( mini == n ){
				flag = true;
				break;	
			}	
			taken[mini] = true;
			b[i] = a[mini];
			sum -= a[mini];		
		}
		if( flag ){
			queue< ll > q;
			for(int i = 0 ; i < n ; i++)
				if( !taken[i] and !fixa[i] )
					q.push(a[i]);
				else if( fixa[i] )
					b[i] = a[i];
			for(int i = 0 ; i < n ; i++)
				if( b[i] < -1e5 ){
					b[i] = q.front();
					q.pop();
				}
		}
		for(int i = 0 ; i < n ; i++)
			cout << b[i] << " ";
		cout << endl;
	}
	return(0);
}