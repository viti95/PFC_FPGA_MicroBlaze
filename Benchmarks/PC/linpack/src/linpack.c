#include <time.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define ROLL
#define SP

#ifdef SP
#define REAL float
#define ZERO 0.0
#define ONE 1.0
#define PREC "Single "
#endif

#ifdef DP
#define REAL double
#define ZERO 0.0e0
#define ONE 1.0e0
#define PREC "Double "
#endif

#ifdef ROLL
#define ROLLING "Rolled "
#endif

#ifdef UNROLL
#define ROLLING "Unrolled "
#endif

#define NTIMES 10

static REAL atime[9][15];

void print_time(int row);
void matgen(REAL a[], int lda, int n, REAL b[], REAL *norma);
void dgefa(REAL a[], int lda, int n, int ipvt[], int *info);
void dgesl(REAL a[], int lda, int n, int ipvt[], REAL b[], int job);
void dmxpy(int n1, REAL y[], int n2, int ldm, REAL x[], REAL m[]);
void daxpy(int n, REAL da, REAL dx[], int incx, REAL dy[], int incy);
REAL epslon(REAL x);
int idamax(int n, REAL dx[], int incx);
void dscal(int n, REAL da, REAL dx[], int incx);
REAL ddot(int n, REAL dx[], int incx, REAL dy[], int incy);

REAL second() {
        REAL secs;
        unsigned int Time;
        Time = clock();
        secs = (REAL) Time / (REAL) CLOCKS_PER_SEC;
        return secs;
}

/*----------------------*/
void print_time(int row)

{
        fprintf(stdout, "%11.5f%11.5f%11.5f%11.2f%11.4f%11.4f\n",
                        (double) atime[0][row], (double) atime[1][row],
                        (double) atime[2][row], (double) atime[3][row],
                        (double) atime[4][row], (double) atime[5][row]);
        return;
}

/*----------------------*/

void matgen(REAL a[], int lda, int n, REAL b[], REAL *norma)

/* We would like to declare a[][lda], but c does not allow it.  In this
 function, references to a[i][j] are written a[lda*i+j].  */

{
        int init, i, j;

        init = 1325;
        *norma = 0.0;
        for (j = 0; j < n; j++) {
                for (i = 0; i < n; i++) {
                        init = 3125 * init % 65536;
                        a[lda * j + i] = (init - 32768.0) / 16384.0;
                        *norma = (a[lda * j + i] > *norma) ? a[lda * j + i] : *norma;

                        /* alternative for some compilers
                         if (fabs(a[lda*j+i]) > *norma) *norma = fabs(a[lda*j+i]);
                         */
                }
        }
        for (i = 0; i < n; i++) {
                b[i] = 0.0;
        }
        for (j = 0; j < n; j++) {
                for (i = 0; i < n; i++) {
                        b[i] = b[i] + a[lda * j + i];
                }
        }
        return;
}

/*----------------------*/
void dgefa(REAL a[], int lda, int n, int ipvt[], int *info)

/* We would like to declare a[][lda], but c does not allow it.  In this
 function, references to a[i][j] are written a[lda*i+j].  */
/*
 dgefa factors a double precision matrix by gaussian elimination.

 dgefa is usually called by dgeco, but it can be called
 directly with a saving in time if  rcond  is not needed.
 (time for dgeco) = (1 + 9/n)*(time for dgefa) .

 on entry

 a       REAL precision[n][lda]
 the matrix to be factored.

 lda     integer
 the leading dimension of the array  a .

 n       integer
 the order of the matrix  a .

 on return

 a       an upper triangular matrix and the multipliers
 which were used to obtain it.
 the factorization can be written  a = l*u  where
 l  is a product of permutation and unit lower
 triangular matrices and  u  is upper triangular.

 ipvt    integer[n]
 an integer vector of pivot indices.

 info    integer
 = 0  normal value.
 = k  if  u[k][k] .eq. 0.0 .  this is not an error
 condition for this subroutine, but it does
 indicate that dgesl or dgedi will divide by zero
 if called.  use  rcond  in dgeco for a reliable
 indication of singularity.

 linpack. this version dated 08/14/78 .
 cleve moler, university of new mexico, argonne national lab.

 functions

 blas daxpy,dscal,idamax
 */

