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
			

			
		}
		static void Draw() {

			BeginDrawing();

			ClearBackground(RAYWHITE);

			

			EndDrawing();
		}

		static void UpdateFrame() {
			UpdateGame();
			Draw();
		}
	}
}