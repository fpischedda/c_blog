/**
 * page.h by Francesco Pischedda
 *
 */

//#include "../data_layer/data_layer.h"

struct _page 
{
	char* name;
	char* title;
	char* content;
}Page;

/**
 * retrive a page by its name
 *
 * parameters:
 * 		name: page name
 */
char* page_content_by_name(const char* name);