#pragma once


void _log(char* msg);
void _logi(char* msg, int target);
void _logf(char* msg, float target);
void _logs(char* msg, char* target);
void _tag(char* filepath, int line, char* func);

#define log(X) {_tag(__FILE__, __LINE__, __func__); _log(X);}
#define logi(X, Y) {_tag(__FILE__, __LINE__, __func__); _logi(X, Y);}
#define logf(X, Y) {_tag(__FILE__, __LINE__, __func__); _logf(X, Y);}
#define logs(X, Y) {_tag(__FILE__, __LINE__, __func__); _logs(X, Y);}
