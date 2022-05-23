#include "Character.h"
#include "background.h"
#include <stdio.h>
#include <iostream>

bool bird::init()
{
    pos.getPos(50, SCREEN_HEIGHT / 2);
    ahead = 0;
    if (isNULL())
    {
        if ( Load( "img/bird.png", scale ) )
        {
            angle = 0;
            time = -1;
            return true;
        }
        else
        {
            printf("could not load bird.img\n");
            return false;
        }
    }
    return false;
}

void bird::Free()
{
    free();
    std::cout << "bird free!\n";
}

void bird::render()
{
    Render(pos.x, pos.y, angle);
}

void bird::update(int pileWidth, int pileHeight)
{
    if (!lost)
    {
        if (time == 0)
        {
            x0 = pos.y;
            angle = -20;
        }
        else if (angle < 70 && time > 30)
        {
            angle += 3;
        }
        if (time >= 0)
        {
            pos.y = x0 + time * time * 0.1 - 5 * time;
            ++time;
        }

        if ( (pos.x + getWidth() > posPile[ahead].x + 3) &&
                (pos.x + 5 < posPile[ahead].x + pileWidth) &&
                ( pos.y + 5 < posPile[ahead].y + pileHeight ||
                  pos.y  + getHeight()  > posPile[ahead].y + pileHeight + holeWidth ))
        {
            lost = true;
        }

        else if (pos.x > posPile[ahead].x + pileWidth )
        {
            ahead = ( ahead + 1 ) % TOTAL_PILE;
            ++score;
        }

        if ( pos.y - 8 > SCREEN_HEIGHT ||
                pos.y < - 8 )
        {
            lost = true;
        }
        
    }
}
