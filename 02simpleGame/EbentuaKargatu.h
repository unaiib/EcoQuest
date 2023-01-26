#ifndef EBENTUAKARGATU_H
#define EBENTUAKARGATU_H

#include "ebentoak.h"
#include "funtzioak.h"
#include "Mugimenduak.h"
#include "Sprite.h"
#include "Mapak.h"
#include "Hizketak.h"

#include "MiniJuego1.h"

#define E_SAKATU_1 ".\\img\\Extras\\tecla_e_1.bmp"
#define E_SAKATU_2 ".\\img\\Extras\\tecla_e_2.bmp"

#define URA_LORTU ".\\img\\convers\\textos\\ura_lortu.bmp"
#define BUELTA_EMAN ".\\img\\convers\\textos\\bidea.bmp"
#define BABESTU ".\\img\\convers\\textos\\ura_babestu.bmp"
#define KENDUTA ".\\img\\convers\\textos\\ura_kenduta.bmp"

void MisioakHasieratu(int misiones[]);

void ebentuaKargatu(int mapa[], int jokalaria[], int extras[], int misiones[]);

void BirKargatu(int jokalaria[], int mapa[], int extras[]);
void DenaKendu(int jokalaria[], int mapa[], int extras[]);

void HitzEgin(int hizketa, int mapa[]);
void MezuaIdatzi(int argazkia, int x, int y);

void EbentuaGertu(int jokalaria[], int mapa[], int kontrol[]);

#endif