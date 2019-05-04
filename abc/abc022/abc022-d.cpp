#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
double ax[100000],bx[100000],ay[100000],by[100000],cx[2]={},cy[2]={},d[2]={};
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf %lf",&ax[i],&ay[i]);
        cx[0]+=ax[i];
        cy[0]+=ay[i];
    }
    cx[0]/=(double)n;
    cy[0]/=(double)n;
    for(int i=0;i<n;i++){
        scanf("%lf %lf",&bx[i],&by[i]);
        cx[1]+=bx[i];
        cy[1]+=by[i];
    }
    cx[1]/=(double)n;
    cy[1]/=(double)n;
    for(int i=0;i<n;i++){
        d[0]=max(d[0],sqrt((ax[i]-cx[0])*(ax[i]-cx[0])+(ay[i]-cy[0])*(ay[i]-cy[0])));
        d[1]=max(d[1],sqrt((bx[i]-cx[1])*(bx[i]-cx[1])+(by[i]-cy[1])*(by[i]-cy[1])));
    }
    printf("%.8f\n",d[1]/d[0]);
}