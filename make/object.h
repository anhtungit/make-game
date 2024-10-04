#pragma once
#include "texturemanager.h"

class Object
{
  private:
      SDL_Rect src, dest;
      SDL_Texture *tex;
  public:
      Object();
      void setsrc(int x, int y, int w, int h);
      void setdest(int x, int y, int w, int h);
      
      SDL_Texture* gettexture();
      SDL_Rect &getsrc(); 
      SDL_Rect &getdest();
      void createtexture(const char* address, SDL_Renderer* ren);
      void Render(SDL_Renderer* ren) ;
      void RenderCopyEx(SDL_Renderer* ren);

};