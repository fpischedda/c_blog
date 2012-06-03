/**
 * data_layer.h
 * created by Francesco Pischedda francesco.pischedda@gmail.com
 * Data layer functions
 **/

/**
 * Return the the only one allowed instance of the db handle
 *
 **/
ham_db_t* data_layer_get_instance();

/**
 * Delete the eventually open db handle
 *
 **/
void data_layer_delete_instance();