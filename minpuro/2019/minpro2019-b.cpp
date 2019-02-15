#include<cstdio>

using namespace std;
int main(){
    int a,b,g[5]={},f=1;
    for(int i=0;i<3;i++){
        scanf("%d%d",&a,&b);
        g[a]++;
        g[b]++;
    }
    for(int i=1;i<=4;i++){
        if(g[i]==0||g[i]==3){
            f=0;
        }
    }
    if(f){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}
