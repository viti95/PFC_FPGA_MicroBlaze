#include <pspsdk.h>
#include <pspkernel.h>
#include <pspdebug.h>
#include <pspthreadman.h>
#include <pspdisplay.h>
#include <psppower.h>

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

PSP_MODULE_INFO("VitiRAM", 0, 1, 1);//Aqui definimos el nombre del modulo, podemos poner el del programa
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER); // Aqui ponemos en que modo queremos que se ejecute, (peude ser en modo user o modo kernel)

#define printf pspDebugScreenPrintf //Aqui simplificamos la funcion pspDebugScreenPrintf para que con solo escribir printf nos valga
#define CPU_SPEED 75 // Bus speed = CPU speed / 2, locked

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

#define SPDP float
#define TIEMPO_EJECUCION 4
#define TIEMPO_CALIBRADO 1

#define TAMANO_CONJUNTO_DATOS 8388608

static unsigned int numero_repeticiones[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608};
static unsigned int tamanos_bloques[] = { TAMANO_CONJUNTO_DATOS/1, TAMANO_CONJUNTO_DATOS/2, TAMANO_CONJUNTO_DATOS/4, TAMANO_CONJUNTO_DATOS/8, TAMANO_CONJUNTO_DATOS/16, TAMANO_CONJUNTO_DATOS/32, TAMANO_CONJUNTO_DATOS/64, TAMANO_CONJUNTO_DATOS/128, TAMANO_CONJUNTO_DATOS/256, TAMANO_CONJUNTO_DATOS/512, TAMANO_CONJUNTO_DATOS/1024, TAMANO_CONJUNTO_DATOS/2048, TAMANO_CONJUNTO_DATOS/4096, TAMANO_CONJUNTO_DATOS/8192, TAMANO_CONJUNTO_DATOS/16384, TAMANO_CONJUNTO_DATOS/32768, TAMANO_CONJUNTO_DATOS/65536,
        TAMANO_CONJUNTO_DATOS/131072, TAMANO_CONJUNTO_DATOS/262144, TAMANO_CONJUNTO_DATOS/524288, TAMANO_CONJUNTO_DATOS/1048576, TAMANO_CONJUNTO_DATOS/2097152, TAMANO_CONJUNTO_DATOS/4194304, TAMANO_CONJUNTO_DATOS/8388608};
        
unsigned int resultado;

static unsigned char conjunto_datos[TAMANO_CONJUNTO_DATOS];
unsigned char conjunto_datos_salida[TAMANO_CONJUNTO_DATOS];

static unsigned long rng_x=123456789, rng_y=362436069, rng_z=521288629;

unsigned long xorshf96() {          
        //period 2^96-1
        unsigned long rng_t;

        rng_x ^= rng_x << 16;
        rng_x ^= rng_x >> 5;
        rng_x ^= rng_x << 1;

        rng_t = rng_x;
        rng_x = rng_y;
        rng_y = rng_z;
        rng_z = rng_t ^ rng_x ^ rng_y;
        
        return rng_z;
}

void inicializar_array()
{
        int i;

        for(i=0; i<TAMANO_CONJUNTO_DATOS; i++){
                conjunto_datos[i] = (unsigned char) xorshf96();
        }
}

SPDP what_time()
{
        SPDP secs;
        clock_t Time;
        Time = clock();
        secs = (SPDP)(Time) / (SPDP)(CLOCKS_PER_SEC);
        return secs;
}

void localidad_temporal_copy(unsigned int numero_pasadas, unsigned int numero_repeticiones, unsigned int tamano_bloque){

        unsigned int contador_pasadas = 0;
        unsigned int contador_repeticiones = 0;

        for(contador_pasadas = 0; contador_pasadas < numero_pasadas; contador_pasadas++){

            for(contador_repeticiones = 0; contador_repeticiones < numero_repeticiones; contador_repeticiones++){

                     memcpy(conjunto_datos_salida, conjunto_datos, tamano_bloque);
            }

        }
}

void localidad_temporal_write(unsigned int numero_pasadas, unsigned int numero_repeticiones, unsigned int tamano_bloque){

        unsigned int contador_pasadas = 0;
        unsigned int contador_repeticiones = 0;

        for(contador_pasadas = 0; contador_pasadas < numero_pasadas; contador_pasadas++){

            for(contador_repeticiones = 0; contador_repeticiones < numero_repeticiones; contador_repeticiones++){

                     memset(conjunto_datos_salida, 0, tamano_bloque);
            }

        }
}

