/**
 * layout.h by Francesco Pischedda
 * retrive layout models
 */

/**
 * loads a layout from the filesystem and returns its content
 * parameters:
 * 	name: the layout name
 */
char* layout_get_by_name(const char* name);

/**
 * sets the layouts' base directory and returns full path to that directory
 * parameters:
 * 	path: relative path to the layouts' directory
 */
char* layout_set_base_path(const char* path);

const char* layout_get_base_path(void);