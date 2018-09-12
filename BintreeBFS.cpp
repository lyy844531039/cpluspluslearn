//
//  main.cpp
//  project
//
//  Created by LU, Yunyao on 11/9/2018.
//  Copyright © 2018 LU, Yunyao. All rights reserved.
//

#include <iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>

using namespace std;


struct Node{
    int val;
    bool valued;
    Node * leftnode;
    Node * rightnode;
    Node():leftnode(NULL),rightnode(NULL),valued(false){}
};

Node *root;

Node * newnode(){ return new Node();}

bool addnode(int,string);

bool read_input(string &s){
    root=newnode();
    while (true) {
        int len=s.length();
        int v;
        sscanf(s.substr(1,len).c_str(),"%d",&v);
        if(!addnode(v,s.substr(s.find(",")+1,len-1)))
            return false;
        
    }
    return true;
}

bool addnode(int v, string s)
{
    int len=s.length();
    Node *cur=root;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='L'){
            if(root->leftnode==NULL)root->leftnode=newnode();
            cur=cur->leftnode;
        }
        else{
            if(root->rightnode==NULL)root->rightnode=newnode();
            cur=cur->rightnode;
        }
    }
    if(cur->valued) return false;
    cur->val=v;
    cur->valued=true;
    return true;
}

void remove_tree(Node *cur){
    if(cur==NULL) return;
    remove_tree(cur->leftnode);
    remove_tree(cur->rightnode);
    delete cur;
}

bool bfs(vector<int> &ans){
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *cur=q.front();q.pop();
        if(!cur->valued) return false;
        ans.push_back(cur->val);
        
        if(cur->leftnode!=NULL) q.push(cur->leftnode);
        if(cur->rightnode!=NULL) q.push(cur->rightnode);
    }
    return true;
}


int main(int argc, const char * argv[]) {
    string s;
    vector<int> ans;
    ans.clear();
    while(cin>>s){
        
        if(s=="()"){
            bfs(ans);
            for(int i=0;i<ans.size();i++)
                cout<<ans[i];
            cout<<endl;
            remove_tree(root);
            ans.clear();
        }
        else{
            read_input(s);
        }
    }

}
