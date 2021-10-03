#include<cstdio>
using namespace std;
int main(){
    int h,w,x,y;
    scanf("%d%d",&h,&w);
    scanf("%d %d",&x,&y);
    printf("%d\n",(h-x)*(w-y));
}