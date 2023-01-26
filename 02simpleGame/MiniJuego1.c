#include "MiniJuego1.h"

#include "ourTypes.h"
#include <time.h>

#include <stdio.h>
#include<Windows.h>

#define MUSICA1 ".\\sound\\Musica1.wav"

int barra[2];
int berde[2];

int janKop=0;
int janGalduta = 0;

int mini_juego_1()
{
    int  x = 700,  baldintza = 0;
    int i = 0, zeintzuk = 0, buelta = 0, gertatu = 0;

    int background, emaitza[2];
    int kendutak = -1;
    int ebentu = 1;
    int erantzunak = 0;

    audioInit();
    loadTheMusic(MUSICA1);
    playMusic();

    EGOERA  egoera = JOLASTEN;

    JOKO_1_ELEMENTUA hamburguesa[HAMBURGUESA_KOP];
    JOKO_1_ELEMENTUA lechuga[LECHUGA_KOP];
    JOKO_1_ELEMENTUA panarriba[PAN_ARRIBA_KOP];
    JOKO_1_ELEMENTUA tubo;

   // parrilla = PARRILLA_AUDIO;

    emaitza[0] = 0; // lleno
    emaitza[1] = 0; //salud

    barra[1] = 0;
    berde[1] = 0;

    MiniJokoaAurkeztu();

    //Irudia_Bistaratu(-100, -50, BALDOSAS_BACKGROUND_IMAGE); // fondo
    background = Irudia_Bistaratu(0, 0, MAQUINA_BACKGROUND_IMAGE); //cargar BACKGROUND

    BarraKargatu(barra);
    BerdeKargatu(berde);

    tubo.pos.x = 900;
    tubo.pos.y = 900;
    tubo.mota = IRUDIA;
    tubo.id = Irudia_Bistaratu(tubo.pos.x, 850, TUBO_PLAYER_IMAGE);

    srand(time(NULL));

    for (i = 0 ; i < JAN_MAX; i++) //lechuga sortu
    {
        panarriba[i] = JanariaKargatu(panarriba, 1, i);
        lechuga[i] = JanariaKargatu(lechuga, 2, i);
        hamburguesa[i] = JanariaKargatu(hamburguesa, 3, i);
    }

    do {
        Sleep(10);

        i = zeintzuk + buelta;

        ebentu = ebentuaJasoGertatuBada();

        tubo = tuboaren_mugimendua(tubo, ebentu);

        hamburguesa[i] = JanariaKomp(hamburguesa, tubo, i, 3);
        lechuga[i] = JanariaKomp(lechuga, tubo, i, 2);
        panarriba[i] = JanariaKomp(panarriba, tubo, i, 1);
       
        if (hamburguesa[i].gertatu == 1)
        {
            emaitza[0] += 10;

            barra[1] ++;
            BarraKargatu(barra);
        }
        if (lechuga[i].gertatu == 1)
        {
            emaitza[1] += 10;

            berde[1] ++;
            BerdeKargatu(berde);
        }
        if (panarriba[i].gertatu == 1)
        {
            emaitza[0] += 5;
            emaitza[1] += 5;

            if (emaitza[0] % 10 == 0)
            {
                barra[1] ++;
                BarraKargatu(barra);
            }

            if (emaitza[1] % 10 == 0)
            {
                berde[1] ++;
                BerdeKargatu(berde);
            }
        }

        if (buelta != 3) buelta++;
        else
        {
            buelta = 0;
        }

        if ((hamburguesa[zeintzuk]. aldatuta != 0) && (lechuga[zeintzuk].aldatuta != 0) && (panarriba[zeintzuk].aldatuta != 0))
        {
            zeintzuk++;
        }

        pantailaGarbitu();
        irudiakMarraztu();
        pantailaBerriztu();


    } while ((ebentu != TECLA_9) && (janKop <= 10) && ((janGalduta + janKop) < 30));

    audioTerminate();

    irudiaKendu(background);

    bukaera();

    if (emaitza[0] < 30) erantzunak = 1; // sigue con hambre
    else if (emaitza[1] < 20) erantzunak = 2; // derrota poco saludable
    else erantzunak = 3; // lo ha completado bien

    for (i = 0; i < LECHUGA_KOP; i++) //lechuga sortu
    {
         if (lechuga[i].aldatuta != 2) irudiaKendu(lechuga[i].id);
         if (panarriba[i].aldatuta != 2) irudiaKendu(panarriba[i].id);
         if (hamburguesa[i].aldatuta != 2) irudiaKendu(hamburguesa[i].id);
    }

    irudiaKendu(barra[0]);
    irudiaKendu(berde[0]);

    pantailaGarbitu();
    pantailaBerriztu();

    return erantzunak;
}

