#!/bin/bash
inicio=100
fin=30000
incremento=500
ejecutable=mejor_caso_ordenacion
salida=tiempos_ordenacion_mejor.dat

i=$(($inicio))
echo > $salida
while [ $i -le $fin ]
do
  echo Ejecución tam = $i
  echo `./$ejecutable $i 10000` >> $salida
  i=$((i+$incremento))
done