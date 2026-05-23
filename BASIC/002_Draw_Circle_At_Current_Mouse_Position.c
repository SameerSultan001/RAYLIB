#include <stdio.h>
#include "raylib.h"


#define WIDTH 900
#define HEIGHT 600
#define FPS 120



int main(void) {
		
	
	InitWindow(WIDTH, HEIGHT, "Basic Window");
    SetTargetFPS(FPS);
    
    Vector2 MousePosition; // Vector2 is a raylib struct with 2D position members for x and y coordinates (float).
	
	while(!WindowShouldClose())
	{
    	BeginDrawing();
    	
    	ClearBackground(BLACK);
    	
    	DrawText("Basic Window In Raylib With Black Background.", 0, 0, 20, GREEN);
    	
    	MousePosition = GetMousePosition(); // the function returns a Vector2 struct corresponding to the current mouse postion.
    	
    	DrawCircle(MousePosition.x, MousePosition.y, 2.0, RED); // Draw a circle at the current mouse position.
    	
    	
    	EndDrawing();
	}
    
    CloseWindow();  
    
    return 0;
}
