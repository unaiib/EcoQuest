#ifndef MAPAK_H
#define MAPAK_H

#include "funtzioak.h"
#include "Mugimenduak.h"
#include "Sprite.h"
#include "Mapak.h"
#include "EbentuaKargatu.h"

#define MAPA_INICIAL ".\\img\\Casa\\casa_inicio.bmp"
#define MAPA_CON_ARBOL ".\\img\\Casa\\casa_arbol.bmp"

#define MAPA_CIUDAD_1 ".\\img\\ciudad\\ciudad_1.bmp"
#define MAPA_CIUDAD_2 ".\\img\\ciudad\\ciudad_2.bmp"

#define MAPA_BOSQUE_1 ".\\img\\bosque\\bosque_bajo.bmp"
#define MAPA_BOSQUE_2 ".\\img\\bosque\\bosque_alto.bmp"

#define	BASURA ".\\img\\Extras\\basura.bmp"
#define ZONA_BASURAS ".\\img\\Extras\\basuras.bmp"
#define MENDIGO ".\\img\\Extras\\mendigo.bmp"

#define REGADERA ".\\img\\Extras\\regadera.bmp"

void MapakKargatu(int mapa []);
void MapaAldatu(int mapa[]);

void colisiones(int mapa[], int jokalaria[], int extras[]);

void LimpiarMapa(int extras[], int zenbat);
void CrearExtras(int mapa[],int extras[]);

//Colisiones Ciudad Baja

void CiudadBaja_Goitik(int jokalaria[], int aldaketa);
void CiudadBaja_Behetik(int jokalaria[], int aldaketa);
void CiudadBaja_ColisionLateral(int jokalaria[], int aldaketa);

void Adaketak_CiudadBaja(int mapa[], int jokalaria[], int extras[]);
void Invisble_CiudadBaja(int jokalaria[], int aldaketa);

//Colisiones Ciudad Alta	

void CiudadAlta_ColisionVertical(int jokalaria[], int aldaketa);
void CiudadAlta_ColisionLateral(int jokalaria[], int aldaketa);

void Invisble_CiudadAlta(int jokalaria[], int aldaketa);

//Colisiones Bosque Bajo

void BosqueBajo_ColisionesVerticales(int jokalaria[], int aldaketa);
void BosqueBajo_ColisionesHorizontales(int jokalaria[], int aldaketa);

//colisiones Bosque Alto

void BosqueAlto(int jokalaria[], int aldaketa);


#endif