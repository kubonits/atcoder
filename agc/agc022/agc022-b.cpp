#include<cstdio>
#include<vector>
using namespace std;
int main(){
    int n,sum=0;
    vector<int> v;
    scanf("%d",&n);
    if(n==3){
        printf("2 5 63\n");
        return 0;
    }
    else if(n==4){
        printf("2 5 20 63\n");
        return 0;
    }
    else if(n==5){
        printf("2 5 20 30 63\n");
        return 0;
    }
    for(int i=2;i<=30000&&n;i++){
        if(i%2==0||i%3==0){
            v.push_back(i);
            sum+=i;
            sum%=6;
            n--;
        }
    }
    if(sum==2){
        for(int i=v.back()+1;i<=30000;i++){
            if(i%6==0){
                v.push_back(i);
                break;
            }
        }
        for(int i=0;i<v.size();i++){
            if(v[i]!=8){
                printf("%d ",v[i]);
            }
        }
        printf("\n");
    }
    else if(sum==3){
        for(int i=v.back()+1;i<=30000;i++){
            if(i%6==0){
                v.push_back(i);
                break;
            }
        }
        for(int i=0;i<v.size();i++){
            if(v[i]!=9){
                printf("%d ",v[i]);
            }
        }
        printf("\n");
    }
    else if(sum==5){
        for(int i=v.back()+1;i<=30000;i++){
            if(i%6==4){
                v.push_back(i);
                break;
            }
        }
        for(int i=0;i<v.size();i++){
            if(v[i]!=9){
                printf("%d ",v[i]);
            }
        }
        printf("\n");
    }
    else{
        for(int i=0;i<v.size();i++){
            printf("%d ",v[i]);
        }
        printf("\n");
    }
}