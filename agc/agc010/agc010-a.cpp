#include<cstdio>
using namespace std;
int main(){
    int n,a,cnt=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if(a%2){
            cnt++;
        }
    }
    if(cnt%2){
        printf("NO\n");
    }
    else{
        printf("YES\n");
    }
}