#include "OurTypes.h"
#include "funtzioak.h"
#include "Mugimenduak.h"
#include "Sprite.h"
#include "Mapak.h"
#include "EbentuaKargatu.h"
#include "Hizketak.h"

#include "MiniJuego1.h"
#include "MiniJuego2.h"
#include "MiniJuego3.h"
#include "MiniJuego4.h"

void MisioakHasieratu(int misiones[]) {

	misiones[0] = 0; // primer minijuego (mendigo + Mac)
	misiones[1] = 0; // segundo minijuego (escapa del bosque)
	misiones[2] = 0; // tercer minijuego (limpiar el agua)
	misiones[3] = 0; // cuarto minijuego (derrota a los monstruos)
	misiones[4] = 0; // quinto minijuego ( Minijuego final) (si hay)
	misiones[5] = 0; // EasterEgg del cementerio

	return;
}

void ebentuaKargatu(int mapa[], int jokalaria[], int extras[], int misiones[]) {

	int emaitza=0, img = 0;

	switch (mapa[1])
	{
		case 1: // terminar juego
		{
			if (mapa[4] == 1) jokalaria[9] = 1;
		}break;

		case 3: // Ebentos mapa 3: Hablar con mendigo y minijuego en el Mac
		{
			if ((jokalaria[1] < 400) && (jokalaria[2] > 480) && (jokalaria[2] < 625))// mendigo
			{
				if (misiones[0] <= 1) // presentacion mendigo (aun no se ha jugado el minijuego)
				{
					DenaKendu(jokalaria, mapa, extras);
					HitzEgin(1, mapa);
					BirKargatu(jokalaria, mapa, extras);

					misiones[0] = 1;
				}
				else if (misiones[0] == 2) // derrota por lleno
				{
					DenaKendu(jokalaria, mapa, extras);
					HitzEgin(2, mapa);
					BirKargatu(jokalaria, mapa, extras);
				}
				else if (misiones[0] == 3) // derrota por salud
				{
					DenaKendu(jokalaria, mapa, extras);
					HitzEgin(3, mapa);
					BirKargatu(jokalaria, mapa, extras);
				}
				else if (misiones[0] == 4) // fin del juego
				{
					DenaKendu(jokalaria, mapa, extras);
					HitzEgin(4, mapa);
					BirKargatu(jokalaria, mapa, extras);
				}
			}
			else if ((jokalaria[1] > 800) && (jokalaria[1] < 1200) && (jokalaria[2] < 600)) // Mac
			{
				if (misiones[0] == 0) // si aun no tienes acceso
				{
					DenaKendu(jokalaria, mapa, extras);
					HitzEgin(5, mapa);
					BirKargatu(jokalaria, mapa, extras);
				}
				else if ((misiones[0] == 1)||((misiones[0] == 2))) // empezar minijuego
				{
					DenaKendu(jokalaria, mapa, extras);

					emaitza = mini_juego_1();

					BirKargatu(jokalaria, mapa, extras);

					if (emaitza = 1) misiones[0] = 2; // derrota por lleno
					if (emaitza = 2) misiones[0] = 3; // derrota poco saludable
					if (emaitza = 3)// conseguido
					{
						misiones[0] = 4;
					}
				}
				else // si ya has terminado el minijuego
				{
					DenaKendu(jokalaria, mapa, extras);
					HitzEgin(6, mapa);
					BirKargatu(jokalaria, mapa, extras);
				}
			}

		}break;

		case 4: // Ebentos mapa 4: Regadera
		{
			if ((jokalaria[1] > 1560) && (jokalaria[1] < 1660) && (jokalaria[2] < 775) && (jokalaria[2] > 675))
			{
				HitzEgin(7, mapa);

				DenaKendu(jokalaria, mapa, extras);

				if (misiones[1] == 0) emaitza = Mini_Juego_2();

				if (emaitza == 0)misiones[1] = 1;

				if (emaitza == 0)
				{
					mapa[1] = 5;

					mapa[0] = irudiaKargatu(MAPA_BOSQUE_2);
					irudiaMugitu(mapa[0], 160, 80);

					jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_1);
					jokalaria[1] = 1300;
					jokalaria[2] = 800;
					jokalaria[3] = 1;
					jokalaria[4] = 1;
					jokalaria[5] = 0;

					irudiaMugitu(jokalaria[0], jokalaria[1], jokalaria[2]);

					pantailaGarbitu();
					irudiakMarraztu();
					pantailaBerriztu();
				}
				else
				{
					mapa[0] = irudiaKargatu(MAPA_BOSQUE_1);
					BirKargatu(jokalaria, mapa, extras);

					pantailaGarbitu();
					irudiakMarraztu();
					pantailaBerriztu();
				}

			}

		}break;

		case 5: // Ultimos Juegos
		{
			if(jokalaria[2] < 200)
			{
				DenaKendu(jokalaria, mapa, extras);

				if (misiones[2] == 0)
				{
					misiones[2] = mini_jokoa_3();
				}
				
				if(misiones[2] == 1)
				{
					img = irudiaKargatu(BABESTU);
					MezuaIdatzi(img, 140, 100);
					irudiaKendu(img);

					misiones[3] = Mini_Juego_4();
				}

				if (misiones[3] == 1)
				{
					img = irudiaKargatu(URA_LORTU);
					MezuaIdatzi(img, 140, 100);
					irudiaKendu(img);

					mapa[1] = 2;
					mapa[4] = 1;

					mapa[0] = irudiaKargatu(MAPA_CIUDAD_1);
					irudiaMugitu(mapa[0], 170, 90);

					jokalaria[1] = 1500;
					jokalaria[2] = 500;
					jokalaria[3] = 3;
					jokalaria[4] = 1;

					jokalaria[0] = irudiaKargatu(JOKALARIA_izq_1);
					irudiaMugitu(jokalaria[0], jokalaria[1], jokalaria[2]);
				}
				else
				{
					img = irudiaKargatu(KENDUTA);
					MezuaIdatzi(img, 140, 100);
					irudiaKendu(img);

					mapa[0] = irudiaKargatu(MAPA_BOSQUE_2);
					jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_1);
					BirKargatu(jokalaria, mapa, extras);
				}

				pantailaGarbitu();
				irudiakMarraztu();
				pantailaGarbitu();
			}

			if ((jokalaria[1] > 1000) && (jokalaria[1] < 1200) && (jokalaria[2] > 850))
			{
				DenaKendu(jokalaria, mapa, extras);

				mapa[0] = irudiaKargatu(BUELTA_EMAN);
				MezuaIdatzi(mapa[0], 0, 0);
				irudiaKendu(img);

				jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_1);
				BirKargatu(jokalaria, mapa, extras);
			}
		}break;
	}

	return;
}

