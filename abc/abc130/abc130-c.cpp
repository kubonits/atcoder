#include<cstdio>
using namespace std;
int main(){
    double x,y,h,w;
    scanf("%lf %lf %lf %lf",&w,&h,&x,&y);
    printf("%f ",h*w/2);
    if(x==w/2&&y==h/2){
        printf("1\n");
    }
    else{
        printf("0\n");
    }
}