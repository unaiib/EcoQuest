#include "OurTypes.h"
#include "funtzioak.h"
#include "Mugimenduak.h"
#include "Sprite.h"
#include "Mapak.h"
#include "EbentuaKargatu.h"

void jokalariaKargatu(int jokalaria[]) {

	jokalaria[1] = 300; // coordenada inicial x
	jokalaria[2] = 700; // coordenada inicial y
	jokalaria[3] = 2; // numero de la direccion (1-arriba, 2-abajo, 3-izquierda, 4-derecha)
	jokalaria[4] = 1; // numero de sprite
	jokalaria[5] = 0; // variable cambio de sprite
	jokalaria[6] = 0; // tamaño del personaje (0- grande, 1- pequeño)
	jokalaria[7] = 0; // invisibilidad
	jokalaria[8] = 0; // condicion salida del juego
	jokalaria[9] = 0; // variable carga ebento

	jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_behera_1);; // crea la foto y guarda la id en [0], pone la imagen por defecto
	irudiaMugitu(jokalaria[0], jokalaria[1], jokalaria[2]); //mueve la foto a las coordenadas iniciales

	return;
}

void jokalariaMugitu(int jokalaria[]) {

	int ebentu = 0, abiadura=10;

	ebentu = ebentuaJasoGertatuBada();

	switch (ebentu) //segun que tecla se haya pulsado
	{
		case TECLA_a: //izquierda = 3
		{
			if (jokalaria[3] == 3)// si el personaje sigue misma direccion
			{
				mugituBerriz(jokalaria, -abiadura, 0);// mover y cambiar sprite
			}
			else // si es la primera vez que hace el movimiento
			{
				irudiaKendu(jokalaria[0]); //quita la imagen anterior

				if (jokalaria[6] == 0) jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_izq_1); //imagen por defecto del movimiento (grandew)
				else jokalaria[0] = irudiaKargatu(JOKALARIA_izq_1);//imagen por defecto del movimiento (pequeño)

				mugimenduaBehin(jokalaria, -abiadura, 0, 3); //mover la imagen y realizar cambios en jokalaria
			}
		}break;

		case TECLA_LEFT: //izquierda = 3 (FLECHAS)
		{
			if (jokalaria[3] == 3)// si el personaje sigue misma direccion
			{
				mugituBerriz(jokalaria, -abiadura, 0);// mover y cambiar sprite
			}
			else // si es la primera vez que hace el movimiento
			{
				irudiaKendu(jokalaria[0]); //quita la imagen anterior

				if (jokalaria[6] == 0) jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_izq_1); //imagen por defecto del movimiento (grandew)
				else jokalaria[0] = irudiaKargatu(JOKALARIA_izq_1);//imagen por defecto del movimiento (pequeño)

				mugimenduaBehin(jokalaria, -abiadura, 0, 3); //mover la imagen y realizar cambios en jokalaria
			}
		}break;

		case TECLA_d: //derecha = 4 
		{
			if (jokalaria[3] == 4)// si el personaje sigue misma direccion
			{
				mugituBerriz(jokalaria, abiadura, 0);// mover y cambiar sprite
			}
			else // si es la primera vez que hace el movimiento
			{
				irudiaKendu(jokalaria[0]); //quita la imagen anterior

				if (jokalaria[6] == 0) jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_dcha_1); //imagen por defecto del movimiento (grandew)
				else jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_1);//imagen por defecto del movimiento (pequeño)

				mugimenduaBehin(jokalaria, abiadura, 0, 4);//mover la imagen y realizar cambios en jokalaria
			}
		}break;

		case TECLA_RIGHT: //derecha = 4 (FLECHAS)
		{
			if (jokalaria[3] == 4)// si el personaje sigue misma direccion
			{
				mugituBerriz(jokalaria, abiadura, 0);// mover y cambiar sprite
			}
			else // si es la primera vez que hace el movimiento
			{
				irudiaKendu(jokalaria[0]); //quita la imagen anterior

				if (jokalaria[6] == 0) jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_dcha_1); //imagen por defecto del movimiento (grandew)
				else jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_1);//imagen por defecto del movimiento (pequeño)

				mugimenduaBehin(jokalaria, abiadura, 0, 4);//mover la imagen y realizar cambios en jokalaria
			}
		}break;

		case TECLA_w: //gorantz = 1
		{
			if (jokalaria[3] == 1) // si el personaje sigue misma direccion
			{
				mugituBerriz(jokalaria, 0, -abiadura);// mover y cambiar sprite
			}
			else// si es la primera vez que hace el movimiento
			{
				irudiaKendu(jokalaria[0]);//quita la imagen anterior

				if (jokalaria[6] == 0) jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_gorantz_1); //imagen por defecto del movimiento (grandew)
				else jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_1);//imagen por defecto del movimiento (pequeño)

				mugimenduaBehin(jokalaria, 0, -abiadura, 1);//mover la imagen y realizar cambios en jokalaria
			}
		}break;

		case TECLA_UP: //gorantz = 1 (FLECHAS)
		{
			if (jokalaria[3] == 1) // si el personaje sigue misma direccion
			{
				mugituBerriz(jokalaria, 0, -abiadura);// mover y cambiar sprite
			}
			else// si es la primera vez que hace el movimiento
			{
				irudiaKendu(jokalaria[0]);//quita la imagen anterior

				if (jokalaria[6] == 0) jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_gorantz_1); //imagen por defecto del movimiento (grandew)
				else jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_1);//imagen por defecto del movimiento (pequeño)

				mugimenduaBehin(jokalaria, 0, -abiadura, 1);//mover la imagen y realizar cambios en jokalaria
			}
		}break;

		case TECLA_s: //beherantz = 2
		{
			if (jokalaria[3] == 2) // si el personaje sigue misma direccion
			{
				mugituBerriz(jokalaria, 0, abiadura);// mover y cambiar sprite
			}
			else // si es la primera vez que hace el movimiento
			{
				irudiaKendu(jokalaria[0]);//quita la imagen anterior

				if (jokalaria[6] == 0) jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_behera_1); //imagen por defecto del movimiento (grandew)
				else jokalaria[0] = irudiaKargatu(JOKALARIA_behera_1);//imagen por defecto del movimiento (pequeño)

				mugimenduaBehin(jokalaria, 0, abiadura, 2);//mover la imagen y realizar cambios en jokalaria
			}
		}break;

		case TECLA_DOWN: //beherantz = 2 (FLECHAS)
		{
			if (jokalaria[3] == 2) // si el personaje sigue misma direccion
			{
				mugituBerriz(jokalaria, 0, abiadura);// mover y cambiar sprite
			}
			else // si es la primera vez que hace el movimiento
			{
				irudiaKendu(jokalaria[0]);//quita la imagen anterior

				if (jokalaria[6] == 0) jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_behera_1); //imagen por defecto del movimiento (grandew)
				else jokalaria[0] = irudiaKargatu(JOKALARIA_behera_1);//imagen por defecto del movimiento (pequeño)

				mugimenduaBehin(jokalaria, 0, abiadura, 2);//mover la imagen y realizar cambios en jokalaria
			}
		}break;

		case TECLA_ESCAPE:
		{
			jokalaria[8] = 1; //condicion de salida 
		}break;

		case TECLA_p:
		{
			printf("%d, %d\n", jokalaria[1], jokalaria[2]);
		}break;

		case TECLA_e:
		{
			jokalaria[9] = 1;
		}break;
	}

	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return;
}

