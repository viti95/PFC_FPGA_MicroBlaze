#include "xmk.h"
#include "sys/init.h"
#include "platform.h"
#include "sys/timer.h"

# include <stdio.h>
# include <math.h>
# include <float.h>
# include <limits.h>
# include <sys/time.h>

#define NTIMES 2

#ifndef N
#   define N	2000000
#endif
#ifndef NTIMES
#   define NTIMES	10
#endif
#ifndef OFFSET
#   define OFFSET	0
#endif

#define CLOCKS_PER_SECOND 100

# define HLINE "-------------------------------------------------------------\n"

# ifndef MIN
# define MIN(x,y) ((x)<(y)?(x):(y))
# endif
# ifndef MAX
# define MAX(x,y) ((x)>(y)?(x):(y))
# endif

#define SP

#ifdef DP
#define SPDP double
#define Precision "SPDP"
#endif

#ifdef SP
#define SPDP float
#define Precision "Single"
#endif

static SPDP a[N + OFFSET], b[N + OFFSET], c[N + OFFSET];

static SPDP avgtime[4] = { 0 }, maxtime[4] = { 0 }, mintime[4] = { FLT_MAX,
		FLT_MAX, FLT_MAX, FLT_MAX };

static char *label[4] = { "Copy:      ", "Scale:     ", "Add:       ",
		"Triad:     " };

static SPDP bytes[4] = { 2 * sizeof(SPDP) * N, 2 * sizeof(SPDP) * N, 3
		* sizeof(SPDP) * N, 3 * sizeof(SPDP) * N };

extern SPDP mysecond();
extern void checkSTREAMresults();

#ifdef TUNED
extern void tuned_STREAM_Copy();
extern void tuned_STREAM_Scale(SPDP scalar);
extern void tuned_STREAM_Add();
extern void tuned_STREAM_Triad(SPDP scalar);
#endif

# define	M	20

int checktick() {
	int i, minDelta, Delta;
	SPDP t1, t2, timesfound[M];

	/*  Collect a sequence of M unique time values from the system. */

	for (i = 0; i < M; i++) {
		t1 = mysecond();
		while (((t2 = mysecond()) - t1) < 1.0E-6)
			;
		timesfound[i] = t1 = t2;
	}

	/*
	 * Determine the minimum difference between these M values.
	 * This result will be our estimate (in microseconds) for the
	 * clock granularity.
	 */

	minDelta = 1000000;
	for (i = 1; i < M; i++) {
		Delta = (int) (1.0E6 * (timesfound[i] - timesfound[i - 1]));
		minDelta = MIN(minDelta, MAX(Delta,0));
	}

	return (minDelta);
}

/* A gettimeofday routine to give access to the wall
 clock timer on most UNIX-like systems.  */

#include <sys/time.h>

SPDP mysecond() {
	SPDP secs;
	unsigned int Time;
	Time = xget_clock_ticks();
	secs = (SPDP) (Time) / (SPDP) (CLOCKS_PER_SECOND);
	return secs;
}

void checkSTREAMresults() {
	SPDP aj, bj, cj, scalar;
	SPDP asum, bsum, csum;
	SPDP epsilon;
	int j, k;

	/* reproduce initialization */
	aj = 1.0;
	bj = 2.0;
	cj = 0.0;
	/* a[] is modified during timing check */
	aj = 2.0E0 * aj;
	/* now execute timing loop */
	scalar = 3.0;
	for (k = 0; k < NTIMES; k++) {
		cj = aj;
		bj = scalar * cj;
		cj = aj + bj;
		aj = bj + scalar * cj;
	}
	aj = aj * (SPDP) (N);
	bj = bj * (SPDP) (N);
	cj = cj * (SPDP) (N);

	asum = 0.0;
	bsum = 0.0;
	csum = 0.0;
	for (j = 0; j < N; j++) {
		asum += a[j];
		bsum += b[j];
		csum += c[j];
	}
#ifdef VERBOSE
	printf ("Results Comparison: \n");
	printf ("        Expected  : %f %f %f \n",aj,bj,cj);
	printf ("        Observed  : %f %f %f \n",asum,bsum,csum);
#endif

#ifndef abs
#define abs(a) ((a) >= 0 ? (a) : -(a))
#endif
	epsilon = 1.e-8;

	if (abs(aj-asum) / asum > epsilon) {
		printf("Failed Validation on array a[]\n");
		printf("        Expected  : %f \n", aj);
		printf("        Observed  : %f \n", asum);
	} else if (abs(bj-bsum) / bsum > epsilon) {
		printf("Failed Validation on array b[]\n");
		printf("        Expected  : %f \n", bj);
		printf("        Observed  : %f \n", bsum);
	} else if (abs(cj-csum) / csum > epsilon) {
		printf("Failed Validation on array c[]\n");
		printf("        Expected  : %f \n", cj);
		printf("        Observed  : %f \n", csum);
	} else {
		printf("Solution Validates\n");
	}
}

void tuned_STREAM_Copy() {
	int j;
	for (j = 0; j < N; j++)
		c[j] = a[j];
}

void tuned_STREAM_Scale(SPDP scalar) {
	int j;
	for (j = 0; j < N; j++)
		b[j] = scalar * c[j];
}