{
        /*     internal variables       */

        REAL t;
        int j, k, kp1, l, nm1;

        /*     gaussian elimination with partial pivoting       */

        *info = 0;
        nm1 = n - 1;
        if (nm1 >= 0) {
                for (k = 0; k < nm1; k++) {
                        kp1 = k + 1;

                        /* find l = pivot index */

                        l = idamax(n - k, &a[lda * k + k], 1) + k;
                        ipvt[k] = l;

                        /* zero pivot implies this column already
                         triangularized */

                        if (a[lda * k + l] != ZERO) {

                                /* interchange if necessary */

                                if (l != k) {
                                        t = a[lda * k + l];
                                        a[lda * k + l] = a[lda * k + k];
                                        a[lda * k + k] = t;
                                }

                                /* compute multipliers */

                                t = -ONE / a[lda * k + k];
                                dscal(n - (k + 1), t, &a[lda * k + k + 1], 1);

                                /* row elimination with column indexing */

                                for (j = kp1; j < n; j++) {
                                        t = a[lda * j + l];
                                        if (l != k) {
                                                a[lda * j + l] = a[lda * j + k];
                                                a[lda * j + k] = t;
                                        }
                                        daxpy(n - (k + 1), t, &a[lda * k + k + 1], 1,
                                                        &a[lda * j + k + 1], 1);
                                }
                        } else {
                                *info = k;
                        }
                }
        }
        ipvt[n - 1] = n - 1;
        if (a[lda * (n - 1) + (n - 1)] == ZERO)
                *info = n - 1;
        return;
}

/*----------------------*/

void dgesl(REAL a[], int lda, int n, int ipvt[], REAL b[], int job)

/* We would like to declare a[][lda], but c does not allow it.  In this
 function, references to a[i][j] are written a[lda*i+j].  */

/*
 dgesl solves the double precision system
 a * x = b  or  trans(a) * x = b
 using the factors computed by dgeco or dgefa.

 on entry

 a       double precision[n][lda]
 the output from dgeco or dgefa.

 lda     integer
 the leading dimension of the array  a .

 n       integer
 the order of the matrix  a .

 ipvt    integer[n]
 the pivot vector from dgeco or dgefa.

 b       double precision[n]
 the right hand side vector.

 job     integer
 = 0         to solve  a*x = b ,
 = nonzero   to solve  trans(a)*x = b  where
 trans(a)  is the transpose.

 on return

 b       the solution vector  x .

 error condition

 a division by zero will occur if the input factor contains a
 zero on the diagonal.  technically this indicates singularity
 but it is often caused by improper arguments or improper
 setting of lda .  it will not occur if the subroutines are
 called correctly and if dgeco has set rcond .gt. 0.0
 or dgefa has set info .eq. 0 .

 to compute  inverse(a) * c  where  c  is a matrix
 with  p  columns
 dgeco(a,lda,n,ipvt,rcond,z)
 if (!rcond is too small){
 for (j=0,j<p,j++)
 dgesl(a,lda,n,ipvt,c[j][0],0);
 }

 linpack. this version dated 08/14/78 .
 cleve moler, university of new mexico, argonne national lab.

 functions

 blas daxpy,ddot
 */
{
        /*     internal variables       */

        REAL t;
        int k, kb, l, nm1;

        nm1 = n - 1;
        if (job == 0) {

                /* job = 0 , solve  a * x = b
                 first solve  l*y = b         */

                if (nm1 >= 1) {
                        for (k = 0; k < nm1; k++) {
                                l = ipvt[k];
                                t = b[l];
                                if (l != k) {
                                        b[l] = b[k];
                                        b[k] = t;
                                }
                                daxpy(n - (k + 1), t, &a[lda * k + k + 1], 1, &b[k + 1], 1);
                        }
                }

                /* now solve  u*x = y */

                for (kb = 0; kb < n; kb++) {
                        k = n - (kb + 1);
                        b[k] = b[k] / a[lda * k + k];
                        t = -b[k];
                        daxpy(k, t, &a[lda * k + 0], 1, &b[0], 1);
                }
        } else {

                /* job = nonzero, solve  trans(a) * x = b
                 first solve  trans(u)*y = b                  */

                for (k = 0; k < n; k++) {
                        t = ddot(k, &a[lda * k + 0], 1, &b[0], 1);
                        b[k] = (b[k] - t) / a[lda * k + k];
                }

                /* now solve trans(l)*x = y     */

                if (nm1 >= 1) {
                        for (kb = 1; kb < nm1; kb++) {
                                k = n - (kb + 1);
                                b[k] = b[k] + ddot(n - (k + 1), &a[lda * k + k + 1], 1,
                                                &b[k + 1], 1);
                                l = ipvt[k];
                                if (l != k) {
                                        t = b[l];
                                        b[l] = b[k];
                                        b[k] = t;
                                }
                        }
                }
        }
        return;
}

