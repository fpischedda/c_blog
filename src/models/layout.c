#include "layout.h"
#include "../utils/file_utils.h"
#include <string.h>
#include <unistd.h>

static char s_layout_path[256] = "layouts/";

char* layout_set_base_path(const char* path)
{
	getcwd(s_layout_path, 256);
	return strncat(s_layout_path, path, 256);
}

const char* layout_get_base_path(void)
{
	return s_layout_path;
}

char* layout_get_by_name(const char* name)
{
	static char layout_path[1024];
	strncpy(layout_path, s_layout_path,1024);
	strncat(layout_path, name, 1024);
	return file_get_content(layout_path);
}