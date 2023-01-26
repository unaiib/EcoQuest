#ifndef SPRITE_H
#define SPRITE_H

#include "funtzioak.h"
#include "mugimenduak.h"
#include "OurTypes.h"
#include "EbentuaKargatu.h"

// fotos del personaje (pequeño)

#define JOKALARIA_behera_1 ".\\img\\personaje\\TXIKI\\1\\aurretik_1.bmp"
#define JOKALARIA_izq_1 ".\\img\\personaje\\TXIKI\\1\\izquierda_1.bmp"
#define JOKALARIA_dcha_1 ".\\img\\personaje\\TXIKI\\1\\derecha_1.bmp"
#define JOKALARIA_gorantz_1 ".\\img\\personaje\\TXIKI\\1\\atzetik_1.bmp"

#define JOKALARIA_behera_2 ".\\img\\personaje\\TXIKI\\2\\aurretik_2.bmp"
#define JOKALARIA_izq_2 ".\\img\\personaje\\TXIKI\\2\\izquierda_2.bmp"
#define JOKALARIA_dcha_2 ".\\img\\personaje\\TXIKI\\2\\derecha_2.bmp"
#define JOKALARIA_gorantz_2 ".\\img\\personaje\\TXIKI\\2\\atzetik_2.bmp"

#define JOKALARIA_behera_3 ".\\img\\personaje\\TXIKI\\3\\aurretik_3.bmp"
#define JOKALARIA_izq_3 ".\\img\\personaje\\TXIKI\\3\\izquierda_3.bmp"
#define JOKALARIA_dcha_3 ".\\img\\personaje\\TXIKI\\3\\derecha_3.bmp"
#define JOKALARIA_gorantz_3 ".\\img\\personaje\\TXIKI\\3\\atzetik_3.bmp"

#define JOKALARIA_behera_4 ".\\img\\personaje\\TXIKI\\4\\aurretik_4.bmp"
#define JOKALARIA_izq_4 ".\\img\\personaje\\TXIKI\\4\\izquierda_4.bmp"
#define JOKALARIA_dcha_4 ".\\img\\personaje\\TXIKI\\4\\derecha_4.bmp"
#define JOKALARIA_gorantz_4 ".\\img\\personaje\\TXIKI\\4\\atzetik_4.bmp"

#define JOKALARIA_behera_5 ".\\img\\personaje\\TXIKI\\5\\aurretik_5.bmp"
#define JOKALARIA_izq_5 ".\\img\\personaje\\TXIKI\\5\\izquierda_5.bmp"
#define JOKALARIA_dcha_5 ".\\img\\personaje\\TXIKI\\5\\derecha_5.bmp"
#define JOKALARIA_gorantz_5 ".\\img\\personaje\\TXIKI\\5\\atzetik_5.bmp"

#define JOKALARIA_behera_6 ".\\img\\personaje\\TXIKI\\6\\aurretik_6.bmp"
#define JOKALARIA_izq_6 ".\\img\\personaje\\TXIKI\\6\\izquierda_6.bmp"
#define JOKALARIA_dcha_6 ".\\img\\personaje\\TXIKI\\6\\derecha_6.bmp"
#define JOKALARIA_gorantz_6 ".\\img\\personaje\\TXIKI\\6\\atzetik_6.bmp"

#define JOKALARIA_behera_7 ".\\img\\personaje\\TXIKI\\7\\aurretik_7.bmp"
#define JOKALARIA_izq_7 ".\\img\\personaje\\TXIKI\\7\\izquierda_7.bmp"
#define JOKALARIA_dcha_7 ".\\img\\personaje\\TXIKI\\7\\derecha_7.bmp"
#define JOKALARIA_gorantz_7 ".\\img\\personaje\\TXIKI\\7\\atzetik_7.bmp"

#define JOKALARIA_behera_8 ".\\img\\personaje\\TXIKI\\8\\aurretik_8.bmp"
#define JOKALARIA_izq_8 ".\\img\\personaje\\TXIKI\\8\\izquierda_8.bmp"
#define JOKALARIA_dcha_8 ".\\img\\personaje\\TXIKI\\8\\derecha_8.bmp"
#define JOKALARIA_gorantz_8 ".\\img\\personaje\\TXIKI\\8\\atzetik_8.bmp"

#define JOKALARIA_behera_9 ".\\img\\personaje\\TXIKI\\9\\aurretik_9.bmp"
#define JOKALARIA_izq_9 ".\\img\\personaje\\TXIKI\\9\\izquierda_9.bmp"
#define JOKALARIA_dcha_9 ".\\img\\personaje\\TXIKI\\9\\derecha_9.bmp"
#define JOKALARIA_gorantz_9 ".\\img\\personaje\\TXIKI\\9\\atzetik_9.bmp"


