#include <raylib.h>
#include <iostream>

using namespace std;
class Ball{
public:
float x,y;
int speed_x,speed_y;
int radius;

void Draw(){
     DrawCircle(x,y,radius,WHITE);
}
void update(){
    x+=speed_x;  
    y+=speed_y;

    if(y + radius>=GetScreenHeight() || y-radius<=0){
        speed_y *=-1;                //This for collision with the walls
    }
    if(x+radius>=GetScreenWidth()|| x-radius<=0){
        speed_x *=-1;
    }
}
};  

Ball ball;

int main(){
    cout<<"Starting the game"<<endl;
    const int screen_width =1200;
    const int screen_height=800;  // Here we are using const because we cannot change the value of int it should be constant 
    InitWindow(screen_width,screen_height,"Pong game!!");  //This for the blank space 

     ball.radius=20;
     ball.x=screen_width/2;
     ball.y=screen_height/2;
     ball.speed_x=7;
     ball.speed_y=7;

    SetTargetFPS(60); //It ensures works same for the all computer devices
    while(WindowShouldClose()==false){
            BeginDrawing();
              //Updating
              ball.update();
               //Drawing 
               ClearBackground(BLACK);
               DrawLine(screen_width/2,0,screen_width/2,screen_height,WHITE);
            //    DrawCircle(screen_width/2,screen_height/2,20,WHITE);
               ball.Draw();
                DrawRectangle(10,screen_height/2-60,25,120,WHITE);
                DrawRectangle(screen_width-35,screen_height/2-60,25,120,WHITE);
              
            EndDrawing();
    }
    CloseWindow();//This is for ending 
    return 0;
}