/*----------------------*/

void daxpy(int n, REAL da, REAL dx[], int incx, REAL dy[], int incy)
/*
 constant times a vector plus a vector.
 jack dongarra, linpack, 3/11/78.
 */

{
        int i, ix, iy, m, mp1;

        mp1 = 0;
        m = 0;

        if (n <= 0)
                return;
        if (da == ZERO)
                return;

        if (incx != 1 || incy != 1) {

                /* code for unequal increments or equal increments
                 not equal to 1                                       */

                ix = 0;
                iy = 0;
                if (incx < 0)
                        ix = (-n + 1) * incx;
                if (incy < 0)
                        iy = (-n + 1) * incy;
                for (i = 0; i < n; i++) {
                        dy[iy] = dy[iy] + da * dx[ix];
                        ix = ix + incx;
                        iy = iy + incy;

                }
                return;
        }

        /* code for both increments equal to 1 */

#ifdef ROLL

        for (i = 0;i < n; i++) {
                dy[i] = dy[i] + da*dx[i];
        }

#endif

#ifdef UNROLL

        m = n % 4;
        if (m != 0) {
                for (i = 0; i < m; i++)
                        dy[i] = dy[i] + da * dx[i];

                if (n < 4)
                        return;
        }
        for (i = m; i < n; i = i + 4) {
                dy[i] = dy[i] + da * dx[i];
                dy[i + 1] = dy[i + 1] + da * dx[i + 1];
                dy[i + 2] = dy[i + 2] + da * dx[i + 2];
                dy[i + 3] = dy[i + 3] + da * dx[i + 3];

        }

#endif
        return;
}

/*----------------------*/

REAL ddot(int n, REAL dx[], int incx, REAL dy[], int incy)
/*
 forms the dot product of two vectors.
 jack dongarra, linpack, 3/11/78.
 */

{
        REAL dtemp;
        int i, ix, iy, m, mp1;

        mp1 = 0;
        m = 0;

        dtemp = ZERO;

        if (n <= 0)
                return (ZERO);

        if (incx != 1 || incy != 1) {

                /* code for unequal increments or equal increments
                 not equal to 1                                       */

                ix = 0;
                iy = 0;
                if (incx < 0)
                        ix = (-n + 1) * incx;
                if (incy < 0)
                        iy = (-n + 1) * incy;
                for (i = 0; i < n; i++) {
                        dtemp = dtemp + dx[ix] * dy[iy];
                        ix = ix + incx;
                        iy = iy + incy;

                }
                return (dtemp);
        }

        /* code for both increments equal to 1 */

#ifdef ROLL

        for (i=0;i < n; i++)
        dtemp = dtemp + dx[i]*dy[i];

        return(dtemp);

#endif

#ifdef UNROLL

        m = n % 5;
        if (m != 0) {
                for (i = 0; i < m; i++)
                        dtemp = dtemp + dx[i] * dy[i];
                if (n < 5)
                        return (dtemp);
        }
        for (i = m; i < n; i = i + 5) {
                dtemp = dtemp + dx[i] * dy[i] + dx[i + 1] * dy[i + 1] + dx[i + 2]
                                * dy[i + 2] + dx[i + 3] * dy[i + 3] + dx[i + 4] * dy[i + 4];
        }
        return (dtemp);

#endif

}

