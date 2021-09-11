#include<cstdio>
using namespace std;
int main(){
    int a,b,n;
    scanf("%d %d %d",&a,&b,&n);
    for(int i=n;i<=40000;i++){
        if(i%a==0&&i%b==0){
            printf("%d\n",i);
            return 0;
        }
    }
}