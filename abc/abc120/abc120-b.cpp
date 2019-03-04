#include<cstdio>
#include<vector>
using namespace std;

int main(){
    int a,b,k,cnt=0;
    vector<int> v;
    scanf("%d %d %d",&a,&b,&k);
    for(int i=1;i<=100;i++){
        if(a%i==0&&b%i==0){
            v.push_back(i);
        }
    }
    printf("%d\n",v[v.size()-k]);
}