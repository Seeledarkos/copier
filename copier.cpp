#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
// Прототипы функций
int checker(int argc, char** argv);
void helpPage();
char localeFinder();

int main(int argc, char ** argv) {
	checker(argc, argv);
	return 0;
}

int checker(int argc, char** argv) {
	if (argc < 5) {
		helpPage();
		return 0;
	}
	
	FILE* what = fopen(argv[1], "r");
	// rb -> read binary
	FILE* toWhere = fopen(argv[2], "w");
	// w -> write

	if (what == NULL) {
		perror("ТЫ НВАХ!");
		return -1;
	}
	if (toWhere == NULL) {
		perror("ПУТЬ СУКА? NO PATHS???");
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
	printf("Copier v0.6.6.6 by seeledakos.\n");
	printf("Using:\n");
	printf("--from <path\\file.ext> --to <path\\file.ext2>");
	printf("--help: display this.");
}