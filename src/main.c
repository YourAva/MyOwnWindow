#include "windowLogic.h"
#include <stdio.h>
#include <time.h>

#define X_SCALE 1920
#define Y_SCALE 1080

int main(){
    // HINSTANCE hInstance;
    // HINSTANCE hPrevInstance;
    // LPSTR lpCmdLine;
    // int nCmdShow;
    // int x_scale;
    // int y_scale;
    // char title[20];

    // printf("title: ");
    // scanf("%s", title);
    // printf("x_scale: ");
    // scanf("%i", &x_scale);
    // printf("y_scale: ");
    // scanf("%i", &y_scale);

    srand(time(NULL));
    makeWindow("title", X_SCALE, Y_SCALE, rand() % 30);
    return 0;
}