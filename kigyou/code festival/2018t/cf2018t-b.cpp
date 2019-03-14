#include<cstdio>
using namespace std;
int main(){
    int x,y,z;
    scanf("%d %d",&x,&y);
    if((x+y)%4==0){
        z=(x+y)/4;
        if(x-z>=0&&(x-z)%2==0&&y-z>=0&&(y-z)%2==0){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
}