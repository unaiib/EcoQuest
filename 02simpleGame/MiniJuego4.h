#ifndef MINIJUEGO4_H
#define MINIJUEGO4_H

#include "ourTypes.h"
#include "Mugimenduak.h"
#include "Bala.h"

#include "ebentoak.h"

#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"

#include <stdio.h>
#include <windows.h>

#define MUSICA4 ".\\sound\\Musica4.wav"

#define VEL 10

typedef struct PT_POSIZIOA
{
    float x;
    float y;
} POSIZIOA4;

void jokoaAurkeztu4(void);

int Mini_Juego_4 (void);

int jokoAmaierakoa4(int egoera);

void sarreraMezuaIdatzi4();

int BUKAERA_irudiaBistaratu4();

//BALA
void jokalariaTiro4(int jokalaria[], int bala[]);
void balaSortu4(int bala[], int jokalaria[], int dir);
void balaNorabideanMugitu4(int bala[]);
void balaMugitu4(int bala[], int x, int y);
void balaAnimazioa4(int bala[]);
void animazioa4(int bala[], char sprite[], int hurrengoa);
void balaKanpoan4(int bala[]);
void balaKendu4(int bala[]);
void balaPun4(int bala[]);

void jokalariaMugitu4(int[]);
void mapatikIrten4(int jokalaria[]);

void jokalariaKargatu4(int jokalaria[]);
void mugimenduaBehin4(int jokalaria[], int x, int y, int aldaketa);
void mugituBerriz4(int jokalaria[], int x, int y);

void SpritaSortu4(int jokalaria[]);
void Aldaketak4(int jokalaria[]);

//ETSAIAK


typedef struct
{
    POSIZIOA4 pos;
    POSIZIOA4 direkzioa;
    POSIZIOA4 desbio;
    int dir;
    int sprite;
    int animazioa;
    int id;
}ETSAIA;

void etsaiakFuntzioa4(ETSAIA etsaiak[], int jokalaria[], int bala[], int datuak[]);
int etsaiaSortu4(ETSAIA etsaiak[], int i);
void etsaiaMugitu4(ETSAIA etsaiak[], int jokalaria[], int dim);
void etsaiaAnimazioa4(ETSAIA etsaiak[], int i);
void eAnimazioa4(ETSAIA etsaiak[], int i, char sprite[], int hurrengoa);
void bideaAurkitu4(ETSAIA etsaiak[], int jokalaria[], int i, int kop);
void etsaiaKolisioa4(ETSAIA etsaiak[], int bala[], int datuak[]);
void etsaiaKendu4(ETSAIA etsaiak[], int i, int datuak[]);
void animazioaAktibatu4(ETSAIA etsaiak[], int kont, int kop);
void jokalariaHil4(ETSAIA etsaiak[], int jokalaria[], int datuak[]);

#define ETSAIA_1_1 ".\\img\\MJ4\\Etsaia\\1\\1.bmp"
#define ETSAIA_1_2 ".\\img\\MJ4\\Etsaia\\1\\2.bmp"
#define ETSAIA_1_3 ".\\img\\MJ4\\Etsaia\\1\\3.bmp"

#define ETSAIA_2_1 ".\\img\\MJ4\\Etsaia\\2\\1.bmp"
#define ETSAIA_2_2 ".\\img\\MJ4\\Etsaia\\2\\2.bmp"
#define ETSAIA_2_3 ".\\img\\MJ4\\Etsaia\\2\\3.bmp"

#define ETSAIA_3_1 ".\\img\\MJ4\\Etsaia\\3\\1.bmp"
#define ETSAIA_3_2 ".\\img\\MJ4\\Etsaia\\3\\2.bmp"
#define ETSAIA_3_3 ".\\img\\MJ4\\Etsaia\\3\\3.bmp"

#define ETSAIA_4_1 ".\\img\\MJ4\\Etsaia\\4\\1.bmp"
#define ETSAIA_4_2 ".\\img\\MJ4\\Etsaia\\4\\2.bmp"
#define ETSAIA_4_3 ".\\img\\MJ4\\Etsaia\\4\\3.bmp"

int irudiaSortu4(char irudia[]);

#define FONDO4 ".\\img\\MJ4\\Fondo\\fondo.bmp"
#define NOLA_JOLASTU ".\\img\\MJ4\\Nola_jolastu\\Nola_jolastu.bmp"

#endif