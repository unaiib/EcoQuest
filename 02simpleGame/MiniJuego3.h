#ifndef MINIJUEGO3_H
#define MINIJUEGO3_H

#include "OurTypes.h"

#define LAKUA_2 ".\\img\\MJ3\\LagoFoto2.bmp"

#define HOW_TO_PLAY1 ".\\img\\MJ3\\HowToPlay2.0.bmp"
#define HOW_TO_PLAY2 ".\\img\\MJ3\\HowToPlay2.1.bmp"

#define COLA_IMAGE ".\\img\\MJ3\\LataCoca.bmp"
#define BOTILA ".\\img\\MJ3\\botella.bmp"
#define KARTOIA ".\\img\\MJ3\\cajaCarton.bmp"
#define CONTENEDOR ".\\img\\MJ3\\contenedor.bmp"

#define CUBO_VE ".\\img\\MJ3\\cuboVerde.bmp"
#define CUBO_AM ".\\img\\MJ3\\cuboAmarillo.bmp"
#define CUBO_AZ ".\\img\\MJ3\\cuboAzul.bmp"

#define BOSQUE ".\\img\\MJ3\\bosque1.bmp"

#define LATA_KOP 3
#define KARTOI_KOP 3
#define BEIRA_KOP 3

#define VEL_PLASTIKOA 3
#define VEL_BEIRA 2
#define VEL_KARTOIA 3 

typedef struct
{
	POSIZIOA pos;
	int id;
	MOTA mota;
	int aurkituta;	// 0 aurkitu gabe - 1 aurkituta
	int heldu;		// 0 heldu gabe - 1 helduta
	int mugitzen;

}JOKO_ELEMENTUA3;

int mini_jokoa_3();
int lata_bistaratu(int x, int y);
int nola_jolasten_da();
int nola_jolasten_da2();

int contenedor_bistaratu(int x, int y);

int beira_bistaratu(int x, int y);
int kartoia_bistaratu(int x, int y);

//--------

void mover_basura(JOKO_ELEMENTUA3 basura[], int v);
int moverAlContenedor(JOKO_ELEMENTUA3 basura[], int v, int i);
int mov_automatikoa(JOKO_ELEMENTUA3 basura[], int v);

//-----------------------

void jokoaGaldu(void);
void jokoaIrabazi(void);

int cuboVe_bistaratu(int x, int y);
int cuboAm_bistaratu(int x, int y);
int cuboAz_bistaratu(int x, int y);

int basoa_bistaratu();

#endif