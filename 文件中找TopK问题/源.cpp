#define _CRT_SECURE_NO_WARNINGS 1 
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void CreateNDate(){
	int n = 10000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL){
		perror("fopen error");
		return;
	}
	for (size_t i = 0; i < n; ++i){
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}
void Swap(int* px, int* py){
	int tmp = *px;
	*px = *py;
	*py = tmp;
}
void AdjustDown(int* a, int n, int parent){
	int child = parent * 2 + 1;
	while (child < n){
		if (child + 1 < n && a[child + 1] < a[child]){
			++child;
		}
		if (a[child] < a[parent]){
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else{
			break;
		}
	}
}
void PrintTopK() {
	printf("ÇëÊäÈë");
	int k = 0;
	scanf("%d", &k);
	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL) {
		perror("fopen error");
		return;
	}
	int val = 0;
	int* minheap = (int*)malloc(sizeof(int) * k);
	if (minheap == NULL) {
		perror("malloc error");
		return;
	}
	for (int i = 0; i < k; i++) {
		fscanf(fout, "%d", &minheap[i]);
	}
	for (int i = (k - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(minheap, k, i);
	}
	int x = 0;
	while (fscanf(fout, "%d", &x) != EOF) {
		if (x > minheap[0]) {
			minheap[0] = x;
			AdjustDown(minheap, k, 0);
		}
	}
	for (int i = 0; i < k;  i++) {
		printf("%d\n", minheap[i]);
	}
	free(minheap);
	fclose(fout);
}
int main(){
	CreateNDate();
	PrintTopK();
	return 0;
}