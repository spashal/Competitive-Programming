#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, k;
    string s;
    cin >> t;
    for(int i = 1 ; i <= t ; i++){
        cin >> n >> k >> s;
        int ctr = 0;
        for(int j = 0 ; j < (n+1)/2 ; j++){
            if(s[j] == s[n-j-1]){
                ctr++;
	    	cout << j << " ";
	    }
        }
        cout << "Case #" << i << ": " << abs(ctr-k) << endl;
    }
    return 0;
}
