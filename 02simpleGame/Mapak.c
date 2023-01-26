#include "OurTypes.h"
#include "funtzioak.h"
#include "Mugimenduak.h"
#include "Sprite.h"
#include "Mapak.h"
#include "EbentuaKargatu.h"

void MapakKargatu(int mapa[]) {

	mapa[0] = irudiaKargatu(MAPA_INICIAL); //cargar imagen casa sin planta

	irudiaMugitu(mapa[0], 260, 0); //centrar foto del mapa

	mapa[1] = 1; //numero de mapa ( 1 = casa)
	mapa[2] = 0; //si hay o no planta en la casa (al principio no hay)
	mapa[3] = 0; //aun no se ha completado la primera mision
	mapa[4] = 0; // se han completado todas las misiones
}

void colisiones(int mapa[], int jokalaria[], int extras[]) {

	int aldaketa = 5;

	switch (mapa[1]) //segun la zona del mapa
	{
		case 1: //colisiones en la casa
		{
			if (jokalaria[2] <= 600)// colision por arriba
			{
				if (jokalaria[1] <=1000) //colision parte izquierda por arriba (desde la izquierda hasta las escaleras)
				{
					while(jokalaria[2]<=600)jokalaria[2] += 10; 
				}
				else // colisiones parte derecha por arriba (desde las escaleras hasta la derecha)
				{
					while (jokalaria[2] <= 570)jokalaria[2] += 10;
				}	
			}

			while (jokalaria[2] >= 920)jokalaria[2] -= 10; // colision por abajo

			while (jokalaria[1] <= 260)jokalaria[1] += 10; // colision por la izquierda

			if (jokalaria[1] >= 1700) //cambiar a la ciudad
			{
				jokalaria[1] = 200; // donde va a aparecer x
				jokalaria[2] = 500; // donde va a aparecer y
				jokalaria[4] = 1; //volvemos al primer sprite
				jokalaria[5] = 0; // reseteamos variable cambio sprite
				jokalaria[6] = 1; // personaje a pequeño

				mapa[1] = 2; // a que mapa cambia (2 = ciudad baja)

				MapaAldatu(mapa); // cambiar imagen del mapa

				irudiaKendu(jokalaria[0]);
				jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_1);

				irudiaMugitu(jokalaria[0], jokalaria[1], jokalaria[2]); // centrar foto del mapa
			}

		} break;

		case 2: // colisiones en la ciudad baja
		{
			if (jokalaria[2] <= 350) CiudadBaja_Goitik(jokalaria, aldaketa);

			if (jokalaria[2] >= 525) CiudadBaja_Behetik(jokalaria, aldaketa);

			CiudadBaja_ColisionLateral(jokalaria, aldaketa);
			
			Adaketak_CiudadBaja(mapa, jokalaria, extras);

		}break;

		case 3: // colisiones en la ciudad alta
		{
			CiudadAlta_ColisionVertical(jokalaria, aldaketa);

			CiudadAlta_ColisionLateral(jokalaria, aldaketa);

			Invisble_CiudadAlta(jokalaria, aldaketa);

			if (jokalaria[2] > 910) //Vuelta a la ciudad 2 
			{
				jokalaria[1] = 420; // donde va a aparecer x
				jokalaria[2] = 110; // donde va a aparecer y
				jokalaria[4] = 2; //volvemos al primer sprite
				jokalaria[5] = 0; // reseteamos variable cambio sprite
				jokalaria[6] = 1; // personaje a pequeño

				mapa[1] = 2; // a que mapa cambia (2 = ciudad baja)

				LimpiarMapa(extras, 3);

				MapaAldatu(mapa); // cambiar imagen del mapa

				irudiaKendu(jokalaria[0]);
				jokalaria[0] = irudiaKargatu(JOKALARIA_behera_1);

				irudiaMugitu(jokalaria[0], jokalaria[1], jokalaria[2]); // centrar foto del mapa
			}

		}break;

		case 4: // colisiones bosque bajo
		{
			BosqueBajo_ColisionesVerticales(jokalaria, aldaketa);

			BosqueBajo_ColisionesHorizontales(jokalaria, aldaketa);

			if (jokalaria[1] < 200)
			{
				jokalaria[1] = 1600; // donde va a aparecer x
				jokalaria[2] = 800; // donde va a aparecer y
				jokalaria[4] = 2; //volvemos al primer sprite
				jokalaria[5] = 0; // reseteamos variable cambio sprite

				mapa[1] = 2; // a que mapa cambia (2 = ciudad baja)

				if (mapa[3] == 1) LimpiarMapa(extras, 1);

				MapaAldatu(mapa); // cambiar imagen del mapa

				irudiaKendu(jokalaria[0]);
				jokalaria[0] = irudiaKargatu(JOKALARIA_izq_1);

				irudiaMugitu(jokalaria[0], jokalaria[1], jokalaria[2]); // centrar foto del mapa
			}

		}break;

		case 5: // colisiones bosque alto
		{
			BosqueAlto(jokalaria, aldaketa);
		}break;

	}

	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return;
}

