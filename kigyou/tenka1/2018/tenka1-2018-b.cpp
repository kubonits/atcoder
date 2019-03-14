#include<cstdio>
using namespace std;
int main(){
    int a,b,k;
    scanf("%d %d %d",&a,&b,&k);
    for(int i=0;i<k;i++){
        if(i%2==0){
            b+=a/2;
            a/=2;
        }
        else{
            a+=b/2;
            b/=2;
        }
    }
    printf("%d %d\n",a,b);
}