void MiniJokoaAurkeztu() {

    int ebentu = -1, img = 0;

    img = Irudia_Bistaratu(0, 0, NOLA_JOLASTU_BACKGROUND_IMAGE);

    do
    {
        ebentu = ebentuaJasoGertatuBada();

    } while (ebentu != TECLA_RETURN);

    irudiaKendu(img);

    return;
}

int Irudia_Bistaratu(int x, int y, char* irudia)
{
    int id = -1;
    id = irudiaKargatu(irudia);
    irudiaMugitu(id, x, y);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return id;

}

void BarraKargatu(int barra[]){

    switch (barra[1])
    {
        case 0:
        {
            barra[0] = irudiaKargatu(BARRA_0_IMAGE);
            irudiaMugitu(barra[0], 1500, 100);
        }break;

        case 1:
        {
            irudiaKendu(barra[0]);
            barra[0] = irudiaKargatu(BARRA_1_IMAGE);
            irudiaMugitu(barra[0], 1500, 100);
        }break;

        case 2:
        {
            irudiaKendu(barra[0]);
            barra[0] = irudiaKargatu(BARRA_2_IMAGE);
            irudiaMugitu(barra[0], 1500, 100);
        }break;

        case 3:
        {
            irudiaKendu(barra[0]);
            barra[0] = irudiaKargatu(BARRA_3_IMAGE);
            irudiaMugitu(barra[0], 1500, 100);
        }break;

        case 4:
        {
            irudiaKendu(barra[0]);
            barra[0] = irudiaKargatu(BARRA_4_IMAGE);
            irudiaMugitu(barra[0], 1500, 100);
        }break;

        case 5:
        {
            irudiaKendu(barra[0]);
            barra[0] = irudiaKargatu(BARRA_5_IMAGE);
            irudiaMugitu(barra[0], 1500, 100);
        }break;

        case 6:
        {
            irudiaKendu(barra[0]);
            barra[0] = irudiaKargatu(BARRA_6_IMAGE);
            irudiaMugitu(barra[0], 1500, 100);
        }break;
    }

    return;
}

void BerdeKargatu(int berde[]) {

    switch (berde[1])
    {
        case 0:
        {
            berde[0] = irudiaKargatu(BARRA_0_IMAGE);
            irudiaMugitu(berde[0], 1500, 175);
        }break;

        case 1:
        {
            irudiaKendu(berde[0]);
            berde[0] = irudiaKargatu(BERDE_1_IMAGE);
            irudiaMugitu(berde[0], 1500, 175);
        }break;

        case 2:
        {
            irudiaKendu(berde[0]);
            berde[0] = irudiaKargatu(BERDE_2_IMAGE);
            irudiaMugitu(berde[0], 1500, 175);
        }break;

        case 3:
        {
            irudiaKendu(berde[0]);
            berde[0] = irudiaKargatu(BERDE_3_IMAGE);
            irudiaMugitu(berde[0], 1500, 175);
        }break;

        case 4:
        {
            irudiaKendu(berde[0]);
            berde[0] = irudiaKargatu(BERDE_4_IMAGE);
            irudiaMugitu(berde[0], 1500, 175);
        }break;

        case 5:
        {
            irudiaKendu(berde[0]);
            berde[0] = irudiaKargatu(BERDE_5_IMAGE);
            irudiaMugitu(berde[0], 1500, 175);
        }break;

        case 6:
        {
            irudiaKendu(berde[0]);
            berde[0] = irudiaKargatu(BERDE_6_IMAGE);
            irudiaMugitu(berde[0], 1500, 175);
        }break;
        }

    return;
}

