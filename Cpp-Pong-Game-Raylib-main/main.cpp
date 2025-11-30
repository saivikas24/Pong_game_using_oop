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

class paddle{
    protected:
        void LimitMovement(){
            if(y <=0){
                y=0;
        }
            if(y+height >= GetScreenHeight()){

            y= GetScreenHeight() - height;
        }
}
    public:
    
    float x,y;
    float width,height;
    int speed;

    void Draw(){
       DrawRectangle(x,y, width, height , WHITE);
    }

    void Update(){
        if(IsKeyDown(KEY_UP)){
            y=y - speed; 
        }
        if(IsKeyDown(KEY_DOWN)){
            y=y + speed;
        }
       LimitMovement();
    }
};

class CpuPaddle: public paddle{
    public:

    void Update(int ball_y){
         if(y+height/2 > ball_y){
            y= y-speed;
        };
        if(y + height/2 <=ball_y){
            y =y+speed;
        }
        LimitMovement();
    }
    
};

Ball ball;
paddle player;
CpuPaddle cpu;

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

    player.width=25;
    player.height=120;
    player.x = screen_width - player.width-10;
    player.y=screen_height/2 - player.height/2;
    player.speed=6;

    cpu.height = 120;
    cpu.width=25;
    cpu.x=10;
    cpu.y=screen_height/2 - cpu.height/2;
    cpu.speed=6;

    SetTargetFPS(60); //It ensures works same for the all computer devices
    while(WindowShouldClose()==false){
            BeginDrawing();
              //Updating
              ball.update();
              player.Update();
              cpu.Update(ball.y);
               //Drawing 
               ClearBackground(BLACK);
               DrawLine(screen_width/2,0,screen_width/2,screen_height,WHITE);
            //    DrawCircle(screen_width/2,screen_height/2,20,WHITE);
               ball.Draw();
               cpu.Draw();
            // DrawRectangle(10,screen_height/2-60,25,120,WHITE);
                player.Draw();
                
                
            EndDrawing();
    }
    CloseWindow();//This is for ending 
    return 0;
}
