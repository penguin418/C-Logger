#include "log.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#ifndef _LOG
#define _LOG

#ifdef _WIN32
#define SEPARATOR '\\'
#else
#define SEPARATOR  '/'
#endif

#define COLOR_VERBOSE "\033[0m"
#define COLOR_DEBUG "\033[36m"
#define COLOR_INFO "\033[32m"
#define COLOR_WARN "\033[33m"
#define COLOR_ERROR  "\033[31m"

// referenced internally
void log__tag(char* filepath, int line, char* func);
void log__color(enum log_level level);
void setLevel(enum log_level level);
void log__logging(enum log_level level, char* filepath, int line, char* func, char* msg);
void log__loggingI(enum log_level level, char* filepath, int line, char* func, char* msg, int target);
void log__loggingF(enum log_level level, char* filepath, int line, char* func, char* msg, float target);
void log_loggingS(enum log_level level, char* filepath, int line, char* func, char* msg, char* target);


// referenced externally (indirect)
void log__logging(enum log_level level, char* filepath, int line, char* func, char* msg) {
	if (Log.level <= level) {
		log__color(level);
		log__tag(filepath, line, func);
		printf("%s\n", msg);
		log__color(VERBOSE);
	}
}

void log__loggingI(enum log_level level, char* filepath, int line, char* func, char* msg, int target) {
	log__color(level);
	log__tag(filepath, line, func);
	printf("%s %d\n", msg, target);
	log__color(VERBOSE);
}

void log__loggingF(enum log_level level, char* filepath, int line, char* func, char* msg, float target) {
	log__color(level);
	log__tag(filepath, line, func);
	printf("%s %f\n", msg, target);
	log__color(VERBOSE);
}

void log_loggingS(enum log_level level, char* filepath, int line, char* func, char* msg, char* target) {
	log__color(level);
	log__tag(filepath, line, func);
	printf("%s %s\n", msg, target);
	log__color(VERBOSE);
}

void log__color(enum log_level level) {
	switch (level) {
	case VERBOSE: printf("%s", COLOR_VERBOSE); return;
	case DEBUG: printf("%s", COLOR_DEBUG); return;
	case INFO: printf("%s", COLOR_INFO); return;
	case WARN: printf("%s", COLOR_WARN); return;
	case ERROR: printf("%s", COLOR_ERROR); return;
	default: printf("%s", COLOR_VERBOSE); return;
	}
}

void log__tag(char* filepath, int line, char* func) {
	// extract file name
	int len = strlen(filepath);
	int i = len - 1;
	while (filepath[--i] != SEPARATOR);

	printf("%-15s[%3i] %-10s:", filepath + i + 1, line, func);
}

// referenced externally (direct)
struct log Log = {
	.level = VERBOSE,
	.Logging = log__logging,
	.LoggingI = log__loggingI,
	.LoggingF = log__loggingF,
	.LoggingS = log_loggingS
};

void setLevel(enum log_level level) {
	Log.level = level;
}

#undef SEPARATOR
#endif _LOG
