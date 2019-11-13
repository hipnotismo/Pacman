#include "raylib.h"

#include "Gameplay/gameplay.h"
#include "Menu/Menu.h"

namespace gradius {
	namespace gameplay {

		static void InitGame();
		static void Change();
		static void UpdateFrame();

		GameScreen Screens;

		const int screenWidth = 800;
		const int screenHeight = 450;

		bool collision = false;
		//colicion con power up
		bool collisionPower = false;
		bool collisionPower2 = false;

		bool inicio = false;
		bool player1Win = true;
		int points1;

		int mauseradius;
		float scrollingBack;

		Wave wallWav;
		Wave playerWav;
		Sound playerColition;
		Sound wallColition;
		Music music;


		Rectangle player1;
		Color player1Color;
		int count1;
		int endPoint1;

		Rectangle retry;
		Rectangle menu;

		Texture2D background;
		Vector2 mause;

		Vector2 powerSpeed1;
		Vector2 powerSpeed2;

		int Core()
		{

			InitGame();
			menu::InitMenu();

			while (!WindowShouldClose())
			{
				Change();

			}

			UnloadSound(wallColition);
			UnloadWave(wallWav);
			UnloadWave(playerWav);
			UnloadSound(playerColition);
			UnloadMusicStream(music);

			CloseAudioDevice();

			CloseWindow();

			return 0;
		}

		static void InitGame() {

			//inicia el audio
			InitAudioDevice();

			//wallWav = LoadWave("assets/sounds/Wall_colition.wav");
			//playerWav = LoadWave("assets/sounds/Player_colition.wav");

			playerColition = LoadSoundFromWave(playerWav);
			wallColition = LoadSoundFromWave(wallWav);
			//music = LoadMusicStream("assets/sounds/Electronic Fantasy.ogg");

			InitWindow(screenWidth, screenHeight, "PONG");
			background = LoadTexture("Res/Assets/images/Background.png");

			//primer jugador
			player1.x = static_cast<float>(screenWidth) / 8;
			player1.y = static_cast<float>(screenHeight) / 2;
			player1.height = 30;
			player1.width = 40;
			player1Color = MAROON;
			endPoint1 = 0;
			points1 = 0;
			count1 = 0;

			menu.height = 40;
			menu.width = 90;
			menu.x = static_cast<float>(screenWidth) / 2 + 80;
			menu.y = static_cast<float>(screenHeight) / 4 + 50;

			retry.height = 40;
			retry.width = 100;
			retry.x = static_cast<float>(screenWidth) / 2 + 80;
			retry.y = static_cast<float>(screenHeight) / 4 + 100;
			//pelota

			scrollingBack = 0.0f;

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
			}
		}

		static void UpdateGame() {
			if (IsKeyPressed('P')) inicio = !inicio;

			if (inicio) {
				UpdateMusicStream(music);
				PlayMusicStream(music);
				//controles del jugador
				if (IsKeyDown(KEY_A)) {
					if (player1.x > 0) {
						player1.x -= 5.0f;
					}
				}

				if (IsKeyDown(KEY_D)) {
					if (player1.x + player1.x / 2 - 50 < GetScreenWidth()) {
						player1.x += 5.0f;
					}
				}

				if (IsKeyDown(KEY_W)) {
					if (player1.y + player1.y / 2 > 0) {
						player1.y -= 5.0f;
					}
				}

				if (IsKeyDown(KEY_S)) {
					if (player1.y + player1.y / 2 < GetScreenHeight()) {
						player1.y += 5.0f;
					}
				}

				scrollingBack -= 0.1f;

				//chequea los puntos para terminar el mach
				if (points1 > 3) {
					endPoint1 = endPoint1 + 1;
				}



				mause = GetMousePosition();

			}
		}
		static void Draw() {

			BeginDrawing();

			ClearBackground(RAYWHITE);

			DrawTextureEx(background, { scrollingBack, 20 }, 0.0f, 2.0f, WHITE);
			DrawTextureEx(background, { background.width * 2 + scrollingBack, 20 }, 0.0f, 2.0f, WHITE);

			DrawRectangle(static_cast<int>(player1.x), static_cast<int>(player1.y), static_cast<int>(player1.width), static_cast<int>(player1.height), player1Color);

			DrawText(FormatText("Puntos: %i", points1), 10, 40, 20, LIGHTGRAY);

			EndDrawing();
		}

		static void UpdateFrame() {
			UpdateGame();
			Draw();
		}
	}
}