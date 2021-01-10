PHP_ARG_ENABLE(php_factorial, Whether to enable the factorialPHP extension, [ --enable-factorial-php Enable factorialPHP])

if test "$PHP_factorial" != "no"; then
    PHP_NEW_EXTENSION(php_factorial, php_factorial.c, $ext_shared)
fi

PHP_ARG_ENABLE(php_sort, Whether to enable the sortPHP extension, [ --enable-sort-php Enable sortPHP])

if test "$PHP_sort" != "no"; then
    PHP_NEW_EXTENSION(php_sort, php_sort.c, $ext_shared)
fi