void MapaAldatu(int mapa[]) {

	switch (mapa[1])
	{
		case 1: //Cargar mapa de la casa
		{
			irudiaKendu(mapa[0]); //quitar mapa anterior

			if (mapa[2] == 0)
			{
				mapa[0] = irudiaKargatu(MAPA_INICIAL); //sin planta
				irudiaMugitu(mapa[0], 260, 0); //colocar la imgen
			}
			else
			{
				mapa[0] = irudiaKargatu(MAPA_CON_ARBOL);//con planta
				irudiaMugitu(mapa[0], 265, 100); //colocar la imgen
			}

			
		}break;

		case 2: //Cargar mapa de la ciudad baja
		{
			irudiaKendu(mapa[0]); //quitar mapa anterior

			mapa[0] = irudiaKargatu(MAPA_CIUDAD_1); //cambiar a mapa ciudad baja

			irudiaMugitu(mapa[0], 170, 90); // colocar imagen de la ciudad baja

		}break;

		case 3: //Cargar mapa de la ciudad alta
		{
			irudiaKendu(mapa[0]); //quitar mapa anterior

			mapa[0] = irudiaKargatu(MAPA_CIUDAD_2); //cambiar a mapa ciudad baja

			irudiaMugitu(mapa[0], 180, 110); // colocar imagen de la ciudad baja
		}break;

		case 4: //Cargar mapa bosque bajo
		{
			irudiaKendu(mapa[0]); //quitar mapa anterior

			mapa[0] = irudiaKargatu(MAPA_BOSQUE_1); //cambiar a mapa ciudad baja

			irudiaMugitu(mapa[0], 180, 105); // colocar imagen de la ciudad baja
		}break;

		case 5: //Cargar mapa bosque alto
		{
			irudiaKendu(mapa[0]); //quitar mapa anterior

			mapa[0] = irudiaKargatu(MAPA_BOSQUE_2); //cambiar a mapa ciudad baja

			irudiaMugitu(mapa[0], 180, 105); // colocar imagen de la ciudad baja
		}break;
	}

	return;
}

void LimpiarMapa(int extras[], int zenbat) {

	int i;

	for (i = 0; i < zenbat; i++)
	{
		irudiaKendu(extras[i]);
	}

	return;
}

void CrearExtras(int mapa[], int extras[]) {

	switch (mapa[1])
	{
		case 3:
		{
			extras[0] = irudiaKargatu(BASURA);
			irudiaMugitu(extras[0], 1220, 575);

			extras[1] = irudiaKargatu(ZONA_BASURAS);
			irudiaMugitu(extras[1],200, 500);

			extras[2] = irudiaKargatu(MENDIGO);
			irudiaMugitu(extras[2], 220, 560);
		}break;

		case 4:
		{
			extras[0] = irudiaKargatu(REGADERA);
			irudiaMugitu(extras[0], 1615, 745);

		}break;
	}

	return;
}

