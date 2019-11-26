#include "Gameplay/gameplay.h"

#include <iostream>

#include "raylib.h"

#include "Menu/Menu.h"
#include "Credits/credits.h"
#include "Controls/controls.h"
#include "Game over/game-over.h"

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
		Vector2 pill2;
		Vector2 pill3;

		int pillRadius1;
		int pillRadius2;
		int pillRadius3;

		bool pill1Active ;
		bool pill2Active ;
		bool pill3Active ;


		Rectangle block1;
		Rectangle block2;
		Rectangle block3;
		Rectangle block4;
		
		Rectangle menu;

		static Vector2 mousePoint;

		int points;
		int direction;
		int lives;

		int Core()
		{

			InitGame();
			menu::InitMenu();
			credits::InitCredits();
			controls::InitControls();
			over::InitOver();

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

			points = 0;
			lives = 3;
			pill1 = { 100, 100 };
			pill2 = { 1000, 100 };
			pill3 = { static_cast<float>(GetScreenWidth()/2),  static_cast<float>(GetScreenHeight() - 500) };

			pillRadius1 = 10;
			pillRadius2 = 10;
			pillRadius3 = 10;

			pill1Active = true;
			pill1Active = true;
			pill1Active = true;

			block1.height = static_cast <float>(GetScreenHeight());
			block1.width = static_cast <float>(50);
			block1.x = static_cast <float>(0);
			block1.y = static_cast <float>(0);

			block2.height = static_cast <float>(50);
			block2.width = static_cast <float>(GetScreenWidth());
			block2.x = static_cast <float>(0);
			block2.y = static_cast <float>(0);

			block3.height = static_cast <float>(GetScreenHeight());
			block3.width = static_cast <float>(50);
			block3.x = static_cast <float>(GetScreenWidth() - 50);
			block3.y = static_cast <float>(0);

			block4.height = static_cast <float>(50);
			block4.width = static_cast <float>(GetScreenWidth());
			block4.x = static_cast <float>(0);
			block4.y = static_cast <float>(GetScreenHeight() - 50);

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
			} break;
			case End: {
				over::UpdateOver();
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
							playerSpeed.x = -6.0f;
							playerSpeed.y = 0.0f;
						}
					}

					if (IsKeyDown(KEY_D)) {
						direction = 4;
						if (playerPosition.x > 0) {
							playerSpeed.x = 6.0f;
							playerSpeed.y = 0.0f;
						}
					}
					if (CheckCollisionCircleRec(playerPosition,playerRadius,block1)) {
						if (direction == 1) {
							//playerPosition.y = 0.0f;
						}
						if (direction == 2) {
							//playerPosition.y = 0.0f;
						}
						if (direction == 3) {
							playerPosition.x += 5.0f;
						}
						if (direction == 4) {
							playerPosition.x -= 5.0f;
						}
					}
					if (CheckCollisionCircles(pill1, pillRadius1, playerPosition, playerRadius)) {
						if(pill1Active==true){ points += 1; }					
						pill1Active = false;
					}

					if (CheckCollisionCircles(pill2, pillRadius2, playerPosition, playerRadius)) {
						if (pill1Active == true) { points += 1; }
						pill1Active = false;
					}

					if (CheckCollisionCircles(pill3, pillRadius3, playerPosition, playerRadius)) {
						if (pill1Active == true) { points += 1; }
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

				if (lives == 0) {
					gameOver = !gameOver;
				}
			}

			//gameplay::Screens = gameplay::End;
		}

		static void Draw() {

			BeginDrawing();

			ClearBackground(RAYWHITE);
			DrawCircleV(playerPosition, static_cast<float>(playerRadius), BLACK);
			DrawRectangle(block1.x,block1.y,block1.width,block1.height,BLUE);
			DrawRectangle(block2.x, block2.y, block2.width, block2.height, BLUE);
			DrawRectangle(block3.x, block3.y, block3.width, block3.height, BLUE);
			DrawRectangle(block4.x, block4.y, block4.width, block4.height, BLUE);

			if (pill1Active == true) {
				DrawCircleV(pill1, static_cast<float>(pillRadius1), GOLD);
			}

			if (pill2Active == true) {
				DrawCircleV(pill2, static_cast<float>(pillRadius2), GOLD);
			}

			if (pill3Active == true) {
				DrawCircleV(pill3, static_cast<float>(pillRadius3), GOLD);
			}
			DrawText(TextFormat("SCORE %4i", points), 20, 10, 40, LIGHTGRAY);
			DrawText(TextFormat("LIVES %4i", lives), 1300, 10, 40, LIGHTGRAY);


			if (pause == true) {
				DrawRectangle(menu.x,menu.y,menu.width,menu.height,BLACK);
				DrawText(TextFormat("menu", points), menu.x + 5, menu.y, 40, WHITE);
			}
			EndDrawing();
		}

		static void UpdateFrame() {
			UpdateGame();
			Draw();
		}
	}
}