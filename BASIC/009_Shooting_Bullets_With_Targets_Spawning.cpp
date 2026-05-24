#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "raylib.h"

using namespace std;


#define WIDTH 900
#define HEIGHT 600
#define FPS 120

#define BULLET_SPEED 2
#define GROUND_Y (HEIGHT*0.8)
#define GROUND_THICKNESS 5

#define GUN_LENGTH 50
#define BULLET_SIZE 10

#define TARGET_SIZE 30
#define TARGET_Y (HEIGHT*0.1) // top left edge of the target rectangle
#define TARGET_INITIAL_Y 0
#define TARGET_SPEED 0.5


vector<Vector2> Bullets;
vector<Vector2> Targets;

string fileName = "Level";

double timeElapsed = 0.0;

int main(void) {
	
	int level;
	cout << "Enter Level Number: ";
	cin >> level;
	
	fileName += to_string(level);
	fileName += ".txt";
	
	ifstream file(fileName);
	
	if(!file.is_open())
	{
		cout << fileName << endl;
		cout << "File Failed To Open.\nExiting..." << endl;
		cin >> level;
		return 0;
	}
	
	
	
	
	bool isOpen = true;
	bool isShotDown = false;
	
	
	
	
	
	
	InitWindow(WIDTH, HEIGHT, "Shooter Game");
  	SetTargetFPS(FPS);
    
    Vector2 groundStartPos = {0,GROUND_Y};
    Vector2 groundEndPos = {WIDTH, GROUND_Y};
	
	
	Vector2 gunPosition = {WIDTH/2, GROUND_Y - GROUND_THICKNESS/2 - GUN_LENGTH}; // initialization (centralized)
	Vector2 BulletPosition;

	while(!WindowShouldClose())
	{
    	BeginDrawing();
    	
    	ClearBackground(BLACK);
    	
    	DrawText("Shooter Game.", 0, 0, 20, GREEN);
    	
    	timeElapsed += GetFrameTime();
    	
			
		
    	if(!isOpen && Targets.empty())
    	{
    		break;
		}
		
		
		
		if(timeElapsed >= 4) // every 4 seconds, a new target is loaded
    	{
    		timeElapsed = 0; // reset everytime
    		int temp;
    		if(file >> temp)
    		{
    			isOpen = true;
	    		Vector2 temporaryPosition = {temp, TARGET_INITIAL_Y};
	    		Targets.push_back(temporaryPosition);    			
			}
			else
			{
				isOpen = false;
			}			

		}
    	
    	
    	

    
	// Sensing {
		if(IsKeyPressed(KEY_LEFT) || IsKeyDown(KEY_LEFT))
		{
			if(gunPosition.x > 0)
			{
				gunPosition.x -= 2;
			}			
		}
		
		
		if(IsKeyPressed(KEY_RIGHT) || IsKeyDown(KEY_RIGHT))
		{
			if(gunPosition.x < (WIDTH - GUN_LENGTH))
			{
				gunPosition.x += 2;
			}
			
		}
		
					
    	if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_UP))
		{
			BulletPosition.x = gunPosition.x + (GUN_LENGTH/2) - (BULLET_SIZE/2);
			BulletPosition.y = gunPosition.y - BULLET_SIZE;
		    Bullets.push_back(BulletPosition);
		} 				   	
    	
	// } Sensing 



	// Drawing {
		
		
    	// Draw Ground:
    	DrawLineEx(groundStartPos, groundEndPos, GROUND_THICKNESS, GRAY);    	
    	
    	
		// Draw Gun (Rectangular):
		DrawRectangle(gunPosition.x, gunPosition.y, GUN_LENGTH, GUN_LENGTH, WHITE);    	
    	
    	
    	// Draw Bullets:
		for(int i = 0; i < Bullets.size(); i++)
		{
			bool bulletIsAtTop = false;
			DrawRectangle(Bullets[i].x, Bullets[i].y, BULLET_SIZE, BULLET_SIZE, RED);
			
			Bullets[i].y -= BULLET_SPEED;
			
			if(Bullets[i].y <= 0)
			{
				Bullets.erase(Bullets.begin() + i);
				i--;
				bulletIsAtTop = true;
			}
			
			
			// Collision Detection (Each target with each bullet)
			if(!bulletIsAtTop)
			{
				for(int j = 0; j < Targets.size(); j++)			
				{
					if(Bullets[i].y <= (Targets[j].y + TARGET_SIZE) && (((Bullets[i].x + BULLET_SIZE) >= Targets[j].x) && (Bullets[i].x <= (Targets[j].x + TARGET_SIZE)))) // collision detection btw bullet and target
					{
						Targets.erase(Targets.begin() + j); // erase the target
						j--;
						Bullets.erase(Bullets.begin() + i); // erase the bullet
						isShotDown = true; // flag the target as "shot down"
						i--;
						break;
					}
				}				
			}
			

		}    	
    	
    	
    	// Draw Targets:
    	for(int i = 0; i < Targets.size(); i++)
		{
    		DrawRectangle(Targets[i].x, Targets[i].y, TARGET_SIZE, TARGET_SIZE, GREEN); 
    		Targets[i].y += TARGET_SPEED;
		}
    	   	
    	   	
    // } Drawing
		
    	EndDrawing();
	}
    
    CloseWindow();  
    
    return 0;
}
