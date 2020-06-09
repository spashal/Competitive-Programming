#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while( t-- ){
        string a, b, s;
        cin >> a;
        cin >> b;
        int j = 0;
        for( int i = 0 ; i < (int)b.size() ; i++ ){
            while( j < (int)a.size() ){
                if( a[j] <= 'Z' ){
                    if( a[j] == b[i] ){
                        s.push_back(b[i]);
                        j++;
                        break;
                    }
                    else
                        s.push_back(a[j]);
                }
                else if( a[j] - 32 == b[i] ){
                    s.push_back(b[i]);
                    j++;
                    break;
                }
                j++;
            }
        }
        // cout << j << endl;
        while( j < (int)a.size() ){
            if( a[j] <= 'Z' )
                s.push_back(a[j]);
            j++;
        }
        // cout << s << endl;
        if( b == s )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        s.clear();
    }
    return 0;
}
