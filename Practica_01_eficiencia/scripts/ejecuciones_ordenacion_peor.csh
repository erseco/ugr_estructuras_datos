#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 500
set ejecutable = ordenacion
set salida = ordenacion_peor.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `../bin/{$ejecutable} $i 1` >> ../data/$salida
  @ i += $incremento
end

gnuplot -e "set terminal jpeg; set output \"ordenacion_p.jpg\"; set title \"ordenacion peor\"; plot \"ordenacion_p.dat\" with lines"