#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include<algorithm>
//3-1
// int main()
// {
//     char s[100];
//     while (scanf("%s", s)!=0){
//         int score = 0,n=strlen(s),On=0;
//         for (int i = 0; i < n;i++){
//             if(s[i]=='O')
//                 On++;
//             else{
//                 for (int j = 1; j <= On;j++)
//                     score += j;
//                 On = 0;
//             }
//         }
//         if(On!=0)
//         for (int j = 1; j <= On;j++)
//             score += j;
//         printf("%d", score);
//     }
// }

//3-2
// int main()
// {
//     char s[100];
//     while (scanf("%s", s)!=0){
//         double mass = 0,single=0;
//         int n = strlen(s);
//         for (int i = 0; i < n;i++)
//         {
//             if(isdigit(s[i]))
//                 mass += single * (s[i] - '0'-1);
//             else{

//                 switch (s[i])
//                 {
//                     case 'C':
//                         single = 12.01;
//                         break;
//                     case 'H':
//                         single = 1.008;
//                         break;
//                     case 'O':
//                         single = 16.00;
//                         break;
//                     default:
//                         single = 14.01;
//                         break;
//                 }
//                 mass += single;
//             }
//         }
//         printf("%.3f\n", mass);
//     }
// }

//3-3
// int main()
// {
//     char s[10],c;
//     memset(s, 0, sizeof(s));
//     while ((c=getchar())!=EOF){

//         if(c!='\n'){
//             s[c - '0']++;
//         }
//         else{
//             for (int i = 0; i < 10;i++)
//             {
//                 printf("%d", s[i]);
//                 if(i!=9)
//                     putchar(' ');
//                 else
//                     putchar('\n');
//             }
//             memset(s, 0, sizeof(s));
//         }
//     }
// }

//3-4
// int main()
// {
//     char s[85];
//     while (scanf("%s", s) != 0)
//     {
//         int n = strlen(s);
//         for (int i = 1; i < n; i++)
//         {
//             if (n % i == 0)
//             {
//                 bool flag = false;
//                 int m = n / i;
//                 for (int k = 0; k < i; k++)
//                 {
//                     for (int j = 1; j < m; j++)
//                         if (s[k] != s[k + j * i])
//                         {
//                             flag = true;
//                             break;
//                         }
//                     if(flag)
//                         break;
//                 }
//                 if(flag==false){
//                     printf("%d\n", i);
//                     break;
//                 }
//             }
//         }
//     }
// }

//3-5
// char p[10][10];

// int main()
// {
//     int kase = 0;

//     while (true)
//     {
//         int x, y;
//         memset(p, '0', sizeof(p));
//         for (int i = 1; i <= 5; i++)
//             for (int j = 1; j <= 6; j++)
//             {
//                 p[i][j] = getchar();
//                 if (p[i][j] == '\n')
//                     p[i][j] = '0';
//                 if (p[i][j] == ' ')
//                 {
//                     x = i;
//                     y = j;
//                 }
//                 if (p[i][j] == 'Z')
//                     return 0;
//             }
//         char c;
//         bool flag = false;
//         while ((c = getchar()) != '0')
//         {

//             switch (c)
//             {
//             case 'A':
//                 if (p[x - 1][y] != '0')
//                 {
//                     p[x][y] = p[x - 1][y];
//                     p[--x][y] = ' ';
//                 }
//                 else
//                     flag = true;
//                 break;
//             case 'B':
//                 if (p[x + 1][y] != '0')
//                 {
//                     p[x][y] = p[x + 1][y];
//                     p[++x][y] = ' ';
//                 }
//                 else
//                     flag = true;
//                 break;
//             case 'L':
//                 if (p[x][y - 1] != '0')
//                 {
//                     p[x][y] = p[x][y - 1];
//                     p[x][--y] = ' ';
//                 }
//                 else
//                     flag = true;
//                 break;
//             case 'R':
//                 if (p[x][y + 1] != '0')
//                 {
//                     p[x][y] = p[x][y + 1];
//                     p[x][++y] = ' ';
//                 }
//                 else
//                     flag = true;
//                 break;
//             default:
//                 break;
//             }
//             if (flag)
//                 break;
//         }
//         getchar();
//         printf("Puzzle #%d:\n", ++kase);
//         if (flag)
//             printf("The puzzel has no final configuration.\n");
//         else
//         {
//             for (int i = 1; i <= 5; i++)
//                 for (int j = 1; j <= 5; j++)
//                 {
//                     putchar(p[i][j]);

//                     if (j < 5)
//                         putchar(' ');
//                     else
//                         putchar('\n');
//                 }
//             putchar('\n');
//         }
//     }
// }

//3-6
// char p[20][20];
// int num[20][20];

// int main()
// {
//     int r, c, kase = 0;
//     while (scanf("%d%d", &r, &c) != 0 && r != 0)
//     {
//         memset(p, '0', sizeof(p));
//         memset(num, 0, sizeof(num));
//         getchar();
//         for (int i = 1; i <= r; i++){
//             for (int j = 1; j <= c;j++)
//                 p[i][j] = getchar();
//             getchar();
//         }

//         int n = 0;
//         for (int i = 1; i <= r; i++)
//             for (int j = 1; j <= c; j++)
//             {
//                 if (p[i][j] != '*' && (p[i][j - 1] == '0' || p[i - 1][j] == '0' ||
//                 p[i - 1][j] == '*' || p[i][j - 1] == '*'))
//                     num[i][j] = ++n;
//             }

