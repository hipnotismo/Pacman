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

		const int screenWidth = 1600;
		const int screenHeight = 800;

		static bool gameOver = false;
		static bool pause = false;

		Vector2 playerPosition;
		int playerRadius;

		Vector2 point1;
		int pointRadius1;

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
			playerRadius = 15;
			SetTargetFPS(60);

			point1 = { 10, 10 };
			pointRadius1 = 10;
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
			if (!gameOver) {
				if (IsKeyPressed('P')) pause = !pause;

				if (!pause) {
					if (IsKeyDown(KEY_W)) {
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
			}
		}

		static void Draw() {

			BeginDrawing();

			ClearBackground(RAYWHITE);
			DrawCircleV(playerPosition, static_cast<float>(playerRadius), BLACK);
			DrawCircleV(point1, static_cast<float>(pointRadius1), GOLD);

			EndDrawing();
		}

		static void UpdateFrame() {
			UpdateGame();
			Draw();
		}
	}
}