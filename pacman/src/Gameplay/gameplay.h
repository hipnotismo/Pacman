#ifndef Gameplay_H
#define Gameplay_H

namespace pacman {
	namespace gameplay {

		enum GameScreen
		{
			Menu = 0,
			Game,
			End,
			Credits,
			Controls
		};
		extern GameScreen Screens;

		int Core();

	}
}
#endif // Gameplay.H
