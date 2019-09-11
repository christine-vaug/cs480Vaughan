
#include "engine.h"

Engine::Engine(string name, int width, int height)
{
  m_WINDOW_NAME = name;
  m_WINDOW_WIDTH = width;
  m_WINDOW_HEIGHT = height;
  m_FULLSCREEN = false;
}

Engine::Engine(string name)
{
  m_WINDOW_NAME = name;
  m_WINDOW_HEIGHT = 0;
  m_WINDOW_WIDTH = 0;
  m_FULLSCREEN = true;
}

Engine::~Engine()
{
  delete m_window;
  delete m_graphics;
  m_window = NULL;
  m_graphics = NULL;
}

bool Engine::Initialize(int argc, char **argv)
{
  // Start a window
  m_window = new Window();
  if(!m_window->Initialize(m_WINDOW_NAME, &m_WINDOW_WIDTH, &m_WINDOW_HEIGHT))
  {
    printf("The window failed to initialize.\n");
    return false;
  }

  // Start the graphics
  m_graphics = new Graphics();
  if(!m_graphics->Initialize(m_WINDOW_WIDTH, m_WINDOW_HEIGHT, argc, argv))
  {
    printf("The graphics failed to initialize.\n");
    return false;
  }

  // Set the time
  m_currentTimeMillis = GetCurrentTimeMillis();

  // No errors
  return true;
}

void Engine::Run()
{
  m_running = true;

  while(m_running)
  {
    // Update the DT
    m_DT = getDT();

    // Check the keyboard input
    while(SDL_PollEvent(&m_event) != 0)
    {
      Keyboard();
    }

    // Update and render the graphics
    m_graphics->Update(m_DT);
    m_graphics->Render();

    // Swap to the Window
    m_window->Swap();
  }
}

void Engine::Keyboard()
{
  if(m_event.type == SDL_QUIT)
  {
    m_running = false;
  }
  else if (m_event.type == SDL_KEYDOWN)
  {
    // handle key down events here
	switch(m_event.key.keysym.sym)
	{
		case SDLK_ESCAPE:
		m_running = false; //quit the program
		break;

		case SDLK_a: //A
		m_graphics->planet->reversedOrbit = !(m_graphics->planet->reversedOrbit); //make the planet reverse its orbit
		break;

		case SDLK_s: //S
		m_graphics->planet->pausedOrbit = !(m_graphics->planet->pausedOrbit); //make the planet pause/unpause its orbit
		break;

		case SDLK_j: //J
		m_graphics->planet->reversedSpin = !(m_graphics->planet->reversedSpin); //make planet reverse spin
		break;

		case SDLK_k: //K
		m_graphics->planet->pausedSpin = !(m_graphics->planet->pausedSpin); //make planet pause/unpause its spin
		break;

		default:
		break;
	}
  }
  else if (m_event.type == SDL_MOUSEBUTTONDOWN)
  {
    // handle key down events here
	switch(m_event.button.button)
	{
		case SDL_BUTTON_LEFT: //left mouse button
		m_graphics->moon->reversedOrbit = !(m_graphics->moon->reversedOrbit); //make the moon reverse its orbit
		break;

		case SDL_BUTTON_RIGHT: //right mouse button
		m_graphics->moon->pausedOrbit = !(m_graphics->moon->pausedOrbit); //make the moon pause/unpause its orbit
		break;

		default:
		break;
	}
  }
}

unsigned int Engine::getDT()
{
  long long TimeNowMillis = GetCurrentTimeMillis();
  assert(TimeNowMillis >= m_currentTimeMillis);
  unsigned int DeltaTimeMillis = (unsigned int)(TimeNowMillis - m_currentTimeMillis);
  m_currentTimeMillis = TimeNowMillis;
  return DeltaTimeMillis;
}

long long Engine::GetCurrentTimeMillis()
{
  timeval t;
  gettimeofday(&t, NULL);
  long long ret = t.tv_sec * 1000 + t.tv_usec / 1000;
  return ret;
}
