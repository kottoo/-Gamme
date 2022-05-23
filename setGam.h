#ifndef SETGAM_H
#define SETGAM_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>
#include <stdio.h>


class position
{
public:
    int x, y, angle, state;
public:
    void getPos(const int x,const int y);
    void getAngle(int newAngle);
};


class LTexture
{
public:
    LTexture();

    ~LTexture() {}

    bool isNULL();

    //Deallocates texture
    void free();

    //Set color modulation
    void setColor( Uint8 red, Uint8 green, Uint8 blue );

    //load image
    bool Load(std::string path, double scale = 1);

    // Load Text
    void Load_Text(std::string text, int scale = 1);

    //Renders texture at given point
    void Render(int x, int y, int angle = 0, SDL_Rect* clip = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

    //Set blending
    void setBlendMode( SDL_BlendMode blending = SDL_BLENDMODE_BLEND);

    //Set alpha modulation
    void setAlpha( Uint8 alpha );

    //Gets image dimensions
    int getWidth();
    int getHeight();

    void fixWidth(int newWidth);

    void fixHeight(int newHeight);

public:
    //The actual hardware texture
    SDL_Texture* Texture;

    //Image dimensions
    int tWidth;
    int tHeight;

public:

    static SDL_Window* gWindow;
    static SDL_Renderer* gRenderer;
    static TTF_Font* Font;
    static bool quit;
    static bool lost;
    static SDL_Event e;
    static int countedFrame;
    static int score;

    static const int SCREEN_WIDTH = 520;
    static const int SCREEN_HEIGHT = 690;
    static const int Font_Size = 2;

    static const int holeWidth = 200;
    static const int TOTAL_PILE = 4;
    static const int distance = 400;

};


#endif
