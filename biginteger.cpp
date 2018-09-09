//
//  main.cpp
//  project
//
//  Created by LU, Yunyao on 9/9/2018.
//  Copyright © 2018 LU, Yunyao. All rights reserved.
//

#include <iostream>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>

struct BigInteger{
    static const int BASE=100000000;
    static const int width=8;
    std::vector<int> s;
    
    
    BigInteger(long long num){*this=num;}
    BigInteger operator = (long long num){
        do{
            s.push_back(num%BASE);
            num/=BASE;
        }while(num);
        return *this;
    }
    
    BigInteger operator=(std::string &str){
        s.clear();
        int x,len=(str.length()-1)/width +1;
        for(int i=0;i<len;i++){
            int end=str.length()-i*width;
            int start=std::max(0,end-width);
            sscanf(str.substr(start,end).c_str(),"%d",&x);
            s.push_back(x);
        }
        return *this;
    }
};

std::ostream& operator<<(std::ostream &out, const BigInteger &x){
    out<<x.s.back();
    for(int i=x.s.size()-2;i>=0;i--){
        char buf[20];
        sprintf(buf,"%08d", x.s[i]);
        for(int j=0;j<strlen(buf);j++)
            out<<buf;
    }
    return out;
}

std::istream& operator>>(std::istream &in,const BigInteger &x){
    std::string s;
    if(!(in>>s)) return in;
    x=s;
    return in;
}

//int main(int argc, const char * argv[]) {
//    BigInteger bi=12345678910;
//    std::cin>>bi;
//    std::cout<<bi;
//}

