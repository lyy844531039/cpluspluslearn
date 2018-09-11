#include<iostream>
#include<string>
using namespace std;
//W设为引用保证每次递归更新W的值，即子树的总重量
bool solve(int &W){
    int W1, W2, D1, D2;
    cin >> W1 >> D1 >> W2 >> D2;
    bool b1 = true,b2 = true;
    if(!W1)
        b1=solve(W1);
    if(!W2)
        b2=solve(W2);
    W = W1 + W2;
    return b1 && b2 && (W1 * D1 == W2 * D2);

}



int main(){
    int n,w;
    cin >> n;
    while(n--){
        if(solve(w)) cout<<"YES"<<endl;
        else
            cout << "NO" << endl;
    }
}