void mugimenduaBehin(int jokalaria[], int x, int y, int aldaketa) { //primera vez que realiza el movimiento

	if (jokalaria[6] == 0) //Si esta en grande
	{
		jokalaria[1] += x; //cambio en x grande
		jokalaria[2] += y; //cambio en y grande
	}
	else // si esta en pequeño
	{
		jokalaria[1] += x/2; //cambio en x del pequeño
		jokalaria[2] += y/2; //cambio en y del pequeño
	}

	jokalaria[3] = aldaketa; // nuevo numero de dirreccion (1-arriba, 2-abajo, 3-izquierda, 4-derecha)
	jokalaria[4] = 1; // numero de sprite (reseteado)
	jokalaria[5] = 0; // variable cambio de sprite (reseteado)

	irudiaMugitu(jokalaria[0], jokalaria[1], jokalaria[2]); // mueve la imgen a las nuevas coordenadas

	return;
}

void mugituBerriz(int jokalaria[], int x, int y) {

	irudiaKendu(jokalaria[0]); //borrar imagen anterior

	if (jokalaria[6] == 0) //Si esta en grande
	{
		jokalaria[1] += x; //cambio en x grande
		jokalaria[2] += y; //cambio en y grande

		SpritaHandiaSortu(jokalaria); //cambiar sprite grande
	}
	else // si esta en pequeño
	{
		jokalaria[1] += x / 2; //cambio en x del pequeño
		jokalaria[2] += y / 2; //cambio en y del pequeño

		SpritaSortu(jokalaria); // cambiar sprite pequeño
	}
	
	Aldaketak(jokalaria); //guardar cambios

	irudiaMugitu(jokalaria[0], jokalaria[1], jokalaria[2]); // mover imagen a las nuevas coordenadas

	return;
}

