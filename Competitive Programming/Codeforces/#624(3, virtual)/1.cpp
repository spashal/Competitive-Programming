#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, t, a, b;
int main(){
	cin >> t;
	while( t-- ){
		cin >> a >> b;
		if( a == b )
			cout << "0" << endl;
		else if( (a + b) % 2 ){
			if( a < b )
				cout << "1" << endl;
			else
				cout << "2" << endl;
		}
		else{
			if( a > b )
				cout << "1" << endl;
			else
				cout << "2" << endl;
		}
	}
	return(0);
}