#include "OurTypes.h"
#include "Sprite.h"
#include "Mugimenduak.h"
#include "MiniJuego2.h"

#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>

void jokoaAurkeztu_2() // Pantalla de "Press return jolasten hasteko"
{
    int ebentu = 0, fondo = 0;

	fondo = irudiaKargatu(NolaJolastu);
	irudiaMugitu(fondo, 100, 60);

	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);// evento de return

	irudiaKendu(fondo);

    pantailaGarbitu();
    pantailaBerriztu();
}

int Mini_Juego_2()  //Estruk de egoera
{
	int jokalaria[7], kargatuobj[5], kargatumounstro[4], kargatumapa[5], burua[4];
    int saltobaiedoez = 0, meta = 0, baiedoez = 0, egoera=0; //boolean
	int aurrekoa = 0, emaitza = 0;

	audioInit();
	loadTheMusic(MUSICA2);
	playMusic();

	jokoaAurkeztu_2();

    mapakargatu(kargatumapa); //kargamos el mapa
    OztopoakKargatu(kargatuobj); //Kargamos los oztopoak
    Mounstroakargatu(kargatumounstro); //kargamos el monstruo
    jokalariaKargatu2(jokalaria);//funcion de crear el personaje
    meta = metakargatu(meta, burua); //Kargamos la meta

    do {

        Sleep(2); //Pequeña pausa

        mounstroaMugitu(kargatumounstro);// cambiamos las variables
        mugituBerriz2(jokalaria, 0, 0); //Sprites continuamente del personaje

        if (saltobaiedoez == 0)// Para que no haga saltos infitinos volando
        {
            jokalariaMugitu2(jokalaria, kargatuobj);// cambiamos las variables
        }

        saltobaiedoez = salto(jokalaria, saltobaiedoez);// Para que no haga saltos infitinos volando

        baiedoez = OztopoakMugitu(kargatuobj, baiedoez);

        if (baiedoez == 1)
        {
			metaaldatu(meta, burua);
			baiedoez = 0;

			irudiaKendu(kargatuobj[0]);
			OztopoakKargatu(kargatuobj);
        }

        Mapamugitu(kargatumapa);

        pantailaGarbitu();
        irudiakMarraztu();
        pantailaBerriztu();

        emaitza = zeegoera(kargatuobj, jokalaria);

    } while ((emaitza == 0)&&(burua[1] < 1000)); //Termina cuando presionemos scape o cuando egoera cambie(egoera cambiara dependiendo del valor del oxigeno)

	audioTerminate();

	irudiaKendu(burua[0]);
    irudiaKendu(jokalaria[0]);
    irudiaKendu(kargatumounstro[0]);
	irudiaKendu(kargatumapa[0]);
	irudiaKendu(kargatuobj[0]);
	irudiaKendu(meta);
	
	bukaerakoa(emaitza);

    pantailaGarbitu();
    pantailaBerriztu();

    return emaitza;

}

int metakargatu(int meta, int burua[]) // Pantailaratuar las imagenes
{
	meta = irudiaKargatu(META);
	irudiaMugitu(meta, 700, 20);

	burua[0] = irudiaKargatu(BURUA);

	burua[1] = 700;
	burua[2] = 190;

	irudiaMugitu(burua[0], burua[1], burua[2]);

	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return meta;
}

int OztopoakMugitu(int oztopoak[], int baiedoez)
{
	baiedoez = 0;

	oztopoak[1] = oztopoak[1] - 10;
	irudiaMugitu(oztopoak[0], oztopoak[1], oztopoak[2]);

	if (oztopoak[1] < 300)
	{
		baiedoez = 1;
	}

	return baiedoez;
}

void metaaldatu(int meta, int burua[])
{
	burua[1] += 30;
	irudiaMugitu(burua[0], burua[1], burua[2]);

	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return;
}

void Mapamugitu(int mapa[])
{
	mapa[1] = mapa[1] - 7;
	irudiaMugitu(mapa[0], mapa[1], mapa[2]);

	if (mapa[1] <= -1883)
	{
		mapa[1] = 0;
	}

	return;
}

