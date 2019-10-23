#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;

int main(){
    int n,a[200000],m1=-1,m2=-1;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(m1<a[i]){
            m2=m1;
            m1=a[i];
        }
        else{
            m2=max(m2,a[i]);
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]==m1){
            printf("%d\n",m2);
        }
        else{
            printf("%d\n",m1);
        }
    }
}