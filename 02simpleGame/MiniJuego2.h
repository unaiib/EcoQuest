#ifndef MINIJUEGO2_H
#define MINIJUEGO2_H

#include "OurTypes.h"
#include "Sprite.h"
#include "Mugimenduak.h"

#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>

//Meta
#define META ".\\img\\MJ2\\meta\\meta.bmp"
#define BURUA ".\\img\\MJ2\\meta\\burua.bmp"

//Oztopoak
#define PIEDRA ".\\img\\MJ2\\Obstaculos\\1\\piedras1.bmp"
#define NEUMATICO ".\\img\\MJ2\\Obstaculos\\2\\neumatico.bmp"
#define ARBOL ".\\img\\MJ2\\Obstaculos\\3\\arbol.bmp"

//Mounstroa
#define MOUNSTRO ".\\img\\MJ2\\mounstro\\mounstro.bmp"

//Background
#define FONDO ".\\img\\MJ2\\fondo\\1\\bosque (1).bmp"
#define NolaJolastu ".\\img\\MJ2\\fondo\\2\\nola-jolastu.bmp"

//Final
#define IHESEGIN ".\\img\\MJ2\\fondo\\ihes.bmp"
#define HARRAPATUTA ".\\img\\MJ2\\fondo\\harrapatuta.bmp"

//Soinua
#define MUSICA2 ".\\sound\\Musica2.wav"

int zeegoera(int objetua[], int jokalaria[]);

void jokalariaMugitu2(int[], int[]);
void mugituBerriz2(int jokalaria[], int x, int y);
void mounstroaMugitu(int[]);
int OztopoakMugitu(int[], int baiedoez);
void Mapamugitu(int[]);

int metakargatu(int meta, int burua[]);
void metaaldatu(int meta, int burua[]);

void jokalariaKargatu2(int jokalaria[]);
void OztopoakKargatu(int Oztopoa[]);
void Mounstroakargatu(int mounstroa[]);
void mapakargatu(int mapa[]);

void jokoaAurkeztu_2();

int salto(int jokalaria[], int saltoabaiedoez);

void SpritaSortu2(int jokalaria[]);
void AldaketakS(int jokalaria[]);

int Mini_Juego_2();

void bukaerakoa(int emaitza);

#endif