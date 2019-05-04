#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;
int b[2][3],c[3][2],f[3][3];

pair<int,int> dfs(int x){
    pair<int,int> res,a;
    int flag=0;
    res=make_pair(0,0);
    if(x==9){
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                if(f[i][j]==f[i+1][j]){
                    res.first+=b[i][j];
                }
                else{
                    res.second+=b[i][j];
                }
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<2;j++){
                if(f[i][j]==f[i][j+1]){
                    res.first+=c[i][j];
                }
                else{
                    res.second+=c[i][j];
                }
            }
        }
        return res;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(!f[i][j]){
                if(x%2){
                    f[i][j]=1;
                    a=dfs(x+1);
                    if(res.second<a.second||flag==0){
                        res=a;
                        flag=1;
                    }
                    f[i][j]=0;
                }
                else{
                    f[i][j]=-1;
                    a=dfs(x+1);
                    if(res.first<a.first||flag==0){
                        flag=1;
                        res=a;
                    }
                    f[i][j]=0;
                }
            }
        }
    }
    return res;
}

int main(){
    pair<int,int> ans;
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&b[i][j]);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            scanf("%d",&c[i][j]);
        }
    }
    ans=dfs(0);
    printf("%d\n",ans.first);
    printf("%d\n",ans.second);
}