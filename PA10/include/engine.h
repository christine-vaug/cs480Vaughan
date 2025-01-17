#ifndef ENGINE_H
#define ENGINE_H

#define GLM_ENABLE_EXPERIMENTAL
#include <sys/time.h>
#include <assert.h>

#include "window.h"
#include "graphics.h"
#include "camera.h"
#include "physics.h"



class Engine
{
  public:
    Engine(string name, int width, int height);
    Engine(string name);
    ~Engine();
    bool Initialize(char **argv);
    void Run();
    void Keyboard();
    unsigned int getDT();
    long long GetCurrentTimeMillis();
    void LoseBall();

    int shaderToggle = 0;
    int buffer;
    int bufferMax;

    const int MAX_BALLS = 3; //The maximum number of balls the player starts with in a game
    int ballsRemaining; //The number of balls the player has remaining before game over

    unsigned int score;

    void outputObjects() const;
    int getIndexOf(const std::string& key); // Returns index from 0-objs.size();

    bool toggleFollowBall();
    bool followBall;

  private:
    std::vector<Object*> objs;
    //unsigned int dynamicCubeIndex;
    unsigned int ballIndex;
    unsigned int plungerIndex;
    unsigned int rPaddleIndex;
    unsigned int lPaddleIndex;
    
    // Window related variables
    Window *m_window;    
    string m_WINDOW_NAME;
    int m_WINDOW_WIDTH;
    int m_WINDOW_HEIGHT;
    bool m_FULLSCREEN;
    SDL_Event m_event;

    Graphics *m_graphics;
    Physics *m_physics;
    unsigned int m_DT;
    long long m_currentTimeMillis;
    bool m_running;

    //btVector3 vel;
    //btVector3 pos;
    float counter;
    bool playing;
};

#endif // ENGINE_H
