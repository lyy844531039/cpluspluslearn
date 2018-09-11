#include<iostream>
using namespace std;

int main(){
    int D, I;
    while(cin>>D>>I){
        int node=1;
        for (int i = 0; i < D - 1;i++)
        {
            if(I%2) {
                node = node * 2;
                I = (I + 1) / 2;
            }
            else
            {
                node = node * 2 + 1;
                I = I / 2;
            }
        }
        cout << node << endl;
    }
}

// 使用第I个小球向左还是向右模拟小球下落路径