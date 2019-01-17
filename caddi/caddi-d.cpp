#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,a[100000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]%2){
            printf("first\n");
            return 0;
        }
    }
    printf("second\n");
}