void mounstroaMugitu(int mounstroa[])
{

	if (mounstroa[3] == 0)
	{
		mounstroa[2] = mounstroa[2] - 1;

		if (mounstroa[2] <= 500)
		{
			mounstroa[3] = 1;
		}
	}
	if (mounstroa[3] == 1)
	{
		mounstroa[2] = mounstroa[2] + 1;

		if (mounstroa[2] >= 650)
		{
			mounstroa[3] = 0;
		}
	}

	irudiaMugitu(mounstroa[0], mounstroa[1], mounstroa[2]);

	return;
}

void jokalariaMugitu2(int jokalaria[], int obstaculos[]) {

	int ebentu = 0;

	ebentu = ebentuaJasoGertatuBada();

	if((ebentu==TECLA_SPACE)||(ebentu==TECLA_w)) jokalaria[6] = 1;

	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return;
}

void jokalariaKargatu2(int jokalaria[]) {

	jokalaria[1] = 500;// cordenada x
	jokalaria[2] = 760; // cordenada y
	jokalaria[3] = 4; // direcion 
	jokalaria[4] = 1; // numero de sprite
	jokalaria[5] = 0; //variable para control de cambio sprite
	jokalaria[6] = 9; //Variable para el salto

	jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_1);
	irudiaMugitu(jokalaria[0], jokalaria[1], jokalaria[2]);

	return;
}

void OztopoakKargatu(int Oztopoa[]) {

	int num = 0;

	Oztopoa[1] = 1920;// cordenada x
	Oztopoa[2] = 840; // cordenada y

	Oztopoa[4] = 0;

	srand(time(NULL));
	
	num = ((rand() % 3 - 1 + 1) + 1);
	//Oztopoa[1] = (rand() % 2000 - 1920) + 1920;

	switch (num)
	{
	case 1:
		Oztopoa[0] = irudiaKargatu(PIEDRA);
		break;
	case 2:
		Oztopoa[0] = irudiaKargatu(NEUMATICO);
		break;
	case 3:
		Oztopoa[0] = irudiaKargatu(ARBOL);
		break;
	}

	irudiaMugitu(Oztopoa[0], Oztopoa[1], Oztopoa[2]);

	return;
}

void mapakargatu(int Oztopoa[]) {

	Oztopoa[1] = 190;// cordenada x
	Oztopoa[2] = -70; // cordenada y


	Oztopoa[0] = irudiaKargatu(FONDO);


	irudiaMugitu(Oztopoa[0], Oztopoa[1], Oztopoa[2]);

	return;
}

void Mounstroakargatu(int Oztopoa[]) {

	Oztopoa[3] = 0;
	Oztopoa[1] = 200;// cordenada x
	Oztopoa[2] = 650; // cordenada y

	Oztopoa[0] = irudiaKargatu(MOUNSTRO);
	irudiaMugitu(Oztopoa[0], Oztopoa[1], Oztopoa[2]);
}

int salto(int jokalaria[], int saltoabaiedoez)
{

	if (jokalaria[6] == 1)
	{
		saltoabaiedoez = 1;

		SpritaSortu2(jokalaria);

		AldaketakS(jokalaria);

		jokalaria[2] = jokalaria[2] - 7;
		irudiaMugitu(jokalaria[0], jokalaria[1], jokalaria[2]);

		if (jokalaria[2] <= 500)
		{
			jokalaria[6] = 2;
		}

		pantailaGarbitu();
		irudiakMarraztu();
		pantailaBerriztu();
	}
	else if (jokalaria[6] == 2)
	{
		SpritaSortu2(jokalaria);
		AldaketakS(jokalaria);

		irudiaMugitu(jokalaria[0], jokalaria[1], jokalaria[2]);
		jokalaria[2] = jokalaria[2] + 7;

		pantailaGarbitu();
		irudiakMarraztu();
		pantailaBerriztu();

		if (jokalaria[2] >= 760)
		{
			jokalaria[6] = 0;
			saltoabaiedoez = 0;
		}
	}

	return saltoabaiedoez;
}

