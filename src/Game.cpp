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
    TheTexture::Instance()->load("complete.png","cp",m_pRenderer);
    std::cout << "init success\n";
    return true;
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);
   /* for(int j=9;j>=0;--j){
        for(int i=0;i<10;++i){
            if(px==i&&py==j) {std::cout<<2<<" ";}
            else std::cout<<maps[i][j]<<" ";
        }
        std::cout<<std::endl;
  }
    std::cout<<"\n";

    /*SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
    SDL_RenderClear(m_pRenderer);
    SDL_SetRenderDrawColor(m_pRenderer,0, 0, 0, 255);
    for(int i=0; i<10; i++){
    double l=(1+i)*100;
    double x=(1000*l)/(l+500);
    SDL_RenderDrawLine(m_pRenderer,360-100*px+i*20,720-50-x,360+100*(10-px)-i*20,720-50-x);
    }*/

    SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
    SDL_RenderClear(m_pRenderer);
    SDL_SetRenderDrawColor(m_pRenderer, 252, 224, 166, 255);
    SDL_Rect B; B.x=290; B.y=10; B.w=700; B.h=700;
    SDL_RenderFillRect(m_pRenderer, &B);
    SDL_SetRenderDrawColor(m_pRenderer, 91, 189, 43, 255);
    for(int i=0; i<=10; ++i){
        SDL_RenderDrawLine(m_pRenderer, 290, 10+i*70, 990, 10+i*70);
    }
    for(int i=0; i<=10; ++i){
        SDL_RenderDrawLine(m_pRenderer, 290+i*70, 10, 290+i*70, 710);
    }
    SDL_SetRenderDrawColor(m_pRenderer, 0, 178, 191, 255);
    SDL_Rect R1,R2,R,T;
    R1.x=290;
    R1.y=640;
    R2.x=920;
    R2.y=10;
    R1.w=70;
    R2.w=70;
    R1.h=70;
    R2.h=70;
    SDL_RenderFillRect(m_pRenderer, &R1);
    SDL_RenderFillRect(m_pRenderer, &R2);
    R.x=290+px*70;
    T.x=R.x+10;
    R.y=640-py*70;
    T.y=R.y+10;
    if(status==1){R.w=70; R.h=70; T.w=50; T.h=50;}
    if(status==0&&statuss==1)
    {
        R.y-=140; T.y=R.y+10;
        R.w=70;   T.w=50;
        R.h=210;  T.h=190;
    }
    if(status==0&&statuss==0)
    {
        R.w=210; T.w=190;
        R.h=70;  T.h=50;
    }
    SDL_SetRenderDrawColor(m_pRenderer, 85, 85, 85, 255);
    SDL_RenderFillRect(m_pRenderer, &R);
    SDL_SetRenderDrawColor(m_pRenderer, 148, 83, 5, 255);
    SDL_RenderFillRect(m_pRenderer, &T);
    if(px==9&&py==9){ // if cai j do
        SDL_RenderCopy(m_pRenderer,TheTexture::Instance()->getTexture("cp"),NULL,NULL);
        // SDL_Delay(5000);
        // ++level; loadMap(level);
    }
    SDL_RenderPresent(m_pRenderer);
}

void Game::handleEvents()
{
    SDL_Event event;
    while(SDL_PollEvent(&event)!=0)
        {
        if(event.type == SDL_QUIT)
        {
           m_bRunning=false;
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
                    if(py<=9-length){
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
