#!/bin/bash
inicio=100
fin=30000
incremento=500
ejecutable=ejercicio_desc
salida=tiempo_desc.dat

i=$(($inicio))
echo > $salida
while [ $i -le $fin ]
do
  echo Ejecución tam = $i
  echo `./$ejecutable $i` >> $salida
  i=$((i+$incremento))
done