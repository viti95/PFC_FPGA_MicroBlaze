/*
 * Copyright (c) 2009 Xilinx, Inc.  All rights reserved.
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION.
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

/* helloworld_xmk.c: launch a thread that prints out Hello World */

#include "xmk.h"
#include "sys/init.h"
#include "platform.h"
#include "sys/timer.h"

#include <stdio.h>

#define SPDP float
#define TIEMPO_EJECUCION 10
#define TIEMPO_CALIBRADO 1

#define CLOCKS_PER_SECOND 100

#define NUMERO_SALTOS 524288

static unsigned int resultado = 0;
static unsigned int selector_saltos[] = { 0x00000000, 0xffffffff, 1, 2, 4, 8,
		16 };

SPDP what_time() {
	SPDP secs;
	unsigned int Time;
	Time = xget_clock_ticks();
	secs = (SPDP) (Time) / (SPDP) (CLOCKS_PER_SECOND);
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

void *vitijumps(void *arg) {

	unsigned int numero_pasadas = 1;
	SPDP inicio = 0, fin = 0;
	SPDP tiempo_computo = 0;
	SPDP resultado_final = 0;

	unsigned int contador = 0;

	unsigned int numero_pasadas_final = 1;

	unsigned int numero_saltos = NUMERO_SALTOS;
	unsigned int numero_predictores = sizeof(selector_saltos)
			/ sizeof(unsigned int);

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

	return resultado;
}

int main() {
	init_platform();

	/* Initialize xilkernel */
	xilkernel_init();

	/* add a thread to be launched once xilkernel starts */
	xmk_add_static_thread(vitijumps, 0);

	/* start xilkernel - does not return control */
	xilkernel_start();

	/* Never reached */
	cleanup_platform();

	return 0;
}
