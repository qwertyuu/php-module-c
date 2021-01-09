// include the PHP API itself
#include <php.h>
#include <gmp.h>

// then include the header of your extension
#include "php_factorial.h"

// register our function to the PHP API 
// so that PHP knows, which functions are in this module
zend_function_entry factorial_php_functions[] = {
    PHP_FE(factorial_php, NULL)
    {NULL, NULL, NULL}
};

// some pieces of information about our module
zend_module_entry factorial_php_module_entry = {
    STANDARD_MODULE_HEADER,
    PHP_factorial_EXTNAME,
    factorial_php_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    PHP_factorial_VERSION,
    STANDARD_MODULE_PROPERTIES
};

// use a macro to output additional C code, to make ext dynamically loadable
ZEND_GET_MODULE(factorial_php)

PHP_FUNCTION(factorial_php) {
    zend_long n;

    if (zend_parse_parameters_throw(ZEND_NUM_ARGS(), "l", &n) == FAILURE)
    {
        return;
    }
    mpz_t fact;
    mpz_init(fact);
    mpz_set_ui(fact, 1);
    while (n > 1)
    {
        mpz_mul_ui(fact, fact, n);
        n--;
    }
    //RETVAL_LONG(n);
    const char *result = mpz_get_str(0, 10, fact);
    RETVAL_STRING(result);
}