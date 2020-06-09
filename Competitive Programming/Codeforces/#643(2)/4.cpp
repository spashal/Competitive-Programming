#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
		cin >> n >> s;
		if( s >= 2 * n ){
			cout << "YES" << endl;
			for( int i = 0 ; i < n - 1 ; i++ )
				cout << "1 ";
			cout << s - n + 1 << endl << n << endl;
		}
		else
			cout << "NO" << endl;
	return(0);
}