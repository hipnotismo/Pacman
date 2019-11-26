#include "raylib.h"

#include <iostream>
#include "Gameplay/gameplay.h"
#include "Menu/Menu.h"
#include "Credits/credits.h"
#include "Controls/controls.h"

namespace pacman {
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
		Vector2 playerSpeed;

		Vector2 pill1;
		int pillRadius1;
		bool pill1Active = true;

		Rectangle block1;
		
		Rectangle menu;

		static Vector2 mousePoint;

		int poinst = 0;
		int direction;

		int Core()
		{

			InitGame();
			menu::InitMenu();
			credits::InitCredits();
			controls::InitControls();

			while (!WindowShouldClose())
			{
				Change();

			}

			CloseWindow();

			return 0;
		}

		static void InitGame() {

			InitWindow(screenWidth, screenHeight, "PACMAN");
			
			playerPosition = { static_cast<float>(GetScreenWidth()) / 2, static_cast<float>(GetScreenHeight()) / 2 };
			playerRadius = 15;
			playerSpeed = {0.0f,0.0f};
			SetTargetFPS(60);

			pill1 = { 100, 100 };
			pillRadius1 = 10;

			block1.height = static_cast <float>(100);
			block1.width = static_cast <float>(100);
			block1.x = static_cast <float>(200);
			block1.y = static_cast <float>(200);

			menu.height = static_cast <float>(100);
			menu.width = static_cast <float>(100);
			menu.x = static_cast <float>(GetScreenWidth()-200);
			menu.y = static_cast <float>(GetScreenHeight()/6);
			//block1 = {(static_cast < float>(40),static_cast < float>(40))};
			//blockPosition= {(static_cast < float>(200),static_cast < float>(200))};
		}

		static void Change() {
			switch (Screens) {
			case Menu: {
				menu::UpdateMenu();

			} break;
			case Game: {
				UpdateFrame();

			} break;
			case Controls: {
				controls::UpdateControls();
			} break;
			case Credits: {
				credits::UpdateCredits();
			}
			}
		}

		static void UpdateGame() {
			if (!gameOver) {
				if (IsKeyPressed('P')) pause = !pause;

				if (!pause) {
					playerPosition.x += playerSpeed.x;
					playerPosition.y += playerSpeed.y;

					if (IsKeyDown(KEY_W)) {
						direction = 1;
						if (playerPosition.y > 0) {
							playerSpeed.y = -5.0f;
							playerSpeed.x = 0.0f;
						}
					}

					if (IsKeyDown(KEY_S)) {
						direction = 2;
						if (playerPosition.y > 0) {
							playerSpeed.y = 5.0f;
							playerSpeed.x = 0.0f;
						}
					}

					if (IsKeyDown(KEY_A)) {
						direction = 3;
						if (playerPosition.x > 0) {
							playerSpeed.x = -5.0f;
							playerSpeed.y = 0.0f;
						}
					}

					if (IsKeyDown(KEY_D)) {
						direction = 4;
						if (playerPosition.x > 0) {
							playerSpeed.x = 5.0f;
							playerSpeed.y = 0.0f;
						}
					}
					if (CheckCollisionCircleRec(playerPosition,playerRadius,block1)) {
						if (direction == 1) {
							playerPosition.y += 6.0f;
						}
						if (direction == 2) {
							playerPosition.y -= 6.0f;
						}
						if (direction == 3) {
							playerPosition.x += 6.0f;
						}
						if (direction == 4) {
							playerPosition.x -= 6.0f;
						}
					}
					if (CheckCollisionCircles(pill1, pillRadius1, playerPosition, playerRadius)) {
						if(pill1Active==true){ poinst += 1; }					
						pill1Active = false;
					}
				}

				mousePoint = GetMousePosition();

				if (CheckCollisionPointRec(mousePoint,menu)) {
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
						InitGame();
						pause = !pause;
						gameplay::Screens = gameplay::Menu;
					}
				}
			}
		}

		static void Draw() {

			BeginDrawing();

			ClearBackground(RAYWHITE);
			DrawCircleV(playerPosition, static_cast<float>(playerRadius), BLACK);
			DrawRectangle(block1.x,block1.y,block1.width,block1.height,BLUE);
			if (pill1Active == true) {
				DrawCircleV(pill1, static_cast<float>(pillRadius1), GOLD);
			}
			DrawText(TextFormat("SCORE %4i", poinst), 20, 20, 40, LIGHTGRAY);

			if (pause == true) {
				DrawRectangle(menu.x,menu.y,menu.width,menu.height,GREEN);
			}
			EndDrawing();
		}

		static void UpdateFrame() {
			UpdateGame();
			Draw();
		}
	}
}