//         printf("Puzzle #%d:\n", ++kase);

//         printf("Across\n");
//         for (int i = 1; i <= r; i++)
//             for (int j = 1; j <= c;)
//             {
//                 if (p[i][j] != '*')
//                 {
//                     printf("%d.", num[i][j]);
//                     for (; p[i][j] != '*' && p[i][j] != '0'; j++)
//                         putchar(p[i][j]);
//                     putchar('\n');
//                 }

//                 else
//                 {
//                     for (; p[i][j] == '*'; j++)
//                         ;
//                 }
//             }

//         printf("Down\n");
//         for (int i = 1; i <= r; i++)
//             for (int j = 1; j <= c;j++)
//             {
//                 if (p[i][j] != '*'&& num[i][j]!=0)
//                 {
//                     printf("%d.", num[i][j]);
//                     for (int k=i; p[k][j] != '*' && p[k][j] != '0' ; k++){
//                         putchar(p[k][j]);
//                         num[k][j] = 0;
//                     }

//                     putchar('\n');
//                 }
//             }
//         putchar('\n');
//     }
// }

//3-7
// int a[5][1005];
// int main()
// {

//     int m, n,kase=0,time;
//     scanf("%d", &time);
//     while (++kase<=time)
//     {
//         scanf("%d%d", &m, &n);
//         memset(a, 0, sizeof(a));
//         getchar();
//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)

//                 switch (getchar())
//                 {
//                 case 'A':
//                     a[0][j]++;
//                     break;
//                 case 'C':
//                     a[1][j]++;
//                     break;
//                 case 'G':
//                     a[2][j]++;
//                     break;
//                 case 'T':
//                     a[3][j]++;
//                     break;
//                 default:
//                     break;
//                 }
//             getchar();
//         }
//         int  sum = 0, maxsum = 0;
//         int result[1005];
//         for (int j = 0; j < n; j++)
//         {
//             int max = 0;
//             for (int i = 0; i < 4; i++)
//             {
//                 sum += a[i][j];
//                 if (a[i][j] > max)
//                 {
//                     max = a[i][j];
//                     result[j] = i;
//                 }
//             }
//             maxsum += max;
//         }
//         for (int i = 0; i < n; i++)
//         {
//             if (result[i] == 0)
//                 putchar('A');
//             if (result[i] == 1)
//                 putchar('C');
//             if (result[i] == 2)
//                 putchar('G');
//             if (result[i] == 3)
//                 putchar('T');
//         }
//         putchar('\n');
//         printf("%d\n", sum - maxsum);
//     }
// }

//3-9
// char sub[500], s[1000];
// int main()
// {
//     while (scanf("%s", sub) != 0)
//     {
//         scanf("%s", s);
//         int sublen = strlen(sub);
//         int slen = strlen(s);
//         bool flag = true;
//         if (sublen > slen)
//             flag = false;

//         else
//         {
//             int mark = 0;
//             for (int i = 0; i < sublen; i++)
//             {
//                 int j = mark;
//                 while (sub[i] != s[j])
//                 {
//                     if (j == slen)
//                     {
//                         flag = false;
//                         break;
//                     }
//                     j++;
//                 }
//                 mark = j+1;
//             }
//         }
//         if (flag)
//             printf("Yes\n");

//         else
//         {
//             printf("No\n");
//         }
//     }
// }

//3-10
// #include<iostream>
// using namespace std;

// struct rect{
//     int x, y;
// }a[6];

// bool check(){
//     if(memcmp(a,a+1,sizeof(rect))!=0 || memcmp(a+2,a+3,sizeof(rect))!=0 || memcmp(a+4,a+5,sizeof(rect))!=0)
//         return false;
//     if(a[0].x!=a[2].x || a[0].y!=a[4].x || a[2].y!=a[4].y)
//         return false;
//     return true;
// }

// int main(){
//     while(cin>>a[0].x>>a[0].y>>a[1].x>>a[1].y>>a[2].x>>a[2].y>>a[3].x
//     >>a[3].y>>a[4].x>>a[4].y>>a[5].x>>a[5].y){
//         for (int i = 0; i < 6;i++)
//         if(a[i].x<a[i].y)
//             swap(a[i].x, a[i].y);
//         sort(a, a + 6, [](const rect a, const rect b) {return a.x == b.x ? a.y > b.y : a.x > b.x; });
//         printf("%s\n",check() ? "POSSIBLE" : "IMPOSSIBLE");
//     }
// }

//3-8
// int r[3005], mark[3005];
// int main(){
//     int a, b;
//     while(scanf("%d%d",&a,&b)!=0){
//         memset(mark, 0, sizeof(mark));
//         printf("%d/%d = %d.", a, b, a / b);
//         a = a % b;

//         int count = 1;

//         while(a){
//             a *= 10;
//             r[count] = a / b;
//             a = a % b;
//             if(mark[a]!=0)
//                 break;
//             mark[a]=count;
//             count++;
//         }

//         int start = mark[a], end = count;

//         if(a){
//         for (int i = 1; i <=end && i<51;i++){
//             if(i==start)
//                 printf("(");
//             printf("%d",r[i]);
//         }
//         if(end-start >50)
//             printf("...");
//         }
        
//         else
//         {
//             for (int i = 1; i <= start;i++)
//                 printf("%d", r[i]);
//             printf("(0");
//         }
        
//         printf(")\n");
//         printf("%d\n", end-start);
//     }
// }