void HitzEgin(int hizketa, int mapa[]) {

	int ebentua;
	int argazkiak[2];

		switch (hizketa)
		{
			case 1: // Presentacion mendigo
			{
				mapa[0] = irudiaKargatu(MENDIGO_1);
				MezuaIdatzi(mapa[0], 140, 100);
				irudiaKendu(mapa[0]);

				mapa[0] = irudiaKargatu(MENDIGO_2);
				MezuaIdatzi(mapa[0], 140, 100);
				irudiaKendu(mapa[0]);

				mapa[0] = irudiaKargatu(MENDIGO_3);
				MezuaIdatzi(mapa[0], 140, 100);
				irudiaKendu(mapa[0]);

				mapa[0] = irudiaKargatu(MENDIGO_4);
				MezuaIdatzi(mapa[0], 140, 100);

			}break;

			case 2: // Derrota_1 por lleno
			{
				mapa[0] = irudiaKargatu(MENDIGO_5);
				MezuaIdatzi(mapa[0], 140, 100);
				irudiaKendu(mapa[0]);

				mapa[0] = irudiaKargatu(MENDIGO_6);
				MezuaIdatzi(mapa[0], 140, 100);

			}break;

			case 3: // Derrota_1 por salud
			{
				mapa[0] = irudiaKargatu(MENDIGO_7);
				MezuaIdatzi(mapa[0], 140, 100);
				irudiaKendu(mapa[0]);

				mapa[0] = irudiaKargatu(MENDIGO_8);
				MezuaIdatzi(mapa[0], 140, 100);
				irudiaKendu(mapa[0]);

				mapa[0] = irudiaKargatu(MENDIGO_9);
				MezuaIdatzi(mapa[0], 140, 100);
				irudiaKendu(mapa[0]);

				mapa[0] = irudiaKargatu(MENDIGO_7);
				MezuaIdatzi(mapa[0], 140, 100);
				irudiaKendu(mapa[0]);

				mapa[0] = irudiaKargatu(MENDIGO_10);
				MezuaIdatzi(mapa[0], 140, 100);
				irudiaKendu(mapa[0]);

				mapa[0] = irudiaKargatu(MENDIGO_11);
				MezuaIdatzi(mapa[0], 140, 100);

			}break;
			
			case 4: // Conseguido minijuego1
			{
				mapa[0] = irudiaKargatu(MENDIGO_12);
				MezuaIdatzi(mapa[0], 140, 100);
				if (mapa[2] != 1) irudiaKendu(mapa[0]);

				if (mapa[2] != 1)
				{
					mapa[0] = irudiaKargatu(MENDIGO_13);
					MezuaIdatzi(mapa[0], 140, 100);
					irudiaKendu(mapa[0]);

					mapa[0] = irudiaKargatu(MENDIGO_14);
					MezuaIdatzi(mapa[0], 140, 100);

					mapa[2] = 1; // hay planta en casa
					mapa[3] = 1; // acceso a bosque bajo
				}

			}break;

			case 5: // El Mac no ha abierto
			{
				mapa[0] = irudiaKargatu(Mac1);
				MezuaIdatzi(mapa[0], 140, 100);

			}break;

			case 6: // El Mac ha cerrado
			{
				mapa[0] = irudiaKargatu(Mac2);
				MezuaIdatzi(mapa[0], 140, 100);

			}break;

			case 7: // Se consigue la regadera
			{
				argazkiak[0] = irudiaKargatu(FOTO_REGADERA);
				irudiaMugitu(argazkiak[0], 850, 300);

				argazkiak[1] = irudiaKargatu(TEXTO_REGADERA);
				irudiaMugitu(argazkiak[1], 600, 700);

				pantailaGarbitu();
				irudiakMarraztu();
				pantailaBerriztu();

				do
				{
					ebentua = ebentuaJasoGertatuBada();

				} while (ebentua != TECLA_RETURN);

				irudiaKendu(argazkiak[0]);
				irudiaKendu(argazkiak[1]);

				pantailaGarbitu();
				irudiakMarraztu();
				pantailaBerriztu();

			}break;
				
		}

		return;
	}