//Colisiones Mapa Ciudad Baja

void CiudadBaja_Goitik (int jokalaria[], int aldaketa){

	if (jokalaria[1] <= 355) // primer edificio por la izquierda
	{
		while (jokalaria[2] <= 315) jokalaria[2] += aldaketa;
	}
	else if ((jokalaria[1] >= 685) && (jokalaria[1] <= 755)) //segundo edificio hasta las basuras
	{
		while (jokalaria[2] <= 335) jokalaria[2] += aldaketa;
	}
	else if ((jokalaria[1] >= 755) && (jokalaria[1] <= 1300))// basuras y tercer edificio
	{
		while (jokalaria[2] <= 350) jokalaria[2] += aldaketa;
	}
	else if (jokalaria[1] > 1300) // colisiones en el puente
	{
		while (jokalaria[2] <= 335) jokalaria[2] += aldaketa;
	}

	return;
}

void CiudadBaja_Behetik (int jokalaria[], int aldaketa){

	if (jokalaria[1] >= 1281) //colision en el puente
	{
		while (jokalaria[2] >= 525)jokalaria[2] -= aldaketa;
	}
	else if ((jokalaria[1] >= 1200) && (jokalaria[1] < 1280)) // colision parte baja del paseillo 
	{
		while (jokalaria[2] >= 850)jokalaria[2] -= aldaketa;
	}
	else if ((jokalaria[1] >= 700) && (jokalaria[1] < 760)) // colision cementerio
	{
		while (jokalaria[2] >= 575) jokalaria[2] -= aldaketa;
	}
	else if ((jokalaria[1]<700)&&(jokalaria[1]>650)) // colision paredes cementerio derecha
	{
		while (jokalaria[2] >= 550) jokalaria[2] -= aldaketa;
	}
	else if ((jokalaria[1] < 650) && (jokalaria[1] > 320)) //colsion verja cementerio
	{
		while (jokalaria[2] >= 575) jokalaria[2] -= aldaketa;
	}
	else if (jokalaria[1] < 320) //colision basuras izquierda y ultima pared cementerio
	{
		while (jokalaria[2] >= 550)jokalaria[2] -= aldaketa;
	}

	return;
}

void CiudadBaja_ColisionLateral (int jokalaria[], int aldaketa) {

	//En la zona baja

	if ((jokalaria[2] >= 545) && (jokalaria[1] >= 1230)) //colision camino al lado del rio (derecha)
	{
		while (jokalaria[1] >= 1275) jokalaria[1] -= aldaketa;
	}

	if ((jokalaria[2] > 555) && (jokalaria[1] < 1230) && (jokalaria[1]>=765)) //invisible en el edificio
	{
		Invisble_CiudadBaja(jokalaria, aldaketa);
	}

	//En la zona alta

	if ((jokalaria[1] >= 350) && (jokalaria[2] < 315)) // pared derecha del primer edificio
	{
		while (jokalaria[1] < 365) jokalaria[1] += aldaketa; 
	}

	if ((jokalaria[1] <= 690) && (jokalaria[2] < 335)) // pared izquierda del segundo edificio
	{
		while (jokalaria[1] > 660) jokalaria[1] -= aldaketa; 
	}

	return;
}

