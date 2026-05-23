#include <stdio.h>
#include <vector>
#include "raylib.h"
using namespace std;

#define WIDTH 900
#define HEIGHT 600
#define FPS 60



int main(void) {
		
	
	InitWindow(WIDTH, HEIGHT, "Basic Window");
    SetTargetFPS(FPS);
    
    Vector2 MousePosition; // Vector2 is a raylib struct with 2D position members for x and y coordinates (float).
    
    
	
	vector<Vector2> MousePositionHistory;
	
	while(!WindowShouldClose())
	{
    	BeginDrawing();
    	
    	ClearBackground(BLACK);
    	
    	DrawText("Basic Window In Raylib With Black Background.", 0, 0, 20, GREEN);
    	
    	MousePositionHistory.push_back(GetMousePosition()); // the function returns a Vector2 struct corresponding to the current mouse postion.
    	
    	for(int j = 0; j < MousePositionHistory.size(); j++)
    	{
    		DrawCircle(MousePositionHistory[j].x, MousePositionHistory[j].y, 2.0, RED); // Draw a circle at the mouse position stored in the mouse position history.
		}
    	
    	
    	
    	EndDrawing();
	}
    
    CloseWindow();  
    
    return 0;
}