void bukaera() {

    int background = 0, ebentu=0;

    background = irudiaKargatu(BUKAERA);
    irudiaMugitu(background, 140, 100);

    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();

    do
    {
        ebentu = ebentuaJasoGertatuBada();

    } while (ebentu != TECLA_RETURN);

    irudiaKendu(background);

    return;
}

JOKO_1_ELEMENTUA tuboaren_mugimendua(JOKO_1_ELEMENTUA tubo, int ebentu)
{
    if (ebentu == TECLA_LEFT)                   //tuboaren mugimendua (ezkerra)
    {
        tubo.pos.x -= 10;
        irudiaMugitu(tubo.id, tubo.pos.x, 850);
        pantailaGarbitu();
        irudiakMarraztu();
        pantailaBerriztu();
    }

    if (ebentu == TECLA_RIGHT)                 //tuboaren mugimendua (eskuma)
    {
        tubo.pos.x += 10;
        irudiaMugitu(tubo.id, tubo.pos.x, 850);
        pantailaGarbitu();
        irudiakMarraztu();
        pantailaBerriztu();
    }

    if (tubo.pos.x < 450)tubo.pos.x += 10;          //tuboaren kolisioak 

    if (tubo.pos.x > 1000)tubo.pos.x -= 10;

    return tubo;

}

JOKO_1_ELEMENTUA JanariaKargatu(JOKO_1_ELEMENTUA janaria[], int mota, int i) {

    janaria[i].pos.x = (rand() % (1150 - 650 + 1)) + 650;                      //x posizioa
    janaria[i].pos.y = (rand() % -1000 ) - 1000;                                 // y posizioa (random)
    janaria[i].mota = IRUDIA;
    janaria[i].gertatu = 0;
    janaria[i].aldatuta = 0;

    switch (mota)
    {
        case 1:
             janaria[i].id = Irudia_Bistaratu(janaria[i].pos.x, janaria[i].pos.y, PAN_ARRIBA_OBJECT_IMAGE);
        break;

        case 2:
             janaria[i].id = Irudia_Bistaratu(janaria[i].pos.x, janaria[i].pos.y, LECHUGA_OBJECT_IMAGE);
        break;

        case 3:
             janaria[i].id = Irudia_Bistaratu(janaria[i].pos.x, janaria[i].pos.y, HAMBURGUESA_OBJECT_IMAGE);
        break;
    }

    return janaria[i];
}

JOKO_1_ELEMENTUA JanariaKomp(JOKO_1_ELEMENTUA janaria[], JOKO_1_ELEMENTUA tubo, int i, int mota){

    if (janaria[i].gertatu != 0) janaria[i].gertatu = 0;
         
    if (janaria[i].aldatuta == 0)
    {
        janaria[i].pos.y += 5;
        irudiaMugitu(janaria[i].id, janaria[i].pos.x, janaria[i].pos.y);
    }

    if ((janaria[i].pos.y > tubo.pos.y - 80) && (janaria[i].pos.y < tubo.pos.y - 10) &&
        (janaria[i].pos.x <= tubo.pos.x + 200) && (janaria[i].pos.x > tubo.pos.x + 50) && (janaria[i].aldatuta == 0))
    {
        janaria[i].aldatuta = 1;
        irudiaMugitu(janaria[i].id, 1290, 780);

        janaria[i].gertatu = 1;

        janKop++;

        // loadTheMusic(PARRILLA_AUDIO);

        pantailaGarbitu();
        pantailaBerriztu();
    }

    if ((janaria[i].pos.y > 1000) && (janaria[i].aldatuta == 0))
    {
        janaria[i].aldatuta = 2;
        irudiaKendu(janaria[i].id);
    }
   
    return janaria[i];
}
