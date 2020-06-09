#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, m;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n >> m;
		if( n % 2 > 0 and m % 2 > 0 )
			cout << (n*m + 1)/2 << endl;
		else
			cout << (n*m)/2 << endl;
 	}
	return(0);
}