void tuned_STREAM_Add() {
	int j;
	for (j = 0; j < N; j++)
		c[j] = a[j] + b[j];
}

void tuned_STREAM_Triad(SPDP scalar) {
	int j;
	for (j = 0; j < N; j++)
		a[j] = b[j] + scalar * c[j];
}

void *stream(void *arg) {
	int quantum, checktick();
		int BytesPerWord;
		register int j, k;
		SPDP scalar, t, times[4][NTIMES];

		/* --- SETUP --- determine precision and check timing --- */

		printf(HLINE);
		printf("STREAM version $Revision: 5.9 $\n");
		printf(HLINE);
		BytesPerWord = sizeof(SPDP);
		printf("This system uses %d bytes per SPDP PRECISION word.\n", BytesPerWord);

		printf(HLINE);
	#ifdef NO_LONG_LONG
		printf("Array size = %d, Offset = %d\n" , N, OFFSET);
	#else
		printf("Array size = %llu, Offset = %d\n", (unsigned long long) N, OFFSET);
	#endif

		printf("Total memory required = %.1f MB.\n",
				(3.0 * BytesPerWord) * ((SPDP) N / 1048576.0));
		printf("Each test is run %d times, but only\n", NTIMES);
		printf("the *best* time for each is used.\n");

	#ifdef _OPENMP
		printf(HLINE);
	#pragma omp parallel
		{
	#pragma omp master
			{
				k = omp_get_num_threads();
				printf ("Number of Threads requested = %i\n",k);
			}
		}
	#endif

		printf(HLINE);
		{
			printf("Printing one line per active thread....\n");
		}

		/* Get initial value for system clock. */
		for (j = 0; j < N; j++) {
			a[j] = 1.0;
			b[j] = 2.0;
			c[j] = 0.0;
		}

		printf(HLINE);

		if ((quantum = checktick()) >= 1)
			printf("Your clock granularity/precision appears to be "
				"%d microseconds.\n", quantum);
		else {
			printf("Your clock granularity appears to be "
				"less than one microsecond.\n");
			quantum = 1;
		}

		t = mysecond();
		for (j = 0; j < N; j++)
			a[j] = 2.0E0 * a[j];
		t = 1.0E6 * (mysecond() - t);

		printf("Each test below will take on the order"
			" of %d microseconds.\n", (int) t);
		printf("   (= %d clock ticks)\n", (int) (t / quantum));
		printf("Increase the size of the arrays if this shows that\n");
		printf("you are not getting at least 20 clock ticks per test.\n");

		printf(HLINE);

		printf("WARNING -- The above is only a rough guideline.\n");
		printf("For best results, please be sure you know the\n");
		printf("precision of your system timer.\n");
		printf(HLINE);

		/*	--- MAIN LOOP --- repeat test cases NTIMES times --- */

		scalar = 3.0;
		for (k = 0; k < NTIMES; k++) {
			times[0][k] = mysecond();
	#ifdef TUNED
			tuned_STREAM_Copy();
	#else
			for (j = 0; j < N; j++)
				c[j] = a[j];
	#endif
			times[0][k] = mysecond() - times[0][k];

			times[1][k] = mysecond();
	#ifdef TUNED
			tuned_STREAM_Scale(scalar);
	#else
			for (j = 0; j < N; j++)
				b[j] = scalar * c[j];
	#endif
			times[1][k] = mysecond() - times[1][k];

			times[2][k] = mysecond();
	#ifdef TUNED
			tuned_STREAM_Add();
	#else
			for (j = 0; j < N; j++)
				c[j] = a[j] + b[j];
	#endif
			times[2][k] = mysecond() - times[2][k];

			times[3][k] = mysecond();
	#ifdef TUNED
			tuned_STREAM_Triad(scalar);
	#else
			for (j = 0; j < N; j++)
				a[j] = b[j] + scalar * c[j];
	#endif
			times[3][k] = mysecond() - times[3][k];
		}

		/*	--- SUMMARY --- */

		for (k = 1; k < NTIMES; k++) /* note -- skip first iteration */
		{
			for (j = 0; j < 4; j++) {
				avgtime[j] = avgtime[j] + times[j][k];
				mintime[j] = MIN(mintime[j], times[j][k]);
				maxtime[j] = MAX(maxtime[j], times[j][k]);
			}
		}

		printf("Function      Rate (MB/s)   Avg time     Min time     Max time\n");
		for (j = 0; j < 4; j++) {
			avgtime[j] = avgtime[j] / (SPDP) (NTIMES - 1);

			printf("%s%11.4f  %11.4f  %11.4f  %11.4f\n", label[j],
					1.0E-06 * bytes[j] / mintime[j], avgtime[j], mintime[j],
					maxtime[j]);
		}
		printf(HLINE);

		/* --- Check Results --- */
		checkSTREAMresults();
		printf(HLINE);

		return 0;
}

int main() {
	init_platform();

	/* Initialize xilkernel */
	xilkernel_init();

	/* add a thread to be launched once xilkernel starts */
	xmk_add_static_thread(stream, 0);

	/* start xilkernel - does not return control */
	xilkernel_start();

	/* Never reached */
	cleanup_platform();

	return 0;
}