void Invisble_CiudadBaja (int jokalaria[],int aldaketa) {

	int ebentu = 0;

	irudiaKendu(jokalaria[0]);

	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	jokalaria[7] = 1;

	while ((jokalaria[8] == 0) && (jokalaria[7] == 1))
	{
		ebentu = ebentuaJasoGertatuBada();

		switch (ebentu)
		{
		case TECLA_w:
			jokalaria[2] -= aldaketa;
			break;

		case TECLA_s:
			jokalaria[2] += aldaketa;
			break;

		case TECLA_a:
			jokalaria[1] -= aldaketa;
			break;

		case TECLA_d:
			jokalaria[1] += aldaketa;
			break;

		case TECLA_ESCAPE:
			jokalaria[8] = 1;
			break;

		case TECLA_RETURN:
			jokalaria[8] = 1;
			break;

		case TECLA_p:
			printf("%d, %d\n", jokalaria[1], jokalaria[2]);
			break;

		case TECLA_UP:
			jokalaria[2] -= aldaketa;
			break;

		case TECLA_DOWN:
			jokalaria[2] += aldaketa;
			break;

		case TECLA_RIGHT:
			jokalaria[1] -= aldaketa;
			break;

		case TECLA_LEFT:
			jokalaria[1] += aldaketa;
			break;
		}

		while (jokalaria[1] <= 770) jokalaria[1] += aldaketa; // colison por la izquierda del edificio
		while (jokalaria[2] >= 850)jokalaria[2] -= aldaketa; //colision por la parte baja del edificio

		if ((jokalaria[1] > 1230) || (jokalaria[2] < 555)) jokalaria[7] = 0; //si sale del edificio

		pantailaGarbitu();
		irudiakMarraztu();
		pantailaBerriztu();
	}

	if (jokalaria[2] < 555) //Por donde sale
	{
		jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_1); //si sale por arriba

		jokalaria[3] = 1;
	}
	else
	{
		jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_1); //si sale por abajo

		jokalaria[3] = 4;
	}

	jokalaria[4] = 1;
	jokalaria[5] = 0;

	irudiaMugitu(jokalaria[0], jokalaria[1], jokalaria[2]);
}

void Adaketak_CiudadBaja(int mapa[], int jokalaria[], int extras[]) {

	if (jokalaria[1] <= 190) // colision en la izquierda (cambio a la casa)
	{
		jokalaria[1] = 1650;
		jokalaria[2] = 700;
		jokalaria[4] = 1; //volvemos al primer sprite
		jokalaria[5] = 0; //reseteamos variable sprite
		jokalaria[6] = 0; // personaje a grande

		mapa[1] = 1;

		MapaAldatu(mapa);

		irudiaKendu(jokalaria[0]);
		jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_izq_1);

		irudiaMugitu(jokalaria[0], jokalaria[1], jokalaria[2]);
	}

	if (jokalaria[1] >= 1700) // colision en la derecha (cambio a parque bajo)
	{
		if ((mapa[3] == 0)||(mapa[4]==1))
		{
			while (jokalaria[1] > 1700) jokalaria[1] -= 5;
		}
		else
		{
			jokalaria[1] = 200; //x desde donde se va a salir
			jokalaria[2] = 800; //y desde donde se va a salir
			jokalaria[4] = 1; //volvemos al primer sprite
			jokalaria[5] = 0; //reseteamos variable sprite

			mapa[1] = 4;

			MapaAldatu(mapa); // cambiar al tercer 

			if (mapa[3] == 1) CrearExtras(mapa, extras);

			irudiaKendu(jokalaria[0]);
			jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_1); //aseguramos que vuelve al primer sprite

			irudiaMugitu(jokalaria[0], jokalaria[1], jokalaria[2]); //movemos el personaje al "inicio" del mapa
		}
	}

	if (jokalaria[2] <= 100)  // colision por arriba (cambio a ciudad alta)
	{
		jokalaria[1] = 485; //x desde donde se va a salir
		jokalaria[2] = 880; //y desde donde se va a salir
		jokalaria[4] = 1; //volvemos al primer sprite
		jokalaria[5] = 0; //reseteamos variable sprite

		mapa[1] = 3; 

		MapaAldatu(mapa); // cambiar al tercer 

		CrearExtras(mapa, extras);

		irudiaKendu(jokalaria[0]);
		jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_1); //aseguramos que vuelve al primer sprite

		irudiaMugitu(jokalaria[0], jokalaria[1], jokalaria[2]); //movemos el personaje al "inicio" del mapa
	}
}

// Colisiones Mapa Ciudad Alta

