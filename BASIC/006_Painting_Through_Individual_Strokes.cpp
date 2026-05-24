#include <stdio.h> // for .c files (unused)
#include <vector> // for cpp files
#include <iostream> // for cpp files
#include "raylib.h"
using namespace std;

#define WIDTH 900
#define HEIGHT 600
#define FPS 120



int main(void) {		
	
	InitWindow(WIDTH, HEIGHT, "Basic Painting Window");
    SetTargetFPS(FPS);

	// To Store Points: (Only When Mouse Left Button Clicked)
	vector<Vector2> MousePositionHistoryCircle; // Vector2 is a raylib struct with 2D position members for x and y coordinates (float).

	// To Store Full Strokes: (Only While Mouse Left Button Is Down)
	vector<vector<Vector2>> strokes; // a 2D matrix

	
	while(!WindowShouldClose()) // the function here returns a true if the "Esc" has been pressed or if the Windows Close Boottor (X) has been pressed.
	{
    	BeginDrawing();    	
    	ClearBackground(BLACK);    	
    	DrawText("Basic Painting Window In Raylib With Black Background.", 0, 0, 20, GREEN);

		
		
		// Sensing (Mouse Key Pressed) {
		
		
    	if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
		    strokes.push_back(vector<Vector2>());
		    MousePositionHistoryCircle.push_back(GetMousePosition());
		} 		
						
    	if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) && !strokes.empty())
		{
		    strokes.back().push_back(GetMousePosition());
		}	
				
    	// } Sensing.
    	

		
    	// Drawing {
    	
    	// Drawing the Lines:
    	for(int i = 0; i < strokes.size(); i++)
		{
		    for(int j = 1; j < strokes[i].size(); j++)
		    {
		        DrawLineEx(strokes[i][j - 1], strokes[i][j], 2.0, RED);
		    }
		}

    	// Drawing the Circles:
    	for(int i = 0; i < MousePositionHistoryCircle.size(); i++)
    	{
    		DrawCircle(MousePositionHistoryCircle[i].x, MousePositionHistoryCircle[i].y, 2.0, RED);
		}
		
    	// } Drawing.

		

    	// To Experiment With The Code {
    	 		
    	// Checking the Drawing Coordinates Of The Circles:    	
    	if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
    	{
    		cout << "Mouse Position X: " << GetMousePosition().x << endl;
    		cout << "Mouse Position Y: " << GetMousePosition().y << endl;
		}

		// } Experiment.

		
    	EndDrawing();
	}    
	
    CloseWindow();  
    
    return 0;
}
