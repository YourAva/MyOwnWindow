#include "windowLogic.h"

int main(){
    HINSTANCE hInstance;
    HINSTANCE hPrevInstance;
    LPSTR lpCmdLine;
    int nCmdShow;
    char title[] = "hai";
    int x_scale = 1000;
    int y_scale = 1000;

    makeWindow(hInstance,hPrevInstance,lpCmdLine,nCmdShow, title, x_scale, y_scale);
}