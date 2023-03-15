#include "Game.h"
#include <iostream>
#include <cstdlib>
Game* Game::m_pGame = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
    std::cout << "SDL init success\n";
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if(m_pWindow != 0) // window init success
    {
    std::cout << "window creation success\n";
    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_PRESENTVSYNC);
    if(m_pRenderer != 0) // renderer init success
    {
    std::cout << "renderer creation success\n";
    SDL_SetRenderDrawColor(m_pRenderer,0,0,0,255);}
    else
    {
    std::cout << "renderer init fail\n";
    return false; // renderer init fail
    }
    }
    else
    {
    std::cout << "window init fail\n";
    return false; // window init fail
    }
    }
    else
    {
    std::cout << "SDL init fail\n";
    return false; // SDL init fail
        }
    m_bRunning = true;
    for(int j=0;j<10;++j){
            std::vector<int> tmp;
        for(int i=0;i<10;++i){
            tmp.push_back(0);
        }
            maps.push_back(tmp);
    }
    px=0;
    py=0;
    length=3;
    status=true;
    statuss=false;
    std::cout << "init success\n";
    return true;
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);
  /*  for(int j=9;j>=0;--j){
        for(int i=0;i<10;++i){
            if(px==i&&py==j) {std::cout<<2<<" ";}
            else std::cout<<maps[i][j]<<" ";
        }
        std::cout<<std::endl;
  }
    std::cout<<"\n";*/
    SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
    SDL_RenderClear(m_pRenderer);
    SDL_SetRenderDrawColor(m_pRenderer,0, 0, 0, 255);
    for(int i=0; i<10; i++){
    double l=(1+i)*100;
    double x=(1000*l)/(l+500);
    SDL_RenderDrawLine(m_pRenderer,360-100*px+i*20,720-50-x,360+100*(10-px)-i*20,720-50-x);
    }
    SDL_RenderPresent(m_pRenderer);
}

void Game::handleEvents()
{
    bool quit = false;
    SDL_Event event;
    while(SDL_PollEvent(&event)!=0)
        {
        if(event.type == SDL_QUIT)
        {
            quit=true;
        }
        else if(event.type == SDL_KEYDOWN)
        {
        switch (event.key.keysym.sym)
        {
            case SDLK_UP:
            if(status){
                if(py<10-length){
                ++py;
                status=false;
                statuss=true;
                }
            }
            else if(!status){
                if(statuss){
                    if(py<9){
                    py+=length;
                    status=true;}
                }
                else {
                    if(py<9){
                    ++py;
                    }
                }
            }
            break;
            case SDLK_DOWN:
            if(status){
                if(py>=length){
                py-=length ;
                status=false;
                statuss=true;
                }
            }
            else if(!status){
                if(statuss){
                    if(py>0){
                    --py;
                    status=true;}
                }
                else {
                    if(py>0){
                    --py;
                        }
                }
            }
            break;
            case SDLK_LEFT:
            if(status){
                if(px>=length){
                px-=length ;
                status=false;
                statuss=false;
                }
            }
            else if(!status){
                if(statuss){
                    if(px>0){
                    --px;
                    }
                }
                else {
                    if(px>0){
                    --px;
                    status=true;}
                }
            }
            break;
            case SDLK_RIGHT:
            if(status){
                if(px<10-length){
                px++;
                status=false;
                statuss=false;
                }
            }
            else if(!status){
                if(statuss){
                    if(px<9){
                    ++px;
                    }
                }
                else {
                    if(px<10-length){
                    px+=length;
                    status=true;}
                }
            }
            break;
            default:
            break;
        }
        }
        }

}

void Game::update()
{


}

void Game::clean()
{
    std::cout<< "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}
