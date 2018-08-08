#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
#define MAXX_N 100
#define INF 12345678900

ll n,m,dist[MAXX_N+1][MAXX_N+1];

int main(){
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==j) continue;
            dist[i][j]=INF;
        }
    }
    for(ll i=0;i<m;i++){
        ll x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        dist[x][y]=min(dist[x][y],z);
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%lld ",dist[i][j]==INF ? 0 : dist[i][j]);
        }
        puts("");
    }
}
