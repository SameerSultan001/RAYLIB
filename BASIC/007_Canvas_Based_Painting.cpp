#include <stdio.h>
#include "raylib.h"


#define WIDTH 900
#define HEIGHT 600
#define FPS 120



int main(void) {
		
	
	InitWindow(WIDTH, HEIGHT, "Canvas Based Drawing");
    SetTargetFPS(FPS);
    
    bool Canvas[WIDTH][HEIGHT] = {false};
    
    Vector2 MousePosition; // Vector2 is a raylib struct with 2D position members for x and y coordinates (float).
    
	

	
	while(!WindowShouldClose())
	{
    	BeginDrawing();
    	
    	ClearBackground(BLACK);
    	
    	DrawText("Basic Window In Raylib With Black Background.", 0, 0, 20, GREEN);
    	
    	MousePosition = GetMousePosition(); // the function returns a Vector2 struct corresponding to the current mouse postion.
    	
    	if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    	{
    		Canvas[(int)MousePosition.x][(int)MousePosition.y] = true;
		}
		
		
    	if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) // for erase
    	{
    		Canvas[(int)MousePosition.x][(int)MousePosition.y] = false;
		}		
		
		
    	for(int i = 0; i < WIDTH; i++)
    	{
    		for(int j = 0; j < HEIGHT; j++)
    		{
    			if(Canvas[i][j])
    			{
    				DrawCircle(i, j, 2.0, RED); // Draw a circle at the position in the canvas if it is set to be true.
				}
			}
		}
    	
    	
    	
    	EndDrawing();
	}
    
    CloseWindow();  
    
    return 0;
}
