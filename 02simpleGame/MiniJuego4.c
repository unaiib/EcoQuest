#include "OurTypes.h"
#include "MiniJuego4.h"
#include "Mugimenduak.h"
#include "Bala.h"

#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"

#include <stdio.h>
#include <windows.h>
#include <time.h>

void jokoaAurkeztu4(void) // Pantalla de "Press return jolasten hasteko"
{
    int ebentu = 0, img;

    img = irudiaKargatu(NOLA_JOLASTU);
    irudiakMarraztu();
    pantailaBerriztu();

    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);// evento de return

    irudiaKendu(img);

    pantailaGarbitu();
    pantailaBerriztu();
}

void sarreraMezuaIdatzi4()
{
    pantailaGarbitu();

    textuaIdatzi(225, 200, ONGI_ETORRI_MEZUA);// Hay que definir porque de lo contrario printeariamos en la otra pagina

    pantailaBerriztu();
}

int Mini_Juego_4(void)  //devuelve 0 o 1
{
    jokoaAurkeztu4();

    int mugitu = 0; //boolean
    int dembora = 2;//El denbora es  el tiempo, un valor que si llega a 0 perdemos.Como si fuera la vida
    int kont = 0; //para la animación de los enemigos

    int jokalaria[6], id[5];
    int bala[7];
    bala[5] = 0;
    int datuak[4];
    datuak[0] = 1; //oleada, etsaiak pantailan, hurrengo oleada, jokoa bukatzeko
    datuak[3] = 1;

    ETSAIA etsaiak[10];
    int  emaitza = 0; //Esta en jolasten por que todavia no hay manera de perder ni ganar

    audioInit();
    loadTheMusic(MUSICA4);
    playMusic();

    id[0] = irudiaKargatu(FONDO4);
    irudiaMugitu(id[0],0, 0); 

    jokalariaKargatu4(jokalaria);//funcion de crear el personaje

    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();

    do {               
        Sleep(2);

        jokalariaMugitu4(jokalaria);// cambiamos las variables

        if (!bala[5]) jokalariaTiro4(jokalaria, bala);
        else balaNorabideanMugitu4(bala);

        etsaiakFuntzioa4(etsaiak, jokalaria, bala, datuak);

        pantailaGarbitu();
        irudiakMarraztu();
        pantailaBerriztu();

        kont++;

        animazioaAktibatu4(etsaiak, kont, datuak[1]);

        if (kont == 100) kont = 0;

        if (!datuak[3]) dembora = 0;

        if (datuak[0] == 4) dembora = 0;
        
    } while (dembora != 0); //Termina cuando presionemos scape o cuando egoera cambie(egoera cambiara dependiendo del valor del oxigeno)
    
    audioTerminate();

    irudiaKendu(jokalaria[0]);
    irudiaKendu(id[0]);

    if (bala[5] != 0) irudiaKendu(bala [0]);

    for(kont=0; kont<=datuak[1]; kont++)
    {
        irudiaKendu(etsaiak[kont].id);
    }

    pantailaGarbitu();
    pantailaBerriztu();

    if (!datuak[3]) emaitza = 0;        //se pierde
    else {
        emaitza = 1;                    //se gana
    }
    
    return emaitza;
}

//BALA

void jokalariaTiro4(int jokalaria[], int bala[])
{
    int ebentu;
    ebentu = ebentuaJasoGertatuBada();

    switch (ebentu)
    {
    case TECLA_UP:
        balaSortu4(bala, jokalaria, 1);
        break;
    case TECLA_DOWN:
        balaSortu4(bala, jokalaria, 2);
        break;
    case TECLA_LEFT:
        balaSortu4(bala, jokalaria, 3);
        break;
    case TECLA_RIGHT:
        balaSortu4(bala, jokalaria, 4);
        break;
    }

    return;
}

void balaSortu4(int bala[], int jokalaria[], int dir)
{
    bala[1] = jokalaria[1] - 19; // cordenada x
    bala[2] = jokalaria[2]; // cordenada y
    bala[3] = dir; // direcion 
    bala[4] = 1; // numero de sprite
    bala[5] = 1; //mapan dago?
    bala[6] = 0; // PUN

    bala[0] = irudiaKargatu(BALA_GORA_1);
    irudiaMugitu(bala[0], bala[1], bala[2]);
    return;
}

