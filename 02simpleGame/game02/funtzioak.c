#include "funtzioak.h"
#include "Mugimenduak.h"
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

void jokoaAurkeztu(void)
{
  int ebentu = 0, img;

  img = irudiaKargatu(HASIERA_IMAGE);
  irudiaMugitu(img, 130, 100);

  pantailaGarbitu();
  irudiakMarraztu();
  pantailaBerriztu();

  do
  {
    ebentu = ebentuaJasoGertatuBada();
  } while (ebentu != TECLA_RETURN);// esperar hasta que se pulsa return

  irudiaKendu(img);

  pantailaGarbitu();
  pantailaBerriztu();
}

EGOERA jokatu(void) 
{
  int jokalaria[10]; //crear vector personaje
  int mapa[5]; // crear vector mapa
  int extras[5]; // para obstaculos extras
  int misiones[6]; // control de minijuegos
  int kontrol[3];// para controlar los textos

  EGOERA  egoera = JOLASTEN; // variable control de cuando estamos jugando

  MapakKargatu(mapa); // cargar datos del mapa
  jokalariaKargatu(jokalaria); // cargar datos del jugador
  MisioakHasieratu(misiones);

  kontrol[0] = kontrol[1] = kontrol[2] = 0;

  do {

    Sleep(2);
 
    pantailaGarbitu();

    jokalariaMugitu(jokalaria); // mover jugador
    colisiones(mapa, jokalaria, extras); // comprobar si hay colision o cambio de mapa
    EbentuaGertu(jokalaria, mapa, kontrol);

    if (jokalaria[9] == 1) // si intentan entrar a un ebento
    {
        if (kontrol[1] != 0)
        {
            irudiaKendu(kontrol[0]);
            kontrol[1] = 0;
        }

        ebentuaKargatu(mapa, jokalaria, extras, misiones); // comprobar si hay que cargar ebentos

        jokalaria[9] = 0; // devolver ebento a 0
    }

    irudiakMarraztu();
    pantailaBerriztu();

    egoera = JOKOA_egoera(jokalaria); // comprobar si se termina el juego

  } while (egoera == JOLASTEN); // mientras se este jugando

  if (mapa[1] == 3) LimpiarMapa(extras, 3);
  if (kontrol[1] != 0) irudiaKendu(kontrol[0]);

  irudiaKendu(jokalaria[0]); 
  irudiaKendu(mapa[0]);

  //vaciar pantalla
  
  pantailaGarbitu();
  pantailaBerriztu();

  if (mapa[4] == 1) JokoaBukatu();
  else BUKAERA_irudiaBistaratu();

  return egoera;
}

EGOERA JOKOA_egoera(int jokalaria[]) {

    EGOERA  ret = JOLASTEN;

    if (jokalaria[8] == 1) // si te has quedado sin tiempo o quieres salir pierdes
    { 
        ret = GALDU;
    }

    return ret;
}

int  jokoAmaierakoa(EGOERA egoera)
{
  int ebentu = 0, id;

  id = BUKAERA_irudiaBistaratu(); //mostrar el game over

  do 
  {
    ebentu = ebentuaJasoGertatuBada();
  } while ((ebentu!= TECLA_RETURN) && (ebentu!= SAGU_BOTOIA_ESKUMA)); //esperar hasta que se pulse el raton o return

  irudiaKendu(id); // quitar la foto

  return (ebentu != TECLA_RETURN) ? 1 : 0; //si se quiere volver a jugar
}

int BUKAERA_irudiaBistaratu() {
  int id = -1;

  id = irudiaKargatu(GALDUTA_IMAGE); //mostrar la imagen de game over

  irudiaMugitu(id, 750, 450); // colocar esa foto

  pantailaGarbitu();
  irudiakMarraztu();
  pantailaBerriztu();

  return id;
}

void JokoaBukatu() {

    int img, ebentu, y =0;

    audioInit();
    loadTheMusic(MUSICAF);
    playMusic();

    //primera foto

    img = irudiaKargatu(BUKAERA_IMAGE_1);
    irudiaMugitu(img, 140, 100);

    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();

    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);

    irudiaKendu(img);

    //segunda foto

    img = irudiaKargatu(BUKAERA_IMAGE_MUNDUA);
    irudiaMugitu(img, 650, 300);

    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();

    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);

    irudiaKendu(img);

    //tercera foto

    img = irudiaKargatu(BUKAERA_IMAGE_CREDITS);
    irudiaMugitu(img, 140, 900);

    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();

    y = 900;

    do
    {
        Sleep(60);

        y -= 10;
        irudiaMugitu(img, 140, y);

        pantailaGarbitu();
        irudiakMarraztu();
        pantailaBerriztu();

        ebentu = ebentuaJasoGertatuBada();
    } while ((ebentu != TECLA_RETURN)&&(y > -900));

    irudiaKendu(img);

    audioTerminate();

}

