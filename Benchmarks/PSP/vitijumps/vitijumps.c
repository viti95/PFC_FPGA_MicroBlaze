#include <pspsdk.h>
#include <pspkernel.h>
#include <pspdebug.h>
#include <pspthreadman.h>
#include <pspdisplay.h>
#include <psppower.h>
#include <time.h>
#include <stdio.h>

PSP_MODULE_INFO("VitiJumps", 0, 1, 1);//Aqui definimos el nombre del modulo, podemos poner el del programa
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER); // Aqui ponemos en que modo queremos que se ejecute, (peude ser en modo user o modo kernel)

#define printf pspDebugScreenPrintf //Aqui simplificamos la funcion pspDebugScreenPrintf para que con solo escribir printf nos valga
#define CPU_SPEED 75 // Bus speed = CPU speed / 2, locked

#define SPDP float
#define TIEMPO_EJECUCION 10
#define TIEMPO_CALIBRADO 1

#define NUMERO_SALTOS 524288

static unsigned int resultado = 0;
static unsigned int selector_saltos[] = { 0x00000000, 0xffffffff, 1, 2, 4, 8,
	16 };

void dump_threadstatus(void);

/* Exit callback */
int exit_callback(int arg1, int arg2, void *common)
{
	sceKernelExitGame();
	return 0;
}

/* Callback thread */
int CallbackThread(SceSize args, void *argp)
{
	int cbid;

	cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
	sceKernelRegisterExitCallback(cbid);
	sceKernelSleepThreadCB();

	return 0;
}

/* Sets up the callback thread and returns its thread id */
int SetupCallbacks(void)
{
	int thid = 0;

	thid = sceKernelCreateThread("update_thread", CallbackThread,
	0x11, 0xFA0, 0, 0);
	if(thid >= 0)
	{
		sceKernelStartThread(thid, 0, 0);
	}

	return thid;
}

SPDP what_time() {
	SPDP secs;
	unsigned int Time;
	Time = clock();
	secs = (SPDP) (Time) / (SPDP) (CLOCKS_PER_SEC);
	return secs;
}

void test_1(unsigned int numero_saltos, unsigned int numero_pasadas,
unsigned int selector_salto) {

	unsigned int contador_saltos = 0;
	unsigned int contador_pasadas = 0;

	for (contador_pasadas = 0; contador_pasadas < numero_pasadas; contador_pasadas++) {

		for (contador_saltos = 0; contador_saltos < numero_saltos; contador_saltos++) {

			if ((contador_saltos & selector_salto) == 0)
			resultado++;
			else
			resultado--;

		}

	}
}

void test_2(unsigned int numero_saltos, unsigned int numero_pasadas,
unsigned int selector_salto_1, unsigned int selector_salto_2) {

	int a, b;
	unsigned int contador_saltos = 0;
	unsigned int contador_pasadas = 0;

	for (contador_pasadas = 0; contador_pasadas < numero_pasadas; contador_pasadas++) {
		for (contador_saltos = 0; contador_saltos < numero_saltos; contador_saltos++) {

			if ((contador_saltos % selector_salto_1) == 0)
			a = 1;
			else
			a = 0;

			if ((contador_saltos % selector_salto_2) == 0)
			b = 1;
			else
			b = 0;

			if ((a & b) == 1)
			resultado++;
			else
			resultado--;

		}
	}
}

int main() {

	unsigned int numero_pasadas = 1;
	SPDP inicio = 0, fin = 0;
	SPDP tiempo_computo = 0;
	SPDP resultado_final = 0;

	unsigned int contador = 0;

	unsigned int numero_pasadas_final = 1;

	unsigned int numero_saltos = NUMERO_SALTOS;
	unsigned int numero_predictores = sizeof(selector_saltos)
	/ sizeof(unsigned int);

	pspDebugScreenInit();
	pspDebugScreenClear();
	SetupCallbacks();
	
	scePowerSetClockFrequency(CPU_SPEED,CPU_SPEED,CPU_SPEED/2);
	
	printf("Numero de saltos: %u\r\n", numero_saltos);

	printf("Test 1\r\n");

	for (contador = 0; contador < numero_predictores; contador++) {

		numero_pasadas = 1;
		numero_pasadas_final = 1;

		printf("Predictor de saltos: %u\r\n", selector_saltos[contador]);

		do {
			//printf("%u iteraciones en ", numero_pasadas);

			inicio = what_time();

			test_1(numero_saltos, numero_pasadas, selector_saltos[contador]);

			fin = what_time();

			tiempo_computo = fin - inicio;

			//printf("%3.2f segundos\r\n", tiempo_computo);

			if (tiempo_computo < TIEMPO_CALIBRADO) {
				numero_pasadas = numero_pasadas * 2;
			}

		} while (tiempo_computo < TIEMPO_CALIBRADO);

		numero_pasadas_final = (unsigned int) (((SPDP) TIEMPO_EJECUCION
		* (SPDP) numero_pasadas) / (SPDP) tiempo_computo);

		printf("Calculando %u iteraciones (%u segundos)...\r\n",
		numero_pasadas_final, TIEMPO_EJECUCION);

		inicio = what_time();

		test_1(numero_saltos, numero_pasadas_final, selector_saltos[contador]);

		fin = what_time();

		tiempo_computo = fin - inicio;

		resultado_final = numero_pasadas_final / tiempo_computo;

		printf("Resultado : %8.5f VitiJumps/segundo\r\n", resultado_final);

	}

	printf("Test 2\r\n");

	for (contador = 2; contador < numero_predictores - 1; contador++) {

		numero_pasadas = 1;
		numero_pasadas_final = 1;

		printf("Predictores de saltos: %u, %u\r\n", selector_saltos[contador],
		selector_saltos[contador + 1]);

		do {
			//printf("%u iteraciones en ", numero_pasadas);

			inicio = what_time();

			test_2(numero_saltos, numero_pasadas, selector_saltos[contador],
			selector_saltos[contador + 1]);

			fin = what_time();

			tiempo_computo = fin - inicio;

			//printf("%3.2f segundos\r\n", tiempo_computo);

			if (tiempo_computo < TIEMPO_CALIBRADO) {
				numero_pasadas = numero_pasadas * 2;
			}

		} while (tiempo_computo < TIEMPO_CALIBRADO);

		numero_pasadas_final = (unsigned int) (((SPDP) TIEMPO_EJECUCION
		* (SPDP) numero_pasadas) / (SPDP) tiempo_computo);

		printf("Calculando %u iteraciones (%u segundos)...\r\n",
		numero_pasadas_final, TIEMPO_EJECUCION);

		inicio = what_time();

		test_2(numero_saltos, numero_pasadas_final, selector_saltos[contador],
		selector_saltos[contador + 1]);

		fin = what_time();

		tiempo_computo = fin - inicio;

		resultado_final = numero_pasadas_final / tiempo_computo;

		printf("Resultado : %8.5f VitiJumps/segundo\r\n", resultado_final);

	}
	sceKernelSleepThreadCB();
	
	return resultado;
}
