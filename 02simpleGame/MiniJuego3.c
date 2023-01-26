#define _CRT_SECURE_NO_WARNINGS

#include "OurTypes.h"
#include "MiniJuego3.h"

#include "imagen.h"
#include "soinua.h"
#include "text.h"
#include "graphics.h"

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "SDL_image.h"
#include "SDL_TTF.h"

#define MUSICA3 ".\\sound\\Musica3.wav"

int cuentala = 0;		//puntuazioa	--> aldagai globala

int mini_jokoa_3()
{
	int kont = 0, kop = 0;
	POSIZIOA saguPos;
	SDL_Renderer* renderer = getRenderer();

	int ebentua = 1, i = 0, y = 0;
	int aurkitu = 0;
	int instruct1, instruct2, j = 0;
	//int idLago;

	JOKO_ELEMENTUA3 lata[LATA_KOP];
	JOKO_ELEMENTUA3 beira[BEIRA_KOP];
	JOKO_ELEMENTUA3 kartoia[KARTOI_KOP];
	JOKO_ELEMENTUA3 contenedor;

	//JOKOA_SOUND

	audioInit();
	loadTheMusic(MUSICA3);
	playMusic();

	do
	{
		instruct1 = nola_jolasten_da();
		Sleep(100);
		irudiaKendu(instruct1);

		instruct2 = nola_jolasten_da2();
		Sleep(100);
		irudiaKendu(instruct2);

		ebentua = ebentuaJasoGertatuBada();

	} while (ebentua != TECLA_RETURN);

	cuentala = 0;		//resetear el marcador a 0

	contenedor.pos.x = 840;
	contenedor.pos.y = 830;
	contenedor.mota = IRUDIA;

	for (i = 0; i < LATA_KOP; i++)	//lata sortu
	{
		lata[i].pos.x = -((rand() % 200) + 50);
		lata[i].pos.y = (rand() % (790 - 30)) + 30;
		lata[i].id = lata_bistaratu(lata[i].pos.x, lata[i].pos.y);
		lata[i].mota = IRUDIA;
		lata[i].aurkituta = 0;
		lata[i].heldu = 0;
	}

	for (i = 0; i < BEIRA_KOP; i++)	//beira sortu
	{
		beira[i].pos.x = -((rand() % 200) + 50);
		beira[i].pos.y = (rand() % (790 - 30)) + 30;
		beira[i].id = beira_bistaratu(beira[i].pos.x, beira[i].pos.y);
		beira[i].aurkituta = 0;
		beira[i].heldu = 0;
	}

	for (i = 0; i < KARTOI_KOP; i++)	//kartoia sortu
	{
		kartoia[i].pos.x = -((rand() % 200) + 50);
		kartoia[i].pos.y = (rand() % (790 - 40)) + 30;
		kartoia[i].id = kartoia_bistaratu(kartoia[i].pos.x, kartoia[i].pos.y);
		kartoia[i].mota = IRUDIA;
		kartoia[i].aurkituta = 0;
		kartoia[i].heldu = 0;
	}

	Sleep(300);

	textuaGaitu();

	char punt[20];
	int text_x = 100, text_y = 100;

	TTF_Font* fonta = TTF_OpenFontIndex("C:\\WINDOWS\\Fonts\\ARIAL.TTF", 35, 0);	//declarar variable 'fuente' letra
	SDL_Color color = { 255,255,255 };		// color: white

	SDL_Surface* textSurface = TTF_RenderText_Solid(fonta, punt, color);	// superficie dnd escribes/dnd va el texto

	SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer, textSurface); //renderizar (pintar) la textura

	SDL_Surface* background = IMG_Load(LAKUA_2);		//cargar imagen background:fondo
	SDL_Texture* background_texture = SDL_CreateTextureFromSurface(renderer, background); //crear surface(superficie para background)

	do
	{
		//textuaIdatzi(200, 200, "siiii");
		SDL_RenderCopy(renderer, background_texture, NULL, NULL);	//pintas en background en renderer (que es la 'window')

		sprintf(punt, "Puntuazioa: %i", cuentala);		//escribir lo q sale en pantalla

		textSurface = TTF_RenderText_Solid(fonta, punt, color);	//renderizar (pintar) textura en bucle
		text_texture = SDL_CreateTextureFromSurface(renderer, textSurface);	//crear surface (superficie para background) en bucle

		SDL_Rect rect = { text_x, text_y, textSurface->w, textSurface->h };	//crear rectangulo
		SDL_RenderCopy(renderer, text_texture, NULL, &rect);	// pintar la 'puntuacion/ sprintf'

		SDL_Delay(7);

		if (kont == (LATA_KOP + KARTOI_KOP + BEIRA_KOP)) kont++;		//azkenengo puntuazioa agertzeko

		ebentua = ebentuaJasoGertatuBada();

		if (ebentua == SAGU_BOTOIA_EZKERRA)
		{
			saguPos = saguarenPosizioa();

			i = 0;
			aurkitu = 0;
			while (i < LATA_KOP && aurkitu == 0)
			{

				///--------------------- lata
				if (saguPos.x > lata[i].pos.x - 2 && saguPos.x < lata[i].pos.x + 28 &&
					saguPos.y > lata[i].pos.y && saguPos.y < lata[i].pos.y + 30)
				{

					lata[i].aurkituta = 1;

					aurkitu = moverAlContenedor(lata, VEL_PLASTIKOA, i);

					mover_basura(lata, VEL_PLASTIKOA);
					mover_basura(beira, VEL_BEIRA);
					mover_basura(kartoia, VEL_KARTOIA);
				}
				///--------------------- beira

				if (saguPos.x > beira[i].pos.x - 2 && saguPos.x < beira[i].pos.x + 26 &&
					saguPos.y > beira[i].pos.y && saguPos.y < beira[i].pos.y + 42)
				{
					beira[i].aurkituta = 1;

					//playSound(waterSound);


					aurkitu = moverAlContenedor(beira, VEL_BEIRA, i);

					mover_basura(lata, VEL_PLASTIKOA);
					mover_basura(beira, VEL_BEIRA);
					mover_basura(kartoia, VEL_KARTOIA);

				}

				///--------------------- kartoia

				if (saguPos.x > kartoia[i].pos.x - 2 && saguPos.x < kartoia[i].pos.x + 67 &&
					saguPos.y > kartoia[i].pos.y && saguPos.y < kartoia[i].pos.y + 57)
				{
					kartoia[i].aurkituta = 1;

					aurkitu = moverAlContenedor(kartoia, VEL_PLASTIKOA, i);

					mover_basura(lata, VEL_PLASTIKOA);
					mover_basura(beira, VEL_BEIRA);
					mover_basura(kartoia, VEL_KARTOIA);

				}
				i++;
			}
		}

		if (ebentua == TECLA_p)
		{
			do
			{
				ebentua = ebentuaJasoGertatuBada();

			} while (ebentua != TECLA_p);

		}

		//------------------------- lata
		kont = kont + mov_automatikoa(lata, VEL_PLASTIKOA);

		//------------------- kartoia
		kont = kont + mov_automatikoa(kartoia, VEL_KARTOIA);

		//---------------------- beira
		kont = kont + mov_automatikoa(beira, VEL_BEIRA);

		//printf("%i-", kont);


		contenedor.id = contenedor_bistaratu(contenedor.pos.x, contenedor.pos.y);

		irudiaKendu(contenedor.id);
		irudiakMarraztu();
		pantailaBerriztu();
		pantailaGarbitu();



	} while ((kont <= (LATA_KOP + KARTOI_KOP + BEIRA_KOP)) && (ebentua != TECLA_8));

	//------------------------------------- 2.en fasea

	int k = 0, l = 0;
	int emaitza = 0;
	POSIZIOA auxPos = { 0,0 };
	int idVe, idAm, idAz, idB;
	idVe = idAm = idAz = idB = 0;
	j = 0;
	background = IMG_Load(BOSQUE);

	/*idB = basoa_bistaratu();*/

	idVe = cuboVe_bistaratu(450, 750);
	idAm = cuboAm_bistaratu(850, 750);
	idAz = cuboAz_bistaratu(1250, 750);

	for (i = 0; i < LATA_KOP; i++)
	{
		kop = lata[i].aurkituta + kop;
		kop = beira[i].aurkituta + kop;
		kop = kartoia[i].aurkituta + kop;
	}

	for (i = 0; i < LATA_KOP; i++)
	{

		if (lata[i].aurkituta == 1)
		{
			lata[i].pos.x = 200 + j;
			lata[i].pos.y = 200;
			lata[i].mugitzen = 0;
			lata[i].heldu = 0;
			lata[i].id = lata_bistaratu(lata[i].pos.x, lata[i].pos.y);
			j += 50;
		}
		if (beira[i].aurkituta == 1)
		{
			beira[i].pos.x = 600 + k;
			beira[i].pos.y = 200;
			beira[i].mugitzen = 0;
			beira[i].heldu = 0;
			beira[i].id = beira_bistaratu(beira[i].pos.x, beira[i].pos.y);
			k += 50;
		}
		if (kartoia[i].aurkituta == 1)
		{
			kartoia[i].pos.x = 1000 + l;
			kartoia[i].pos.y = 200;
			kartoia[i].mugitzen = 0;
			kartoia[i].heldu = 0;
			kartoia[i].id = kartoia_bistaratu(kartoia[i].pos.x, kartoia[i].pos.y);
			l += 70;
		}
	}

	j = 0;

	background = IMG_Load(BOSQUE);		//cargar imagen background:fondo
	background_texture = SDL_CreateTextureFromSurface(renderer, background); //crear surface(superficie para background)

	do
	{
		SDL_RenderCopy(renderer, background_texture, NULL, NULL);

		sprintf(punt, "Puntuazioa: %i", cuentala);		//escribir lo q sale en pantalla
		ebentua = ebentuaJasoGertatuBada();

		textSurface = TTF_RenderText_Solid(fonta, punt, color);	//renderizar (pintar) textura en bucle
		text_texture = SDL_CreateTextureFromSurface(renderer, textSurface);	//crear surface (superficie para background) en bucle

		SDL_Rect rect = { text_x, text_y, textSurface->w, textSurface->h };	//crear rectangulo
		SDL_RenderCopy(renderer, text_texture, NULL, &rect);	// pintar la 'puntuacion/ sprintf'

		if (ebentua == SAGU_BOTOIA_EZKERRA)
		{

			saguPos = saguarenPosizioa();

			i = 0;

			while (i < LATA_KOP)
			{

				if (saguPos.x > lata[i].pos.x - 3 && saguPos.x < lata[i].pos.x + 27 &&
					saguPos.y > lata[i].pos.y && saguPos.y < lata[i].pos.y + 30)
				{
					auxPos = lata[i].pos;
					lata[i].mugitzen = 1;

					do {

						saguPos = saguarenPosizioa();

						ebentua = ebentuaJasoGertatuBada();
						SDL_RenderCopy(renderer, background_texture, NULL, NULL);
						sprintf(punt, "Puntuazioa: %i", cuentala);
						SDL_RenderCopy(renderer, text_texture, NULL, &rect);	// pintar la 'puntuacion/ sprintf'

						irudiaMugitu(lata[i].id, saguPos.x - 10, saguPos.y - 12);
						irudiakMarraztu();
						pantailaBerriztu();
						pantailaGarbitu();

						if (ebentua == SAGU_BOTOIA_EZKERRA)
						{
							lata[i].mugitzen = 0;
							lata[i].pos.x = saguPos.x - 10;
							lata[i].pos.y = saguPos.y - 12;
						}

					} while (lata[i].mugitzen == 1);

				}

				if (saguPos.x > beira[i].pos.x - 2 && saguPos.x < beira[i].pos.x + 26 &&
					saguPos.y > beira[i].pos.y && saguPos.y < beira[i].pos.y + 42)
				{
					auxPos = beira[i].pos;
					beira[i].mugitzen = 1;

					do {

						saguPos = saguarenPosizioa();

						ebentua = ebentuaJasoGertatuBada();
						SDL_RenderCopy(renderer, background_texture, NULL, NULL);
						sprintf(punt, "Puntuazioa: %i", cuentala);
						SDL_RenderCopy(renderer, text_texture, NULL, &rect);	// pintar la 'puntuacion/ sprintf'

						irudiaMugitu(beira[i].id, saguPos.x - 11, saguPos.y - 19);
						irudiakMarraztu();
						pantailaBerriztu();
						pantailaGarbitu();

						if (ebentua == SAGU_BOTOIA_EZKERRA)
						{
							beira[i].mugitzen = 0;
							beira[i].pos.x = saguPos.x - 11;
							beira[i].pos.y = saguPos.y - 19;
						}

					} while (beira[i].mugitzen == 1);

				}

				if (saguPos.x > kartoia[i].pos.x - 2 && saguPos.x < kartoia[i].pos.x + 66 &&
					saguPos.y > kartoia[i].pos.y && saguPos.y < kartoia[i].pos.y + 57)
				{

					auxPos = kartoia[i].pos;

					kartoia[i].mugitzen = 1;

					do {

						saguPos = saguarenPosizioa();

						ebentua = ebentuaJasoGertatuBada();
						SDL_RenderCopy(renderer, background_texture, NULL, NULL);
						sprintf(punt, "Puntuazioa: %i", cuentala);
						SDL_RenderCopy(renderer, text_texture, NULL, &rect);	// pintar la 'puntuacion/ sprintf'

						irudiaMugitu(kartoia[i].id, saguPos.x - 30, saguPos.y - 26);
						irudiakMarraztu();
						pantailaBerriztu();
						pantailaGarbitu();

						if (ebentua == SAGU_BOTOIA_EZKERRA)
						{
							kartoia[i].mugitzen = 0;
							kartoia[i].pos.x = saguPos.x - 30;
							kartoia[i].pos.y = saguPos.y - 26;
						}

					} while (kartoia[i].mugitzen == 1);

				}



				//--- plastico

				if (lata[i].pos.x >= 880 && lata[i].pos.x <= 930 && lata[i].pos.y >= 780 && lata[i].pos.y <= 1000 && lata[i].heldu == 0)
				{
					irudiaKendu(lata[i].id);
					lata[i].heldu = 1;
					j++;
				}
				else if ((beira[i].pos.x >= 880 && beira[i].pos.x <= 930 && beira[i].pos.y >= 780 && beira[i].pos.y <= 1000 && beira[i].heldu == 0) ||
					(kartoia[i].pos.x >= 880 && kartoia[i].pos.x <= 930 && kartoia[i].pos.y >= 780 && kartoia[i].pos.y <= 1000 && kartoia[i].heldu == 0))
				{
					cuentala -= 5;
				}

				//--- cristal
				if (beira[i].pos.x >= 480 && beira[i].pos.x <= 530 && beira[i].pos.y >= 780 && beira[i].pos.y <= 1000 && beira[i].heldu == 0)
				{
					irudiaKendu(beira[i].id);
					beira[i].heldu = 1;
					j++;
				}
				else if ((lata[i].pos.x >= 480 && lata[i].pos.x <= 530 && lata[i].pos.y >= 780 && lata[i].pos.y <= 1000 && lata[i].heldu == 0) ||
					(kartoia[i].pos.x >= 480 && kartoia[i].pos.x <= 530 && kartoia[i].pos.y >= 780 && kartoia[i].pos.y <= 1000 && kartoia[i].heldu == 0))
				{
					cuentala -= 5;
				}

				//--- carton
				if (kartoia[i].pos.x >= 1280 && kartoia[i].pos.x <= 1330 && kartoia[i].pos.y >= 780 && kartoia[i].pos.y <= 1000 && kartoia[i].heldu == 0)
				{
					irudiaKendu(kartoia[i].id);
					kartoia[i].heldu = 1;
					j++;
				}
				else if ((lata[i].pos.x >= 1280 && lata[i].pos.x <= 1330 && lata[i].pos.y >= 780 && lata[i].pos.y <= 1000 && lata[i].heldu == 0) ||
					(beira[i].pos.x >= 1280 && beira[i].pos.x <= 1330 && beira[i].pos.y >= 780 && beira[i].pos.y <= 1000 && beira[i].heldu == 0))
				{
					cuentala -= 5;
				}

				i++;
			}
		}

		irudiakMarraztu();
		pantailaBerriztu();
		pantailaGarbitu();

	} while (kop != j);

	if (cuentala < 20)
	{
		emaitza = 0;	// 0 - galdu & errepikatu
	}
	else
	{
		emaitza = 1;	// 1 - irabazi
	}

	irudiaKendu(idAm);
	irudiaKendu(idVe);
	irudiaKendu(idAz);

	pantailaBerriztu();
	pantailaGarbitu();

	audioTerminate();

	return emaitza;
}