void BirKargatu(int jokalaria[], int mapa[], int extras[]) {
		
		MapaAldatu(mapa);

		CrearExtras(mapa, extras);

		SpritaSortu(jokalaria);
		irudiaMugitu(jokalaria[0], jokalaria[1], jokalaria[2]);

		return;
	}

void DenaKendu(int jokalaria[], int mapa[], int extras[]) {

		irudiaKendu(mapa[0]);
		irudiaKendu(jokalaria[0]);

		if (mapa[1] == 3) LimpiarMapa(extras, 3);
		if (mapa[1] == 4) LimpiarMapa(extras, 1);

		pantailaGarbitu();
		pantailaBerriztu();

		return;
	}

void MezuaIdatzi(int argazkia, int x, int y)
	{
		int ebentu;

		irudiaMugitu(argazkia, x, y);

		pantailaGarbitu();
		irudiakMarraztu();
		pantailaBerriztu();

		do
		{
			ebentu = ebentuaJasoGertatuBada();
		} while (ebentu != TECLA_RETURN);// esperar hasta que se pulsa return

		return;
	}

void EbentuaGertu(int jokalaria[], int mapa[], int kontrol[]) {

	if(kontrol[1] == 0)		
	{
		switch (mapa[1])
		{
			case 1:
			{
				if (mapa[4] == 1)
				{
					kontrol[0] = irudiaKargatu(E_SAKATU_1);
					kontrol[1] = 1;
					kontrol[2] = 0;
					irudiaMugitu(kontrol[0], 1200, 200);
				}
			}break;

			case 3:
			{
				if ((jokalaria[1] < 350) && (jokalaria[2] > 480) && (jokalaria[2] < 600))// mendigo
					{
						kontrol[0] = irudiaKargatu(E_SAKATU_1);
						kontrol[1] = 1;
						kontrol[2] = 0;
						irudiaMugitu(kontrol[0], 200, 200);
					}

				if((jokalaria[1]>950)&&(jokalaria[1]<1200)&&(jokalaria[2]>400) && (jokalaria[2]<600))
					{
						kontrol[0] = irudiaKargatu(E_SAKATU_1);
						kontrol[1] = 1;
						kontrol[2] = 0;
						irudiaMugitu(kontrol[0], 1200, 200);
					}

			}break;

			case 4:
			{
				if ((jokalaria[1] > 1560) && (jokalaria[1] < 1660) && (jokalaria[2] < 775) && (jokalaria[2] > 675))
				{
					kontrol[0] = irudiaKargatu(E_SAKATU_1);
					kontrol[1] = 1;
					kontrol[2] = 0;
					irudiaMugitu(kontrol[0], 1500, 200);
				}

			}break;

			case 5:
			{
				if (jokalaria[2] <= 190)
				{
					kontrol[0] = irudiaKargatu(E_SAKATU_1);
					kontrol[1] = 1;
					kontrol[2] = 0;
					irudiaMugitu(kontrol[0], 1500, 200);
				}

				if ((jokalaria[1] > 1000) && (jokalaria[1] < 1200) && (jokalaria[2] > 850))
				{
					kontrol[0] = irudiaKargatu(E_SAKATU_1);
					kontrol[1] = 1;
					kontrol[2] = 0;
					irudiaMugitu(kontrol[0], 1500, 200);
				}
			}break;
		}
	}
	else
	{
		switch (mapa[1])
		{
			case 1:
			{
				if (mapa[2] == 1)
				{
					irudiaKendu(kontrol[0]);
					kontrol[1] = 0;
					kontrol[2] = 1;
				}
				else if (kontrol[2] % 29 == 0)
				{
					if (kontrol[1] == 1)
					{
						irudiaKendu(kontrol[0]);
						kontrol[0] = irudiaKargatu(E_SAKATU_2);
						kontrol[1] = 2;
						kontrol[2] = 1;
						irudiaMugitu(kontrol[0], 1495, 195);
					}
					else
					{
						irudiaKendu(kontrol[0]);
						kontrol[0] = irudiaKargatu(E_SAKATU_1);
						kontrol[1] = 1;
						kontrol[2] = 1;
						irudiaMugitu(kontrol[0], 1500, 200);
					}
				}
				else
				{
					kontrol[2]++;
				}
			}break;

			case 3:
			{
					if (jokalaria[1] < 600)// mendigo
					{
						if ((jokalaria[1] > 350) || (jokalaria[2] < 480) || (jokalaria[2] > 600))// mendigo
						{
							irudiaKendu(kontrol[0]);
							kontrol[1] = 0;
							kontrol[2] = 0;
						}
						else if (kontrol[2]%23==0)
						{
							if (kontrol[1] == 1)
							{
								irudiaKendu(kontrol[0]);
								kontrol[0] = irudiaKargatu(E_SAKATU_2);
								kontrol[1] = 2;
								kontrol[2] = 1;
								irudiaMugitu(kontrol[0], 195, 195);
							}
							else
							{
								irudiaKendu(kontrol[0]);
								kontrol[0] = irudiaKargatu(E_SAKATU_1);
								kontrol[1] = 1;
								kontrol[2] = 1;
								irudiaMugitu(kontrol[0], 200, 200);
							}
						}
						else
						{
							kontrol[2]++;
						}
					}

					if (jokalaria[1] > 600)// mendigo
					{
						if ((jokalaria[1] < 950) || (jokalaria[1] > 1200) || (jokalaria[2] < 400) || (jokalaria[2] > 600))// mendigo
						{
							irudiaKendu(kontrol[0]);
							kontrol[1] = 0;
							kontrol[2] = 1;
						}
						else if (kontrol[2] % 23 == 0)
						{
							if (kontrol[1] == 1)
							{
								irudiaKendu(kontrol[0]);
								kontrol[0] = irudiaKargatu(E_SAKATU_2);
								kontrol[1] = 2;
								kontrol[2] = 1;
								irudiaMugitu(kontrol[0], 1195, 195);
							}
							else
							{
								irudiaKendu(kontrol[0]);
								kontrol[0] = irudiaKargatu(E_SAKATU_1);
								kontrol[1] = 1;
								kontrol[2] = 1;
								irudiaMugitu(kontrol[0], 1200, 200);
							}
						}
						else
						{
							kontrol[2]++;
						}
					}

				}break;

			case 4:
			{
				if ((jokalaria[1] < 1560) || (jokalaria[1] > 1660) || (jokalaria[2] > 775) || (jokalaria[2] < 675))
				{
					irudiaKendu(kontrol[0]);
					kontrol[1] = 0;
					kontrol[2] = 1;
				}
				else if (kontrol[2] % 23 == 0)
				{
					if (kontrol[1] == 1)
					{
						irudiaKendu(kontrol[0]);
						kontrol[0] = irudiaKargatu(E_SAKATU_2);
						kontrol[1] = 2;
						kontrol[2] = 1;
						irudiaMugitu(kontrol[0], 1495, 195);
					}
					else
					{
						irudiaKendu(kontrol[0]);
						kontrol[0] = irudiaKargatu(E_SAKATU_1);
						kontrol[1] = 1;
						kontrol[2] = 1;
						irudiaMugitu(kontrol[0], 1500, 200);
					}
				}
				else
				{
					kontrol[2]++;
				}

			}break;

			case 5:
			{
				if ((jokalaria[2] > 190)&&(jokalaria[2] < 600))
				{
					irudiaKendu(kontrol[0]);
					kontrol[1] = 0;
					kontrol[2] = 1;
				}
				else if (kontrol[2] % 29 == 0)
				{
					if (kontrol[1] == 1)
					{
						irudiaKendu(kontrol[0]);
						kontrol[0] = irudiaKargatu(E_SAKATU_2);
						kontrol[1] = 2;
						kontrol[2] = 1;
						irudiaMugitu(kontrol[0], 1495, 195);
					}
					else
					{
						irudiaKendu(kontrol[0]);
						kontrol[0] = irudiaKargatu(E_SAKATU_1);
						kontrol[1] = 1;
						kontrol[2] = 1;
						irudiaMugitu(kontrol[0], 1500, 200);
					}
				}
				else
				{
					kontrol[2]++;
				}

				if (((jokalaria[1] < 1000) || (jokalaria[1] > 1200) || (jokalaria[2] < 850))&&(jokalaria[2]>600))
				{
					irudiaKendu(kontrol[0]);
					kontrol[1] = 0;
					kontrol[2] = 1;
				}
				else if (kontrol[2] % 29 == 0)
				{
					if (kontrol[1] == 1)
					{
						irudiaKendu(kontrol[0]);
						kontrol[0] = irudiaKargatu(E_SAKATU_2);
						kontrol[1] = 2;
						kontrol[2] = 1;
						irudiaMugitu(kontrol[0], 1495, 195);
					}
					else
					{
						irudiaKendu(kontrol[0]);
						kontrol[0] = irudiaKargatu(E_SAKATU_1);
						kontrol[1] = 1;
						kontrol[2] = 1;
						irudiaMugitu(kontrol[0], 1500, 200);
					}
				}
				else
				{
					kontrol[2]++;
				}

			}break;
		}
	}

	return;
}

