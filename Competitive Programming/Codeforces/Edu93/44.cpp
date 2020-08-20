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
	priority_queue< ll > pq1, pq2, pq3;
	ll n1, n2, n3, x;
	cin >> n1 >> n2 >> n3;
	for(int i = 0 ; i < n1 ; i++){
		cin >> x;
		pq1.push(x);
	}
	for(int i = 0 ; i < n2 ; i++){
		cin >> x;
		pq2.push(x);
	}	
	for(int i = 0 ; i < n3 ; i++){
		cin >> x;
		pq3.push(x);
	}	
	pq1.push(0);
	pq2.push(0);
	pq3.push(0);
	ll ans = 0;
	while( 1 ){
		if( pq1.top() == min(pq1.top(), min(pq2.top(), pq3.top())) ){
			if( pq2.top() == 0 or pq3.top() == 0 )
				break;
			// cout << "2 3" << endl;
			ans += pq2.top() * pq3.top();
			pq2.pop();
			pq3.pop();
		}
		else if( pq2.top() == min(pq1.top(), min(pq2.top(), pq3.top())) ){
			// cout << "1 3" << endl;
			if( pq1.top() == 0 or pq3.top() == 0 )
				break;
			ans += pq1.top() * pq3.top();
			pq1.pop();
			pq3.pop();
		}
		else{
			// cout << "2 1" << endl;
			if( pq1.top() == 0 or pq2.top() == 0 )
				break;
			ans += pq1.top() * pq2.top();
			pq1.pop();
			pq2.pop();
		}
	}
	cout << ans << endl;
	return(0);
}