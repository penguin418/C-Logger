#pragma once


enum log_level {VERBOSE, DEBUG, INFO, WARN, ERROR};
void setLevel(enum log_level level);
void log__logging(enum log_level level, char* filepath, int line, char* func,char* msg);
void log__loggingI(enum log_level level, char* filepath, int line, char* func,char* msg, int target);
void log__loggingF(enum log_level level, char* filepath, int line, char* func, char* msg, float target);
void log_loggingS(enum log_level level, char* filepath, int line, char* func, char* msg, char* target);

struct log {
	enum log_level level;
	void (*setLevel)(enum log_level);
	void (*verbose)(char*);
	void (*verbosei)(char*, int);
	void (*verbosef)(char*, float);
	void (*verboses)(char*, char*);
	void (*debug)(char*);
	void (*debugi)(char*, int);
	void (*debugf)(char*, float);
	void (*debugs)(char*, char*);
	void (*info)(char*);
	void (*infoi)(char*, int);
	void (*infof)(char*, float);
	void (*infos)(char*, char*);
	void (*warn)(char*);
	void (*warni)(char*, int);
	void (*warnf)(char*, float);
	void (*warns)(char*, char*);
	void (*error)(char*);
	void (*errori)(char*, int);
	void (*errorf)(char*, float);
	void (*errors)(char*, char*);
	void (*Logging)(enum log_level, char*, int, char*);
	void (*LoggingI)(enum log_level, char*, int, char*, int);
	void (*LoggingF)(enum log_level, char*, int, char*, float);
	void (*LoggingS)(enum log_level, char*, int, char*, char*);
};

extern struct log Log;

#define verbose(X) Logging(VERBOSE, __FILE__, __LINE__, __func__, X)
#define verbosei(X, Y) LoggingI(VERBOSE, __FILE__, __LINE__, __func__, X, Y)
#define verbosef(X, Y) LoggingF(VERBOSE, __FILE__, __LINE__, __func__, X, Y)
#define verboses(X, Y) LoggingS(VERBOSE, __FILE__, __LINE__, __func__, X, Y)
#define debug(X) Logging(DEBUG, __FILE__, __LINE__, __func__, X)
#define debugi(X, Y) LoggingI(DEBUG, __FILE__, __LINE__, __func__, X, Y)
#define debugf(X, Y) LoggingF(DEBUG, __FILE__, __LINE__, __func__, X, Y)
#define debugs(X, Y) LoggingS(DEBUG, __FILE__, __LINE__, __func__, X, Y)
#define info(X) Logging(INFO, __FILE__, __LINE__, __func__, X)
#define infoi(X, Y) LoggingI(INFO, __FILE__, __LINE__, __func__, X, Y)
#define infof(X, Y) LoggingF(INFO, __FILE__, __LINE__, __func__, X, Y)
#define infos(X, Y) LoggingS(INFO, __FILE__, __LINE__, __func__, X, Y)
#define warn(X) Logging(WARN, __FILE__, __LINE__, __func__, X)
#define warni(X, Y) LoggingI(WARN, __FILE__, __LINE__, __func__, X, Y)
#define warnf(X, Y) LoggingF(WARN, __FILE__, __LINE__, __func__, X, Y)
#define warns(X, Y) LoggingS(WARN, __FILE__, __LINE__, __func__, X, Y)
#define error(X) Logging(ERROR, __FILE__, __LINE__, __func__, X)
#define errori(X, Y) LoggingI(ERROR, __FILE__, __LINE__, __func__, X, Y)
#define errorf(X, Y) log__loggingF(ERROR, __FILE__, __LINE__, __func__, X, Y)
#define errors(X, Y) LoggingS(ERROR, __FILE__, __LINE__, __func__, X, Y)
