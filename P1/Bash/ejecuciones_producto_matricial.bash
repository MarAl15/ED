#!/bin/bash
inicio=100
fin=2000
incremento=100
ejecutable=producto_matricial
salida=tiempos_matriz.dat

i=$(($inicio))
echo > $salida
while [ $i -le $fin ]
do
  echo Ejecución tam = $i
  echo `./$ejecutable $i` >> $salida
  i=$((i+$incremento))
done