void balaNorabideanMugitu4(int bala[])
{
    switch (bala[3])
    {
    case 1:
        balaMugitu4(bala, 0, -3);
        return;
    case 2:
        balaMugitu4(bala, 0, 3);
        return;
    case 3:
        balaMugitu4(bala, -3, 0);
        return;
    case 4:
        balaMugitu4(bala, 3, 0);
        return;
    }

    return;
}

void balaMugitu4(int bala[], int x, int y)
{

    bala[1] += x;
    bala[2] += y;

    balaAnimazioa4(bala);
    balaKanpoan4(bala);
    balaPun4(bala);

    irudiaMugitu(bala[0], bala[1], bala[2]);

    return;
}

void balaAnimazioa4(int bala[])
{
    switch (bala[3])
    {
    case 1:
    {
        switch (bala[4])
        {
        case 1:
            animazioa4(bala, BALA_GORA_2, 2);
            break;

        case 2:
            animazioa4(bala, BALA_GORA_3, 3);
            break;

        case 3:
            animazioa4(bala, BALA_GORA_4, 4);
            break;

        case 4:
            animazioa4(bala, BALA_GORA_5, 5);
            break;

        case 5:
            animazioa4(bala, BALA_GORA_6, 6);
            break;

        case 6:
            animazioa4(bala, BALA_GORA_7, 7);
            break;

        case 7:
            animazioa4(bala, BALA_GORA_8, 8);
            break;

        case 8:
            animazioa4(bala, BALA_GORA_9, 9);
            break;

        case 9:
            animazioa4(bala, BALA_GORA_10, 10);
            break;

        case 10:
            animazioa4(bala, BALA_GORA_11, 11);
            break;

        case 11:
            animazioa4(bala, BALA_GORA_12, 12);
            break;

        case 12:
            animazioa4(bala, BALA_GORA_13, 13);
            break;

        case 13:
            animazioa4(bala, BALA_GORA_14, 14);
            break;

        case 14:
            animazioa4(bala, BALA_GORA_15, 15);
            break;

        case 15:
            animazioa4(bala, BALA_GORA_16, 16);
            break;

        case 16:
            animazioa4(bala, BALA_GORA_17, 17);
            break;

        case 17:
            animazioa4(bala, BALA_GORA_18, 18);
            break;

        case 18:
            animazioa4(bala, BALA_GORA_19, 19);
            break;

        case 19:
            animazioa4(bala, BALA_GORA_20, 20);
            break;

        case 20:
            animazioa4(bala, BALA_GORA_21, 21);
            break;

        case 21:
            animazioa4(bala, BALA_GORA_5, 5);
            break;
        }
    }break;

    case 2:
    {
        switch (bala[4])
        {
        case 1:
            animazioa4(bala, BALA_BEHERA_2, 2);
            break;

        case 2:
            animazioa4(bala, BALA_BEHERA_3, 3);
            break;

        case 3:
            animazioa4(bala, BALA_BEHERA_4, 4);
            break;

        case 4:
            animazioa4(bala, BALA_BEHERA_5, 5);
            break;

        case 5:
            animazioa4(bala, BALA_BEHERA_6, 6);
            break;

        case 6:
            animazioa4(bala, BALA_BEHERA_7, 7);
            break;

        case 7:
            animazioa4(bala, BALA_BEHERA_8, 8);
            break;

        case 8:
            animazioa4(bala, BALA_BEHERA_9, 9);
            break;

        case 9:
            animazioa4(bala, BALA_BEHERA_10, 10);
            break;

        case 10:
            animazioa4(bala, BALA_BEHERA_11, 11);
            break;

        case 11:
            animazioa4(bala, BALA_BEHERA_12, 12);
            break;

        case 12:
            animazioa4(bala, BALA_BEHERA_13, 13);
            break;

        case 13:
            animazioa4(bala, BALA_BEHERA_14, 14);
            break;

        case 14:
            animazioa4(bala, BALA_BEHERA_15, 15);
            break;

        case 15:
            animazioa4(bala, BALA_BEHERA_16, 16);
            break;

        case 16:
            animazioa4(bala, BALA_BEHERA_17, 17);
            break;

        case 17:
            animazioa4(bala, BALA_BEHERA_18, 18);
            break;

        case 18:
            animazioa4(bala, BALA_BEHERA_19, 19);
            break;

        case 19:
            animazioa4(bala, BALA_BEHERA_20, 20);
            break;

        case 20:
            animazioa4(bala, BALA_BEHERA_21, 21);
            break;

        case 21:
            animazioa4(bala, BALA_BEHERA_5, 5);
            break;
        }
    }break;

    case 3:
    {
        switch (bala[4])
        {
        case 1:
            animazioa4(bala, BALA_EZK_2, 2);
            break;

        case 2:
            animazioa4(bala, BALA_EZK_3, 3);
            break;

        case 3:
            animazioa4(bala, BALA_EZK_4, 4);
            break;

        case 4:
            animazioa4(bala, BALA_EZK_5, 5);
            break;

        case 5:
            animazioa4(bala, BALA_EZK_6, 6);
            break;

        case 6:
            animazioa4(bala, BALA_EZK_7, 7);
            break;

        case 7:
            animazioa4(bala, BALA_EZK_8, 8);
            break;

        case 8:
            animazioa4(bala, BALA_EZK_9, 9);
            break;

        case 9:
            animazioa4(bala, BALA_EZK_10, 10);
            break;

        case 10:
            animazioa4(bala, BALA_EZK_11, 11);
            break;

        case 11:
            animazioa4(bala, BALA_EZK_12, 12);
            break;

        case 12:
            animazioa4(bala, BALA_EZK_13, 13);
            break;

        case 13:
            animazioa4(bala, BALA_EZK_14, 14);
            break;

        case 14:
            animazioa4(bala, BALA_EZK_15, 15);
            break;

        case 15:
            animazioa4(bala, BALA_EZK_16, 16);
            break;

        case 16:
            animazioa4(bala, BALA_EZK_17, 17);
            break;

        case 17:
            animazioa4(bala, BALA_EZK_18, 18);
            break;

        case 18:
            animazioa4(bala, BALA_EZK_19, 19);
            break;

        case 19:
            animazioa4(bala, BALA_EZK_20, 20);
            break;

        case 20:
            animazioa4(bala, BALA_EZK_21, 21);
            break;

        case 21:
            animazioa4(bala, BALA_EZK_5, 5);
            break;
        }
    }break;

    case 4:
    {
        switch (bala[4])
        {
        case 1:
            animazioa4(bala, BALA_ESK_2, 2);
            break;

        case 2:
            animazioa4(bala, BALA_ESK_3, 3);
            break;

        case 3:
            animazioa4(bala, BALA_ESK_4, 4);
            break;

        case 4:
            animazioa4(bala, BALA_ESK_5, 5);
            break;

        case 5:
            animazioa4(bala, BALA_ESK_6, 6);
            break;

        case 6:
            animazioa4(bala, BALA_ESK_7, 7);
            break;

        case 7:
            animazioa4(bala, BALA_ESK_8, 8);
            break;

        case 8:
            animazioa4(bala, BALA_ESK_9, 9);
            break;

        case 9:
            animazioa4(bala, BALA_ESK_10, 10);
            break;

        case 10:
            animazioa4(bala, BALA_ESK_11, 11);
            break;

        case 11:
            animazioa4(bala, BALA_ESK_12, 12);
            break;

        case 12:
            animazioa4(bala, BALA_ESK_13, 13);
            break;

        case 13:
            animazioa4(bala, BALA_ESK_14, 14);
            break;

        case 14:
            animazioa4(bala, BALA_ESK_15, 15);
            break;

        case 15:
            animazioa4(bala, BALA_ESK_16, 16);
            break;

        case 16:
            animazioa4(bala, BALA_ESK_17, 17);
            break;

        case 17:
            animazioa4(bala, BALA_ESK_18, 18);
            break;

        case 18:
            animazioa4(bala, BALA_ESK_19, 19);
            break;

        case 19:
            animazioa4(bala, BALA_ESK_20, 20);
            break;

        case 20:
            animazioa4(bala, BALA_ESK_21, 21);
            break;

        case 21:
            animazioa4(bala, BALA_ESK_5, 5);
            break;
        }
    }break;
    }
    return;
}

