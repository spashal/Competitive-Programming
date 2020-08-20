#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n;
vector< ll > a;

int main(){
	cin >> n;
	for( int i = 0 ; i < n ; i++ ){
		ll u;
		cin >> u;
		a.push_back(u);
	}
	ll cost = 0;
	for( int i = 1 ; i < n ; i++ ){
		ll mini = 1000000000000000000;
		ll z = 0;
		for( int j = 1 ; j < n-i+1 ; j++ )
			if( mini > a[j] + a[j-1] ){
				z = j;
				mini = a[j] + a[j-1];
			}
		a[z-1] += a[z];
		for( ll j = z ; j < n - 1 ; j++ )
			a[j] = a[j+1];
		cost += a[z-1];
	}
	cout << cost << endl;
	return(0);
}