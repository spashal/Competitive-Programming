#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, k;

int minD( ll a){
	int mini = 10;
	while( a > 0 ){
		mini = min( mini, (int)(a % 10));
		a /= 10;
	}
	return mini;
}

int maxD( ll a){
	int maxa = 0;
	while( a > 0 ){
		maxa = max( maxa, (int)(a % 10));
		a /= 10;
	}
	return maxa;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n >> k;
		// ll ans = 0;
		ll ai = 0;
		for( int i = 0 ; i < k - 1 ; i++ ){
			ai = minD(n);
			if( ai == 0 ){
				// z = 1;
				break;
			}
			n = n + ai * maxD(n);
		}
		cout << n << endl;
	}
	return(0);
}