/*----------------------*/
void dscal(int n, REAL da, REAL dx[], int incx)

/*     scales a vector by a constant.
 jack dongarra, linpack, 3/11/78.
 */

{
        int i, m, mp1, nincx;

        mp1 = 0;
        m = 0;

        if (n <= 0)
                return;
        if (incx != 1) {

                /* code for increment not equal to 1 */

                nincx = n * incx;
                for (i = 0; i < nincx; i = i + incx)
                        dx[i] = da * dx[i];

                return;
        }

        /* code for increment equal to 1 */

#ifdef ROLL

        for (i = 0; i < n; i++)
        dx[i] = da*dx[i];

#endif

#ifdef UNROLL

        m = n % 5;
        if (m != 0) {
                for (i = 0; i < m; i++)
                        dx[i] = da * dx[i];
                if (n < 5)
                        return;
        }
        for (i = m; i < n; i = i + 5) {
                dx[i] = da * dx[i];
                dx[i + 1] = da * dx[i + 1];
                dx[i + 2] = da * dx[i + 2];
                dx[i + 3] = da * dx[i + 3];
                dx[i + 4] = da * dx[i + 4];
        }

#endif

}

/*----------------------*/
int idamax(int n, REAL dx[], int incx)

/*
 finds the index of element having max. absolute value.
 jack dongarra, linpack, 3/11/78.
 */

{
        REAL dmax;
        int i, ix, itemp;

        if (n < 1)
                return (-1);
        if (n == 1)
                return (0);
        if (incx != 1) {

                /* code for increment not equal to 1 */

                ix = 1;
                dmax = fabs((double) dx[0]);
                ix = ix + incx;
                for (i = 1; i < n; i++) {
                        if (fabs((double) dx[ix]) > dmax) {
                                itemp = i;
                                dmax = fabs((double) dx[ix]);
                        }
                        ix = ix + incx;
                }
        } else {

                /* code for increment equal to 1 */

                itemp = 0;
                dmax = fabs((double) dx[0]);
                for (i = 1; i < n; i++) {
                        if (fabs((double) dx[i]) > dmax) {
                                itemp = i;
                                dmax = fabs((double) dx[i]);
                        }
                }
        }
        return (itemp);
}

/*----------------------*/REAL epslon(REAL x)

/*
 estimate unit roundoff in quantities of size x.
 */

{
        REAL a, b, c, eps;
        /*
         this program should function properly on all systems
         satisfying the following two assumptions,
         1.  the base used in representing dfloating point
         numbers is not a power of three.
         2.  the quantity  a  in statement 10 is represented to
         the accuracy used in dfloating point variables
         that are stored in memory.
         the statement number 10 and the go to 10 are intended to
         force optimizing compilers to generate code satisfying
         assumption 2.
         under these assumptions, it should be true that,
         a  is not exactly equal to four-thirds,
         b  has a zero for its last bit or digit,
         c  is not exactly equal to one,
         eps  measures the separation of 1.0 from
         the next larger dfloating point number.
         the developers of eispack would appreciate being informed
         about any systems where these assumptions do not hold.

         *****************************************************************
         this routine is one of the auxiliary routines used by eispack iii
         to avoid machine dependencies.
         *****************************************************************

         this version dated 4/6/83.
         */

        a = 4.0e0 / 3.0e0;
        eps = ZERO;
        while (eps == ZERO) {
                b = a - ONE;
                c = b + b + b;
                eps = fabs((double) (c - ONE));
        }
        return (eps * fabs((double) x));
}

/*----------------------*/
void dmxpy(int n1, REAL y[], int n2, int ldm, REAL x[], REAL m[])

/* We would like to declare m[][ldm], but c does not allow it.  In this
 function, references to m[i][j] are written m[ldm*i+j].  */

