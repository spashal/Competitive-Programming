#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[2005], odd = 0, even = 0;
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ){ cin >> a[i]; if(a[i] % 2) odd++; else even++;}
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> t;
	while( t-- ){
		// cout << "*" << endl;
		cin >> n;
		n *= 2;
		ari;
		ll j = 0, k = 0;
		if( odd % 2 ){
			ll iodd = 0;
			ll ieven = 0;
			odd--;
			even--;
			for(int i = 0 ; i < n ; i++){
				if( a[i] % 2 ){
					j = i + 1;
					break;
				}
			}
			for(int i = 0 ; i < n ; i++)
				if( a[i] % 2 == 0 ){
					k = i + 1;
					break;
				}
			// while( odd > iodd and even > ieven ){
			// 	while( a[k] % 2 )
			// 		k++;
			// 	cout << k + 1 << " ";
			// 	while( a[j] % 2 == 0 )
			// 		j++;
			// 	cout << j + 1 << endl;
			// 	ieven++;
			// 	iodd++;
			// 	j++;
			// 	k++;
			// }
			int ct = 0;
			while( k < n ){
				if( a[k] % 2 == 0 ){
					if( ct == 0 ){
						cout << k + 1 << " ";
						ct++;
					}
					else{
						ct = 0;
						cout << k + 1 << endl;
					}
				}				
					k++;
			}
			while( j < n ){
				if( a[j] % 2 ){
					if( ct == 0 ){
						cout << j + 1 << " ";
						ct++;
					}
					else{
						ct = 0;
						cout << j + 1 << endl;
					}
				}
					j++;
			}
			odd = 0;
			even = 0;
		}
		else{
			int ct = 0;
			if( odd > 0 ){
				int ctr = 0;
				for(int i = 0 ; i < n ; i++)
					if( a[i] % 2 ){
						if( !ctr )
							ctr++;
						else{
							j = i + 1;
							break;
						}
					}
			}
			else{
				int ctr = 0;
				for(int i = 0 ; i < n ; i++)
					if( a[i] % 2 == 0 ){
						if( !ctr )
							ctr++;
						else{
							k = i + 1;
							break;
						}
					}
			}
			while( k < n ){
				if( a[k] % 2 == 0 ){
					if( ct == 0 ){
						cout << k + 1 << " ";
						ct++;
					}
					else{
						ct = 0;
						cout << k + 1 << endl;
					}
				}				
					k++;
			}
			while( j < n ){
				if( a[j] % 2 ){
					if( ct == 0 ){
						cout << j + 1 << " ";
						ct++;
					}
					else{
						ct = 0;
						cout << j + 1 << endl;
					}
				}
					j++;
			}
			odd = 0;
			even = 0;
		}
	}
	return(0);
}