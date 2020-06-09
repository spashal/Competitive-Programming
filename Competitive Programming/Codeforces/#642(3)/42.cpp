#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair< pair< ll, ll>, ll> pp;
/*So just by the time I was looking for questions where I could apply DSA knowledge
  this question appears in a div3 contest and it wants to use priority queue. Maybe
  it can also be done using queue if we optimize things a bit but this is as it is.
  Still this is a good question and I like it how Vaibhav quickly applied his 
  knowledge this time around.*/

bool compy( pp a, pp b){
	if( (a.first.second - a.first.first) == (b.first.second - b.first.first))
		return a.first.first > b.first.first;
	return (a.first.second - a.first.first) < (b.first.second - b.first.first);
}
int main(){
	ll t, n, ans[200005];
	cin >> t;
	while( t-- ){
		ll k = 0;
		cin >> n;
		priority_queue< pp, vector< pp >, function< bool( pp, pp) > > pq(compy);
		pq.push( make_pair( make_pair( 1, n), ceil((float)n/2)));
		while( !pq.empty() ){
			ll a = pq.top().second;
			ll low = pq.top().first.first;
			ll high = pq.top().first.second;
			ans[a] = ++k;
			pq.pop();
			if( a < high )
				pq.push( make_pair( make_pair( a + 1, high), a + ceil((float)( high - a )/2)));
			if( low < a ){
				if( ( a - low ) % 2 == 0 )
					pq.push( make_pair( make_pair( low, a - 1), low + ( a - low )/2 - 1));
				else
					pq.push( make_pair( make_pair( low, a - 1), low + ( a - low )/2));
			}
		}
		for( int i = 1 ; i <= n ; i++ )
			cout << ans[i] << " ";
		cout << endl;
	}
	return(0);
}