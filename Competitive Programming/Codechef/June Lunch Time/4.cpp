#include <bits/stdc++.h>
using namespace std;
typedef long double ll;
ll n, m, t, a[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> t;
	while( t-- ){
		ll g1, g2, a1, a2, b1, b2;
		cin >> n;
		cin >> g1 >> a1 >> b1;
		if( n > 1 )
			cin >> g2 >> a2 >> b2;
		if( n == 1 )
			cout << fixed << setprecision(6) << (g1) * (a1 / (a1 + b1)) << " " << g1 * (b1 / (a1 + b1)) << endl;
		else{
			ll b_one = g1 * (a1 / (a1 + b1)) + g2 * (a2 / (a2 + b2));
			ll a_one = g1 * (b1 / (a1 + b1)) + g2 * (b2 / (a2 + b2));
			ll b_two;
			if( a1 > b2 )
				b_two = g2 + g1 * (1 - b2 / a1) * a1 / (a1 + b1);
			else
				b_two = g2 * a1 / b2 + g2 * (1 - a1 / b2) * a2 / (a2  + b2);
			ll a_two = (g1 + g2 - b_two);
			ll b_three;
			if( a2 > b1 )
				b_three = g1 + g2 * (1 - b1 / a2) * a2 / (a2 + b2);
			else
				b_three = g1 * (a2 / b1) + g1 * (1 - a2 / b1) * a1 / (a1 + b1);
			ll a_three = g1 + g2 - b_three;
			ll mini = min(abs(a_one - b_one), min(abs(a_two - b_two), abs(a_three - b_three)));
			if( mini == abs(a_one - b_one) )
				cout << fixed << setprecision(6) << a_one << " " << b_one << endl;
			else if( mini == abs(a_two - b_two) )
				cout << fixed << setprecision(6) << a_two << " " << b_two << endl;
			else
				cout << fixed << setprecision(6) << a_three << " " << b_three << endl;
		}
	}
	return(0);
}