void CiudadAlta_ColisionVertical(int jokalaria[], int aldaketa) {

	if (jokalaria[2] < 350) // colision extremo superior
	{
		while (jokalaria[2] < 350) jokalaria[2] += aldaketa;
	}
	else if ((jokalaria[1] > 1210) && (jokalaria[2] > 850))
	{
		while (jokalaria[2] > 915) jokalaria[2] -= aldaketa;
	}
	else if ((jokalaria[1] > 840 ) && (jokalaria[1] < 950 )) // colision superior e inferior de la maquina expendedora
	{
		if (jokalaria[2] < 500)
		{
			while (jokalaria[2] > 430) jokalaria[2] -= aldaketa;
		}
		else 
		{
			while (jokalaria[2] < 625) jokalaria[2] += aldaketa;
		}

	}
	else if ((jokalaria[1] > 945) && (jokalaria[1] < 1050)) // colision sup. e inf. primera parte Mac
	{
		if (jokalaria[2] < 500)
		{
			while (jokalaria[2] > 420) jokalaria[2] -= aldaketa;
		}
		else
		{
			while (jokalaria[2] < 575) jokalaria[2] += aldaketa;
		}
	}
	else if ((jokalaria[1] > 1040) && (jokalaria[1] < 1180)) // colision parte baja del Mc
	{
		while (jokalaria[2] < 575) jokalaria[2] += aldaketa;
	}
	else if ((jokalaria[1] > 1180) && (jokalaria[1] < 1240)) // colision superior despues del Mac
	{
		while (jokalaria[2] < 445) jokalaria[2] += aldaketa;
	}
	else if ((jokalaria[1] > 1240)) // colision inferior basuras al lado del rio
	{
		while (jokalaria[2] < 640) jokalaria[2] += aldaketa;
	}

	return;
}

void CiudadAlta_ColisionLateral(int jokalaria[], int aldaketa) {

	if (jokalaria[1] < 200) // colsion extremo izquierdo
	{
		while (jokalaria[1] < 200) jokalaria[1] += aldaketa;
	}
	else if ((jokalaria[1]>820) && (jokalaria[2] < 630) && (jokalaria[2] > 460) && jokalaria[1] < 850) //colision lado de maquinaExp
	{
		while (jokalaria[1] > 830) jokalaria[1] -= aldaketa;
	}
	else if ((jokalaria[1] > 850) && (jokalaria[2] > 525) && (jokalaria[2] < 625) && jokalaria[1] < 960) //colision lado de maquinaExp
	{
		while (jokalaria[1] < 960) jokalaria[1] += aldaketa;
	}
	else if ((jokalaria[1] < 1000) && (jokalaria[2] < 460)) // colision parede alta deL Mc
	{
		while (jokalaria[1] > 985) jokalaria[1] -= aldaketa;
	}
	else if ((jokalaria[1] > 1170) && (jokalaria[2] < 575) && (jokalaria[1] < 1240)) // colision lateral del Mac
	{
		while (jokalaria[1] <= 1185) jokalaria[1] += aldaketa;
	}
	else if (jokalaria[2] < 605) // colision con el rio alta
	{
		while (jokalaria[1] >= 1240) jokalaria[1] -= aldaketa;
	}
	else if (jokalaria[1] > 630)// colision lateral rio inferior
	{
		while (jokalaria[1] > 1310) jokalaria[1] -= aldaketa;
	}

	return;
}

