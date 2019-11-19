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

		Vector2 pill1;
		int pillRadius1;
		bool pill1Active = true;

		int poinst;

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

			pill1 = { 100, 100 };
			pillRadius1 = 10;

			poinst = 0;
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

					if (CheckCollisionCircles(pill1, pillRadius1, playerPosition, playerRadius)) {
						if(pill1Active==true){ poinst += 1; }					
						pill1Active = false;
					}
				}
			}
		}

		static void Draw() {

			BeginDrawing();

			ClearBackground(RAYWHITE);
			DrawCircleV(playerPosition, static_cast<float>(playerRadius), BLACK);
			if (pill1Active == true) {
				DrawCircleV(pill1, static_cast<float>(pillRadius1), GOLD);
			}
			DrawText(TextFormat("SCORE %4i", poinst), 20, 20, 40, LIGHTGRAY);
			EndDrawing();
		}

		static void UpdateFrame() {
			UpdateGame();
			Draw();
		}
	}
}