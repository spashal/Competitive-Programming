#include <bits/stdc++.h>
using namespace std;

int noOfDigits( int a ){
	int digits = 0;
	for( int i = 0 ; i < 7 ; i++ ){
		if( a % 2 )
			digits++;
		a /= 2;
	}
	return digits;
}

int main(){
	n[0] = 126; n[1] = 36; n[2] = 93; n[3] = 109; n[4] = 46;
	n[5] = 107; n[6] = 123; n[7] = 37; n[8] = 127; n[9] = 111;
	cin >> n >> k;
	for( int i = 0 ; i < n ; i++ ){
		for( int j = 0 ; j < 7 ; j++ ){
			cin >> b;
			val[i] += p[ 6 - j ] * b;
		}
	}
	for( int i = 0 ; i < n ; i++ ){
		mini[i] = 11;
		for( int j = 0 ; j < 10 ; j++ )
			if( ( n[j] | val[i] ) == n[i] ){
				mini[i] = min( mini[i], noOfDigits(n[j]) - noOfDigits(val[i]));
				if( mini[i] == 11 )
					ctr++;
			}
		if( mini[i] != 11 )
			total += mini[i];
	}
	
	return(0);
}