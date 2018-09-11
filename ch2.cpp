

#include <math.h>
#include <stdio.h>
//2-3
// int main(){
//     int r1, r2, r3, kase = 0,total,flag;
//     while(scanf("%d%d%d",&r1,&r2,&r3)){
//         kase++;
//         flag = 1;
//         total = r3;
//         for (; total % 5 != r2;){
//             total += 7;
//             if(total>100){
//                 flag = 0;
//                 break;
//             }
//         }
//         for (; total % 3 != r1;){
//             total += 35;
//             if(total>100){
//                 flag = 0;
//                 break;
//             }
//         }
//         if(flag)
//             printf("Case %d: %d\n", kase, total);
//         else
//             printf("Case %d: No answer\n", kase);
//     }
// }

//2-5
// int main()
// {
//     int a,b,c,kase=0;
//     while(scanf("%d%d%d",&a,&b,&c)==3 && (a||b||c))
//     {
//         kase++;
//         printf("Case %d: %d.", kase, floor((double)a / b));
//         if(c==0)
//             {
//                 printf("\n");
//                 continue;
//             }
//         for (int i = 0; i < c-1;i++){
//             a = a * 10;
//             int s = floor((double)a / b);
//             int r = s % 10;
//             printf("%d",r);
//         }
//         a = a * 10;
//         int s = floor((double)a / b+0.5);
//         int r = s % 10;
//         printf("%d\n",r);
//     }
// }

//2-6
// int main(){
//     int a, b, c, d, e, f, g, h, i,s=123;
//     for (;s<=329;s++)
//     {
//         a = s / 100;
//         b = (s % 100) / 10;
//         c = s % 10;
//         int s1 =s * 2;
//         d = s1 / 100;
//         e = (s1 % 100) / 10;
//         f = s1 % 10;
//         int s2 = s * 3;
//         g = s2 / 100;
//         h = (s2 % 100) / 10;
//         i = s2 % 10;
//         // if(a!=b && a!=c && a!=d && a!=f &&a!=g&&a!=h&&a!=i)
//         // if(b!=c&&b!=d&&b!=e&&b!=f&&b!=g&&b!=h&&b!=i)
//         // if(c!=d&&c!=e&&c!=f&&c!=g&&c!=h&&c!=i)
//         // if(d!=e&&d!=f&&d!=g&&d!=h&&d!=i)
//         // if(e!=f&&e!=g&&e!=h&&e!=i)
//         // if(f!=g&&f!=h&&f!=i)
//         // if(g!=h&&g!=i)
//         // if(h!=i)
//         // printf("%d %d %d\n", s, s1, s2); //没有 考虑有0的情况
//         bool flag = true;
//         for (int j = 1; j < 10;j++)
//         if(j!=a && j!=b&&j!=c&&j!=d&&j!=e&&j!=f&&j!=g&&j!=h&&j!=i)
//             flag = false;
//         if(flag)printf("%d %d %d\n", s, s1, s2);
//     }
//     getchar();
// }


