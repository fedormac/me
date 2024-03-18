#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>


// int foo(float *a) {
//     if (!(scanf("%f", a) == 1)) {      //float
//         printf("n/a");
//         return 0;
//     }
//     if (!(*a != (int)*a)) {
//         printf("n/a");
//         return 0;
//     }
//     return 1;
// }

int foo(float *a) {                         // int
    if (!(scanf("%f", a) == 1)) {
        printf("n/a");
        return 0;
    }
    if (*a != (int)*a) {
        printf("n/a");
        return 0;
    }
    *a=(int)*a;
    return 1;
}

int main() {
    float f_;
    int f;
    foo(&f_);
    f=(int)f_;
    // printf("%.0f",f);

    printf("%d", f);

    return 0;
}

// int main() {  ь                                              //динамический массив
//     int *a,s;
//     scanf("%d",&s);
//     a = (int*)malloc(s * sizeof(int));
//     for (int i = 0; i < s; i++)
//     {
//         a[i]=i;
//     }
    
// for (int i = 0; i < s+2; i++)
// {
//     printf("%d",a[i]);
// }

//     free(a);
//     if (a==NULL){
//         printf("rfegegergr");
//     }

//     return 0;
// }




// #define FABS(x) ((x) < 0 ? -(x) : (x))    //квадратный корень

// double newton_sqrt(double x)

// {
//   double precision = 1e-9;
//   double result = 1.0, current;

//   do
//   {
//     current = result;
//     result = (current + x / current) / 2;
//   } while (FABS(result - current) > precision);

//   return result;
// }

// int main(void) {
//     double x=2.0;
//     printf("%lf",newton_sqrt( x));
//     return 0;
// }

// #include <ncurses.h>
// #include <stdio.h>
// #include <stdlib.h>

// int foo(int *a, int *b, char *c,int d[]) {
//     *a = 6 + 15;
//     d[2]=40;

//     *b = 6;
//     *c = 'd';

// }

// int main() {
//     int d[3]={};

//     char c=' ';
//     int a = 4;
//     int b = 4;
//     foo(&a, &b, &c,d);

//     printf(" %d %d %c %d \n", a, b, c,d[2]);
//     //free(d);
//     printf(" %d %d %c %d", a, b, c,d[2]);
//     //       char a;
//     getch(a)

//     printf(
//     "███████████████████████████████████" "\n"
//     "█─███─█───█─███────█────█─███─█───█" "\n"
//     "█─███─█─███─███─██─█─██─█──█──█─███" "\n"
//     "█─█─█─█───█─███─████─██─█─█─█─█───█" "\n"
//     "█─────█─███─███─██─█─██─█─███─█─███" "\n"
//     "██─█─██───█───█────█────█─███─█───█" "\n"
//     "███████████████████████████████████" "\n");

//     printf("\n\n\n\n"
//     "███████████████████████████████████" "\n"
//     "█───█████───███─█████████─█████████" "\n"
//     "█─██─███─██─████─███████─██████████" "\n"
//     "█───███─███─█████─█████─███████████" "\n"
//     "█─█████████─██████─█─█─████████████" "\n"
//     "█─█████████─███████─█─█████████████" "\n"
//     "███████████████████████████████████" "\n");

//    printf("\n\n\n\n"
//     "███████████████████████████████████" "\n"
//     "█───█████────███─█████████─████████" "\n"
//     "█─██─███████─████─███████─█████████" "\n"
//     "█───███████─██████─█████─██████████" "\n"
//     "█─████████─████████─█─█─███████████" "\n"
//     "█─███████────███████─█─████████████" "\n"
//     "███████████████████████████████████" "\n");

// return 0;
// }