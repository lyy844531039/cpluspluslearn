//
//  main.cpp
//  try
//
//  Created by LU, Yunyao on 10/9/2018.
//  Copyright © 2018 LU, Yunyao. All rights reserved.
//
#include<cstdio>
#include <iostream>
#include <vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;


typedef queue<string> cmds;
queue<int> block;
deque<int> ready;
vector<cmds> pid_cmds;


int t[5],var[26],tq;
bool locked;

void run(int pid);

int main(int argc, const char * argv[]) {
    int kase,n;
    cin>>kase;
    while(kase--){
        cin>>n>>t[0]>>t[1]>>t[2]>>t[3]>>t[4]>>tq;
        cin.get();
        for(int i=0;i<n;i++){
            cmds commands;
            string command;
            getline(cin,command);
            commands.push(command);
            while(command!="end"){
                getline(cin,command);
                commands.push(command);
            }
            pid_cmds.push_back(commands);
            ready.push_back(i);
        }
        
        locked=false;
        
        while(!ready.empty()){
            int pid=ready.front();
            ready.pop_front();
            run(pid);
        }
        
    }
}

void run(int pid){
    int q=tq;
    

    while(q>0){
        string command=pid_cmds[pid].front();
        pid_cmds[pid].pop();
        switch (command[2]) {
            case '=':
                sscanf(command.substr(4,command.size()).c_str(),"%d",&var[command[0]-'a']);
                q-=t[0];
                break;
            case 'i':
                cout<<pid+1<<":"<<var[command[6]-'a']<<'\n';
                q-=t[1];
                break;
            case 'c':
                if(locked) {block.push(pid);return;}
                locked=true;
                q-=t[2];
                break;
            case 'l':
                if(!block.empty()){
                    int pid2=block.front();
                    block.pop();
                    ready.push_front(pid2);
                }
                q-=t[3];
                break;
            case 'd':
                q-=t[4];
                return;
            default:
                break;
        }
        
    }

        ready.push_back(pid);

}
