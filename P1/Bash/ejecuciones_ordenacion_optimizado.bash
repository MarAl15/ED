#!/bin/bash
inicio=100
fin=30000
incremento=500
ejecutable=ordenacion_optimizado
salida=tiempos_ordenacion_optimizado.dat

i=$(($inicio))
echo > $salida
while [ $i -le $fin ]
do
  echo Ejecución tam = $i
  echo `./$ejecutable $i 10000` >> $salida
  i=$((i+$incremento))
done