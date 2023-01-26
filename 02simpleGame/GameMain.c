//---------------------------------------------------------------------------------
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
//---------------------------------------------------------------------------------

#include <stdio.h>

#include "ourTypes.h"
#include "funtzioak.h"
#include "Sprite.h"


int main(int argc, char * str[]) {

  int jarraitu = 0;
  EGOERA egoera;
 
  if (sgHasieratu() == -1) 
  {
    fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
    return 1;
  }

  textuaGaitu(); 

  jokoaAurkeztu();

  egoera = jokatu();

  sgItxi();

  return 0;
}

