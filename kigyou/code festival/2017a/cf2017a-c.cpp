#include<cstdio>
using namespace std;
int main(){
    int h,w,f[30]={},flag[4]={},ans=1;
    scanf("%d %d",&h,&w);
    char a[100][101];
    for(int i=0;i<h;i++){
        scanf("%s",a[i]);
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            f[a[i][j]-'a']++;
        }
    }
    for(int i=0;i<30;i++){
        flag[f[i]%4]++;
    }
    if(w%2&&h%2){
        if(flag[1]+flag[3]!=1){
            ans=0;
        }
        if(flag[3]+flag[2]>(w+h-2)/2){
            ans=0;
        }
    }
    else if(w%2!=h%2){
        if(flag[1]||flag[3]){
            ans=0;
        }
        if(h%2&&flag[2]>w/2){
            ans=0;
        }
        if(w%2&&flag[2]>h/2){
            ans=0;
        }
    }
    else if(flag[1]||flag[2]||flag[3]){
        ans=0;
    }
    if(ans){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}