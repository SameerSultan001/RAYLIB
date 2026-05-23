#include <stdio.h>
#include "raylib.h"


#define WIDTH 900
#define HEIGHT 600
#define FPS 120



int main(void) {
		
	
	InitWindow(WIDTH, HEIGHT, "Basic Window");
  SetTargetFPS(FPS);
    
	
	while(!WindowShouldClose())
	{
    	BeginDrawing();
    	
    	ClearBackground(BLACK);
    	
    	DrawText("Basic Window In Raylib With Black Background.", 0, 0, 20, GREEN);
    	
    	EndDrawing();
	}
    
    CloseWindow();  
    
    return 0;
}
