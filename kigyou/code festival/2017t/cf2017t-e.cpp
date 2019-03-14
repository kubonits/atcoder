#include<cstdio>
using namespace std;

int main(){
    int n,w[50],ans,fi[5]={1,5,25,125,625},f[50]={},sa[5]={781,1,6,31,156};
    scanf("%d",&n);
    for(int i=0;i<(n-1)/5+1;i++){
        printf("? ");
        for(int j=0;j<n;j++){
            if(j/5==i){
                printf("%d ",fi[j%5]);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
        fflush(stdout);
        scanf("%d",&ans);
        if((i+1)*5>n){
            ans-=8*sa[n%5];
        }
        else{
            ans-=6248;
        }
        for(int j=0;j<5;j++){
            if(ans%5==1||ans%5==3){
                f[i*5+j]=1;
            }
            ans/=5;
        }
    }
    printf("! ");
    for(int i=0;i<n;i++){
        printf("%d ",f[i]);
    }
    printf("\n");
    fflush(stdout);
}