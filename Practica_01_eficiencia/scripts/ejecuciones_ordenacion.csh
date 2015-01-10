#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 500
set ejecutable = ordenacion
set salida = tiempos_ordenacion.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `../bin/{$ejecutable} $i 0` >> ../data/$salida
  @ i += $incremento
end




#gnuplot -e "set terminal jpeg; set output \"ordenacion.jpg\"; f(x) = a*x**2 + b*x + c; \"tiempos_ordenacion.dat\"  via a,b,c; set title \"bubble sort\"; plot \"tiempos_ordenacion.dat\", f(x)"

#gnuplot -e "set terminal jpeg; set output \"ordenacion_2.jpg\"; set title \"bubble sort\"; plot \"tiempos_ordenacion.dat\" with lines, \"tiempos_ordenacion_mejor.dat\" with lines, \"tiempos_ordenacion_peor.dat\" with lines"

