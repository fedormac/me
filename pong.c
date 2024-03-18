#include <stdio.h>

void print(int size_x, int size_y, int ball_pos_x, int ball_pos_y, int ra_p_fi_pl_y, int ra_p_se_pl_y,
           int point_1st, int point_2nd);                  //функция отрисовки
int move_racket(int ra_p_fi_pl_y, int size_y, char buff);  //функция перемещения ракеток
int move_ball_x(int ball_pos_x, int ball_speed_x);  //функция перемещения мяча по оси х
int move_ball_y(int ball_pos_y, int bl_sd_y);  //функция перемещения мяча по оси у
int bl_sd_y_change(int bl_sd_y);
void printScore(int point_1st, int point_2nd, int size_x);
void winer(int point_1st, int SCOPE);
int render(int point_1st, int point_2nd, int size_x, int size_y, int ball_pos_x, int ball_pos_y,
           int ra_p_fi_pl_y, int ra_p_se_pl_y, int ball_speed_x, int bl_sd_y, int SCOPE, char buff);

int main() {
    int size_x = 80, size_y = 25, ball_pos_x = 9, ball_pos_y = size_y / 2, ball_speed_x = 1, bl_sd_y = -1,
        point_1st = 0, point_2nd = 0, SCOPE = 21, ra_p_fi_pl_y = size_y / 2, ra_p_se_pl_y = size_y / 2;
    char buff = ' ';
    render(point_1st, point_2nd, size_x, size_y, ball_pos_x, ball_pos_y, ra_p_fi_pl_y, ra_p_se_pl_y,
           ball_speed_x, bl_sd_y, SCOPE, buff);
}

int render(int point_1st, int point_2nd, int size_x, int size_y, int ball_pos_x, int ball_pos_y,
           int ra_p_fi_pl_y, int ra_p_se_pl_y, int ball_speed_x, int bl_sd_y, int SCOPE, char buff) {
    while (point_1st < SCOPE && point_2nd < SCOPE) {  //основной цикл
        print(size_x, size_y, ball_pos_x, ball_pos_y, ra_p_fi_pl_y, ra_p_se_pl_y, point_1st, point_2nd);
        scanf("%c", &buff);
        if (buff == 's' || buff == 'w' || buff == 't' || buff == 'g' || buff == ' ') {
            if (buff == 's' || buff == 'w') {  //условный опператор проверяющий введённые данные
                ra_p_fi_pl_y = move_racket(ra_p_fi_pl_y, size_y, buff);  //перемещение ракетки
            } else if (buff == 't' || buff == 'g') {
                ra_p_se_pl_y = move_racket(ra_p_se_pl_y, size_y, buff);
            }
            if ((ball_pos_x + ball_speed_x == 1 && ball_pos_y + bl_sd_y == ra_p_fi_pl_y) ||
                (ball_pos_x + ball_speed_x == size_x - 2 && ball_pos_y + bl_sd_y == ra_p_se_pl_y)) {
                ball_speed_x *= -1;
                bl_sd_y = 0;  //столкнавение мяча с центральной частью ракетки
            } else if ((ball_pos_x + ball_speed_x == 1 && ball_pos_y + bl_sd_y == ra_p_fi_pl_y - 1) ||
                       (ball_pos_x + ball_speed_x == size_x - 2 &&
                        ball_pos_y + bl_sd_y == ra_p_se_pl_y - 1)) {
                ball_speed_x *= -1;  //столкнавение мяча с верхней частью ракетки
                bl_sd_y = -1;
            } else if ((ball_pos_x + ball_speed_x == 1 && ball_pos_y + bl_sd_y == ra_p_fi_pl_y + 1) ||
                       (ball_pos_x + ball_speed_x == size_x - 2 &&
                        ball_pos_y + bl_sd_y == ra_p_se_pl_y + 1)) {
                ball_speed_x *= -1;  //столкнавение мяча с нижней частью ракетки
                bl_sd_y = 1;
            }

            if (ball_pos_x + ball_speed_x == 0) {
                point_2nd += 1;  //выход мяча за пределы поля левого игрока и счетчик очков для правого игрока
                ball_pos_x = size_x / 2;
                ball_pos_y = size_y / 2;
                ball_speed_x *= -1;
                bl_sd_y = 0;
            } else if (ball_pos_x + ball_speed_x == size_x) {
                point_1st += 1;  //выход мяча за пределы поля правого игрока и счетчик очков для левого игрока
                ball_pos_x = size_x / 2;
                ball_pos_y = size_y / 2;
                ball_speed_x *= -1;
                bl_sd_y = 0;
            } else {
                ball_pos_x = move_ball_x(ball_pos_x, ball_speed_x);  //функция перемещения мяча горизонт
            }
            if ((ball_pos_y == 1 && bl_sd_y == -1) ||
                (ball_pos_y == size_y - 2 && bl_sd_y == 1)) {  //столконвение со стенами
                bl_sd_y = bl_sd_y_change(bl_sd_y);
            } else {
                ball_pos_y = move_ball_y(ball_pos_y, bl_sd_y);  //функция перемещения мяча вертикаль
            }
        }
    }
    winer(point_1st, SCOPE);
    return 0;
}

