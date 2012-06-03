#include "page.h"
#include "../utils/file_utils.h"
#include <string.h>
#include <unistd.h>

static char s_page_path[256] = "pages/";

char* page_set_base_path(const char* path)
{
	getcwd(s_page_path, 256);
	return strncat(s_page_path, path, 256);
}

const char* page_get_base_path(void)
{
	return s_page_path;
}

char* page_content_by_name(const char* name)
{
	static char page_path[1024];
	strncpy(page_path, s_page_path,1024);
	strncat(page_path, name, 1024);
	return file_get_content(page_path);
}