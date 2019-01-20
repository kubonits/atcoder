#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int n,l,r,mid;
    char s1[10],s2[10],s3[10],x[10],f;
    strcpy(s1,"Vacant");
    strcpy(s2,"Male");
    strcpy(s3,"Female");
    cin>>n;
    cout<<"0\n"<<flush;
    cin>>x;
    if(strcmp(x,s1)==0){
        return 0;
    }
    if(strcmp(x,s2)==0){
        f=0;
    }
    else{
        f=1;
    }
    l=1;
    r=n-1;
    while(1){
        mid=(l+r)/2;
        cout<<mid<<"\n"<<flush;
        cin>>x;
        if(strcmp(x,s1)==0){
            return 0;
        }
        if(strcmp(x,s2)==0){
            if(mid%2==f){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        else{
            if(mid%2==f){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
    }
}