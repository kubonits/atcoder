#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int a[5];
    vector<int> v;
    for(int i=0;i<5;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            for(int k=j+1;k<5;k++){
                v.push_back(a[i]+a[j]+a[k]);
            }
        }
    }
    sort(v.begin(),v.end());
    printf("%d\n",v[7]);
}