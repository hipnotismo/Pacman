#include "Credits/credits.h"

#include <iostream>

#include "raylib.h"

#include "Gameplay/gameplay.h"

namespace pacman {
	namespace credits {
		static void DrawCredits();

		Texture2D background2;

		static Vector2 mousePoint;
		static Rectangle rec1;
	

		void InitCredits() {

			background2 = LoadTexture("res\assets\images\Credits.png");

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
			DrawTexture(background2, 100, 100, WHITE);

			DrawText("atras", rec1.x + 18, rec1.y + 10, 18, WHITE);
			DrawText("Creado por: Martin Concetti",100,100,20,BLACK);
			DrawText("Consulta y ayuda por: Baretto Sergio", 100, 150, 20, BLACK);
			DrawText("Creado usando; Paint, Visual studio y Raylib", 100, 200, 20, BLACK);

			EndDrawing();
		}

	}
}