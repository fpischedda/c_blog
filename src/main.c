#include <microhttpd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "models/page.h"
#include "models/layout.h"
#include "view/layout.h"
#include "utils/url_utils.h"

#define PAGE "<html><head><title>libmicrohttpd demo</title>"\
             "</head><body>libmicrohttpd demo</body></html>"

static const char* s_default_page = "about";

char* get_content_by_url(const char* url, const char* layout_name);

static int ahc_echo(void * cls,
		    struct MHD_Connection * connection,
		    const char * url,
		    const char * method,
                    const char * version,
		    const char * upload_data,
		    size_t * upload_data_size,
                    void ** ptr) {
  static int dummy;
  const char * page = cls;
  struct MHD_Response * response;
  int ret;
  
  char* page_content=NULL;

  if (0 != strcmp(method, "GET"))
    return MHD_NO; /* unexpected method */

  if (0 == strcmp(url, "/favicon.ico"))
  {
    return MHD_NO;
  }

  if (&dummy != *ptr) 
    {
      /* The first time only the headers are valid,
         do not respond in the first round... */
      *ptr = &dummy;
      return MHD_YES;
    }
  if (0 != *upload_data_size)
    return MHD_NO; /* upload data in a GET!? */

  page_content = get_content_by_url(url,"application");

  puts(page_content);

  *ptr = NULL; /* clear context pointer */
  response = MHD_create_response_from_data(strlen(page_content),
					   (void*) page_content,
					   MHD_NO,
					   MHD_NO);
  ret = MHD_queue_response(connection,
			   MHD_HTTP_OK,
			   response);
  MHD_destroy_response(response);

  if(NULL != page_content)
  {
    free(page_content);
  }

  return ret;
}

char* get_content_by_url(const char* url, const char* layout_name)
{
  char* page_name = url_to_page_name(url);
  char* page_layout;
  char* page_content;
  char* result = NULL;

  if(NULL != page_name)
  {
    page_content = page_content_by_name(page_name);
    free(page_name);
  }
  else
  {
    page_content = page_content_by_name(s_default_page);
  }

  if(NULL == page_content)
  {
    page_content = strdup("404 resource not found");
  }
  
  page_layout = layout_get_by_name(layout_name);
  result = layout_insert_content(page_layout, page_content);

  free(page_layout);
  free(page_content);

  return result;
}

int main(int argc,
	 char ** argv) {
  struct MHD_Daemon * d;
  if (argc != 2) {
    printf("%s PORT\n",
	   argv[0]);
    return 1;
  }

  page_set_base_path("/pages/");
  layout_set_base_path("/layouts/");

  d = MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION,
		       atoi(argv[1]),
		       NULL,
		       NULL,
		       &ahc_echo,
		       PAGE,
		       MHD_OPTION_END);
  if (d == NULL)
    return 1;
  
  getchar();

  MHD_stop_daemon(d);
  return 0;
}