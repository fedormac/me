#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
void On_create_g(int ***game_pole, int n, int m);
void render(int **game_pole, int n, int m);
void cp(int **pole, int **pole_cop, int n, int m);
void life_cheack(int **game_pole, int **game_pole_cop, int n, int m, int counter);
void dead_cheack(int **pole, int **pole_cop, int n, int m, int x, int y, int counnter);
void dead_cheack_con(int **pole, int n, int m, int x, int y, int i, int i2, int *counnter);
void life_cheack_con(int **pole, int **pole_cop, int n, int m, int x, int y, int *counnter);
void random_pole(int **pole, int n, int m);
void DELL(int ***pole, int n);
int main()
{
    // srand(time(NULL));
    int **game_pole = NULL, **game_pole_cop = NULL, n = 10, m = 20, counter = 0;

    On_create_g(&game_pole, n, m);
    On_create_g(&game_pole_cop, n, m);
    random_pole(game_pole, n, m);
    // game_pole[0][3] = 1;
    // game_pole[0][4] = 1;
    // game_pole[0][0] = 1;
    game_pole[n - 1][0] = 1;
    game_pole[n - 1][m - 1] = 1;
    game_pole[n - 2][m - 1] = 1;
    game_pole[n - 1][m - 2] = 1;
    game_pole[0][m - 1] = 1;
    // game_pole[5][m - 1] = 1;

    // game_pole[6][4] = 1;
    // game_pole[5][4] = 1;
    // game_pole[5][5] = 1;
    // game_pole[6][5] = 1;

    render(game_pole, n, m);
    sleep(1000);
    while (1)
    {
        sleep(1000);

        cp(game_pole_cop, game_pole, n, m);

        for (int i = 0; i < n; i++)
        {
            for (int i2 = 0; i2 < m; i2++)
            {
                if (game_pole[i][i2] == 1)
                {
                    dead_cheack(game_pole, game_pole_cop, n, m, i2, i, counter);
                }
                else
                {
                }
            }
        }
        cp(game_pole, game_pole_cop, n, m);
        render(game_pole, n, m);
    }

    DELL(&game_pole, n);
    DELL(&game_pole_cop, n);
    return 0;
}
void random_pole(int **pole, int n, int m)
{
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        for (int i2 = 0; i2 < m; i2++)
        {
            a = rand();
            if (a % 2 == 0)
            {

                pole[i][i2] = 1;
            }
        }
    }
}
void dead_cheack(int **pole, int **pole_cop, int n, int m, int x, int y, int counnter)
{

    for (int i = -1; i < 2; i++)
    {
        for (int i2 = -1; i2 < 2; i2++)
        {

            dead_cheack_con(pole, n, m, x, y, i, i2, &counnter);
        }
    }
    if (counnter < 2 || counnter > 3)
    {
        pole_cop[y][x] = 0;
    }

    printf(" %d \n", counnter);
}

void dead_cheack_con(int **pole, int n, int m, int x, int y, int i, int i2, int *counnter)
{

    if (x == 0 || y == 0 || x == m - 1 || y == n - 1)
    {

        if (x == 0 && !((y + i == y) && (x + i2 == x)) && !(y == 0 || y == n - 1))
        {

            if (pole[y + i][x + i2] == 1)
            {
                *counnter += 1;
            }
        }
        if (x == 0 && (m - 1) + i2 == (m - 1) && (x + i2 == x) && !(y == 0 || y == n - 1))
        {

            if (pole[y + i][(m - 1)] == 1)
            {
                *counnter += 1;
            }
        }
        if (y == 0 && !((y + i == y) && (x + i2 == x)) && (y + i >= 0) && !(x == 0 || x == m - 1))
        {
            // printf("y %d %d %d  \n", y + i, y, i);
            // printf("x %d %d %d  \n\n", x + i2, x, i2);

            if (pole[y + i][x + i2] == 1)
            {
                *counnter += 1;
            }
        }
        if (y == 0 && !((y + i == y) && (x + i2 == x)) && i == 1 && !(x == 0 || x == m - 1))
        {
            // printf("y %d %d %d  \n", y + i, y, i);
            // printf("x %d %d %d  \n\n", x + i2, x, i2);

            if (pole[n - 1][x + i2] == 1)
            {
                *counnter += 1;
            }
        }

        if (x == m - 1 && !((y + i == y) && (x + i2 == x)) && (x + i2 <= m - 1) && !(y == 0 || y == n - 1))
        {

            // printf("y %d %d %d  \n", y + i, y, i);
            // printf("x %d %d %d  \n\n", x + i2, x, i2);
            if (pole[y + i][x + i2] == 1)
            {
                *counnter += 1;
            }
        }
        if (x == m - 1 && !(y == 0 || y == n - 1))
        {

            // printf("y %d %d %d  \n", y + i, y, i);
            // printf("x %d %d %d  \n\n",  i2, x, i2);
            if (pole[y + i][i2] == 1)
            {
                *counnter += 1;
            }
        }

        if (y == n - 1 && !((y + i == y) && (x + i2 == x)) && (i <= 0) && !(x == 0 || x == m - 1))
        {

            // printf("y %d %d %d  \n", y + i, y, i);
            // printf("x %d %d %d  \n\n", x + i2, x, i2);
            if (pole[(n - 1) + i][x + i2] == 1)
            {
                *counnter += 1;
            }
        }
        if (y == n - 1 && (i == 0) && !(x == 0 || x == m - 1))
        {

            // printf("y %d %d %d  \n", 0, y, i);
            // printf("x %d %d %d  \n\n", x + i2, x, i2);
            if (pole[0][x + i2] == 1)
            {
                *counnter += 1;
            }
        }
    }

    else
    {
        // printf(" rrg ");

        if (!((y + i == y) && (x + i2 == x)) && (pole[y + i][x + i2] == 1))
        {
            // printf("%d %d ", i, i2);

            *counnter += 1;
        }
    }
}
void DELL(int ***pole, int n)
{

    if (*pole == NULL)
    {
        for (int i = 0; i < n; i++)
        {
            free((*pole)[i]);
        }

        free(*pole);
    }
}
// void life_cheack(int **pole, int **pole_cop, int n, int m, int x, int y, int *counnter)
// {

//     for (int i = 1; i < 2; i++)
//     {
//         for (int i2 = -1; i2 < 2; i2++)
//         {
//             if (i == 0 && i2 == 0)
//             {
//             }
//             else
//             {

//                 life_cheack_con(pole, pole_cop, n, m, x + i, y + i2, &counnter);
//             }
//         }
//     }
// }
// void life_cheack_con(int **pole, int **pole_cop, int n, int m, int x, int y, int *counnter)
// {
// }

void render(int **game_pole, int n, int m)
{
    printf("\n");
    // printf("\e[1;1H\e[2J");
    for (int i = 0; i < n; i++)
    {
        for (int i2 = 0; i2 < m; i2++)
        {
            printf("%d", game_pole[i][i2]);
        }
        printf("\n");
    }
}
void On_create_g(int ***game_pole, int n, int m)
{

    *game_pole = (int **)malloc(n * sizeof(int *));
    if (*game_pole == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        (*game_pole)[i] = (int *)calloc(m, sizeof(int));
    }
}
void cp(int **pole, int **pole_cop, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int i2 = 0; i2 < m; i2++)
        {

            pole[i][i2] = pole_cop[i][i2];
        }
    }
}