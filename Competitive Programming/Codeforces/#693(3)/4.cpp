#include <iostream>
#include <vector>
#include <queue>
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
		priority_queue< ll > odd, even;
		ari;
		ll A = 0, B = 0;
		for(int i = 0 ; i < n ; i++)
			if( a[i] % 2 )
				odd.push(a[i]);
			else
				even.push(a[i]);
		for(int i = 0 ; !odd.empty() or !even.empty() ; i++){
			if( i % 2 == 0 ){
				if( !odd.empty() and !even.empty() and even.top() >= odd.top() ){
					A += even.top();
					even.pop();
				}
				else if( !odd.empty() and !even.empty() ){
					odd.pop();
				}
				else if( !even.empty() ){
					A += even.top();
					even.pop();
				}
				else
					odd.pop();
			}
			else{
				if( !odd.empty() and !even.empty() and even.top() <= odd.top() ){
					B += odd.top();
					odd.pop();
				}
				else if( !odd.empty() and !even.empty() ){
					even.pop();
				}
				else if( !odd.empty() ){
					B += odd.top();
					odd.pop();
				}
				else
					even.pop();
			}
		}
		if( A > B )
			cout << "Alice\n";
		else if( A < B )
			cout << "Bob\n";
		else
			cout << "Tie\n";
	}
	return(0);
}