void animazioa4(int bala[], char sprite[], int hurrengoa)
{
    irudiaKendu(bala[0]);
    bala[0] = irudiaKargatu(sprite);
    bala[4] = hurrengoa;
    return;
}

void balaKanpoan4(int bala[])
{
    if ((bala[1] < -64 || bala[1] > 1920 || bala[2] < -64 || bala[2] > 1080) && bala[5] == 1)
    {
        balaKendu4(bala);
    }
    return;
}

void balaKendu4(int bala[])
{
    bala[5] = 0;

    irudiaKendu(bala[0]);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
}

void balaPun4(int bala[])
{
    if (bala[6] == 1)
    {
        switch (bala[3])
        {
        case 1:
        {
            if (bala[4] <= 21) animazioa4(bala, BALA_PUN_GORA_1, 101);
            switch (bala[4])
            {
            case 101:
                animazioa4(bala, BALA_PUN_GORA_2, 102);
                break;

            case 102:
                animazioa4(bala, BALA_PUN_GORA_3, 103);
                break;

            case 103:
                animazioa4(bala, BALA_PUN_GORA_4, 104);
                break;

            case 104:
                animazioa4(bala, BALA_PUN_GORA_5, 105);
                break;

            case 105:
                animazioa4(bala, BALA_PUN_GORA_6, 106);
                break;

            case 106:
                animazioa4(bala, BALA_PUN_GORA_7, 107);
                break;

            case 107:
                animazioa4(bala, BALA_PUN_GORA_8, 108);
                break;

            case 108:
                animazioa4(bala, BALA_PUN_GORA_9, 109);
                break;

            case 109:
                animazioa4(bala, BALA_PUN_GORA_10, 110);
                break;

            case 110:
                animazioa4(bala, BALA_PUN_GORA_11, 111);
                break;

            case 111:
                animazioa4(bala, BALA_PUN_GORA_12, 112);
                break;

            case 112:
                animazioa4(bala, BALA_PUN_GORA_13, 113);
                break;

            case 113:
                bala[6] = 0;
                balaKendu4(bala);
                break;
            }
        }break;

        case 2:
        {
            if (bala[4] <= 21) animazioa4(bala, BALA_PUN_BEHERA_1, 101);
            switch (bala[4])
            {
            case 101:
                animazioa4(bala, BALA_PUN_BEHERA_2, 102);
                break;

            case 102:
                animazioa4(bala, BALA_PUN_BEHERA_3, 103);
                break;

            case 103:
                animazioa4(bala, BALA_PUN_BEHERA_4, 104);
                break;

            case 104:
                animazioa4(bala, BALA_PUN_BEHERA_5, 105);
                break;

            case 105:
                animazioa4(bala, BALA_PUN_BEHERA_6, 106);
                break;

            case 106:
                animazioa4(bala, BALA_PUN_BEHERA_7, 107);
                break;

            case 107:
                animazioa4(bala, BALA_PUN_BEHERA_8, 108);
                break;

            case 108:
                animazioa4(bala, BALA_PUN_BEHERA_9, 109);
                break;

            case 109:
                animazioa4(bala, BALA_PUN_BEHERA_10, 110);
                break;

            case 110:
                animazioa4(bala, BALA_PUN_BEHERA_11, 111);
                break;

            case 111:
                animazioa4(bala, BALA_PUN_BEHERA_12, 112);
                break;

            case 112:
                animazioa4(bala, BALA_PUN_BEHERA_13, 113);
                break;

            case 113:
                bala[6] = 0;
                balaKendu4(bala);
                break;
            }
        }break;

        case 3:
        {
            if (bala[4] <= 21) animazioa4(bala, BALA_PUN_EZK_1, 101);
            switch (bala[4])
            {
            case 101:
                animazioa4(bala, BALA_PUN_EZK_2, 102);
                break;

            case 102:
                animazioa4(bala, BALA_PUN_EZK_3, 103);
                break;

            case 103:
                animazioa4(bala, BALA_PUN_EZK_4, 104);
                break;

            case 104:
                animazioa4(bala, BALA_PUN_EZK_5, 105);
                break;

            case 105:
                animazioa4(bala, BALA_PUN_EZK_6, 106);
                break;

            case 106:
                animazioa4(bala, BALA_PUN_EZK_7, 107);
                break;

            case 107:
                animazioa4(bala, BALA_PUN_EZK_8, 108);
                break;

            case 108:
                animazioa4(bala, BALA_PUN_EZK_9, 109);
                break;

            case 109:
                animazioa4(bala, BALA_PUN_EZK_10, 110);
                break;

            case 110:
                animazioa4(bala, BALA_PUN_EZK_11, 111);
                break;

            case 111:
                animazioa4(bala, BALA_PUN_EZK_12, 112);
                break;

            case 112:
                animazioa4(bala, BALA_PUN_EZK_13, 113);
                break;

            case 113:
                bala[6] = 0;
                balaKendu4(bala);
                break;
            }
        }break;

        case 4:
        {
            if (bala[4] <= 21) animazioa4(bala, BALA_PUN_ESK_1, 101);
            switch (bala[4])
            {
            case 101:
                animazioa4(bala, BALA_PUN_ESK_2, 102);
                break;

            case 102:
                animazioa4(bala, BALA_PUN_ESK_3, 103);
                break;

            case 103:
                animazioa4(bala, BALA_PUN_ESK_4, 104);
                break;

            case 104:
                animazioa4(bala, BALA_PUN_ESK_5, 105);
                break;

            case 105:
                animazioa4(bala, BALA_PUN_ESK_6, 106);
                break;

            case 106:
                animazioa4(bala, BALA_PUN_ESK_7, 107);
                break;

            case 107:
                animazioa4(bala, BALA_PUN_ESK_8, 108);
                break;

            case 108:
                animazioa4(bala, BALA_PUN_ESK_9, 109);
                break;

            case 109:
                animazioa4(bala, BALA_PUN_ESK_10, 110);
                break;

            case 110:
                animazioa4(bala, BALA_PUN_ESK_11, 111);
                break;

            case 111:
                animazioa4(bala, BALA_PUN_ESK_12, 112);
                break;

            case 112:
                animazioa4(bala, BALA_PUN_ESK_13, 113);
                break;

            case 113:
                bala[6] = 0;
                balaKendu4(bala);
                break;
            }
        }break;
        }
    }
    return;
}

