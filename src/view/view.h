/**
 * view.h by Francesco Pischedda
 * export view utility functions
 */

char* markdown_to_xhtml(const char* markdown);

char* fill_template(const char* template, const char** key_val_arguments);