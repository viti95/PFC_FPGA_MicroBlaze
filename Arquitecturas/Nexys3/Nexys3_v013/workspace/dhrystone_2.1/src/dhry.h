/* Compiler and system dependent definitions: */

#ifndef TIME
#define TIMES
#endif
/* Use times(2) time function unless    */
/* explicitly defined otherwise         */

#ifdef TIMES
/* #include <sys/types.h> 
 #include <sys/times.h> */
/* for "times" */
#endif

#define CLOCKS_PER_SECOND 100
#define Mic_secs_Per_Second     1000000.0
/* Berkeley UNIX C returns process times in seconds/HZ */

#ifdef  NOSTRUCTASSIGN
#define structassign(d, s)      memcpy(&(d), &(s), sizeof(d))
#else
#define structassign(d, s)      d = s
#endif

#ifdef  NOENUM
#define Ident_1 0
#define Ident_2 1
#define Ident_3 2
#define Ident_4 3
#define Ident_5 4
typedef int Enumeration;
#else
typedef enum {
	Ident_1, Ident_2, Ident_3, Ident_4, Ident_5
} Enumeration;
#endif
/* for boolean and enumeration types in Ada, Pascal */

/* General definitions: */

#include <stdio.h>
#include <string.h>

/* for strcpy, strcmp */

#define Null 0 
/* Value of a Null pointer */
#define true  1
#define false 0

typedef int One_Thirty;
typedef int One_Fifty;
typedef char Capital_Letter;
typedef int Boolean;
typedef char Str_30[31];
typedef int Arr_1_Dim[50];
typedef int Arr_2_Dim[50][50];

typedef struct record {
	struct record *Ptr_Comp;
	Enumeration Discr;
	union {
		struct {
			Enumeration Enum_Comp;
			int Int_Comp;
			char Str_Comp[31];
		} var_1;
		struct {
			Enumeration E_Comp_2;
			char Str_2_Comp[31];
		} var_2;
		struct {
			char Ch_1_Comp;
			char Ch_2_Comp;
		} var_3;
	} variant;
} Rec_Type, *Rec_Pointer;

