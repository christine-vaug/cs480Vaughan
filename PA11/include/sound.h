#ifndef SOUND_H
#define SOUND_H

#include <iostream>

#include <SDL2/SDL.h>

#include <string>
#include <thread>

#define HIT_SOUND "../Assets/Sounds/Single-yard-dog-woof.wav"
#define BACGROUND_SOUND "../Assets/Sounds/background.wav"
#define GAMEOVER_SOUND "../Assets/Sounds/smb_gameover.wav"

using namespace std;

class Sound
{
  public:

		Sound();
		~Sound();

		void loadSound( std::string soundPath );
		void playSound();

		void launchSound( );

		bool SoundPlaying( );


	private:
		std::thread * threadManager;
		
		Uint32 soundLength;
		Uint8 *soundBuffer;
		SDL_AudioSpec soundSpec;
		bool soundLoaded;
		bool soundPlaying;

        bool alive;

        SDL_AudioDeviceID dev;
 };

#endif /* Sound_H */