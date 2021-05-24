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
		cin >> n;
		vector< ll > p(n, 0);
			ll one = -1; 
		for(int i = 0 ; i + 1 < n ; i += 2){
			cout << "? 2 " << i + 1 << " " << i + 2 << " 1" << endl;
			fflush(stdout);
			ll temp;
			cin >> temp;
			if(temp == 1){
				// sure that i is 1
				one = i;
			}
			else if(temp == 2 and one == -1){
				// i + 1 might be 1 or 2
				cout << "? 1 " << i + 1 << " " << i + 2 << " 1" << endl;
				fflush(stdout);
				cin >> temp;
				if(temp == 1)
					one = i + 1;
			}
			if(one > -1)
				break;
		}
		if(one == -1)
			one = n - 1;
		p[one] = 1;
		for(int i = 0 ;  i < n ; i++){
			if(one == i)
				continue;
			cout << "? 1 " << one + 1 << " " << i + 1 << " " << n - 1 << endl;
			fflush(stdout);
			ll temp;
			cin >> temp;
			p[i] = temp;
		}
		cout << "! ";
		for(int i = 0 ; i < n ; i++)
			cout << p[i] << " ";
		cout << endl;
	}
	return(0);
}