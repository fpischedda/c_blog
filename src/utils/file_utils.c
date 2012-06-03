#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

char* file_get_content(const char* filename)
{
	struct stat file_info;
	int err = stat(filename, &file_info);

	char* content = NULL;

	if(err == 0)
	{
		FILE* f = fopen(filename,"r");

		puts(filename);
		printf("file to serve: %s size:%d\n", filename, (int)file_info.st_size);

		if( NULL != f)
		{
			content = malloc(file_info.st_size+1);

			printf("bytes read %d", (int)fread(content, file_info.st_size, 1, f));
			content[file_info.st_size] = '\0';
		}

		fclose(f);
	}

	return content;
}