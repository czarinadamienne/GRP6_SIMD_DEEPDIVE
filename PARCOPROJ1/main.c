#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <stdint.h> 

extern void x86(int n, int32_t* v1, int32_t* v2, int32_t* sdot);
extern void SIMDX(int n, int32_t* v1,int32_t* v2, int32_t* sdot);
extern void SIMDY(int n, int32_t* v1, int32_t* v2, int32_t* sdot);

void dotprod(int n, int32_t* v1, int32_t* v2, int32_t* sdot) { //solves the dot product
	*sdot = 0;
	for (int i = 0; i < n; i++) {
		*sdot += v1[i] * v2[i];
	}
}

int main() {
	int n = 1 << 28; //highest is 1 << 28
	int32_t sdot = 0;

	printf("\nNumber of elements = %d\n", n);

	const size_t arr_bytes = n * sizeof(INT32);

	srand((unsigned int)time(0));

	//time test
	LARGE_INTEGER li;
	long long int start, end;
	double PCFreq, elapse;
	QueryPerformanceFrequency(&li);
	PCFreq = (double)(li.QuadPart);

	// allocate dynamically
	int32_t* v1 = (int32_t*)malloc(arr_bytes);
	int32_t* v2 = (int32_t*)malloc(arr_bytes);

	if (v1 == NULL || v2 == NULL) {
		printf("Memory allocation failed!\n");
		free(v1);
		free(v2); //frees up if memory allocation failed
		return -1;
	}

	// initialize arrays with the index value
	for (int i = 0; i < n; i++) {
		v1[i] = i;
		v2[i] = i;
	}

	double total_time_c = 0.0;
	double total_time_x86 = 0.0;
	double total_time_xmm = 0.0;
	double total_time_ymm = 0.0;
	int repeat = 30;

	// ------------------------ C PROGRAM ------------------------------
	printf("\n------- C PROGRAM --------\n");
	for (int i = 0; i < repeat; i++) {
		printf("[ITERATION #%d]\n", i + 1);
			
		QueryPerformanceCounter(&li);
		start = li.QuadPart;
			
		dotprod(n, v1, v2, &sdot);
			
		QueryPerformanceCounter(&li);
		end = li.QuadPart;
		elapse = ((double)(end - start)) * 1000.0 / PCFreq;

		int32_t sum = 0;
		for (int j = 0; j < n; j++) {
			sum += v1[j] * v2[j];
		}
		if (sdot != sum) {
			printf("C program is INCORRECT\n");
		}
		else {
			printf("C program is CORRECT\n");
		}
		printf("Dot Product in C = %d\n", sdot);

		printf("Time in C = %f ms\n", elapse);

		total_time_c += elapse;
	}
	printf("\n\n");
		//---------------------- x86-64 PROGRAM ------------------------
		sdot = 0;

		printf("\n------- X86-64 PROGRAM --------\n");
		for (int i = 0; i < repeat; i++) {
			printf("[ITERATION #%d]\n", i + 1);

			QueryPerformanceCounter(&li);
			start = li.QuadPart;

			x86(n, v1, v2, &sdot);

			QueryPerformanceCounter(&li);
			end = li.QuadPart;
			elapse = ((double)(end - start)) * 1000.0 / PCFreq;

			//error checker
			int32_t sum = 0;
			for (int j = 0; j < n; j++) {
				sum += v1[j] * v2[j];
			}
			if (sdot != sum) {
				printf("x86 program is INCORRECT\n");
			}
			else {
				printf("x86 program is CORRECT\n");
			}
			printf("Dot Product in x86-64 = %d\n", sdot);

			printf("Time in x86-64 = %f ms\n", elapse);
			total_time_x86 += elapse;
		}
		printf("\n\n");

		//-------------------------- SIMD XMM PROGRAM -------------------------
		sdot = 0;

		printf("\n------- SIMD XMM PROGRAM --------\n");
		for (int i = 0; i < repeat; i++) {
			printf("[ITERATION #%d]\n", i + 1);

			QueryPerformanceCounter(&li);
			start = li.QuadPart;

			SIMDX(n, v1, v2, &sdot);

			QueryPerformanceCounter(&li);
			end = li.QuadPart;
			elapse = ((double)(end - start)) * 1000.0 / PCFreq;

			//error check
			int32_t sum = 0;
			for (int j = 0; j < n; j++) {
				sum += v1[j] * v2[j];
			}
			if (sdot != sum) {
				printf("SIMD XMM program is INCORRECT\n");
			}
			else {
				printf("SIMD XMM program is CORRECT\n");
			}
			printf("Dot Product in SIMD XMM = %d\n", sdot);

			printf("Time in SIMD XMM = %f ms\n", elapse);
			total_time_xmm += elapse;
		}
		printf("\n\n");
		//--------------------- SIMD YMM PROGRAM -------------------------
		sdot = 0;

		printf("\n------- SIMD YMM PROGRAM --------\n");
		for (int i = 0; i < repeat; i++) {
			printf("[ITERATION #%d]\n", i + 1);

			QueryPerformanceCounter(&li);
			start = li.QuadPart;

			SIMDY(n, v1, v2, &sdot);

			QueryPerformanceCounter(&li);
			end = li.QuadPart;
			elapse = ((double)(end - start)) * 1000.0 / PCFreq;

			//error check
			int32_t sum = 0;
			for (int j = 0; j < n; j++) {
				sum += v1[j] * v2[j];
			}
			if (sdot != sum) {
				printf("SIMD YMM program is INCORRECT\n");
			}
			else {
				printf("SIMD YMM program is CORRECT\n");
			}
			printf("Dot Product in SIMD YMM = %d\n", sdot);

			printf("Time in SIMD YMM = %f ms\n", elapse);
			total_time_ymm += elapse;
		}

		printf("\n\n");

	double avg_time_c = total_time_c / repeat;
	double avg_time_x86 = total_time_x86 / repeat;
	double avg_time_xmm = total_time_xmm / repeat;
	double avg_time_ymm = total_time_ymm / repeat;

	printf("\n\n[AVERAGE TIMES]");
	printf("\nAverage time in C = %f ms\n", avg_time_c);
	printf("Average time in x86-64 = %f ms\n", avg_time_x86);
	printf("Average time in SIMD XMM = %f ms\n", avg_time_xmm);
	printf("Average time in SIMD YMM = %f ms\n", avg_time_ymm);

	free(v1);
	free(v2); //free up both vector memory

	return 0;
}