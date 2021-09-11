#include<cstdio>
using namespace std;
int main(){
    int a[5],k;
    for(int i=0;i<5;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    if(a[4]-a[0]<=k){
        printf("Yay!\n");
    }
    else{
        printf(":(\n");
    }
}