//JOKALARIA

void jokalariaMugitu4(int jokalaria[])
{

    int ebentu = 0;

    ebentu = ebentuaJasoGertatuBada();

    switch (ebentu) //Eventos de movimientos
    {
    case TECLA_a: //izquierda = 3

        if (jokalaria[3] == 3)
        {
            mugituBerriz4(jokalaria, -VEL, 0);
        }
        else
        {
            irudiaKendu(jokalaria[0]);

            jokalaria[0] = irudiaKargatu(JOKALARIA_izq_1);

            mugimenduaBehin4(jokalaria, -VEL, 0, 3);
        }

        break;

    case TECLA_d: //derecha = 4

        if (jokalaria[3] == 4)
        {
            mugituBerriz4(jokalaria, VEL, 0);
        }
        else
        {
            irudiaKendu(jokalaria[0]);

            jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_1);

            mugimenduaBehin4(jokalaria, VEL, 0, 4);
        }

        break;

    case TECLA_w: //gorantz = 1

        if (jokalaria[3] == 1)
        {
            mugituBerriz4(jokalaria, 0, -VEL);
        }
        else
        {
            irudiaKendu(jokalaria[0]);

            jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_1);

            mugimenduaBehin4(jokalaria, 0, -VEL, 1);
        }

        break;

    case TECLA_s: //beherantz = 2

        if (jokalaria[3] == 2)
        {
            mugituBerriz4(jokalaria, 0, VEL);
        }
        else
        {
            irudiaKendu(jokalaria[0]);

            jokalaria[0] = irudiaKargatu(JOKALARIA_behera_1);

            mugimenduaBehin4(jokalaria, 0, VEL, 2);
        }

        break;
    }

    mapatikIrten4(jokalaria);

    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();

    return;
}

