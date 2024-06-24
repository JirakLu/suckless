//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		    /*Update Interval*/	/*Update Signal*/
	{"",		"sb-forecast",		18000,		        5},
	{"",		"sb-pacpackages",	0,			        8},
	{"",		"sb-volume",		0,			        10},
	{"",		"sb-memory",		10,			        14},
	{"",		"sb-clock", 		60,			        1},
	{"",		"sb-battery",		5,			        3},
	{"",		"sb-internet",		5,			        4},
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 3;