//fotos del personaje (grande)


#define JOKALARIHANDIA_behera_1 ".\\img\\personaje\\HANDI\\1\\aurretik_1.bmp"
#define JOKALARIHANDIA_izq_1 ".\\img\\personaje\\HANDI\\1\\izquierda_1.bmp"
#define JOKALARIHANDIA_dcha_1 ".\\img\\personaje\\HANDI\\1\\derecha_1.bmp"
#define JOKALARIHANDIA_gorantz_1 ".\\img\\personaje\\HANDI\\1\\atzetik_1.bmp"

#define JOKALARIHANDIA_behera_2 ".\\img\\personaje\\HANDI\\2\\aurretik_2.bmp"
#define JOKALARIHANDIA_izq_2 ".\\img\\personaje\\HANDI\\2\\izquierda_2.bmp"
#define JOKALARIHANDIA_dcha_2 ".\\img\\personaje\\HANDI\\2\\derecha_2.bmp"
#define JOKALARIHANDIA_gorantz_2 ".\\img\\personaje\\HANDI\\2\\atzetik_2.bmp"

#define JOKALARIHANDIA_behera_3 ".\\img\\personaje\\HANDI\\3\\aurretik_3.bmp"
#define JOKALARIHANDIA_izq_3 ".\\img\\personaje\\HANDI\\3\\izquierda_3.bmp"
#define JOKALARIHANDIA_dcha_3 ".\\img\\personaje\\HANDI\\3\\derecha_3.bmp"
#define JOKALARIHANDIA_gorantz_3 ".\\img\\personaje\\HANDI\\3\\atzetik_3.bmp"

#define JOKALARIHANDIA_behera_4 ".\\img\\personaje\\HANDI\\4\\aurretik_4.bmp"
#define JOKALARIHANDIA_izq_4 ".\\img\\personaje\\HANDI\\4\\izquierda_4.bmp"
#define JOKALARIHANDIA_dcha_4 ".\\img\\personaje\\HANDI\\4\\derecha_4.bmp"
#define JOKALARIHANDIA_gorantz_4 ".\\img\\personaje\\HANDI\\4\\atzetik_4.bmp"

#define JOKALARIHANDIA_behera_5 ".\\img\\personaje\\HANDI\\5\\aurretik_5.bmp"
#define JOKALARIHANDIA_izq_5 ".\\img\\personaje\\HANDI\\5\\izquierda_5.bmp"
#define JOKALARIHANDIA_dcha_5 ".\\img\\personaje\\HANDI\\5\\derecha_5.bmp"
#define JOKALARIHANDIA_gorantz_5 ".\\img\\personaje\\HANDI\\5\\atzetik_5.bmp"

#define JOKALARIHANDIA_behera_6 ".\\img\\personaje\\HANDI\\6\\aurretik_6.bmp"
#define JOKALARIHANDIA_izq_6 ".\\img\\personaje\\HANDI\\6\\izquierda_6.bmp"
#define JOKALARIHANDIA_dcha_6 ".\\img\\personaje\\HANDI\\6\\derecha_6.bmp"
#define JOKALARIHANDIA_gorantz_6 ".\\img\\personaje\\HANDI\\6\\atzetik_6.bmp"

#define JOKALARIHANDIA_behera_7 ".\\img\\personaje\\HANDI\\7\\aurretik_7.bmp"
#define JOKALARIHANDIA_izq_7 ".\\img\\personaje\\HANDI\\7\\izquierda_7.bmp"
#define JOKALARIHANDIA_dcha_7 ".\\img\\personaje\\HANDI\\7\\derecha_7.bmp"
#define JOKALARIHANDIA_gorantz_7 ".\\img\\personaje\\HANDI\\7\\atzetik_7.bmp"

#define JOKALARIHANDIA_behera_8 ".\\img\\personaje\\HANDI\\8\\aurretik_8.bmp"
#define JOKALARIHANDIA_izq_8 ".\\img\\personaje\\HANDI\\8\\izquierda_8.bmp"
#define JOKALARIHANDIA_dcha_8 ".\\img\\personaje\\HANDI\\8\\derecha_8.bmp"
#define JOKALARIHANDIA_gorantz_8 ".\\img\\personaje\\HANDI\\8\\atzetik_8.bmp"

#define JOKALARIHANDIA_behera_9 ".\\img\\personaje\\HANDI\\9\\aurretik_9.bmp"
#define JOKALARIHANDIA_izq_9 ".\\img\\personaje\\HANDI\\9\\izquierda_9.bmp"
#define JOKALARIHANDIA_dcha_9 ".\\img\\personaje\\HANDI\\9\\derecha_9.bmp"
#define JOKALARIHANDIA_gorantz_9 ".\\img\\personaje\\HANDI\\9\\atzetik_9.bmp"

#endif