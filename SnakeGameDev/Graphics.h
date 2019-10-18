#ifdef __linux__
    #include <SDL2/SDL.h>
#elif _WIN32
    #include <SDL.h>
#endif
#include <string>

class Graphics{
public:
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
    const char* TITLE;
    SDL_Window* window;
    SDL_Surface* screenSurface;

    Graphics(std::string title, int initWidth, int initHeight);
    ~Graphics();
    void clear();
    void render();
};