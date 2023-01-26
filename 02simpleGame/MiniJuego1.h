#ifndef MINIJUEGO1_H
#define MINIJUEGO1_H

#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"

#include <stdio.h>

#include "ourTypes.h"

#define MAQUINA_BACKGROUND_IMAGE  ".\\img\\MJ1\\maquinaexpendedora.bmp"
#define BALDOSAS_BACKGROUND_IMAGE  ".\\img\\MJ1\\baldosas.bmp"
#define NOLA_JOLASTU_BACKGROUND_IMAGE ".\\img\\MJ1\\Nolajolastu.bmp"

#define BUKAERA ".\\img\\convers\\Mac\\janaria_prest.bmp" // Aun no se ha aceptado la mision

#define BARRA_6_IMAGE ".\\img\\MJ1\\peque\\Barra_vida_6.bmp"
#define BARRA_5_IMAGE ".\\img\\MJ1\\peque\\Barra_vida_5.bmp"
#define BARRA_4_IMAGE ".\\img\\MJ1\\peque\\Barra_vida_4.bmp"
#define BARRA_3_IMAGE ".\\img\\MJ1\\peque\\Barra_vida_3.bmp"
#define BARRA_2_IMAGE ".\\img\\MJ1\\peque\\Barra_vida_2.bmp"
#define BARRA_1_IMAGE ".\\img\\MJ1\\peque\\Barra_vida_1.bmp"
#define BARRA_0_IMAGE ".\\img\\MJ1\\peque\\Barra_vida_0.bmp"

#define BERDE_6_IMAGE ".\\img\\MJ1\\berde\\Barra_vida_6.bmp"
#define BERDE_5_IMAGE ".\\img\\MJ1\\berde\\Barra_vida_5.bmp"
#define BERDE_4_IMAGE ".\\img\\MJ1\\berde\\Barra_vida_4.bmp"
#define BERDE_3_IMAGE ".\\img\\MJ1\\berde\\Barra_vida_3.bmp"
#define BERDE_2_IMAGE ".\\img\\MJ1\\berde\\Barra_vida_2.bmp"
#define BERDE_1_IMAGE ".\\img\\MJ1\\berde\\Barra_vida_1.bmp"
#define BERDE_0_IMAGE ".\\img\\MJ1\\berde\\Barra_vida_0.bmp"

#define TUBO_PLAYER_IMAGE ".\\img\\MJ1\\tubo.bmp"

#define HAMBURGUESA_OBJECT_IMAGE ".\\img\\MJ1\\hamburguesa.bmp"
#define LECHUGA_OBJECT_IMAGE ".\\img\\MJ1\\lechuga.bmp"
#define PAN_ARRIBA_OBJECT_IMAGE  ".\\img\\MJ1\\panarriba.bmp"

#define HAMBURGUESA_KOP 10
#define LECHUGA_KOP 10
#define PAN_ARRIBA_KOP 10
#define JAN_MAX 10

typedef struct
{
	POSIZIOA pos;
	int id;
	int aldatuta;
	int gertatu;
	int type;
	MOTA mota;

}JOKO_1_ELEMENTUA;

int mini_juego_1();

JOKO_1_ELEMENTUA tuboaren_mugimendua(JOKO_1_ELEMENTUA tubo, int);

int Irudia_Bistaratu(int x, int y, char* irudia);

void BarraKargatu(int barra[]);
void BerdeKargatu(int berde[]);

void MiniJokoaAurkeztu();

void bukaera();

JOKO_1_ELEMENTUA JanariaKargatu(JOKO_1_ELEMENTUA janaria[], int mota, int i);

JOKO_1_ELEMENTUA JanariaKomp(JOKO_1_ELEMENTUA janaria[], JOKO_1_ELEMENTUA tubo, int i, int mota);

#endif