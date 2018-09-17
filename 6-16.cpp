#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;
int G[26][26], vis[26], in[26], out[26];
char word[1000];
int cnt = 0;

void dfs(int u)
{
    if (vis[u])
        return;
    vis[u] = 1;
    for (int v = 0; v < 26; v++)
    {
        if (G[u][v])
        {
            dfs(v);
        }
    }
}

bool hasEuler()
{
    int cnt1 = 0, cnt2 = 0, start;

    for (int i = 0; i < 26; i++)
    {
        int t = out[i] - in[i];
        if (t == 1)
        {
            cnt1++;
            start = i;
        }
        else if (t == -1)
            cnt2++;
        else if (t != 0)
            return false;
    }

    if (cnt1 && cnt2 && cnt1 + cnt2 > 2)
        return false;

    dfs(start);
    for (int i = 0; i < 26; i++)
        if ((in[i] || out[i]) && !vis[i])
            return false;

    return true;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        memset(G, 0, sizeof(G));
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        memset(vis, 0, sizeof(vis));
 
        int m;
        cin >> m;
        while (m--)
        {
            cin >> word;
            G[word[0] - 'a'][word[strlen(word) - 1] - 'a']++;
            out[word[0] - 'a']++;
            in[word[strlen(word) - 1] - 'a']++;
        }
        if(hasEuler())
            cout << "Ordering is possible.\n";
        else
            cout << "The door cannot be opened.\n";
    }
}