#include <stdio.h>
#include <vector>
#include "raylib.h"

using namespace std;


#define WIDTH 900
#define HEIGHT 600
#define FPS 120

#define BULLET_SPEED 100
#define GROUND_Y (HEIGHT*0.8)
#define GROUND_THICKNESS 5

#define GUN_LENGTH 50
#define BULLET_SIZE 10

vector<Vector2> Bullets;


int main(void) {
		
	
	InitWindow(WIDTH, HEIGHT, "Shooter Game");
  	SetTargetFPS(FPS);
    
    Vector2 groundStartPos = {0,GROUND_Y};
    Vector2 groundEndPos = {WIDTH, GROUND_Y};
	
	Vector2 gunPosition = {WIDTH/2, GROUND_Y - GROUND_THICKNESS/2 - GUN_LENGTH}; // initialization (centralized)


	while(!WindowShouldClose())
	{
    	BeginDrawing();
    	
    	ClearBackground(BLACK);
    	
    	DrawText("Shooter Game.", 0, 0, 20, GREEN);
    	
    	// Draw Ground:
    	DrawLineEx(groundStartPos, groundEndPos, GROUND_THICKNESS, GRAY);
    

		if(IsKeyPressed(KEY_LEFT) || IsKeyDown(KEY_LEFT))
		{
			if(gunPosition.x != 0)
			{
				gunPosition.x -= 2;
			}			
		}
		

		if(IsKeyPressed(KEY_RIGHT) || IsKeyDown(KEY_RIGHT))
		{
			if(gunPosition.x != (WIDTH - GUN_LENGTH))
			{
				gunPosition.x += 2;
			}
			
		}
			
		
    	if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_UP))
		{
		    Bullets.push_back(gunPosition);
		} 				
    	
    	
		// Draw Gun (Rectangular):
		DrawRectangle(gunPosition.x, gunPosition.y, GUN_LENGTH, GUN_LENGTH, WHITE);    	
    	
		for(int i = 0; i < Bullets.size(); i++)
		{
			DrawRectangle(Bullets[i].x + (GUN_LENGTH/2) - (BULLET_SIZE/2), Bullets[i].y - BULLET_SIZE , BULLET_SIZE, BULLET_SIZE, RED);
			
			Bullets[i].y -= BULLET_SPEED*GetFrameTime();
			
			if(Bullets[i].y == 0)
			{
				Bullets.erase(Bullets.begin() + i);
			}				
		}    	
    	
    	
    	
    	EndDrawing();
	}
    
    CloseWindow();  
    
    return 0;
}
