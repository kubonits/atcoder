#include<cstdio>
using namespace std;
int main(){
    int k,a,maxa,t;
    scanf("%d %d",&k,&t);
    for(int i=0;i<t;i++){
        scanf("%d",&a);
        if(maxa<a){
            maxa=a;
        }
    }
    if(maxa<=(k+1)/2){
        printf("0\n");
    }
    else{
        printf("%d\n",maxa-(k-maxa)-1);
    }
}