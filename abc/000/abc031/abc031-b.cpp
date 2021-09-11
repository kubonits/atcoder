#include<cstdio>
using namespace std;
int main(){
    int l,h,n,a;
    scanf("%d %d",&l,&h);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if(a>h){
            printf("-1\n");
        }
        else if(a<l){
            printf("%d\n",l-a);
        }
        else{
            printf("0\n");
        }
    }
}