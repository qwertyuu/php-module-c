PHP_ARG_ENABLE(php_factorial, Whether to enable the factorialPHP extension, [ --enable-factorial-php Enable factorialPHP])

if test "$PHP_factorial" != "no"; then
    PHP_NEW_EXTENSION(php_factorial, php_factorial.c, $ext_shared)
fi
