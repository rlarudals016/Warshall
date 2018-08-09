#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 12345678
#define MAXX_N 400

int n,k,dist[MAXX_N+1][MAXX_N+1];

int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dist[i][j]=INF;
        }
    }
    for(int i=0;i<=n;i++)
        dist[i][i]=0;
    
    while(k--){
        int a,b;
        scanf("%d%d",&a,&b);
        dist[a][b]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
            }
        }
    }
    int s;
    scanf("%d",&s);
    while(s--){
        int info1,info2;
        scanf("%d%d",&info1,&info2);
        if(dist[info1][info2]<INF)
            puts("-1");
        else if(dist[info2][info1]<INF)
            puts("1");
        else
            puts("0");
    }
}