void Invisble_CiudadAlta(int jokalaria[], int aldaketa) {

	int ebentu=0, baldintza=0;

	if ((jokalaria[1] <= 370) && (jokalaria[2] >= 860)) // colisiones del primer edificio
	{
		irudiaKendu(jokalaria[0]);

		jokalaria[7] = 1;

		while ((jokalaria[8] == 0) && (jokalaria[7] == 1))
		{
			ebentu = ebentuaJasoGertatuBada();

			switch (ebentu)
			{
			case TECLA_w:
				jokalaria[2] -= aldaketa;
				break;

			case TECLA_s:
				jokalaria[2] += aldaketa;
				break;

			case TECLA_a:
				jokalaria[1] -= aldaketa;
				break;

			case TECLA_d:
				jokalaria[1] += aldaketa;
				break;

			case TECLA_ESCAPE:
				jokalaria[8] = 1;
				break;

			case TECLA_RETURN:
				jokalaria[8] = 1;
				break;

			case TECLA_p:
				printf("%d, %d\n", jokalaria[1], jokalaria[2]);
				break;

			case TECLA_UP:
				jokalaria[2] -= aldaketa;
				break;

			case TECLA_DOWN:
				jokalaria[2] += aldaketa;
				break;

			case TECLA_RIGHT:
				jokalaria[1] -= aldaketa;
				break;

			case TECLA_LEFT:
				jokalaria[1] += aldaketa;
				break;
			}

			while (jokalaria[1] <= 190) jokalaria[1] += aldaketa; // colison por la izquierda del edificio
			while (jokalaria[2] >= 915)jokalaria[2] -= aldaketa; //colision por la parte baja del edificio

			if ((jokalaria[1] > 370) || (jokalaria[2] < 860)) jokalaria[7] = 0; //si sale del edificio

			pantailaGarbitu();
			irudiakMarraztu();
			pantailaBerriztu();
		}

		if (jokalaria[2] < 860) //Por donde sale
		{
			jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_1); //si sale por arriba

			jokalaria[3] = 1;
		}
		else
		{
			jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_1); //si sale por abajo

			jokalaria[3] = 4;
		}

		jokalaria[4] = 1;
		jokalaria[5] = 0;

		irudiaMugitu(jokalaria[0], jokalaria[1], jokalaria[2]);
	}
	else if ((jokalaria[1] >= 670) && (jokalaria[1] <= 1215) && (jokalaria[2] > 845)) // parte baja del edificio 
	{
		if (jokalaria[7] == 0)
		{
			irudiaKendu(jokalaria[0]);

			jokalaria[7] = 1;
		}
		
		while ((jokalaria[8] == 0) && (jokalaria[7] == 1) && (baldintza == 0))
		{
			ebentu = ebentuaJasoGertatuBada();

			switch (ebentu)
			{
			case TECLA_w:
				jokalaria[2] -= aldaketa;
				break;

			case TECLA_s:
				jokalaria[2] += aldaketa;
				break;

			case TECLA_a:
				jokalaria[1] -= aldaketa;
				break;

			case TECLA_d:
				jokalaria[1] += aldaketa;
				break;

			case TECLA_ESCAPE:
				jokalaria[8] = 1;
				break;

			case TECLA_RETURN:
				jokalaria[8] = 1;
				break;

			case TECLA_p:
				printf("%d, %d\n", jokalaria[1], jokalaria[2]);
				break;

			case TECLA_UP:
				jokalaria[2] -= aldaketa;
				break;

			case TECLA_DOWN:
				jokalaria[2] += aldaketa;
				break;

			case TECLA_RIGHT:
				jokalaria[1] -= aldaketa;
				break;

			case TECLA_LEFT:
				jokalaria[1] += aldaketa;
				break;
			}

			while (jokalaria[2] >= 915)jokalaria[2] -= aldaketa; //colision por la parte baja del edificio

			if (((jokalaria[1] < 670) || (jokalaria[1] > 1215)) && (jokalaria[2] > 850)) jokalaria[7] = 0; //si sale del edificio por los lados (parte baja)
			if ((jokalaria[1] < 900) && (jokalaria[2] < 850)) jokalaria[7] = 0; // si sale de ese edificio por arriba (parte baja);
			else if (jokalaria[2] < 850) baldintza = 1;


			pantailaGarbitu();
			irudiakMarraztu();
			pantailaBerriztu();
		}

		if ((jokalaria[1] < 900) && (jokalaria[2] < 850)) //Por donde sale
		{
			jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_1); //si sale por arriba

			jokalaria[3] = 1;
		}
		else if ((jokalaria[1] < 670) && (jokalaria[2] > 850))
		{
			jokalaria[0] = irudiaKargatu(JOKALARIA_izq_1); //si sale por abajo

			jokalaria[3] = 4;
		}
		else if (baldintza == 0)
		{
			jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_1); //si sale por abajo

			jokalaria[3] = 4;
		}

		if (baldintza==0 )
		{
			jokalaria[4] = 1;
			jokalaria[5] = 0;

			irudiaMugitu(jokalaria[0], jokalaria[1], jokalaria[2]);
		}
	}
	else if ((jokalaria[1] >= 850) && (jokalaria[1] <= 1200) && (jokalaria[2] > 740)) //parte media del edificio
	{
		if (jokalaria[7] == 0)
		{
			irudiaKendu(jokalaria[0]);

			jokalaria[7] = 1;
		}

		while ((jokalaria[8] == 0) && (jokalaria[7] == 1) && (baldintza == 0))
		{
			ebentu = ebentuaJasoGertatuBada();

			switch (ebentu)
			{
			case TECLA_w:
				jokalaria[2] -= aldaketa;
				break;

			case TECLA_s:
				jokalaria[2] += aldaketa;
				break;

			case TECLA_a:
				jokalaria[1] -= aldaketa;
				break;

			case TECLA_d:
				jokalaria[1] += aldaketa;
				break;

			case TECLA_ESCAPE:
				jokalaria[8] = 1;
				break;

			case TECLA_RETURN:
				jokalaria[8] = 1;
				break;

			case TECLA_p:
				printf("%d, %d\n", jokalaria[1], jokalaria[2]);
				break;

			case TECLA_UP:
				jokalaria[2] -= aldaketa;
				break;

			case TECLA_DOWN:
				jokalaria[2] += aldaketa;
				break;

			case TECLA_RIGHT:
				jokalaria[1] -= aldaketa;
				break;

			case TECLA_LEFT:
				jokalaria[1] += aldaketa;
				break;
			}

			if (((jokalaria[1] < 850) || (jokalaria[1] > 1200)) && (jokalaria[2] > 740)) jokalaria[7] = 0; //si sale del edificio por los lados
			if ((jokalaria[1] < 975) && (jokalaria[2] < 740)) jokalaria[7] = 0; // si sale de ese edificio por arriba
			else if ((jokalaria[2] < 740) && (jokalaria[1] > 975)) baldintza = 1;


			pantailaGarbitu();
			irudiakMarraztu();
			pantailaBerriztu();
		}

		if ((jokalaria[1] < 975) && (jokalaria[2] < 740)) //Control de por donde sale
		{
			jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_1); //si sale por arriba

			jokalaria[3] = 1;
		}
		else if ((jokalaria[1] < 850) && (jokalaria[2] > 740))
		{
			jokalaria[0] = irudiaKargatu(JOKALARIA_izq_1); //si sale por abajo

			jokalaria[3] = 4;
		}
		else if ((jokalaria[1] > 1200) && (jokalaria[2] > 740))
		{
			jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_1); //si sale por abajo

			jokalaria[3] = 4;
		}

		if (baldintza == 0)
		{
			jokalaria[4] = 1;
			jokalaria[5] = 0;

			irudiaMugitu(jokalaria[0], jokalaria[1], jokalaria[2]);
		}
	}
	else if ((jokalaria[1] >= 980) && (jokalaria[1] <= 1170) && (jokalaria[2] > 655)) //parte alta del edificio
	{
		if (jokalaria[7] == 0)
		{
			irudiaKendu(jokalaria[0]);

			jokalaria[7] = 1;
		}

		while ((jokalaria[8] == 0) && (jokalaria[7] == 1) && (baldintza == 0))
		{
			ebentu = ebentuaJasoGertatuBada();

			switch (ebentu)
			{
			case TECLA_w:
				jokalaria[2] -= aldaketa;
				break;

			case TECLA_s:
				jokalaria[2] += aldaketa;
				break;

			case TECLA_a:
				jokalaria[1] -= aldaketa;
				break;

			case TECLA_d:
				jokalaria[1] += aldaketa;
				break;

			case TECLA_ESCAPE:
				jokalaria[8] = 1;
				break;

			case TECLA_RETURN:
				jokalaria[8] = 1;
				break;

			case TECLA_p:
				printf("%d, %d\n", jokalaria[1], jokalaria[2]);
				break;

			case TECLA_UP:
				jokalaria[2] -= aldaketa;
				break;

			case TECLA_DOWN:
				jokalaria[2] += aldaketa;
				break;

			case TECLA_RIGHT:
				jokalaria[1] -= aldaketa;
				break;

			case TECLA_LEFT:
				jokalaria[1] += aldaketa;
				break;
			}

			if (((jokalaria[1] < 980) || (jokalaria[1] > 1170)) || (jokalaria[2] < 655)) jokalaria[7] = 0; //si sale del edificio por los lados
			else if (jokalaria[2] > 750) baldintza = 1;


			pantailaGarbitu();
			irudiakMarraztu();
			pantailaBerriztu();
		}

		if (jokalaria[2] < 655) //Control de por donde sale
		{
			jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_1); //si sale por arriba

			jokalaria[3] = 1;
		}
		else if (jokalaria[1] < 980)
		{
			jokalaria[0] = irudiaKargatu(JOKALARIA_izq_1); //si sale por abajo

			jokalaria[3] = 4;
		}
		else if (jokalaria[1] > 1170)
		{
			jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_1); //si sale por abajo

			jokalaria[3] = 4;
		}

		if (baldintza == 0)
		{
			jokalaria[4] = 1;
			jokalaria[5] = 0;

			irudiaMugitu(jokalaria[0], jokalaria[1], jokalaria[2]);
		}
	}

	return;
}

