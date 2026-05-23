#include <stdio.h> // for .c files
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
    
    Vector2 MousePosition; // Vector2 is a raylib struct with 2D position members for x and y coordinates (float).
    
    
	/*
	vector<Vector2> MousePositionHistory;
	
	vector<vector<Vector2>> MousePositionHistoryLine; // now, a 2D matrix
	
	*/
	
	vector<Vector2> MousePositionHistoryCircle;
	
	
	
	vector<vector<Vector2>> strokes; // a 2D matrix
	
	while(!WindowShouldClose()) // the function here returns a true if the "Esc" has been pressed or if the Windows Close Boottor (X) has been pressed.
	{
    	BeginDrawing();
    	
    	ClearBackground(BLACK);
    	
    	DrawText("Basic Painting Window In Raylib With Black Background.", 0, 0, 20, GREEN);
    	
    	/*
    	if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    	{
    		MousePositionHistory.push_back(GetMousePosition()); // the function returns a Vector2 struct corresponding to the current mouse postion.
		}
		*/
		
		
		// Sensing: (Mouse Key Pressed)
		
		
    	if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
		    strokes.push_back(vector<Vector2>());
		    MousePositionHistoryCircle.push_back(GetMousePosition());
		} 		
		
		// we could take advantage of the NOT_BUTTON_DOWN function or whatever it's called. basically, move to the next
		// row of the now 2D arry matrix whenever the mouse button is not down. but, only until it actually is down.
		
		// Basically, to summarize the idea, we essentially break down the whole thing into different line segments or
		// different line sections. Whenever there's a line break, or like, a different line section, we move to the 
		// next array element in a different row. we first fill all columns for a particular line section of a continous
		// line, then, we move to the next column for a different section of the line.
		
		// so, we check if the mouse button is not being hold, and, we also check if the previous section/current section
		// has something stored. only when these two conditions are both met, do we increment to the next row.
		
		
    	if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) && !strokes.empty())
		{
		    strokes.back().push_back(GetMousePosition());
		}	
		
		
    	
    	
    	
    	// Drawing:
    	
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
    	
    	
    	
    	
    	// To Experiment With The Code:
    	 	
    	
    	// Checking the Drawing Coordinates Of The Circles:
    	
    	if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
    	{
    		cout << "Mouse Position X: " << GetMousePosition().x << endl;
    		cout << "Mouse Position Y: " << GetMousePosition().y << endl;
		}
    	
    	
    	EndDrawing();
	}
    
    CloseWindow();  
    
    return 0;
}
