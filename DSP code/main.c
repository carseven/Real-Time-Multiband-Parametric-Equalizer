/****************************************************************************/
/*                                                                			*/
/* TRATAMIENTO DIGITAL DE SEÑALES											*/
/* GRADO EN INGENIERÍA ELECTRÓNICA DE TELECOMUNICACIONES					*/
/* 																			*/
/* ------------------------------------------------------------------------ */
/* 																			*/
/* PROYECTO TDS 2019 - ECUALIZADOR PARAMETRICO MULTIBANDA EN PARALELO       */
/* 																			*/
/* ------------------------------------------------------------------------ */
/* 																			*/
/* AUTORES:																	*/
/*																			*/
/* CARLES SERRA VENDRELL													*/
/* JORDI FERRANDO VILA										                */
/*                                                                          */
/****************************************************************************/

#include "stdio.h"
#include "usbstk5515.h"
#include "usbstk5515_led.h"
#include "aic3204.h"
#include "PLL.h"
#include "bargraph.h"
#include "oled.h"
#include "pushbuttons.h"
#include "stereo.h"
#include "dsplib.h"
#include "math.h"
#include "stdbool.h"

//Importamos coeficientes de los filtros

#include "Llano.h"
#include "Rock.h"
#include "Dance.h"
#include "Techno.h"
#include "Pop.h"
#include "Clasica.h"
#include "Vivo.h"
#include "BassBoost.h"
#include "Treble.h"
#include "BassTreble.h"
#include "Auriculares.h"

/****************************************************************************/
/* DECLARACIÓN DE VARIABLES													*/
/****************************************************************************/

// Variables de audio
Int16 left_input;
Int16 right_input;
Int16 left_output;
Int16 right_output;
Int16 mono_input;

// Frecuencia de muestreo
#define SAMPLES_PER_SECOND 48000 	// Fm = 48000 kHz

// Ganancia
#define GAIN_IN_dB 0 				// Ganancia = 0 dB

// Superbucle
unsigned long int i = 0;

// Inicializamos Steps
unsigned int Step = 0;
unsigned int LastStep = 99;


// Iniciamos varaibles main
int j;
DATA y;
DATA dbuffer[N+2];
DATA x;
Int16 Parametric[N];

/****************************************************************************/
/* MAIN  																	*/
/****************************************************************************/

void main( void )


