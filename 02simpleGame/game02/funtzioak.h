#ifndef GAME10_H
#define GAME10_H

#include "ourTypes.h"
#include "Mugimenduak.h"
#include "Sprite.h"
#include "Mapak.h"
#include "EbentuaKargatu.h"

#define ONGI_ETORRI_MEZUA "MUNDUA BUKATUKO DA..."

#define HASIERA_IMAGE ".\\img\\JOKOARENA\\inicio.bmp"

#define BUKAERA_IMAGE_1 ".\\img\\JOKOARENA\\final_1.bmp"
#define BUKAERA_IMAGE_MUNDUA ".\\img\\JOKOARENA\\mundua.bmp"
#define BUKAERA_IMAGE_CREDITS ".\\img\\JOKOARENA\\creditos.bmp"

#define GALDUTA_IMAGE ".\\img\\JOKOARENA\\gameOver_2.bmp"

//#define MUSICA_GENERAL ".\\sound\\MusicaGeneral.wav"
#define MUSICAF ".\\sound\\MusicaF.wav"

void jokoaAurkeztu(void);
EGOERA jokatu(void);
int  jokoAmaierakoa(EGOERA egoera);

int BUKAERA_irudiaBistaratu();
EGOERA JOKOA_egoera(int jokalaria[]);

void JokoaBukatu();

#endif