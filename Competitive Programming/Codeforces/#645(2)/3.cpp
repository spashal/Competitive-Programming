#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, X1, X2, Y1, Y2, ma, mi;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> X1 >> Y1 >> X2 >> Y2;
		if( X1 == X2 or Y1 == Y2 )
			cout << "1" << endl;
		else{
			ll ma = max( llabs(Y1-Y2), llabs(X1-X2));
			ll mi = min( llabs(Y1-Y2), llabs(X1-X2));
			cout << ma * mi + 1 << endl;
		}
	}
	return(0);
}