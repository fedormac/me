#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#define size_x 30
#define size_y 10
struct xy {
    int x, y;
};

void print(struct xy ballpoz,int poz_pl_1,int poz_pl_2) {
    printf("\33[0d\33[2J");
    for (int y = 0; y < size_y; y++) {
        for (int x = 0; x < size_x; x++) {
            if (y == 0 || y == size_y - 1) {
                printf("#");
            } else if (x == 0 || x == size_x - 1) {
                printf("#");
            }  else if (poz_pl_1== y && x== 1) {
                printf("]");
            }else if (poz_pl_2== y && x== size_x-2) {
                printf("[");
            }else if (ballpoz.x == x && y == ballpoz.y) {
                printf("0");
            }else {
                printf(" ");
            }
        }

        printf("\n");
    }
}

void stolk(struct xy *ballpoz, struct xy *ball_spead,int poz_pl_1,int poz_pl_2) {
    
    if (ballpoz->y == 1) {
        ball_spead->y *= -1;
    } else if (ballpoz->y == size_y - 2) {
        ball_spead->y *= -1;
    }else if (ballpoz->y == poz_pl_1&&ballpoz->x==1) {
        ball_spead->x *= -1;
    }else if (ballpoz->y == poz_pl_2&&ballpoz->x==size_x - 3) {
        ball_spead->x *= -1;
    }
}
void ball_move(struct xy *ballpoz, struct xy *ball_spead) {
    ballpoz->x += ball_spead->x;
    ballpoz->y += ball_spead->y;
}
void schot(struct xy *ballpoz){
    if (ballpoz->x==0){
        ballpoz->x=size_x/2;
        ballpoz->y=size_y/2;

    }else if (ballpoz->x == size_x - 1) {
        ballpoz->x=size_x/2;
        ballpoz->y=size_y/2;
    }


}
void p_mo(char buff,int *poz_pl_1,int *poz_pl_2){
    if(buff=='a'&&*poz_pl_1>1){
        
        *poz_pl_1-=1;
        
    }else if(buff=='z'&&*poz_pl_1<size_y-2){
        *poz_pl_1+=1;

    }else if(buff=='m'&&*poz_pl_2<size_y-2){
        *poz_pl_2+=1;

    }else if(buff=='k'&&*poz_pl_2>1){
        *poz_pl_2-=1;

    }
}
int main(void) {
    struct xy ballpoz;
    struct xy ball_spead;
    
    int poz_pl_1=size_y/2, poz_pl_2=size_y/2;
    char buff = '[';
    ball_spead.x = -1;
    ball_spead.y = 1;

    ballpoz.x = 5;
    ballpoz.y = 5;
    while (buff != 'w') {
        scanf("%c", &buff);
        
        p_mo(buff,&poz_pl_1,&poz_pl_2);
        ball_move(&ballpoz, &ball_spead);
        stolk(&ballpoz, &ball_spead,poz_pl_1,poz_pl_2);
        print(ballpoz,poz_pl_1,poz_pl_2);
        schot(&ballpoz);
    }
    return 0;
}
