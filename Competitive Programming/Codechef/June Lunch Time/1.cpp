#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int t, a, n;
	cin >> t;
	while( t-- ){
		cin >> a >> n;
		if( n % 2 )
			n--;
		if( a % n == 0 )
			cout << a / n << endl;
		else{
			if( (a % n) % 2 ){
				if( (a % n) == 1 )
					cout << a/n + 1 << endl;
				else
					cout << a / n + 2 << endl;
			}
			else
				cout << a / n + 1 << endl;
		}
	}
	return(0);
}