void mugituBerriz2(int jokalaria[], int x, int y) {

	jokalaria[1] += x;
	jokalaria[2] += y;

	SpritaSortu2(jokalaria);
	Aldaketak(jokalaria);

	irudiaMugitu(jokalaria[0], jokalaria[1], jokalaria[2]);

	return;
}

void SpritaSortu2(int jokalaria[]) {

	int reset = 0;

	switch (jokalaria[4])
	{
		case 1:
			irudiaKendu(jokalaria[0]);
			jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_dcha_1);
			break;

		case 2:
			irudiaKendu(jokalaria[0]);
			jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_dcha_2);
			break;

		case 3:
			irudiaKendu(jokalaria[0]);
			jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_dcha_3);
			break;

		case 4:
			irudiaKendu(jokalaria[0]);
			jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_dcha_4);
			break;

		case 5:
			irudiaKendu(jokalaria[0]);
			jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_dcha_5);
			break;

		case 6:
			irudiaKendu(jokalaria[0]);
			jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_dcha_6);
			break;

		case 7:
			irudiaKendu(jokalaria[0]);
			jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_dcha_7);
			break;

		case 8:
			irudiaKendu(jokalaria[0]);
			jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_dcha_8);
			break;

		case 9:
			irudiaKendu(jokalaria[0]);
			jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_dcha_9);
			break;
	}

	return;
}

void AldaketakS(int jokalaria[]) {

	jokalaria[5]++;

	if (jokalaria[5] % 50 == 0)
	{
		jokalaria[5] = 0;

		if (jokalaria[4] == 9)
		{
			jokalaria[4] = 1;
		}
		else
		{
			jokalaria[4]++;
		}
	}

	return;
}

int zeegoera(int objetua[], int jokalaria[])
{
	int egoera=0;

	if ((jokalaria[1] >= objetua[1] - 65) && (jokalaria[1] <= (objetua[1] + 100)) && (jokalaria[2] <= 760 && jokalaria[2] >= 670) || (jokalaria[1] <= 440))
	{
		egoera = 1;
	}

	return egoera;
}

void bukaerakoa(int emaitza) {

	int ebentu, argazkia[4], kontrol=0;

	if (emaitza == 0)
	{
		argazkia[0] = irudiaKargatu(IHESEGIN);
		irudiaMugitu(argazkia[0], 0, 0);

		pantailaGarbitu();
		irudiakMarraztu();
		pantailaBerriztu();

		do
		{
			ebentu = ebentuaJasoGertatuBada();

		} while (ebentu != TECLA_RETURN);

		irudiaKendu(argazkia[0]);

	}
	else
	{
		argazkia[0] = irudiaKargatu(HARRAPATUTA);
		irudiaMugitu(argazkia[0], 0, 0);

		argazkia[1] = irudiaKargatu(MOUNSTRO);
		irudiaMugitu(argazkia[1], 750, 400);

		argazkia[2] = 0;
		argazkia[3] = 0;

		do
		{
			Sleep(100);

			pantailaGarbitu();
			irudiakMarraztu();
			pantailaBerriztu();

			if (kontrol%50==0)
			{
				if (argazkia[3] == 0)
				{
					argazkia[2]++;

					irudiaMugitu(argazkia[1], 750, 400 - (argazkia[2] * 2));

					if (argazkia[2] == 20) argazkia[3] = 1;
				}
				else
				{
					argazkia[2]--;

					irudiaMugitu(argazkia[1], 750, 400 - (argazkia[2] * 2));

					if (argazkia[2] == 0) argazkia[3] = 0;
				}
			}
			else
			{
				kontrol++;
			}

			ebentu = ebentuaJasoGertatuBada();

		} while (ebentu != TECLA_RETURN);

		irudiaKendu(argazkia[0]);
		irudiaKendu(argazkia[1]);
	}

	return;
}