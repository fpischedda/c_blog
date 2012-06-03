#include "layout.h"
#include <string.h>
#include <memory.h>
#include <stdlib.h>

char* layout_insert_content(const char* layout, const char* content)
{
	static char* placeholder = "##CONTENT##";
	size_t placeholder_lenght = strlen(placeholder);

	int content_lenght = 0;
	int result_lenght = 0;
	int layout_lenght = 0;

	char* placeholder_p = strstr(layout, placeholder);
	int placeholder_start_index = placeholder_p - layout;
	char* result = NULL;

	if(placeholder_p != NULL)
	{
		content_lenght = strlen(content);
		layout_lenght = strlen(layout);

		result_lenght = content_lenght + layout_lenght - placeholder_lenght + 1;
		result = malloc( result_lenght);

		memcpy(result, layout, placeholder_start_index);
		memcpy(result+placeholder_start_index, content, content_lenght);
		memcpy(result+placeholder_start_index+content_lenght,
			placeholder_p+placeholder_lenght,
			layout_lenght - placeholder_start_index - placeholder_lenght);

		result[result_lenght-1] = '\0';
	}

	return result;
}