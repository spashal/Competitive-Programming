#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int t, x, y, z;
	cin >> t;
	while( t-- ){
		cin >> x >> y >> z;
		if( x != y and x != z and y != z )
			cout << "NO" << endl;
		else{
			if( x == y ){
				if( z > x )
					cout << "NO" << endl;
				else if( z == x )
					cout << "YES" << endl << x << " " << x << " " << x << endl;
				else
					cout << "YES" << endl << x << " " << z << " " << z << endl;
			}
			else if( y == z ){
				if( x > z or z == 1 )
					cout << "NO" << endl;
				else
					cout << "YES" << endl << "1 " << x << " " << z << endl;
			}
			else{
				if( y > z or z == 1 )
					cout << "NO" << endl;
				else{
					cout << "YES" << endl << y << " " << z << " 1\n";
				}
			}
		}
	}
	return 0;
}