#ifndef CONFIG_H
#define CONFIG_H

// String used to delimit block outputs in the status.
#define DELIMITER " | "

// Maximum number of Unicode characters that a block can output.
#define MAX_BLOCK_OUTPUT_LENGTH 45

// Control whether blocks are clickable.
#define CLICKABLE_BLOCKS 1

// Control whether a leading delimiter should be prepended to the status.
#define LEADING_DELIMITER 0

// Control whether a trailing delimiter should be appended to the status.
#define TRAILING_DELIMITER 1

// Define blocks for the status feed as X(icon, cmd, interval, signal).
#define BLOCKS(X)             \
    X("",   "sb-forecast",      18000,  5)  \
    X("",   "sb-pacpackages",   0,      8)  \
    X("",   "sb-volume",        0,      10) \
    X("",   "sb-memory",        10,     14) \
    X("",   "sb-clock",         10,     1)  \
    X("",   "sb-internet",      5,      4)

#endif  // CONFIG_H
