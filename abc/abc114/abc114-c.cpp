#include<cstdio>
using namespace std;

long n,ans,keta=0,f[10];

int dfs(int a){
    long flag=1,b=0,c=0,fl[3]={};
    for(int i=a-1;i>=0;i--){
        c*=10;
        c+=f[i];
    }
    if(c>n){
        return 0;
    }
    if(a==9){
        for(int i=0;i<a;i++){
            if(f[i]==3){
                fl[0]=1;
            }
            else if(f[i]==5){
                fl[1]=1;
            }
            else if(f[i]==7){
                fl[2]=1;
            }
        }
        if(fl[0]&&fl[1]&&fl[2]){
            //printf("%ld\n",c);
            return 1;
        }
        else{
            return 0;
        }
    }
    for(int i=0;i<a;i++){
        if(f[i]==0){
            f[a]=0;
            return dfs(a+1);
        }
    }
    if(a>2){
        f[a]=0;
        b=dfs(a+1);
    }
    f[a]=3;
    b+=dfs(a+1);
    f[a]=5;
    b+=dfs(a+1);
    f[a]=7;
    b+=dfs(a+1);
    return b;
}

int main(){
    scanf("%ld",&n);
    printf("%d\n",dfs(0));
}