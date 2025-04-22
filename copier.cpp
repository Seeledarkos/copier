#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
// Прототипы функций
int checker(int argc, char** argv);
void helpPage();
char localeFinder();

int main(int argc, char ** argv) {
	setlocale(0, "ru");
	checker(argc, argv);
	return 0;
}

int checker(int argc, char** argv) {
	if (argc < 5) {
		helpPage();
		return 0;
	}
	// ./copier --from "..." --to "..."
	FILE* what = fopen(argv[2], "rb");
	// rb -> read binary
	FILE* toWhere = fopen(argv[4], "wb");
	// w -> write

	if (what == NULL) {
		perror("ТЫ НВАХ!");
		printf("Укажи правильный путь до файла");
		return -1;
	}
	if (toWhere == NULL) {
		perror("ТЫ ГРЯЗНЫЙ НВАХ!");
		printf("Укажи верный путь куда");
	}

	char buffer;
	while (1) {
		buffer = fgetc(what);
		if (feof(what)) {
			break;
		}
		fputc(buffer, toWhere);
	}
	fclose(what);
	fclose(toWhere);
	return 0;
}

char localeFinder() {
	// read file locale windows
	char userLocale = 'a';
	return userLocale;
}

void helpPage() {
	printf("Copier v0	.6.6.6 by seeledakos.\n");
	printf("Using:\n");
	printf("--from <path\\file.ext> --to <path\\file.ext2>");
	printf("--help: display this.");
}