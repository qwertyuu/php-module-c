<?php

function factorial($n) {
    $fact = 1;
    while ($n > 1) {
        $fact *= $n;
        $n--;
    }
    return $fact;
}

$total = 0;
$iterations = 1;
$start = microtime(true);
for($i = 0; $i < $iterations; $i++)
{
    factorial(1000000);
}
$end = microtime(true);
echo ($end - $start) . "\n";

$start = microtime(true);
for($i = 0; $i < $iterations; $i++)
{
    factorial_php(1000000);
}
$end = microtime(true);
echo ($end - $start) . "\n";