int move_ball_x(int ball_pos_x, int ball_speed_x) { return ball_pos_x + ball_speed_x; }  //функция перемещения
int move_ball_y(int ball_pos_y, int bl_sd_y) { return ball_pos_y + bl_sd_y; }  //функция перемещения
void winer(int point_1st, int SCOPE) {
    if (point_1st == SCOPE) {
        printf("\33[0d\33[2J");
        printf(
            "\n\n\n\n"
            "███████████████████████████████████"
            "\n"
            "█───█████───███─█████████─█████████"
            "\n"
            "█─██─███─██─████─███████─██████████"
            "\n"
            "█───███─███─█████─█████─███████████"
            "\n"
            "█─█████████─██████─█─█─████████████"
            "\n"
            "█─█████████─███████─█─█████████████"
            "\n"
            "███████████████████████████████████"
            "\n");
    } else {
        printf("\33[0d\33[2J");
        printf(
            "\n\n\n\n"
            "███████████████████████████████████"
            "\n"
            "█───█████────███─█████████─████████"
            "\n"
            "█─██─███████─████─███████─█████████"
            "\n"
            "█───███████─██████─█████─██████████"
            "\n"
            "█─████████─████████─█─█─███████████"
            "\n"
            "█─███████────███████─█─████████████"
            "\n"
            "███████████████████████████████████"
            "\n");
    }
}
int bl_sd_y_change(int bl_sd_y) { return bl_sd_y * -1; }  //инвертирование скорость мяча
int move_racket(int ra_p_fi_pl_y, int size_y, char buff) {  //перемещение ракетки
    if ((buff == 's' || buff == 'g') && ra_p_fi_pl_y < size_y - 3) {
        ra_p_fi_pl_y += 1;
    } else if ((buff == 'w' || buff == 't') && ra_p_fi_pl_y > 2) {
        ra_p_fi_pl_y -= 1;
    }

    return ra_p_fi_pl_y;
}
void printScore(int point_1st, int point_2nd, int size_x) {
    int score_panel_length = 0;
    char score_panel[10];

    sprintf(score_panel, " %d : %d ", point_1st, point_2nd);

    for (; score_panel[score_panel_length] != '\0'; score_panel_length++)
        ;

    int padding = ((size_x + 2) - score_panel_length) / 2;

    for (int i = 0; i < padding; i++) {
        printf(" ");
    };
    printf(" %d : %d \n\n", point_1st, point_2nd);
}
void print(int size_x, int size_y, int ball_pos_x, int ball_pos_y, int ra_p_fi_pl_y, int ra_p_se_pl_y,
           int point_1st, int point_2nd) {  //рендер всего на свете:)
    printf("\33[0d\33[2J");

    printScore(point_1st, point_2nd, size_x);

    for (int y = 0; y < size_y; y++) {
        for (int x = 0; x < size_x; x++) {
            if (y == 0 || y == size_y - 1) {
                printf("#");
            } else if (x == 0 || x == size_x - 1) {
                printf("#");
            } else if (ball_pos_x == x && ball_pos_y == y) {
                printf("*");
            } else if (x == (size_x / 2)) {
                printf("|");
            } else if (x == 1 && (ra_p_fi_pl_y == y || ra_p_fi_pl_y == y + 1 || ra_p_fi_pl_y == y - 1)) {
                printf("]");
            } else if (x == size_x - 2 &&
                       (ra_p_se_pl_y == y || ra_p_se_pl_y == y + 1 || ra_p_se_pl_y == y - 1)) {
                printf("[");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}