void mapatikIrten4(int jokalaria[])
{
    if (jokalaria[1] > 1930) jokalaria[1] = -10;
    if (jokalaria[1] < -10) jokalaria[1] = 1930;
    if (jokalaria[2] > 1090) jokalaria[2] = -10;
    if (jokalaria[2] < -10) jokalaria[2] = 1090;

    return;
}

void jokalariaKargatu4(int jokalaria[])
{

    jokalaria[1] = 960;// cordenada x
    jokalaria[2] = 540; // cordenada y
    jokalaria[3] = 2; // direcion 
    jokalaria[4] = 1; // numero de sprite
    jokalaria[5] = 0; //variable para control de cambio sprite

    jokalaria[0] = irudiaKargatu(JOKALARIA_behera_1);
    irudiaMugitu(jokalaria[0], jokalaria[1], jokalaria[2]);

    return;
}

void mugimenduaBehin4(int jokalaria[], int x, int y, int aldaketa)
{

    irudiaMugitu(jokalaria[0], jokalaria[1] + x, jokalaria[2] + y);

    jokalaria[1] += x;
    jokalaria[2] += y;

    jokalaria[3] = aldaketa;
    jokalaria[4] = 1;
    jokalaria[5] = 0;

    return;
}

void mugituBerriz4(int jokalaria[], int x, int y)
{

    jokalaria[1] += x;
    jokalaria[2] += y;

    SpritaSortu4(jokalaria);
    Aldaketak4(jokalaria);

    irudiaMugitu(jokalaria[0], jokalaria[1], jokalaria[2]);

    return;
}

