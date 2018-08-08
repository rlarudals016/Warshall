#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAXX_N 100
#define INF 12345678900
typedef long long ll;

ll n,m,dist[MAXX_N+1][MAXX_N+1],path[MAXX_N+1][MAXX_N+1];

void func(ll st,ll des,vector<ll>& vt){
    if(!path[st][des]){
        vt.push_back(st);
        vt.push_back(des);
        return ;
    }
    func(st,path[st][des],vt);
    vt.pop_back();
    func(path[st][des],des,vt);
}

int main(){
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==j) continue;
            dist[i][j]=INF;
        }
    }
    
    while(m--){
        ll x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        dist[x][y]=min(dist[x][y],z);
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(dist[j][k]>dist[j][i]+dist[i][k]){
                    dist[j][k]=dist[j][i]+dist[i][k];
                    path[j][k]=i;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%lld ",dist[i][j]==INF ? 0 : dist[i][j]);
        }
        puts("");
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j]==INF||dist[i][j]==0){
                puts("0");
                continue;
            }
            vector<ll> tmp;
            func(i,j,tmp);
            printf("%d ",tmp.size());
            for(int k=0;k<tmp.size();k++)
                printf("%lld ",tmp[k]);
            puts("");
        }
    }
    
}
