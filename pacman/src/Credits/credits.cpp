#include "raylib.h"

#include <iostream>
#include "Credits/credits.h"
#include "Gameplay/gameplay.h"

namespace gradius {
	namespace credits {

		Texture2D background2;

		static Vector2 mousePoint;
		static Rectangle rec1;
	

		void InitCredits() {

			rec1.height = 40;
			rec1.width = 100;
			rec1.x = 10;
			rec1.y = 10;
		
		}
		void UpdateCredits() {
			DrawCredits();

			mousePoint = GetMousePosition();


			if (CheckCollisionPointRec(mousePoint, rec1)) {

				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					gameplay::Screens = gameplay::Menu;
				}
			}
			
		}

		void DrawCredits() {

			BeginDrawing();
			ClearBackground(RAYWHITE);

			DrawRectangle(rec1.x, rec1.y, rec1.width, rec1.height, BLACK);
			

			DrawText("atras", rec1.x + 18, rec1.y + 10, 18, WHITE);
			

			EndDrawing();
		}

	}
}