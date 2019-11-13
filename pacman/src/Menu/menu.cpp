#include "raylib.h"

#include <iostream>
#include "Menu/menu.h"
#include "Gameplay/gameplay.h"

namespace gradius {
	namespace menu {

		Texture2D background2;

		static Vector2 mousePoint;
		static Rectangle rec1;
		static Rectangle rec2;
		static Rectangle rec3;

		void InitMenu() {
			background2 = LoadTexture("Res/Assets/images/Background.png");

			rec1.x = GetScreenWidth() / 2 - 50;
			rec1.y = GetScreenHeight() / 2;
			rec1.height = 50;
			rec1.width = 100;

			rec2.x = GetScreenWidth() / 2 - 50;
			rec2.y = GetScreenHeight() / 2 + 80;
			rec2.height = 50;
			rec2.width = 100;

			rec3.x = GetScreenWidth() / 2 - 50;
			rec3.y = GetScreenHeight() / 2 + 160;
			rec3.height = 50;
			rec3.width = 100;
		}
		void UpdateMenu() {
			DrawMenu();

			mousePoint = GetMousePosition();


			if (CheckCollisionPointRec(mousePoint, rec1)) {

				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					gameplay::Screens = gameplay::Game;
				}
			}
			
			if (CheckCollisionPointRec(mousePoint, rec2)) {
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					gameplay::Screens = gameplay::Credits;
				}
			}
			
			if (CheckCollisionPointRec(mousePoint, rec3)) {

				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					gameplay::Screens = gameplay::Controls;
				}
			}
		}

		void DrawMenu() {

			BeginDrawing();
			ClearBackground(RAYWHITE);


			DrawTexture(background2, 0, 0, WHITE);


			DrawRectangle(rec1.x, rec1.y, rec1.width, rec1.height, BLACK);
			DrawRectangle(rec2.x, rec2.y, rec2.width, rec2.height, BLACK);
			DrawRectangle(rec3.x, rec3.y, rec3.width, rec3.height, BLACK);

			DrawText("jugar", rec1.x + 18, rec1.y + 10, 18, WHITE);
			DrawText("Creditos", rec2.x + 5, rec2.y + 10, 18, WHITE);
			DrawText("Controles", rec3.x + 5, rec3.y + 10, 18, WHITE);
			DrawText("PACMAN", GetScreenWidth() / 2 - 120, 100, 50, MAROON);

			EndDrawing();
		}

	}
}