#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[200005];
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
		cin >> n;
		ari;
		set< ll > ar;
		ar.insert(a[0]);
		ll mid, prev, next;
		bool bad = false;
		for(int i = 1 ; i < n ; i++){
			mid = a[i-1];
			if(ar.size() > 1)
				prev = *(--ar.lower_bound(mid));
			else
				prev = INT_MIN;
			if(ar.size() > 1)
				next = *(ar.upper_bound(mid));
			else
				next = INT_MAX;
			if(a[i] == mid){
				ar.insert(INT_MAX);
				ar.insert(INT_MIN);
			}
			else if(a[i] < mid){
				if(a[i] < prev){
					bad = true;
					break;
				}
				if(a[i] == prev){
					ar.insert(INT_MIN);
					ar.insert(INT_MIN);
				}
				else{
					ar.insert(INT_MIN);
					ar.insert(a[i]);
				}
			}
			else{
				if(a[i] > next){
					bad = true;
					break;
				}
				if(a[i] == next){
					ar.insert(INT_MAX);
					ar.insert(INT_MAX);
				}
				else{
					ar.insert(INT_MAX);
					ar.insert(a[i]);
				}
			}
		}
		if(bad)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return(0);
}