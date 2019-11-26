#include "raylib.h"

#include <iostream>
#include "Controls/controls.h"
#include "Gameplay/gameplay.h"

namespace pacman {
	namespace controls {

		Texture2D background2;

		static Vector2 mousePoint;
		static Rectangle rec1;


		void InitControls() {

			background2 = LoadTexture("res\assets\images\Credits.png");

			rec1.height = 40;
			rec1.width = 100;
			rec1.x = 10;
			rec1.y = 10;

		}
		void UpdateControls() {
			DrawControls();

			mousePoint = GetMousePosition();


			if (CheckCollisionPointRec(mousePoint, rec1)) {
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					gameplay::Screens = gameplay::Menu;
				}
			}

		}

		void DrawControls() {

			BeginDrawing();
			ClearBackground(RAYWHITE);

			DrawRectangle(rec1.x, rec1.y, rec1.width, rec1.height, BLACK);
			DrawTexture(background2, 100, 100, WHITE);

			DrawText("atras", rec1.x + 18, rec1.y + 10, 18, WHITE);
			DrawText("A, W, S y D para mover al personaje", 100, 100, 20, BLACK);
			DrawText("P para pausar", 100, 150, 20, BLACK);
			DrawText("Objetivo: comer todas las bolitas del mapa", 100, 200, 20, BLACK);

			EndDrawing();
		}

	}
}