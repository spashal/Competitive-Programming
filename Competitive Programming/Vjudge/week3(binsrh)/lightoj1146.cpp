#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t;
ld a1, a2, b1, b2, x1, x2, Y1, y2;
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}
#define pb push_back
#define ss second
#define ff first
#define fs first.second
#define fff first.first
#define sss second.second
#define sf second.first
#define mp make_pair

ld dist(ld x, ld y){
	ld a, b;
	if( x1 != x2 ){
		a = a1 + ((x - x1) * (a2 - a1)) / (x2 - x1);
		b = b1 + ((x - x1) * (b2 - b1)) / (x2 - x1);
	}
	else if( Y1 != y2 ){
		a = a1 + ((y - Y1) * (a2 - a1)) / (y2 - Y1);
		b = b1 + ((y - Y1) * (b2 - b1)) / (y2 - Y1);
	}
	else{
		 return 0.0;
	}
	ld sq = sqrt((a - x) * (a - x) + (b - y) * (b - y));
	return sq;
}

ld dista(ld a, ld b, ld x, ld y){
	ld sq = sqrt((a - x) * (a - x) + (b - y) * (b - y));
	return sq;
}

ld ternary_search(ld l1, ld r1, ld l2, ld r2){
	ld eps = 1e-9;
	while( dista(l1, r1, l2, r2) > eps ){
		ld m1 = (2.0 * l1 + l2) / 3.0;
		ld m2 = (2.0 * l2 + l1) / 3.0;
		ld n1 = (2.0 * r1 + r2) / 3.0;
		ld n2 = (2.0 * r2 + r1) / 3.0;
		ld f1 = dist(m1, n1);
		ld f2 = dist(m2, n2);
		if( f1 < f2 ){
			l2 = m2;
			r2 = n2;
		}
		else{
			l1 = m1;
			r1 = n1;
		}
	}
	return dist(l1, r1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> a1 >> b1 >> a2 >> b2 >> x1 >> Y1 >> x2 >> y2;
		if( x1 == x2 and Y1 == y2 ){
			swap(a1, x1);
			swap(b1, Y1);
			swap(a2, x2);
			swap(b2, y2);		
		}
		cout << setprecision(8) << fixed << ternary_search(x1, Y1, x2, y2) << endl;
	}
	return(0);
}