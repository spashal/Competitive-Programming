#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, a[200005];
int main(){
	cin >> t;
	while( t-- ){
		cin >> n;
		for( int i = 0 ; i < n ; i++ )
			cin >> a[i];
		ll aa = a[0];
		ll bb = 0;
		ll finalb = 0, finala = 0;
		ll i = 1, ia = 0, ib = 0;
		ll z = 0;
		ll j = 1;
		ia = 1;
		do{
			bb = 0;
			z = 0;
			while( n - j >= i and bb <= aa ){
				// cout << "j is " << j << endl;
				bb += a[ n - j ];
				finalb += a[ n - j ];
				j++;
				if( z == 0 ){
					z++;
					ib++;
				}
			}
			aa = 0;
			z = 0;
			while( n - j >= i and aa <= bb){
				// cout << "i is " << i << endl;
				aa += a[i];
				finala += a[i];
				i++;
				if( z == 0 ){
					z++;
					ia++;
				}
			}

		}while( j + i <= n );
		cout << ia + ib << " " << finala + a[0] << " " << finalb << endl;
	}
	return(0);
}