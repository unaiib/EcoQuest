#ifndef MUGIMENDUAK_H
#define MUGIMENDUAK_H

#include "ebentoak.h"
#include "funtzioak.h"
#include "OurTypes.h"
#include "Sprite.h"
#include "Mapak.h"
#include "EbentuaKargatu.h"

#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>

void jokalariaMugitu(int []);

void jokalariaKargatu(int jokalaria[]);

void mugimenduaBehin(int jokalaria[], int x, int y, int aldaketa);
void mugituBerriz(int jokalaria[], int x, int y);

void SpritaSortu(int jokalaria[]);
void SpritaHandiaSortu(int jokalaria[]);
void Aldaketak(int jokalaria[]);

#endif