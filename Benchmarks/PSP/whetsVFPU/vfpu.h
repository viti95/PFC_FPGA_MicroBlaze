#include <pspmath.h>

float vfpu_logf(float s)
{
	float d;

	__asm__ (
		".set			push\n"					// save assember option
		".set			noreorder\n"			// suppress reordering
		"lv.s			s000, %1\n"				// s000 = s
		"vlog2.s		s000, s000\n"			// s000 = log2(s000)
		"vcst.s			s001, VFPU_LOG2E\n"		// s001 = VFPU_LOG2E
		"vdiv.s			s000, s000, s001\n"		// s000 = s000 / s001 = log2(s000) / log2(e)
		"sv.s			s000, %0\n"				// d    = s000
		".set			pop\n"					// restore assember option
		: "=m"(d)
		: "m"(s)
	);

	return (d);
}

float vfpu_expf(float s)
{
	float d;

	__asm__ (
		".set			push\n"					// save assember option
		".set			noreorder\n"			// suppress reordering
		"lv.s			s000, %1\n"				// s000 = s
		"vcst.s			s001, VFPU_LOG2E\n"		// s001 = VFPU_LOG2E
		"vmul.s			s000, s000, s001\n"		// s000 = s000 * s001 = s * log2(e)
		"vexp2.s		s000, s000\n"			// s000 = pow(2.0f, s000)
		"sv.s			s000, %0\n"				// d    = s000
		".set			pop\n"					// restore assember option
		: "=m"(d)
		: "m"(s)
	);
	
	return (d);
}

float vfpu_sinf(float s)
{
	float d;
	
	__asm__ (
		".set			push\n"					// save assember option
		".set			noreorder\n"			// suppress reordering
		"lv.s			s000, %1\n"				// s000 = s
		"vcst.s			s001, VFPU_2_PI\n"		// s001 = VFPU_2_PI = 2 / PI
		"vmul.s			s000, s000, s001\n"		// s000 = s000 * s001
		"vsin.s			s000, s000\n"			// s000 = sin(s000)
		"sv.s			s000, %0\n"				// d    = s000
		".set			pop\n"					// restore assember option
		: "=m"(d)
		: "m"(s)
	);

	return (d);
}

float vfpu_cosf(float s)
{
	float d;

	__asm__ (
		".set			push\n"					// save assember option
		".set			noreorder\n"			// suppress reordering
		"lv.s			s000, %1\n"				// s000 = s
		"vcst.s			s001, VFPU_2_PI\n"		// s001 = VFPU_2_PI = 2 / PI
		"vmul.s			s000, s000, s001\n"		// s000 = s000 * s001
		"vcos.s			s000, s000\n"			// s000 = cos(s000)
		"sv.s			s000, %0\n"				// d    = s000
		".set			pop\n"					// restore assember option
		: "=m"(d)
		: "m"(s)
	);
	
	return (d);
}

float vfpu_sqrtf(float s)
{
	float d;

	__asm__ (
		".set			push\n"					// save assember option
		".set			noreorder\n"			// suppress reordering
		"lv.s			s000, %1\n"				// s000 = s
		"vsqrt.s		s000, s000\n"			// s000 = sqrt(s000)
		"sv.s			s000, %0\n"				// d    = s000
		".set			pop\n"					// restore assember option
		: "=m"(d)
		: "m"(s)
	);

	return (d);
}