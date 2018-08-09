#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXX_N 100
#define INF 9

int n,m,cnt,visited[MAXX_N+1],check[MAXX_N+1],dist[MAXX_N+1][MAXX_N+1];
vector<vector<int>> vt;
vector<int> ans;
vector<vector<int>> comp;

void dfs(int here,int num){
    visited[here]=1;
    check[here]=num;
    comp[num].push_back(here);
    for(int i=0;i<vt[here].size();i++){
        int there=vt[here][i];
        if(visited[there])
            continue;
        dfs(there,num);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    vt.resize(n+1);
    comp.resize(n+1);
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dist[i][j]=INF;
        }
    }
    
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        dist[a][b]=1;
        dist[b][a]=1;
        vt[a].push_back(b);
        vt[b].push_back(a);
    }
    
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cnt++;
            dfs(i,cnt);
        }
    }

    for(int i=0;i<=n;i++)
        dist[i][i]=0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(check[i]!=check[j]||check[j]!=check[k]||check[i]!=check[k])
                    continue;
                dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
            }
        }
    }
    
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//            printf("%d ",dist[i][j]);
//        }
//        puts("");
//    }
    
    for(int i=1;i<=cnt;i++){
        int cmp=INF;
        int candidate=comp[i][0];
        for(int j=0;j<comp[i].size();j++){
            int tmp=comp[i][j];
            int mola=-1;
            for(int k=1;k<=n;k++){
                if(dist[tmp][k]==INF) continue;
//                if(dist[tmp][k]<cmp){
//                    cmp=dist[tmp][k];
//                    candidate=tmp;
//                }
                mola=max(mola,dist[tmp][k]);
            }
            if(cmp>mola){
                cmp=mola;
                candidate=tmp;
            }
            
        }
        ans.push_back(candidate);
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",cnt);
    for(int i=0;i<ans.size();i++)
        printf("%d\n",ans[i]);
}
