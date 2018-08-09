#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXX_N 400
#define INF 123456789

int v,e,dist[MAXX_N+1][MAXX_N+1];

int main(){
    scanf("%d%d",&v,&e);
    
    for(int i=0;i<=v;i++){
        for(int j=0;j<=v;j++){
            dist[i][j]=INF;
        }
    }
    
    while(e--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        dist[a][b]=c;
    }
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            for(int k=1;k<=v;k++){
                dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
            }
        }
    }
    int ans=INF;
    for(int i=1;i<=v;i++)
        ans=min(ans,dist[i][i]);
    if(ans==INF) puts("-1");
    else
        printf("%d",ans);
}
