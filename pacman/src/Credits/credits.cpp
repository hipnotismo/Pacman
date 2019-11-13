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
			
		}
		void UpdateCredits() {
			DrawCredits();

			mousePoint = GetMousePosition();


			if (CheckCollisionPointRec(mousePoint, rec1)) {

				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					gameplay::Screens = gameplay::Game;
				}
			}
			
		}

		void DrawCredits() {

			BeginDrawing();
			ClearBackground(RAYWHITE);


			DrawTexture(background2, 0, 0, WHITE);


			DrawRectangle(rec1.x, rec1.y, rec1.width, rec1.height, BLACK);
			

			DrawText("jugar", rec1.x + 18, rec1.y + 10, 18, WHITE);
			

			EndDrawing();
		}

	}
}