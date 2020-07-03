#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> t;
	while( t-- ){
		cin >> n;
		ll temp = n;
		if( n == 1 ){
			cout << "FastestFinger" << endl;
			continue;
		}
		else if( n == 2 or n % 2 > 0 ){
			cout << "Ashishgup" << endl;
			continue;
		}
		ll ct = 1;
		int k = 0 ;
		while( n % 2 == 0 ){
			// k++;
			n /= 2;
			ct *= 2;
		}
		int j = 3;
		ll s = sqrt(n);
		ll tem = n;
		for(int i = 3 ; i <= s ; i++){
			while( tem % i == 0 ){
				tem /= i;
			}
		}
		if( tem == n )
			k = 1;
		else
		while( n > 1 ){
			while( n % j == 0 ){
				k++;
				n /= j ;
			}
			j++;
			if( k > 1 )
				break;
		}
		if( ct == 2 ){
			if( k > 1 )
				cout << "Ashishgup" << endl;
			else
				cout << "FastestFinger" << endl;

		}
		else if( ct == temp )
			cout << "FastestFinger" << endl;
		else{
			cout << "Ashishgup" << endl;
		}
	}
	return(0);
}