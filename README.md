# php-module-c
 Example of a php C module. Used https://stackoverflow.com/questions/3632160/how-to-make-a-php-extension as a guide

 # Compile

 Use `make && sudo make install` to compile into a .so in the modules folder. If that doesn't work, try `phpize && ./configure --enable-php-sort && make && sudo make install` or refer to the guide linked up there

 Then use `php -d extension=php_sort.so -r 'var_dump(sort_php([99, 2, 88, 3, 77, 4])) . "\n";'` to test it out!