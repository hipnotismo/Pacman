#include "raylib.h"

#include "Gameplay/gameplay.h"
#include "Menu/Menu.h"
#include "Credits/credits.h"

namespace gradius {
	namespace gameplay {

		static void InitGame();
		static void Change();
		static void UpdateFrame();

		GameScreen Screens;

		const int screenWidth = 800;
		const int screenHeight = 450;

		Vector2 playerPosition;
		int playerRadius;
		int Core()
		{

			InitGame();
			menu::InitMenu();
			credits::InitCredits();

			while (!WindowShouldClose())
			{
				Change();

			}

			CloseWindow();

			return 0;
		}

		static void InitGame() {

			InitWindow(screenWidth, screenHeight, "PACMAN");
			
			playerPosition = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
			playerRadius = 20;
			SetTargetFPS(60);
		}

		static void Change() {
			switch (Screens) {
			case Menu: {
				menu::UpdateMenu();

			} break;
			case Game: {
				UpdateFrame();

			} break;
				/*case Controls: {
					Controls::UpdateControls();
				}*/
			case Credits: {
				credits::UpdateCredits();
			}
			}
		}

		static void UpdateGame() {
			
			if(IsKeyDown(KEY_W)) {
				if (playerPosition.y > 0) {
					playerPosition.y -= 5.0f;
				}
			}

			if (IsKeyDown(KEY_S)) {
				if (playerPosition.y > 0) {
					playerPosition.y += 5.0f;
				}
			}

			if (IsKeyDown(KEY_A)) {
				if (playerPosition.x > 0) {
					playerPosition.x -= 5.0f;
				}
			}

			if (IsKeyDown(KEY_D)) {
				if (playerPosition.x > 0) {
					playerPosition.x += 5.0f;
				}
			}
			
		}
		static void Draw() {

			BeginDrawing();

			ClearBackground(RAYWHITE);
			DrawCircleV(playerPosition, static_cast<float>(playerRadius), BLACK);
			

			EndDrawing();
		}

		static void UpdateFrame() {
			UpdateGame();
			Draw();
		}
	}
}