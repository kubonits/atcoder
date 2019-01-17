#include<cstdio>
using namespace std;
int main(){
    double n;
    int w;
    scanf("%lf",&n);
    for(double i=1;i<=3500;i++){
        for(double j=1;j<=3500;j++){
            w=(n*i*j)/(4*i*j-n*i-n*j);
            if((double)w==(n*i*j)/(4*i*j-n*i-n*j)&&w>0){
                printf("%.0f %.0f %d\n",i,j,w);
                return 0;
            }
        }
    }
}