int main() {

        unsigned int numero_pasadas = 1;
        SPDP inicio = 0, fin = 0;
        SPDP tiempo_computo = 0;
        SPDP resultado_final = 0;

        unsigned int numero_pasadas_final = 1;

        unsigned int contador = 0;
        unsigned int tamano_bloque_datos = 0;
        unsigned int numero_tests_localidad = sizeof(numero_repeticiones) / sizeof(unsigned int);

			    pspDebugScreenInit();
    pspDebugScreenClear();
    SetupCallbacks();

    scePowerSetClockFrequency(CPU_SPEED,CPU_SPEED,CPU_SPEED/2);
		
        //Inicializamos aleatoriamente el conjunto de datos
        inicializar_array();
        
        //Primero localidad temporal (Escritura)

        printf("Benchmark de localidad temporal (Escritura)\r\n\r\n");
        printf("Blocksize\tPasses\tIterations\tResult\r\n");
        for(contador = 0; contador < numero_tests_localidad; contador++){

                tamano_bloque_datos = tamanos_bloques[contador] * sizeof(unsigned char);

                inicio=0;
                fin=0;
                resultado_final=0;
                numero_pasadas=1;
                numero_pasadas_final=1;

                printf("%u\t\t%u\t", tamanos_bloques[contador], numero_repeticiones[contador]);

                //Calibramos
                do{
                        inicio = what_time();
                        localidad_temporal_write(numero_pasadas, numero_repeticiones[contador], tamano_bloque_datos);
                        fin = what_time();
                        tiempo_computo = fin - inicio;
                        if(tiempo_computo < TIEMPO_CALIBRADO){
                                numero_pasadas = numero_pasadas * 2;
                        }
                }while(tiempo_computo < TIEMPO_CALIBRADO);

                //Calculamos
                numero_pasadas_final = (unsigned int) (((SPDP) TIEMPO_EJECUCION * (SPDP)numero_pasadas) / (SPDP)tiempo_computo);
                printf("%u\t\t", numero_pasadas_final);
                inicio = what_time();
                localidad_temporal_write(numero_pasadas_final, numero_repeticiones[contador], tamano_bloque_datos);
                fin = what_time();
                tiempo_computo = fin - inicio;
                resultado_final = numero_pasadas_final / tiempo_computo;
                resultado_final = resultado_final * TAMANO_CONJUNTO_DATOS / 1048576;
                printf("%8.5f MB/s\r\n", resultado_final);
        }

         //Segundo localidad temporal (Copia - Lectura + Escritura)

        printf("Benchmark de localidad temporal (Lectura + Escritura)\r\n\r\n");
        printf("Blocksize\tPasses\tIterations\tResult\r\n");
        for(contador = 0; contador < numero_tests_localidad; contador++){

                tamano_bloque_datos = tamanos_bloques[contador] * sizeof(unsigned char);

                inicio=0;
                fin=0;
                resultado_final=0;
                numero_pasadas=1;
                numero_pasadas_final=1;

                printf("%u\t\t%u\t", tamanos_bloques[contador], numero_repeticiones[contador]);

                //Calibramos
                do{
                        inicio = what_time();
                        localidad_temporal_copy(numero_pasadas, numero_repeticiones[contador], tamano_bloque_datos);
                        fin = what_time();
                        tiempo_computo = fin - inicio;
                        if(tiempo_computo < TIEMPO_CALIBRADO){
                                numero_pasadas = numero_pasadas * 2;
                        }
                }while(tiempo_computo < TIEMPO_CALIBRADO);

                //Calculamos
                numero_pasadas_final = (unsigned int) (((SPDP) TIEMPO_EJECUCION * (SPDP)numero_pasadas) / (SPDP)tiempo_computo);
                printf("%u\t\t", numero_pasadas_final);
                inicio = what_time();
                localidad_temporal_copy(numero_pasadas_final, numero_repeticiones[contador], tamano_bloque_datos);
                fin = what_time();
                tiempo_computo = fin - inicio;
                resultado_final = numero_pasadas_final / tiempo_computo;
                resultado_final = resultado_final * TAMANO_CONJUNTO_DATOS / 1048576;
                printf("%8.5f MB/s\r\n", resultado_final);
        }
		
		sceKernelSleepThreadCB();

        return resultado;
}
