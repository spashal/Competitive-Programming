#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define ff first
#define fff first.first
#define fs first.second
#define ss second
#define sss second.second
#define sf second.first

int main(){
	string s;
	cin >> s;
	s.push_back('$');
	ll c[s.size()];
	int k = 0, n = s.size();

	vector< pair< pair< ll, ll>, ll> > info(s.size());
	
	for(int i = 0 ; i < s.size() ; i++)
		info[i] = make_pair(make_pair(s[i] - 'a',  0), i);
	
	sort(info.begin(), info.end());
	c[info[0].ss] = 0;
	
	for(int i = 1 ; i < info.size() ; i++)
		if( info[i].ff == info[i - 1].ff )
			c[info[i].ss] = c[info[i - 1].ss];
		else
			c[info[i].ss] = c[info[i - 1].ss] + 1;
	

	while( (1 << k) < n ){
	
		for(int i = 0 ; i < n ; i++)
			info[i] = make_pair(make_pair(c[i], c[((1 << k) + i) % n]), i);
	
		sort(info.begin(), info.end());
		c[info[0].ss] = 0;
	
		for(int i = 1 ; i < n ; i++)
			if( info[i].ff == info[i - 1].ff )
				c[info[i].ss] = c[info[i - 1].ss];
			else
				c[info[i].ss] = c[info[i - 1].ss] + 1;
	
		k++;
	}
	
	for(int i = 0 ; i < n ; i++)
		cout << info[i].ss << " " << s.substr(info[i].ss, n - 1 - info[i].ss) << endl;
	
	return(0);
}