#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#define size_x 30
#define size_y 10
struct xy {
    int x, y;
};

void print(struct xy *zmeika_head) {
    printf("\33[0d\33[2J");
    for (int y = 0; y < size_y; y++) {
        for (int x = 0; x < size_x; x++) {
            if (y == 0 || y == size_y - 1) {
                printf("#");
            } else if (x == 0 || x == size_x - 1) {
                printf("#");
            } else if (x == zmeika_head->x && y == zmeika_head->y) {
                printf("o");
            } else {
                printf(" ");
            }
        }

        printf("\n");
    }
}
void mov(char buff, struct xy *zmeika_spead, struct xy *zmeika_head) {
    if (buff == 'w') {
        zmeika_spead->y = -1;
        zmeika_spead->x = 0;
    } else if (buff == 'a') {
        zmeika_spead->y = 0;
        zmeika_spead->x = -1;
    } else if (buff == 's') {
        zmeika_spead->y = 1;
        zmeika_spead->x = 0;
    } else if (buff == 'd') {
        zmeika_spead->y = 0;
        zmeika_spead->x = 1;
    }
    zmeika_head->x += zmeika_spead->x;
    zmeika_head->y += zmeika_spead->y;
}

int main(void) {
    struct xy zmeika_head;
    struct xy zmeika_spead;
    zmeika_head.x = size_x / 2;
    zmeika_head.y = size_y / 2;
    zmeika_spead.x = 0;
    zmeika_spead.y = 0;

    char buff = '[';
    while (buff != 'q') {
        scanf("%c", &buff);
        if (buff == 'w' || buff == 'a' || buff == 's' || buff == 'd' || buff == ' ') {
            mov(buff, &zmeika_spead, &zmeika_head);
            print(&zmeika_head);
        }
    }
    return 0;
}