//--------------------------------------

int basoa_bistaratu()
{
	int id = -1;
	id = irudiaKargatu(BOSQUE);
	irudiaMugitu(id, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return id;
}

int cuboVe_bistaratu(int x, int y)
{
	int id = -1;
	id = irudiaKargatu(CUBO_VE);
	irudiaMugitu(id, x, y);
	//pantailaGarbitu();
	irudiakMarraztu();
	//pantailaBerriztu();
	return id;
}

int cuboAm_bistaratu(int x, int y)
{
	int id = -1;
	id = irudiaKargatu(CUBO_AM);
	irudiaMugitu(id, x, y);
	//pantailaGarbitu();
	irudiakMarraztu();
	//pantailaBerriztu();
	return id;
}

int cuboAz_bistaratu(int x, int y)
{
	int id = -1;
	id = irudiaKargatu(CUBO_AZ);
	irudiaMugitu(id, x, y);
	//pantailaGarbitu();
	irudiakMarraztu();
	//pantailaBerriztu();
	return id;
}

//------------------------------------

int mov_automatikoa(JOKO_ELEMENTUA3 basura[], int v)
{
	int y = 0, aurk = 0, kont = 0;

	for (y = 0; y < LATA_KOP; y++)
	{
		aurk = 0;
		if (basura[y].pos.x < 0)
		{
			basura[y].pos.x = basura[y].pos.x + v;

		}
		else if (basura[y].aurkituta == 0 && basura[y].pos.x >= 0 && basura[y].pos.x <= 1920) {
			basura[y].pos.x = basura[y].pos.x + v;
			irudiaMugitu(basura[y].id, basura[y].pos.x, basura[y].pos.y);
			irudiakMarraztu();

		}
		else if (basura[y].aurkituta == 1 && basura[y].pos.x < 1920)
		{
			aurk = moverAlContenedor(basura, v, y);

			irudiakMarraztu();

		}
		if (basura[y].pos.x >= 1920 && basura[y].heldu == 0)
		{
			kont++;
			basura[y].heldu = 1;
		}
		if (aurk == 1)
		{
			irudiaKendu(basura[y].id);
			kont = 1;
		}

	}
	return kont;
}

int moverAlContenedor(JOKO_ELEMENTUA3 basura[], int v, int i)
{
	int aurk = 0, j = 0;
	if (basura[i].pos.x < 870)
	{
		basura[i].pos.x += v;
		irudiaMugitu(basura[i].id, basura[i].pos.x, basura[i].pos.y);
	}
	if (basura[i].pos.x > 900 && basura[i].pos.x < 1920)
	{
		basura[i].pos.x -= v;
		irudiaMugitu(basura[i].id, basura[i].pos.x, basura[i].pos.y);
	}
	if (basura[i].pos.y < 860)
	{
		basura[i].pos.y += v;
		irudiaMugitu(basura[i].id, basura[i].pos.x, basura[i].pos.y);
	}
	if (basura[i].pos.x >= 870 && basura[i].pos.x <= 900 && basura[i].pos.y >= 860 && basura[i].heldu == 0)
	{
		aurk = 1;
		basura[i].heldu = 1;
		cuentala += 5;
	}

	return aurk;
}

void mover_basura(JOKO_ELEMENTUA3 basura[], int v)
{
	int y = 0;

	for (y = 0; y < 3; y++)
	{
		if (basura[y].aurkituta == 0)
		{
			basura[y].pos.x = basura[y].pos.x + v;
			irudiaMugitu(basura[y].id, basura[y].pos.x, basura[y].pos.y);
		}
	}
}

//--------------------------------------

void jokoaIrabazi(void)
{
	int ebentu = 0;

	pantailaGarbitu();
	textuaIdatzi(760, 540, "Zorionak IRABAZI duzu !!!");
	pantailaBerriztu();

	do
	{
		ebentu = ebentuaJasoGertatuBada();
	} while (ebentu != TECLA_RETURN);
	pantailaGarbitu();
	pantailaBerriztu();
}

void jokoaGaldu(void)
{
	int ebentu = 0;

	pantailaGarbitu();
	textuaIdatzi(760, 540, "GALDU duzu. Mini-jokoa errepikatzeko RETURN eman.");
	pantailaBerriztu();

	do
	{
		ebentu = ebentuaJasoGertatuBada();
	} while (ebentu != TECLA_RETURN);

	pantailaGarbitu();
	pantailaBerriztu();
}

//-----------------------------------------

int contenedor_bistaratu(int x, int y)
{
	int id = -1;
	id = irudiaKargatu(CONTENEDOR);
	irudiaMugitu(id, x, y);
	//pantailaGarbitu();
	irudiakMarraztu();
	//pantailaBerriztu();
	return id;
}

int kartoia_bistaratu(int x, int y)
{
	int id = -1;
	id = irudiaKargatu(KARTOIA);
	irudiaMugitu(id, x, y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return id;
}

int beira_bistaratu(int x, int y)
{
	int id = -1;
	id = irudiaKargatu(BOTILA);
	irudiaMugitu(id, x, y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return id;
}

int lata_bistaratu(int x, int y)
{
	int id = -1;
	id = irudiaKargatu(COLA_IMAGE);
	irudiaMugitu(id, x, y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return id;
}

int nola_jolasten_da() {
	int id = -1;
	id = irudiaKargatu(HOW_TO_PLAY1);
	irudiaMugitu(id, 0, 0);
	pantailaGarbitu(0, 0, 0);
	irudiakMarraztu();
	pantailaBerriztu();
	return id;
}

int nola_jolasten_da2() {
	int id = -1;
	id = irudiaKargatu(HOW_TO_PLAY2);
	irudiaMugitu(id, 0, 0);
	pantailaGarbitu(0, 0, 0);
	irudiakMarraztu();
	pantailaBerriztu();
	return id;
}