#!/bin/csh
@ inicio = 100
@ fin = 3000
@ incremento = 100
set ejecutable = busqueda_lineal
set salida = tiempos_busqueda.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i 10000` >> $salida
  @ i += $incremento
end


gnuplot -e "set terminal jpeg; set output \"busqueda_lineal.jpg\"; set title \"busqueda_lineal\"; plot \"tiempos_busqueda.dat\" with lines"