// colisiones Bosque Bajo

void BosqueBajo_ColisionesVerticales(int jokalaria[], int aldaketa)
{
	if (jokalaria[1] > 1700) // colision borde derecho
	{
		while (jokalaria[1] > 1700) jokalaria[1] -= aldaketa;
	}
	else if (jokalaria[2] < 510) // colision parte alta del rio
	{
		while (jokalaria[1] < 470) jokalaria[1] += aldaketa;
	}
	else if (jokalaria[1] < 470) // colision por la parte baja el rio
	{
		if ((jokalaria[2] > 840) || (jokalaria[2] < 700))
		{
			while (jokalaria[1] < 250) jokalaria[1] += aldaketa;
		}
	}
}

void BosqueBajo_ColisionesHorizontales(int jokalaria[], int aldaketa)
{
	if (jokalaria[2] < 110) // colision superior del bosque
	{
		while (jokalaria[2] < 110) jokalaria[2] += aldaketa;
	}
	else if (jokalaria[2] > 910) // colision inferior del bosque
	{
		while (jokalaria[2] > 910) jokalaria[2] -= aldaketa;
	}
	else if (jokalaria[1] < 470) // colision en el rio
	{
		while (jokalaria[2] < 515) jokalaria[2] += aldaketa;
	}
}

// colisiones Bosque Alto

void BosqueAlto(int jokalaria[], int aldaketa) {

	if (jokalaria[1] <= 490)
	{
		while (jokalaria[1] < 490) jokalaria[1] += aldaketa;
	}
	else if ((jokalaria[1] <= 660) && (jokalaria[2] < 260))
	{
		while (jokalaria[1] <= 660) jokalaria[1] += aldaketa;
	}
	else if ((jokalaria[1]>=880)&&(jokalaria[2] < 260))
	{
		while (jokalaria[1] >= 880) jokalaria[1] -= aldaketa;
	}
	else
	{
		while (jokalaria[1] > 1700) jokalaria[1] -= aldaketa;
	}

	if (jokalaria[2] > 915)
	{
		while (jokalaria[2] > 915) jokalaria[2] -= aldaketa;
	}
	else if ((jokalaria[1] < 660) || (jokalaria[1] > 800))
	{
		while (jokalaria[2] < 280) jokalaria[2] += aldaketa;
	}
	else
	{
		while (jokalaria[2] < 110) jokalaria[2] += aldaketa;
	}

	return;
}
