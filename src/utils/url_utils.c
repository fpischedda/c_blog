#include "url_utils.h"
#include <string.h>

char* url_to_page_name(const char* url)
{
	char* page = NULL;
	char* slash_pos = NULL;

	slash_pos = strchr(url,'/');

	if( NULL != slash_pos && slash_pos != url)
	{
		page = strdup(slash_pos+1);
	}

	return page;
}