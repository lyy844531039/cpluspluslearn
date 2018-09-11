#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
//e.g.4-2
// char answer[100], input[100];
// int chance;

// int judge(int anlen, int inlen)
// {
//     int show = 0;
//     for (int i = 0; i < inlen; i++)
//     {
//         bool match = false;
//         for (int j = 0; j < anlen; j++)
//             if (input[i] == answer[j])
//             {
//                 match = true;
//                 answer[j] = ' ';
//                 show++;
//             }
//         if(show==anlen)
//             return 1;
//         if(!match)
//             chance--;
//         if(chance<=0)
//             return 0; //lose
//     }
//     return -1;
// }

// int main()
// {
//     int num;
//     while (scanf("%d", &num) && num != -1)
//     {
//         chance = 7;
//         scanf("%s", answer);
//         scanf("%s", input);
//         int anlen = strlen(answer), inlen = strlen(input);

//         printf("Round %d\n", num);
//         switch (judge(anlen,inlen))
//         {
//             case 0:
//                 printf("You lose.\n");
//                 break;

//             case 1:
//                 printf("You win.\n");
//                 break;
//             case -1:
//                 printf("You chickened.\n");
//         }
//     }
// }

//e.g.4-3
// int a[25];
// int m, n, k;

// void go(int &p,int d,int t){
//     while(t--){
//         do{p = (p + d + n) % n ;
//         } while (a[p] == 0);
//     }
// }

// int main()
// {

//     while (scanf("%d%d%d", &n, &k, &m))
//     {
//         memset(a, -1, sizeof(a));
//         int A = n-1, B = 0, picked = 0;
//         while (picked != n)
//         {
//             go(A, 1, k);
//             go(B, -1, m);

//             a[B] = a[A] = 0;
//             printf("%3d", A + 1);
//             picked++;
//             if (A != B)
//             {
//                 printf("%3d", B + 1);
//                 picked++;
//             }
//             if(picked!=n) printf(",\n");
//             else
//                 printf("\n");
//         }

//     }

// }

//e.g.4-4
// char codes[8][128];

// char readchar()
// {
//     char ch;
//     while (true)
//     {
//         ch = getchar();
//         if (ch != '\n' && ch != '\r')
//             break;
//     }
//     return ch;
// }

// int readcodes()
// {
//     memset(codes, 0, sizeof(codes));
//     codes[1][0] = readchar();
//     for (int len = 2; len <= 7; len++)
//         for (int i = 0; i < (1 << len) - 1; i++)
//         {
//             char ch = getchar();
//             if (ch == EOF)
//                 return 0;
//             if (ch == '\n' || ch == '\r')
//                 return 1;
//             codes[len][i] = ch;
//         }
//     return 1;
// }

// int readint(int n)
// {
//     int total = 0;
//     while (n--)
//     {
//         int a = (readchar() - '0');
//         total = total * 2 + a;
//     }
//     return total;
// }

// int main()
// {
//     while (readcodes())
//     {
//         while (true)
//         {
//             int len = readint(3);
//             if(len==0)
//                 break;
//             int end = (1 << len) - 1;
//             int value;
//             while ((value = readint(len)) != end)
//             {
//                 putchar(codes[len][value]);
//             }
//         }
//         putchar('\n');
//     }
// }

//  int dice[7][7] = {{1, 2, 3, 4, 5, 6}, {5, 1, 3, 4, 6, 2}, {6, 5, 4, 3, 2, 1},
//   {3, 2, 6, 1, 5, 4}, {4, 2, 1, 6, 5, 3}, {2, 6, 3, 4, 1, 5}};


// int main()
// {
//     char t[15], b[7];
//     char a[7];
//     while (scanf("%s", t)!=EOF)
//     {
        
        
//         bool equal =false;
//         for (int i = 0; i < 6; i++)
//         {
            
//             for (int j = 0; j < 6; j++)
//                 a[j] = t[dice[i][j]-1];
//             for (int j = 0; j < 6;j++)
//                 b[j] = t[6+j];
//             b[6] = '\0';
//             a[6] = '\0';
//             if(strcmp(a,b)==0){
//                 equal = true;
//                 break;
//             }

//             for (int n = 3; n--;)
//             {
//                 char tmp = b[1];
//                 b[1] = b[2];
//                 b[2] = b[4];
//                 b[4] = b[3];
//                 b[3] = tmp;

//                 if(strcmp(a,b)==0){
//                     equal = true;
//                     break;
//                 }
//             }
//             if (equal)
//             break;
//         }
//         if(equal)
//             printf("TRUE\n");
        
//         else
//         {
//             printf("FALSE\n");
//         }
        
//     }
// }
