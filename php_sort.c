#include <php.h>
#include "php_sort.h"

// register our function to the PHP API
// so that PHP knows, which functions are in this module
zend_function_entry sort_php_functions[] = {
    PHP_FE(sort_php, NULL){NULL, NULL, NULL}
};

// some pieces of information about our module
zend_module_entry sort_php_module_entry = {
    STANDARD_MODULE_HEADER,
    PHP_sort_EXTNAME,
    sort_php_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    PHP_sort_VERSION,
    STANDARD_MODULE_PROPERTIES};

void swap(zval *xp, zval *yp)
{
    zval temp = *xp;
    *xp = *yp;
    *yp = temp;
}

ZEND_GET_MODULE(sort_php)

// A function to implement bubble sort
PHP_FUNCTION(sort_php)
{
    zval *arr;
    if (zend_parse_parameters_throw(ZEND_NUM_ARGS(), "a", &arr) == FAILURE)
    {
        return;
    }
    zend_array *arrarr = Z_ARR_P(arr);
    int n = zend_array_count(arrarr);
    int i, j;
    zval *val;
    Bucket *elementJ;
    Bucket *elementJPlusOne;
    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
        {
            elementJ = arrarr->arData + j;
            elementJPlusOne = (arrarr->arData) + j + 1;
            zend_long lElementJ = Z_LVAL(elementJ->val);
            zend_long lElementJPlusOne = Z_LVAL(elementJPlusOne->val);
            if (lElementJ > lElementJPlusOne)
            {
                swap(elementJ, elementJPlusOne);
            }
        }
    }
    RETVAL_ARR(arrarr);
}
