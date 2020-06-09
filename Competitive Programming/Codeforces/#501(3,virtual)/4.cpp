#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, m, s, k;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	cin >> n >> k >> s;
 	ll j = 0;
 	if( s >= k and s <= ( n - 1 ) * k ){
 		cout << "YES" << endl;
 		if( s % k == 0 ){
 			ll m = 1 + s/k;
 			while( k-- ){
 				if( j % 2 == 0 )
 					cout << m << " ";
 				else
 					cout << "1 ";
 				j++;
 			}
 			cout << endl;
 		}
 		else{
 			t = s % k;
 			ll e = t;
 			ll r = s/k;
 			while( t-- ){
 				k--;
 				if( j % 2 == 0 )
 					cout << 2 + r << " ";
 				else
 					cout << "1 ";
 				j++;
 			}
 			while( k-- ){
 				if( e % 2 == 0 ){
	 				if( j % 2 == 0 )
 						cout << 1 + r << " ";
 					else
 						cout<< "1 ";
 				} 
 				else{
 					if( j % 2 == 0 )
 						cout << 2 + r << " ";
 					else
 						cout << "2 ";
 				}
 				j++;
 			}
 			cout << endl;
 		}
 	}
 	else
 		cout << "NO" << endl;
	return(0);
}