#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 500
set ejecutable = ordenacion
set salida = ordenacion_mejor.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `../bin/{$ejecutable} $i 1` >> ../data/$salida
  @ i += $incremento
end

gnuplot -e "set terminal jpeg; set output \"ordenacion_m.jpg\"; set title \"ordenacion mejor\"; plot \"ordenacion_m.dat\" with lines"