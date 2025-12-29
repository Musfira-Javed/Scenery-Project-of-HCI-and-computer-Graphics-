#include <graphics.h>
#include <conio.h>
#include <stdlib.h>

//Sky and Ground
void drawSkyAndGround() {
    int skyBlue = COLOR(135, 206, 235);
    setcolor(skyBlue);
    setfillstyle(SOLID_FILL, skyBlue);
    bar(0, 0, 1250, 500);   // Sky

    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    bar(0, 500, 1250, 650); // Ground
    
}

//Rainbow 
void drawRainbow() {
    int x = 600, y = 550;
    int radius = 400;
   int colors[] = {RED,COLOR(255, 165, 0), YELLOW, GREEN, CYAN, BLUE, MAGENTA, COLOR(135, 206, 235)};


    for (int i = 0; i < 8; i++) {
        setcolor(colors[i]);
        setfillstyle(SOLID_FILL, colors[i]);
        pieslice(x, y, 0, 180, radius - (i * 8));
    }
}

// Mountain
void drawMountains() {
    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);

    int mountain1[] = {60, 550, 200, 370, 340, 550};
    fillpoly(3, mountain1);

    int mountain2[] = {220, 550, 360, 340, 500, 550};
    fillpoly(3, mountain2);

    int mountain3[] = {400, 550, 550, 370, 700, 550};
    fillpoly(3, mountain3);
}

void drawTree() {
    //Taller Trunk
    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    bar(90, 350, 120, 620); // taller and slightly wider trunk

    //Green Canopy
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    fillellipse(105, 300, 70, 70);  // top main canopy
    fillellipse(60, 360, 60, 60);   // left canopy
    fillellipse(150, 360, 60, 60);  // right canopy

    //Pink Flowers on Canopy
    int pink = COLOR(255, 105, 180); // Hot pink color
    setcolor(pink);
    setfillstyle(SOLID_FILL, pink);

    // random flower spots
    fillellipse(80, 320, 6, 6);
    fillellipse(100, 280, 5, 5);
    fillellipse(130, 310, 6, 6);
    fillellipse(70, 350, 5, 5);
    fillellipse(150, 340, 6, 6);
    fillellipse(120, 370, 5, 5);
    fillellipse(90, 340, 6, 6);
}


//House
void drawHouse() {
    int shiftX = 10;  // move to right
    int shiftY = -80;

    // Roof
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    int roof[] = {
        850 + shiftX, 420 + shiftY,
        970 + shiftX, 320 + shiftY,
        1090 + shiftX, 420 + shiftY,
        850 + shiftX, 420 + shiftY
    };
    fillpoly(4, roof);

    // Walls
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(870 + shiftX, 420 + shiftY, 1070 + shiftX, 600 + shiftY);

    // Door
    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    bar(940 + shiftX, 500 + shiftY, 995 + shiftX, 600 + shiftY);

    // Window
    setcolor(BLUE);
    setfillstyle(SOLID_FILL, BLUE);
    bar(890 + shiftX, 460 + shiftY, 930 + shiftX, 500 + shiftY);
}
void drawClouds() {
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    // Draw first cloud
    fillellipse(200, 100, 40, 20); 
    fillellipse(240, 100, 40, 20); 
    fillellipse(180, 100, 40, 20); 
    fillellipse(220, 80, 30, 15);   
    // Draw second cloud
    fillellipse(800, 120, 40, 20); 
    fillellipse(840, 120, 40, 20); 
    fillellipse(780, 120, 40, 20); 
    fillellipse(820, 100, 30, 15); 
}


//Sun
void drawSun() {
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(1050, 130, 60, 60);
}

//Rain
void drawRain(int rainY[]) {
    int rainColor = COLOR(173, 216, 230);
    for (int i = 0; i < 200; i++) {
        int x = (i * 6) % 1150;
        setcolor(rainColor);
        setlinestyle(SOLID_LINE, 0, 2);
        line(x, rainY[i], x + 2, rainY[i] + 12);
    }
}

//Moving Car
void drawMovingCar(int x) {
    int y = getmaxy() - 80; // base position

    // Car body
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    bar(x, y - 30, x + 80, y);

    // Roof
    bar(x + 15, y - 50, x + 65, y - 30);

    // Wheels
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(x + 15, y + 5, 8, 8);
    fillellipse(x + 65, y + 5, 8, 8);

    // Windows
    setcolor(LIGHTBLUE);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(x + 20, y - 45, x + 35, y - 35);
    bar(x + 45, y - 45, x + 60, y - 35);
}

//Main Function
int main() {
    int rainY[200];
    
    for (int i = 0; i < 200; i++)
        rainY[i] = rand() % 100;

    initwindow(1150, 700);
    cleardevice();

    drawSkyAndGround();
    drawRainbow();
    drawMountains();
    drawTree();
    drawHouse();  
    drawSun();
    drawClouds();
   
    drawRain(rainY);

    int car_x = -100;

    // Animation loop
    while (!kbhit()) {
        setcolor(GREEN);
        setfillstyle(SOLID_FILL, GREEN);
        bar(0, getmaxy() - 120, getmaxx(), getmaxy());

        setcolor(GREEN);
        setfillstyle(SOLID_FILL, GREEN);
        bar(0, 500, 1250, 1200);
        setcolor(WHITE);
        line(0,600,1250,600);
        line(0,650,1250,650);
        setfillstyle(1,DARKGRAY);
        floodfill(05,610,WHITE);

        drawMovingCar(car_x);

        delay(100);
        car_x += 10;

        if (car_x > getmaxx())
            car_x = -100;
    }
    
    getch();
    closegraph();
    return 0;
}