{
	/* Initialize BSL */
    USBSTK5515_init( );

	/* Initialize PLL */
	pll_frequency_setup(120);

    /* Initialise hardware interface and I2C for code */
    aic3204_hardware_init();

    /* Initialise the AIC3204 codec */
	aic3204_init();

	/* Turn off the 4 coloured LEDs */
	USBSTK5515_ULED_init();
	
	/* Initialise the OLED LCD display */
	oled_init();
	SAR_init();

	/* Setup sampling frequency 	and 30dB gain for microphone */
    set_sampling_frequency_and_gain(SAMPLES_PER_SECOND, GAIN_IN_dB);

    /* Default to XF LED off */
	asm(" bclr XF");

// SUPERBUCLE

	for ( i = 0  ; i < SAMPLES_PER_SECOND * 600L  ; i++ )
 	{

		// Lee la entrada de audio
		aic3204_codec_read(&left_input, &right_input); // Configured for one interrupt per two channels.

		// Convierte la señal stereo en mono
		mono_input = stereo_to_mono(left_input, right_input);

		// Numero de steps que tendremos.
		Step = pushbuttons_read(12);

// MODO 1: SALIDA = ENTRADA

		if ( Step == 1 )
		{
			if ( Step != LastStep )
			{
				oled_display_message("TDS  SERRA/FERRANDO", "1. SALIDA = ENTRADA");
				LastStep = Step;
			}

			// Salida = Entrada
			right_output = right_input;
			left_output =  left_input;
		}

// MODO 2: LLANO

		else if ( Step == 2 )
		{
			if ( Step != LastStep )
			{
				oled_display_message("TDS  SERRA/FERRANDO", "2. LLANO           ");
				LastStep = Step;
				for(j = 0; j < N; j++) Parametric[j] = Llano[j];			// Convertimos coefs a INT16 guardandolo en una variable.
			}
			x = mono_input;												// Muestra que entrara en el filtro.
			fir(&x, Parametric, &y, dbuffer, 1, N);						// Aplicamos filtro FIR.
			right_output = y;											// Sacamos por la salida el resultado de la conv.
			left_output =  right_output;								// Salida izquierda lo mismo que derecha. MONO

		}

// MODO 3: Rock

		else if ( Step == 3 )
		{
			if ( Step != LastStep )
			{
				oled_display_message("TDS  SERRA/FERRANDO", "3. Rock               ");
				LastStep = Step;
				for(j = 0; j < N; j++) Parametric[j] = Rock[j];	// Convertimos coefs a INT16 guardandolo en una variable.
			}
			x = mono_input;												// Muestra que entrara en el filtro.
			fir(&x, Parametric, &y, dbuffer, 1, N);						// Aplicamos filtro FIR.
			right_output = y;											// Sacamos por la salida el resultado de la conv.
			left_output =  right_output;								// Salida izquierda lo mismo que derecha. MONO

		}

// MODO 4: DANCE

		else if ( Step == 4 )
		{
			if ( Step != LastStep )
			{
				oled_display_message("TDS  SERRA/FERRANDO", "4. Dance               ");
				LastStep = Step;
				for(j = 0; j < N; j++) Parametric[j] = Dance[j];	// Convertimos coefs a INT16 guardandolo en una variable.
			}
			x = mono_input;												// Muestra que entrara en el filtro.
			fir(&x, Parametric, &y, dbuffer, 1, N);						// Aplicamos filtro FIR.
			right_output = y;											// Sacamos por la salida el resultado de la conv.
			left_output =  right_output;								// Salida izquierda lo mismo que derecha. MONO

		}

// MODO 5: TECHNO

		else if ( Step == 5 )
		{
			if ( Step != LastStep )
			{
				oled_display_message("TDS  SERRA/FERRANDO", "5. Techno               ");
				LastStep = Step;
				for(j = 0; j < N; j++) Parametric[j] = Techno[j];	// Convertimos coefs a INT16 guardandolo en una variable.
			}
			x = mono_input;												// Muestra que entrara en el filtro.
			fir(&x, Parametric, &y, dbuffer, 1, N);						// Aplicamos filtro FIR.
			right_output = y;											// Sacamos por la salida el resultado de la conv.
			left_output =  right_output;								// Salida izquierda lo mismo que derecha. MONO

		}

// MODO 6: POP

		else if ( Step == 6 )
		{
			if ( Step != LastStep )
			{
				oled_display_message("TDS  SERRA/FERRANDO", "6. Pop                   ");
				LastStep = Step;
				for(j = 0; j < N; j++) Parametric[j] = Pop[j];	// Convertimos coefs a INT16 guardandolo en una variable.
			}
			x = mono_input;												// Muestra que entrara en el filtro.
			fir(&x, Parametric, &y, dbuffer, 1, N);						// Aplicamos filtro FIR.
			right_output = y;											// Sacamos por la salida el resultado de la conv.
			left_output =  right_output;								// Salida izquierda lo mismo que derecha. MONO

		}

// MODO 7: CLASICA

		else if ( Step == 7 )
		{
			if ( Step != LastStep )
			{
				oled_display_message("TDS  SERRA/FERRANDO", "7. Clasica                   ");
				LastStep = Step;
				for(j = 0; j < N; j++) Parametric[j] = Clasica[j];	// Convertimos coefs a INT16 guardandolo en una variable.
			}
			x = mono_input;												// Muestra que entrara en el filtro.
			fir(&x, Parametric, &y, dbuffer, 1, N);						// Aplicamos filtro FIR.
			right_output = y;											// Sacamos por la salida el resultado de la conv.
			left_output =  right_output;								// Salida izquierda lo mismo que derecha. MONO

		}

// MODO 8: VIVO

		else if ( Step == 8 )
		{
			if ( Step != LastStep )
			{
				oled_display_message("TDS  SERRA/FERRANDO", "8. Vivo                   ");
				LastStep = Step;
				for(j = 0; j < N; j++) Parametric[j] = Vivo[j];	// Convertimos coefs a INT16 guardandolo en una variable.
			}
			x = mono_input;												// Muestra que entrara en el filtro.
			fir(&x, Parametric, &y, dbuffer, 1, N);						// Aplicamos filtro FIR.
			right_output = y;											// Sacamos por la salida el resultado de la conv.
			left_output =  right_output;								// Salida izquierda lo mismo que derecha. MONO

		}

// MODO 9: BASSBOST

		else if ( Step == 9 )
		{
			if ( Step != LastStep )
			{
				oled_display_message("TDS  SERRA/FERRANDO", "9. Bass Boost                   ");
				LastStep = Step;
				for(j = 0; j < N; j++) Parametric[j] = BassBoost[j];	// Convertimos coefs a INT16 guardandolo en una variable.
			}
			x = mono_input;												// Muestra que entrara en el filtro.
			fir(&x, Parametric, &y, dbuffer, 1, N);						// Aplicamos filtro FIR.
			right_output = y;											// Sacamos por la salida el resultado de la conv.
			left_output =  right_output;								// Salida izquierda lo mismo que derecha. MONO

		}

// MODO 10: TREBLE

		else if ( Step == 10 )
		{
			if ( Step != LastStep )
			{
				oled_display_message("TDS  SERRA/FERRANDO", "10. Treble                 ");
				LastStep = Step;
				for(j = 0; j < N; j++) Parametric[j] = Treble[j];	// Convertimos coefs a INT16 guardandolo en una variable.
			}
			x = mono_input;												// Muestra que entrara en el filtro.
			fir(&x, Parametric, &y, dbuffer, 1, N);						// Aplicamos filtro FIR.
			right_output = y;											// Sacamos por la salida el resultado de la conv.
			left_output =  right_output;								// Salida izquierda lo mismo que derecha. MONO

		}

// MODO 11: BASSTREBLE

		else if ( Step == 11 )
		{
			if ( Step != LastStep )
			{
				oled_display_message("TDS  SERRA/FERRANDO", "11. BassTreble                 ");
				LastStep = Step;
				for(j = 0; j < N; j++) Parametric[j] = BassTreble[j];	// Convertimos coefs a INT16 guardandolo en una variable.
			}
			x = mono_input;												// Muestra que entrara en el filtro.
			fir(&x, Parametric, &y, dbuffer, 1, N);						// Aplicamos filtro FIR.
			right_output = y;											// Sacamos por la salida el resultado de la conv.
			left_output =  right_output;								// Salida izquierda lo mismo que derecha. MONO

		}
// MODO 12: BASSTREBLE

		else if ( Step == 12 )
		{
			if ( Step != LastStep )
			{
				oled_display_message("TDS  SERRA/FERRANDO", "12. Auriculares                 ");
				LastStep = Step;
				for(j = 0; j < N; j++) Parametric[j] = Auriculares[j];	// Convertimos coefs a INT16 guardandolo en una variable.
			}
			x = mono_input;												// Muestra que entrara en el filtro.
			fir(&x, Parametric, &y, dbuffer, 1, N);						// Aplicamos filtro FIR.
			right_output = y;											// Sacamos por la salida el resultado de la conv.
			left_output =  right_output;								// Salida izquierda lo mismo que derecha. MONO

		}


		// Salida de audio
		aic3204_codec_write(left_output, right_output);
	}

	/* Disable I2S and put codec into reset */
    aic3204_disable();

    printf( "\n***Program has Terminated***\n" );

    oled_display_message("PROGRAM HAS        ", "TERMINATED        ");

    SW_BREAKPOINT;
}

/****************************************************************************/
/* FIN DEL MAIN  															*/
/****************************************************************************/