void SpritaSortu(int jokalaria[]) {

	switch (jokalaria[3]) // segun la direccion
	{
		case 1: // gorantz
		{
			switch (jokalaria[4]) // segun el numero de sprite
			{
				case 1:
					jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_1);				
				break;

				case 2:
					jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_2);					
				break;

				case 3:
					jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_3);
					break;

				case 4:
					jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_4);
					break;

				case 5:
					jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_5);
					break;

				case 6:
					jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_6);
					break;

				case 7:
					jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_7);
					break;

				case 8:
					jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_8);
					break;

				case 9:
					jokalaria[0] = irudiaKargatu(JOKALARIA_gorantz_9);
					break;
			}
		}break;

		case 2: // beherantz
		{
			switch (jokalaria[4]) // segun el numero de sprite
			{
				case 1:
					jokalaria[0] = irudiaKargatu(JOKALARIA_behera_1);
				break;

				case 2:
					jokalaria[0] = irudiaKargatu(JOKALARIA_behera_2);
				break;

				case 3:
					jokalaria[0] = irudiaKargatu(JOKALARIA_behera_3);
				break;

				case 4:
					jokalaria[0] = irudiaKargatu(JOKALARIA_behera_4);
				break;

				case 5:
					jokalaria[0] = irudiaKargatu(JOKALARIA_behera_5);
				break;

				case 6:
					jokalaria[0] = irudiaKargatu(JOKALARIA_behera_6);
				break;

				case 7:
					jokalaria[0] = irudiaKargatu(JOKALARIA_behera_7);
				break;

				case 8:
					jokalaria[0] = irudiaKargatu(JOKALARIA_behera_8);
				break;

				case 9:
					jokalaria[0] = irudiaKargatu(JOKALARIA_behera_9);
				break;
			}
		}break;

		case 3:// izquierda
		{
			switch (jokalaria[4])// segun el numero de sprite
			{
				case 1:
					jokalaria[0] = irudiaKargatu(JOKALARIA_izq_1);
				break;

				case 2:
					jokalaria[0] = irudiaKargatu(JOKALARIA_izq_2);
				break;

				case 3:
					jokalaria[0] = irudiaKargatu(JOKALARIA_izq_3);
				break;

				case 4:
					jokalaria[0] = irudiaKargatu(JOKALARIA_izq_4);
				break;

				case 5:
					jokalaria[0] = irudiaKargatu(JOKALARIA_izq_5);
				break;

				case 6:
					jokalaria[0] = irudiaKargatu(JOKALARIA_izq_6);
				break;

				case 7:
					jokalaria[0] = irudiaKargatu(JOKALARIA_izq_7);
				break;

				case 8:
					jokalaria[0] = irudiaKargatu(JOKALARIA_izq_8);
				break;

				case 9:
					jokalaria[0] = irudiaKargatu(JOKALARIA_izq_9);
				break;
			}
		}break;

		case 4://derecha
		{
			switch (jokalaria[4])// segun el numero de sprite
			{
				case 1:
					jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_1);
				break;

				case 2:
					jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_2);
				break;

				case 3:
					jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_3);
				break;

				case 4:
					jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_4);
				break;

				case 5:
					jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_5);
				break;

				case 6:
					jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_6);
				break;

				case 7:
					jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_7);
				break;

				case 8:
					jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_8);
				break;

				case 9:
					jokalaria[0] = irudiaKargatu(JOKALARIA_dcha_9);
				break;
			}
		}break;
	}

	return;
}