void SpritaSortu4(int jokalaria[])
{

    int reset = 0;

    switch (jokalaria[3])
    {
    case 1:
    {
        switch (jokalaria[4])
        {
        case 1:
            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_1);
            break;

        case 2:
            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_2);
            break;

        case 3:
            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_3);
            break;

        case 4:
            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_4);
            break;

        case 5:
            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_5);
            break;

        case 6:
            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_6);
            break;

        case 7:
            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_7);
            break;

        case 8:
            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_8);
            break;

        case 9:
            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_9);
            break;
        }
    }break;

    case 2:
    {
        switch (jokalaria[4])
        {
        case 1:
            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_behera_1);
            break;

        case 2:

            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_behera_2);
            break;

        case 3:
            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_behera_3);
            break;

        case 4:

            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_behera_4);
            break;

        case 5:
            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_behera_5);
            break;

        case 6:

            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_behera_6);
            break;

        case 7:
            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_behera_7);
            break;

        case 8:

            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_behera_8);
            break;

        case 9:

            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_behera_9);
            break;
        }
    }break;

    case 3:
    {
        switch (jokalaria[4])
        {
        case 1:
            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_izq_1);
            break;

        case 2:

            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_izq_2);
            break;

        case 3:
            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_izq_3);
            break;

        case 4:

            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_izq_4);
            break;

        case 5:
            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_izq_5);
            break;

        case 6:

            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_izq_6);
            break;

        case 7:
            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_izq_7);
            break;

        case 8:

            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_izq_8);
            break;

        case 9:
            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_izq_9);
            break;
        }
    }break;

    case 4:
    {
        switch (jokalaria[4])
        {
        case 1:
            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_1);
            break;

        case 2:

            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_2);
            break;

        case 3:
            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_3);
            break;

        case 4:

            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_4);
            break;

        case 5:
            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_5);
            break;

        case 6:

            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_6);
            break;

        case 7:
            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_7);
            break;

        case 8:

            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_8);
            break;

        case 9:

            irudiaKendu(jokalaria[0]);
            jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_9);
            break;
        }
    }break;
    }

    return;
}

