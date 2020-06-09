#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, a, b, c, d;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> a >> b >> c >> d;
		if( a <= b ){
			cout << b << endl;
		}
		else{
			if( c > d ){
				if( (a-b)%(c-d) == 0 )
					cout << b + ((a-b)*c)/(c-d)<< endl;
				else
				cout << b + ((a-b)/(c-d))*c + c << endl; 
			}
			else
				cout << "-1" << endl;
		}
	}
	return(0);
}