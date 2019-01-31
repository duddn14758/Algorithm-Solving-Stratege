#include <iostream>

int main(){
    int a1,a2,r1,r2,p,n,m;
    bool t1=true,t2=true;
    bool dog1[1000],dog2[1000];

    std::cin>>a1>>r1>>a2>>r2;
    std::cout<<"hello";

    for(int i=0;i<1000;i++){
        if(i%(a1+r2)<=a1) dog1[i]=true;
        else dog1[i]=false;
        if(i%(a2+r2)<=a2) dog1[i]=true;
        else dog1[i]=false;
    }
    std::cin>>p>>n>>m;

    std::cout<<dog1[p]+dog2[p]<<std::endl<<dog1[m]+dog2[m]<<std::endl<<dog1[n]+dog2[n]<<std::endl;

    return 0;
}