void SpritaHandiaSortu(int jokalaria[]) {

	switch (jokalaria[3]) // segun la direccion
	{
		case 1: // gorantz
		{
			switch (jokalaria[4]) // segun el numero de sprite
			{
				case 1:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_gorantz_1);
				break;

				case 2:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_gorantz_2);
				break;

				case 3:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_gorantz_3);
				break;

				case 4:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_gorantz_4);
				break;
	
				case 5:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_gorantz_5);
				break;

				case 6:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_gorantz_6);
				break;

				case 7:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_gorantz_7);
				break;

				case 8:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_gorantz_8);
				break;

				case 9:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_gorantz_9);
				break;
			}
		}break;

		case 2: // beherantz
		{
			switch (jokalaria[4]) // segun el numero de sprite
			{
				case 1:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_behera_1);
				break;

				case 2:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_behera_2);
				break;

				case 3:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_behera_3);
				break;

				case 4:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_behera_4);
				break;

				case 5:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_behera_5);
				break;

				case 6:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_behera_6);
				break;

				case 7:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_behera_7);
				break;

				case 8:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_behera_8);
				break;

				case 9:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_behera_9);
				break;
			}
		}break;

		case 3:// izquierda
		{
			switch (jokalaria[4])// segun el numero de sprite
			{
				case 1:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_izq_1);
				break;

				case 2:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_izq_2);
				break;

				case 3:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_izq_3);
				break;

				case 4:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_izq_4);
				break;

				case 5:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_izq_5);
				break;

				case 6:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_izq_6);
				break;

				case 7:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_izq_7);
				break;

				case 8:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_izq_8);
				break;

				case 9:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_izq_9);
				break;
			}
		}break;

		case 4://derecha
		{
			switch (jokalaria[4])// segun el numero de sprite
			{
				case 1:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_dcha_1);
				break;
	
				case 2:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_dcha_2);
				break;

				case 3:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_dcha_3);
				break;

				case 4:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_dcha_4);
				break;

				case 5:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_dcha_5);
				break;

				case 6:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_dcha_6);
				break;

				case 7:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_dcha_7);
				break;

				case 8:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_dcha_8);
				break;

				case 9:
					jokalaria[0] = irudiaKargatu(JOKALARIHANDIA_dcha_9);
				break;
			}
		}break;
	}

	return;
}

void Aldaketak(int jokalaria[]) {

	jokalaria[5]++; //cambiar variable de cambio de sprite

	if (jokalaria[6] == 0) //cambio del sprite grande
	{
		if (jokalaria[5] % 3 == 0) // condicion para que pase al siguiente sprite ( control velocidad cambio sprites)
		{
			jokalaria[5] = 0; // si la cumple la reseteamos

			if (jokalaria[4] == 9) // si estabamos en el ultimo sprite de la "fila"
			{
				jokalaria[4] = 1; // se vuelve al primero
			}
			else
			{
				jokalaria[4]++; // si no solo cambiamos al siguiente
			}
		}
	}
	else //cambio del sprite pequeño
	{
		if (jokalaria[5] % 2 == 0) // condicion para que pase al siguiente sprite ( control velocidad cambio sprites)
		{
			jokalaria[5] = 0; // si la cumple la reseteamos

			if (jokalaria[4] == 9) // si estabamos en el ultimo sprite de la "fila"
			{
				jokalaria[4] = 1; // se vuelve al primero
			}
			else
			{
				jokalaria[4]++; // si no solo cambiamos al siguiente
			}
		}
	}
	return;
}