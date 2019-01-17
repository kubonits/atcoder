#include<cstdio>
using namespace std;

int main(){
    int n[4],f[10]={};
    for(int i=0;i<4;i++){
        scanf("%d",&n[i]);
        f[n[i]]=1;
    }
    if(f[1]&&f[9]&&f[4]&&f[7]){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}