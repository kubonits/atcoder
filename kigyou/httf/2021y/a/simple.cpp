#include<iostream>
#include<algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>
#include <deque>
#define MOD 1000000007
using namespace std;
typedef long long ll;
#include<cstring>


int main(){
    int x[100],y[100],a[20][20],px=0,py=0;
    for(int i=0;i<100;i++){
        cin>>x[i]>>y[i];
        a[x[i]][y[i]]=i;
        for(int j=0;j<abs(px-x[i]);j++){
            cout<<(px>x[i]?"U":"D");
        }for(int j=0;j<abs(py-y[i]);j++){
            cout<<(py>y[i]?"L":"R");
        }cout<<"I";
        px=x[i];
        py=y[i];
    }cout<<endl;
}