/*
 purpose:
 multiply matrix m times vector x and add the result to vector y.

 parameters:

 n1 integer, number of elements in vector y, and number of rows in
 matrix m

 y double [n1], vector of length n1 to which is added
 the product m*x

 n2 integer, number of elements in vector x, and number of columns
 in matrix m

 ldm integer, leading dimension of array m

 x double [n2], vector of length n2

 m double [ldm][n2], matrix of n1 rows and n2 columns

 ----------------------------------------------------------------------
 */
{
        int j, i, jmin;
        /* cleanup odd vector */

        j = n2 % 2;
        if (j >= 1) {
                j = j - 1;
                for (i = 0; i < n1; i++)
                        y[i] = (y[i]) + x[j] * m[ldm * j + i];
        }

        /* cleanup odd group of two vectors */

        j = n2 % 4;
        if (j >= 2) {
                j = j - 1;
                for (i = 0; i < n1; i++)
                        y[i] = ((y[i]) + x[j - 1] * m[ldm * (j - 1) + i]) + x[j] * m[ldm
                                        * j + i];
        }

        /* cleanup odd group of four vectors */

        j = n2 % 8;
        if (j >= 4) {
                j = j - 1;
                for (i = 0; i < n1; i++)
                        y[i] = ((((y[i]) + x[j - 3] * m[ldm * (j - 3) + i]) + x[j - 2]
                                        * m[ldm * (j - 2) + i]) + x[j - 1] * m[ldm * (j - 1) + i])
                                        + x[j] * m[ldm * j + i];
        }

        /* cleanup odd group of eight vectors */

        j = n2 % 16;
        if (j >= 8) {
                j = j - 1;
                for (i = 0; i < n1; i++)
                        y[i] = ((((((((y[i]) + x[j - 7] * m[ldm * (j - 7) + i]) + x[j - 6]
                                        * m[ldm * (j - 6) + i]) + x[j - 5] * m[ldm * (j - 5) + i])
                                        + x[j - 4] * m[ldm * (j - 4) + i]) + x[j - 3] * m[ldm * (j
                                        - 3) + i]) + x[j - 2] * m[ldm * (j - 2) + i]) + x[j - 1]
                                        * m[ldm * (j - 1) + i]) + x[j] * m[ldm * j + i];
        }

        /* main loop - groups of sixteen vectors */

        jmin = (n2 % 16) + 16;
        for (j = jmin - 1; j < n2; j = j + 16) {
                for (i = 0; i < n1; i++)
                        y[i] = ((((((((((((((((y[i]) + x[j - 15] * m[ldm * (j - 15) + i])
                                        + x[j - 14] * m[ldm * (j - 14) + i]) + x[j - 13] * m[ldm
                                        * (j - 13) + i]) + x[j - 12] * m[ldm * (j - 12) + i]) + x[j
                                        - 11] * m[ldm * (j - 11) + i]) + x[j - 10] * m[ldm * (j
                                        - 10) + i]) + x[j - 9] * m[ldm * (j - 9) + i]) + x[j - 8]
                                        * m[ldm * (j - 8) + i]) + x[j - 7] * m[ldm * (j - 7) + i])
                                        + x[j - 6] * m[ldm * (j - 6) + i]) + x[j - 5] * m[ldm * (j
                                        - 5) + i]) + x[j - 4] * m[ldm * (j - 4) + i]) + x[j - 3]
                                        * m[ldm * (j - 3) + i]) + x[j - 2] * m[ldm * (j - 2) + i])
                                        + x[j - 1] * m[ldm * (j - 1) + i]) + x[j] * m[ldm * j + i];
        }
        return;
}

