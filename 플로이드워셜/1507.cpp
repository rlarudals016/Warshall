#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXX_N 20

int dist[MAXX_N+1][MAXX_N+1],ans_dist[MAXX_N+1][MAXX_N+1],n,flag;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&dist[i][j]);
            ans_dist[i][j]=dist[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(i==j||j==k||i==k) continue;
                if(dist[j][k]==dist[j][i]+dist[i][k])
                    ans_dist[j][k]=0;
                else if(dist[j][k]>dist[j][i]+dist[i][k])
                    flag=1;
            }
        }
    }
    
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans+=ans_dist[i][j];
        }
    }
    if(flag)
        puts("-1");
    else
        printf("%d",ans/2);
}