void Aldaketak4(int jokalaria[])
{

    jokalaria[5]++;

    if (jokalaria[5] % 1 == 0)
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

//ETSAIA
void etsaiakFuntzioa4(ETSAIA etsaiak[], int jokalaria[], int bala[], int datuak[])
{
    switch (datuak[0])
    {
    case 0:
        break;
    case 1:
        datuak[0] = 0;
        datuak[1] = etsaiaSortu4(etsaiak, 3);
        datuak[2] = 2;
        break;
    case 2:
        datuak[0] = 0;
        datuak[1] = etsaiaSortu4(etsaiak, 6);
        datuak[2] = 3;
        break;
    case 3:
        datuak[0] = 0;
        datuak[1] = etsaiaSortu4(etsaiak, 10);
        datuak[2] = 4;
        break;
    }

    etsaiaMugitu4(etsaiak, jokalaria, datuak[1]);
    if (bala[5]) etsaiaKolisioa4(etsaiak, bala, datuak);
    jokalariaHil4(etsaiak, jokalaria, datuak);

    if (!datuak[1]) datuak[0] = datuak[2];

    return;
}

int etsaiaSortu4(ETSAIA etsaiak[], int kop)
{
    int i, x1, x2, y1, y2;

    srand(time(NULL));

    for (i = 0; i < kop; i++)
    {
        x1 = rand() % 20;
        x2 = rand() % 20;

        y1 = rand() % 20;
        y2 = rand() % 20;

        etsaiak[i].pos.x = (x1 < x2) ? x1 + 1900 : x2 + 20;
        etsaiak[i].pos.y = (y1 < y2) ? y1 + 1060 : y2 + 20;
        etsaiak[i].dir = 1;
        etsaiak[i].sprite = rand() % 2 + 1;
        etsaiak[i].animazioa = 1;
        etsaiak[i].id = irudiaKargatu(ETSAIA_1_1);
        irudiaMugitu(etsaiak[i].id, etsaiak[i].pos.x, etsaiak[i].pos.y);
    }
    return i;
}

void etsaiaMugitu4(ETSAIA etsaiak[], int jokalaria[], int kop)
{
    int i;

    for (i = 0; i < kop; i++)
    {
        bideaAurkitu4(etsaiak, jokalaria, i, kop);
        etsaiak[i].pos.x += etsaiak[i].direkzioa.x;
        etsaiak[i].pos.y += etsaiak[i].direkzioa.y;
        etsaiaAnimazioa4(etsaiak, i);
        irudiaMugitu(etsaiak[i].id, etsaiak[i].pos.x, etsaiak[i].pos.y);
    }
    return;
}

void etsaiaAnimazioa4(ETSAIA etsaiak[], int i)
{
    switch (etsaiak[i].dir)
    {
    case 1:
    {
        switch (etsaiak[i].sprite)
        {
        case 1:
            if (etsaiak[i].animazioa) eAnimazioa4(etsaiak, i, ETSAIA_1_2, 2);
            break;

        case 2:
            if (etsaiak[i].animazioa) eAnimazioa4(etsaiak, i, ETSAIA_1_3, 3);
            break;

        case 3:
            if (etsaiak[i].animazioa) eAnimazioa4(etsaiak, i, ETSAIA_1_1, 1);
            break;
        }
    }break;

    case 2:
    {
        switch (etsaiak[i].sprite)
        {
        case 1:
            if (etsaiak[i].animazioa) eAnimazioa4(etsaiak, i, ETSAIA_2_2, 2);
            break;

        case 2:
            if (etsaiak[i].animazioa) eAnimazioa4(etsaiak, i, ETSAIA_2_3, 3);
            break;

        case 3:
            if (etsaiak[i].animazioa) eAnimazioa4(etsaiak, i, ETSAIA_2_1, 1);
            break;
        }
    }break;

    case 3:
    {
        switch (etsaiak[i].sprite)
        {
        case 1:
            if (etsaiak[i].animazioa) eAnimazioa4(etsaiak, i, ETSAIA_3_2, 2);
            break;

        case 2:
            if (etsaiak[i].animazioa) eAnimazioa4(etsaiak, i, ETSAIA_3_3, 3);
            break;

        case 3:
            if (etsaiak[i].animazioa) eAnimazioa4(etsaiak, i, ETSAIA_3_1, 1);
            break;
        }
    }break;

    case 4:
    {
        switch (etsaiak[i].sprite)
        {
        case 1:
            if (etsaiak[i].animazioa) eAnimazioa4(etsaiak, i, ETSAIA_4_2, 2);
            break;

        case 2:
            if (etsaiak[i].animazioa) eAnimazioa4(etsaiak, i, ETSAIA_4_3, 3);
            break;

        case 3:
            if (etsaiak[i].animazioa) eAnimazioa4(etsaiak, i, ETSAIA_4_1, 1);
            break;
        }
    }break;
    }
    return;
}

void eAnimazioa4(ETSAIA etsaiak[], int i, char sprite[], int hurrengoa)
{
    etsaiak[i].animazioa = 0;
    irudiaKendu(etsaiak[i].id);
    etsaiak[i].id = irudiaKargatu(sprite);
    etsaiak[i].sprite = hurrengoa;
    return;
}

void bideaAurkitu4(ETSAIA etsaiak[], int jokalaria[], int i, int kop)
{
    int j;

    srand(time(NULL));

    etsaiak[i].direkzioa.x = (etsaiak[i].pos.x < jokalaria[1] - 38) ? 0.75 : -0.75;
    etsaiak[i].direkzioa.y = (etsaiak[i].pos.y < jokalaria[2]) ? 0.75 : -0.75;

    for (j = 0; j < kop; j++)
    {
        if (j != i && abs(etsaiak[i].pos.x - etsaiak[j].pos.x) < 50) etsaiak[i].direkzioa.x = (etsaiak[i].pos.x < etsaiak[j].pos.x) ? -1 * (rand() % 2) : 1 * (rand() % 2);
        if (j != i && abs(etsaiak[i].pos.y - etsaiak[j].pos.y) < 50) etsaiak[i].direkzioa.y = (etsaiak[i].pos.y < etsaiak[j].pos.y) ? -1 * (rand() % 2) : 1 * (rand() % 2);
    }

    if (etsaiak[i].direkzioa.x > 0 && etsaiak[i].direkzioa.y < 0) etsaiak[i].dir = 1;
    else if (etsaiak[i].direkzioa.x < 0 && etsaiak[i].direkzioa.y < 0) etsaiak[i].dir = 2;
    else if (etsaiak[i].direkzioa.x < 0 && etsaiak[i].direkzioa.y > 0) etsaiak[i].dir = 3;
    else if (etsaiak[i].direkzioa.x > 0 && etsaiak[i].direkzioa.y > 0) etsaiak[i].dir = 4;

    return;
}

void etsaiaKolisioa4(ETSAIA etsaiak[], int bala[], int datuak[])
{
    int i;
    for (i = 0; i < datuak[1]; i++)
    {
        if ((bala[3] == 1 && bala[1] + 31 >= etsaiak[i].pos.x + 8 && bala[1] + 31 <= etsaiak[i].pos.x + 82 && bala[2] + 13 >= etsaiak[i].pos.y + 8 && bala[2] + 13 <= etsaiak[i].pos.y + 49) ||
            (bala[3] == 2 && bala[1] + 34 >= etsaiak[i].pos.x + 8 && bala[1] + 34 <= etsaiak[i].pos.x + 82 && bala[2] + 52 >= etsaiak[i].pos.y + 8 && bala[2] + 52 <= etsaiak[i].pos.y + 49) ||
            (bala[3] == 3 && bala[1] + 13 >= etsaiak[i].pos.x + 8 && bala[1] + 13 <= etsaiak[i].pos.x + 82 && bala[2] + 34 >= etsaiak[i].pos.y + 8 && bala[2] + 34 <= etsaiak[i].pos.y + 49) ||
            (bala[3] == 4 && bala[1] + 52 >= etsaiak[i].pos.x + 8 && bala[1] + 52 <= etsaiak[i].pos.x + 82 && bala[2] + 31 >= etsaiak[i].pos.y + 8 && bala[2] + 31 <= etsaiak[i].pos.y + 49))
        {
            etsaiaKendu4(etsaiak, i, datuak);
            bala[6] = 1;
        }
    }
    return;
}

void etsaiaKendu4(ETSAIA etsaiak[], int i, int datuak[])
{
    int j;
    irudiaKendu(etsaiak[i].id);

    for (j = i; j < datuak[1]; j++) etsaiak[j] = etsaiak[j + 1];
    datuak[1]--;

    return;
}

void animazioaAktibatu4(ETSAIA etsaiak[], int kont, int kop)
{
    int i;
    if (!(kont % 50))
    {
        for (i = 0; i < kop; i++)
            etsaiak[i].animazioa = 1;   
    }
    return;
}

void jokalariaHil4(ETSAIA etsaiak[], int jokalaria[], int datuak[])
{
    int i;

    for (i = 0; i < datuak[1]; i++)
    {
        if (jokalaria[1] + 15 >= etsaiak[i].pos.x + 8 && jokalaria[1] + 15 <= etsaiak[i].pos.x + 82 && jokalaria[2] + 26 >= etsaiak[i].pos.y + 8 && jokalaria[2] + 26 <= etsaiak[i].pos.y + 49)
        {
            datuak[3] = 0;
        }
    }
}

int irudiaSortu4(char irudia[]) // Pantailaratuar las imagenes
{
    int id = -1;

    id = irudiaKargatu(irudia);
    irudiaMugitu(id, 10, 239);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();

    return id;
}