int main() {

        static REAL aa[200 * 200], a[200 * 201], b[200], x[200];
        REAL cray, ops, total, norma, normx;
        REAL resid, residn, eps, t1, tm2, epsn, x1, x2;
        REAL mflops;
        static int ipvt[200], n, i, j, ntimes, info, lda, ldaa;
        int pass, loop;
        REAL overhead1, overhead2, time1, time2;

        lda = 201;
        ldaa = 200;
        cray = .056;
        n = 100;

        fprintf(stdout, ROLLING);
        fprintf(stdout, PREC);
        fprintf(stdout, "Precision Linpack Benchmark - PC Version in 'C/C++'\n\n");

        ops = (2.0e0 * (n * n * n)) / 3.0 + 2.0 * (n * n);

        matgen(a, lda, n, b, &norma);
        t1 = second();
        dgefa(a, lda, n, ipvt, &info);
        atime[0][0] = second() - t1;
        t1 = second();
        dgesl(a, lda, n, ipvt, b, 0);
        atime[1][0] = second() - t1;
        total = atime[0][0] + atime[1][0];

        /*     compute a residual to verify results.  */

        for (i = 0; i < n; i++) {
                x[i] = b[i];
        }
        matgen(a, lda, n, b, &norma);
        for (i = 0; i < n; i++) {
                b[i] = -b[i];
        }
        dmxpy(n, b, n, lda, x, a);
        resid = 0.0;
        normx = 0.0;
        for (i = 0; i < n; i++) {
                resid = (resid > fabs((double) b[i])) ? resid : fabs((double) b[i]);
                normx = (normx > fabs((double) x[i])) ? normx : fabs((double) x[i]);
        }
        eps = epslon(ONE);
        residn = resid / (n * norma * normx * eps);
        epsn = eps;
        x1 = x[0] - 1;
        x2 = x[n - 1] - 1;

        printf("norm resid      resid           machep");
        printf("         x[0]-1          x[n-1]-1\n");
        printf("%6.1f %17.8e%17.8e%17.8e%17.8e\n\n", (double) residn,
                        (double) resid, (double) epsn, (double) x1, (double) x2);

        fprintf(stdout, "Times are reported for matrices of order        %5d\n", n);
        fprintf(stdout, "1 pass times for array with leading dimension of%5d\n\n",
                        lda);
        fprintf(stdout, "      dgefa      dgesl      total     Mflops       unit");
        fprintf(stdout, "      ratio\n");

        atime[2][0] = total;
        if (total > 0.0) {
                atime[3][0] = ops / (1.0e6 * total);
                atime[4][0] = 2.0 / atime[3][0];
        } else {
                atime[3][0] = 0.0;
                atime[4][0] = 0.0;
        }
        atime[5][0] = total / cray;

        print_time(0);

        /************************************************************************
         *       Calculate overhead of executing matgen procedure              *
         ************************************************************************/

        fprintf(stdout, "\nCalculating matgen overhead\n");
        pass = -20;
        loop = NTIMES;
        do {
                time1 = second();
                pass = pass + 1;
                for (i = 0; i < loop; i++) {
                        matgen(a, lda, n, b, &norma);
                }
                time2 = second();
                overhead1 = (time2 - time1);
                fprintf(stdout, "%10d times %6.2f seconds\n", loop, overhead1);
                if (overhead1 > 5.0) {
                        pass = 0;
                }
                if (pass < 0) {
                        if (overhead1 < 0.1) {
                                loop = loop * 10;
                        } else {
                                loop = loop * 2;
                        }
                }
        } while (pass < 0);

        overhead1 = overhead1 / (double) loop;

        fprintf(stdout, "Overhead for 1 matgen %12.5f seconds\n\n", overhead1);

        /************************************************************************
         *           Calculate matgen/dgefa passes for 5 seconds                *
         ************************************************************************/

        fprintf(stdout, "Calculating matgen/dgefa passes for 5 seconds\n");
        pass = -20;
        ntimes = NTIMES;
        do {
                time1 = second();
                pass = pass + 1;
                for (i = 0; i < ntimes; i++) {
                        matgen(a, lda, n, b, &norma);
                        dgefa(a, lda, n, ipvt, &info);
                }
                time2 = second() - time1;
                fprintf(stdout, "%10d times %6.2f seconds\n", ntimes, time2);
                if (time2 > 5.0) {
                        pass = 0;
                }
                if (pass < 0) {
                        if (time2 < 0.1) {
                                ntimes = ntimes * 10;
                        } else {
                                ntimes = ntimes * 2;
                        }
                }
        } while (pass < 0);

        ntimes = 5.0 * (double) ntimes / time2;
        if (ntimes == 0)
                ntimes = 1;

        fprintf(stdout, "Passes used %10d \n\n", ntimes);
        fprintf(stdout, "Times for array with leading dimension of%4d\n\n", lda);
        fprintf(stdout, "      dgefa      dgesl      total     Mflops       unit");
        fprintf(stdout, "      ratio\n");

        /************************************************************************
         *                              Execute 5 passes                        *
         ************************************************************************/

        tm2 = ntimes * overhead1;
        atime[3][6] = 0;

        for (j = 1; j < 6; j++) {

                t1 = second();

                for (i = 0; i < ntimes; i++) {
                        matgen(a, lda, n, b, &norma);
                        dgefa(a, lda, n, ipvt, &info);
                }

                atime[0][j] = (second() - t1 - tm2) / ntimes;

                t1 = second();

                for (i = 0; i < ntimes; i++) {
                        dgesl(a, lda, n, ipvt, b, 0);
                }

                atime[1][j] = (second() - t1) / ntimes;
                total = atime[0][j] + atime[1][j];
                atime[2][j] = total;
                atime[3][j] = ops / (1.0e6 * total);
                atime[4][j] = 2.0 / atime[3][j];
                atime[5][j] = total / cray;
                atime[3][6] = atime[3][6] + atime[3][j];

                print_time(j);
        }
        atime[3][6] = atime[3][6] / 5.0;
        fprintf(stdout, "Average                          %11.2f\n",
                        (double) atime[3][6]);

        fprintf(stdout, "\nCalculating matgen2 overhead\n");

        /************************************************************************
         *             Calculate overhead of executing matgen procedure         *
         ************************************************************************/

        time1 = second();
        for (i = 0; i < loop; i++) {
                matgen(aa, ldaa, n, b, &norma);
        }
        time2 = second();
        overhead2 = (time2 - time1);
        overhead2 = overhead2 / (double) loop;

        fprintf(stdout, "Overhead for 1 matgen %12.5f seconds\n\n", overhead2);
        fprintf(stdout, "Times for array with leading dimension of%4d\n\n", ldaa);
        fprintf(stdout, "      dgefa      dgesl      total     Mflops       unit");
        fprintf(stdout, "      ratio\n");

        /************************************************************************
         *                              Execute 5 passes                        *
         ************************************************************************/

        tm2 = ntimes * overhead2;
        atime[3][12] = 0;

        for (j = 7; j < 12; j++) {

                t1 = second();

                for (i = 0; i < ntimes; i++) {
                        matgen(aa, ldaa, n, b, &norma);
                        dgefa(aa, ldaa, n, ipvt, &info);
                }

                atime[0][j] = (second() - t1 - tm2) / ntimes;

                t1 = second();

                for (i = 0; i < ntimes; i++) {
                        dgesl(aa, ldaa, n, ipvt, b, 0);
                }

                atime[1][j] = (second() - t1) / ntimes;
                total = atime[0][j] + atime[1][j];
                atime[2][j] = total;
                atime[3][j] = ops / (1.0e6 * total);
                atime[4][j] = 2.0 / atime[3][j];
                atime[5][j] = total / cray;
                atime[3][12] = atime[3][12] + atime[3][j];

                print_time(j);
        }
        atime[3][12] = atime[3][12] / 5.0;
        fprintf(stdout, "Average                          %11.2f\n",
                        (double) atime[3][12]);

        /************************************************************************
         *           Use minimum average as overall Mflops rating               *
         ************************************************************************/

        mflops = atime[3][6];
        if (atime[3][12] < mflops)
                mflops = atime[3][12];

        fprintf(stdout, "\n");
        fprintf(stdout, ROLLING);
        fprintf(stdout, PREC);
        fprintf(stdout, " Precision %11.2f Mflops \n\n", mflops);

        return 0;
}

