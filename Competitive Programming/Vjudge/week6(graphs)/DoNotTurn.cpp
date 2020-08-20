#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair

class DoNotTurn{
    public:
        int minimumTurns(int N, int X0, int A, int B, int Y0, int C, int D, int P, int M){
            ll Y[M], X[M], dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, ar[] = {1, 2, 3, 4}, dist[N][N];
            bool vis[N][N], mov[N][N];
            for(int i = 0 ; i < N ; i++)
                for(int j = 0 ; j < N ; j++){
                    vis[i][j] = false;
                    dist[i][j] = 100000000;
                    mov[i][j] = true;
                }
            
            X[0] = X0 % P;
            Y[0] = Y0 % P;
            if( (X[0] % N == 0  and Y[0] % N == 0 ) or  
                ( (X[0] % N) == N - 1 and (Y[0] % N) == N - 1 ) );
            else{
                mov[X[0] % N][Y[0] % N] = false;
                cout << X[0] % N << " " << Y[0] % N << endl;
            }
            for(int i = 1 ; i < M ; i++){
                X[i] = (X[i - 1] * A + B) % P;
                Y[i] = (Y[i - 1] * C + D) % P;
                if( (X[i] % N == 0  and Y[i] % N == 0 ) or  
                    ( (X[i] % N) == N - 1 and (Y[i] % N) == N - 1 ) )
                    continue;
                else{
                    mov[X[i] % N][Y[i] % N] = false;
                    cout << X[i] % N << " " << Y[i] % N << endl;
                }
            }
            
            
            deque< pair<pair<ll, ll>, ll> > q;
            vis[0][0] = true;
            dist[0][0] = 0;
            if( 1 < N ){
                if( mov[1][0] ){
                    vis[1][0] = true;
                    dist[1][0] = 0;
                    q.push_back(mp(mp(1, 0), 1));
                }
                if( mov[0][1] ){
                    vis[0][1] = true;
                    dist[0][1] = 0;
                    q.push_back(mp(mp(0, 1), 3));
                }
            }
            
            while( !q.empty() ){
                int x = q.front().first.first;
                int y = q.front().first.second;
                int curdir = q.front().second;
                q.pop_front();
                cout << x << " * " << y << " & " << curdir << " " << dist[x][y] << endl;
                for(int i = 0 ; i < 4 ; i++)
                    if( x + dx[i] >= 0 and y + dy[i] >= 0 and
                        x + dx[i] < N and y + dy[i] < N and
                       !vis[x + dx[i]][y + dy[i]] and mov[x + dx[i]][y + dy[i]] ){
                        int xx = x + dx[i], yy = y + dy[i];
                        vis[xx][yy] = true;
                        if( curdir == ar[i] ){
                            dist[xx][yy] = dist[x][y];
                            q.push_front(mp(mp(xx, yy), ar[i]));
                            
                        }
                        else{
                            dist[xx][yy] = dist[x][y] + 1;
                            q.push_back(mp(mp(xx, yy), ar[i]));
                        }
                            cout << xx << " " << yy << " " << ar[i] << endl;
                    }
            }
            
           if( !vis[N - 1][N - 1] )
               return -1;
           return (ll)dist[N - 1][N - 1];
        }
};

int main(){
    int A, X0, Y0, B, C, D, N, P, M;
    cin >> N >> X0 >> A >> B >> Y0 >> C >> D >> P >> M;
    DoNotTurn a;
    cout << a.minimumTurns(N, X0, A, B, Y0, C, D, P, M) << endl;
    return(0);
}