#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int main(){
    double a,ans;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf",&a);
        ans+=1.0/a;
    }
    printf("%.6f\n",1.0/ans);
}