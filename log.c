#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void _log(char* msg) {
	printf("%s\n", msg);
}

void _logi(char* msg, int target) {
	printf("%s %d\n", msg, target);
}

void _logf(char* msg, float target) {
	printf("%s %f\n", msg, target);
}

void _logs(char* msg, char* target) {
	printf("%s %s\n", msg, target);
}

// 내부 함수
#ifdef _WIN32
#define SEPARATOR '\\'
#else
#define SEPARATOR  '/'
#endif

void _tag(char* filepath, int line, char* func) {
	// 길이 구하기
	int len = strlen(filepath);
	int i = len - 1;
	while (filepath[--i] != SEPARATOR);

	// 슬라이스
	printf("%15s[%3i] %-10s:", filepath + i + 1, line, func);
}

#undef SEPARATOR
