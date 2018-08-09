#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAXX_N 100
#define INF 123456789

int t_case,st_y,st_x,des_y,des_x,n,dist[MAXX_N+5][MAXX_N+5];
pair<int,int> arr[MAXX_N+5];

int dist_func(int a,int b,int c,int d){
    return abs(a-c)+abs(b-d);
}

int main(){
    scanf("%d",&t_case);
    while(t_case--){
        scanf("%d",&n);
        
        for(int i=0;i<n+2;i++){
            for(int j=0;j<n+2;j++){
                dist[i][j]=INF;
            }
        }
        
        for(int i=0;i<n+2;i++)
            dist[i][i]=0;
        
        for(int i=0;i<n+2;i++)
            scanf("%d%d",&arr[i].first,&arr[i].second);
        
        for(int i=0;i<n+2;i++){
            for(int j=i+1;j<n+2;j++){
                if(dist_func(arr[i].first,arr[i].second,arr[j].first,arr[j].second)<=1000){
                    dist[i][j]=1;
                    dist[j][i]=1;
                }
            }
        }
        
        for(int i=0;i<n+2;i++){
            for(int j=0;j<n+2;j++){
                for(int k=0;k<n+2;k++){
                    dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
                }
            }
        }
        
        if(dist[0][n+1]==INF)
            puts("sad");
        else
            puts("happy");
    }
}
