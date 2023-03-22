#ifndef GAME_H
#define GAME_H
#include "SDL.h"
#include <vector>
<<<<<<< HEAD
#include "Texture.h"
=======
>>>>>>> f0f3dc4db31df5307efa3b4a539809abafe70438
class Game
{
    public:
        static Game*Instance()
        {
            if(m_pGame == 0)
            {
                m_pGame = new Game();
            }
            return m_pGame;
        }
        bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
        void render();
        void update();
        void handleEvents();
        void clean();
        bool running(){ return m_bRunning;}
    protected:

    private:
        std::vector<std::vector<int>> maps;
        int px,py,length;
        bool status,statuss;
        static Game* m_pGame;
        Game(){};
        ~Game(){};
        SDL_Window* m_pWindow;
        SDL_Renderer* m_pRenderer;
        bool m_bRunning;
};
typedef Game TheGame;
#endif // GAME_H
