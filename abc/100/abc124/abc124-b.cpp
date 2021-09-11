#include<cstdio>
using namespace std;
int main(){
    int n,h[20],cnt=0,f;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&h[i]);
    }
    cnt=1;
    for(int i=1;i<n;i++){
        f=1;
        for(int j=0;j<i;j++){
            if(h[j]>h[i]){
                f=0;
            }
        }
        if(f){
            cnt++;
        }
    }
    printf("%d\n",cnt);
}