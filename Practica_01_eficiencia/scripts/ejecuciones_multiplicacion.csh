#!/bin/csh
@ inicio = 100
@ fin = 2000
@ incremento = 100
set ejecutable = multiplicacion
set salida = tiempos_multiplicacion.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `../bin/{$ejecutable} $i` >> $salida
  @ i += $incremento
end

gnuplot -e "set terminal jpeg; set output \"multiplicacion.jpg\"; set title \"multiplicacion\"; plot \"multiplicacion.dat\" with lines"