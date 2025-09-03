# Parcial primer corte- Ejercicios 

## Ejercicio 1 – Ordenamiento de estudiantes

## Enunciado  
Tienes una lista de estudiantes con sus calificaciones en un examen final.  
El objetivo es ordenar la lista en orden **descendente por calificación** y, en caso de empate, **alfabéticamente por nombre**.  
Se deben implementar dos enfoques que representen diferentes paradigmas de programación: **imperativo** y **declarativo**.  
---
## Objetivo:

Implementar un sistema de ordenamiento de estudiantes utilizando dos paradigmas de programación distintos (imperativo en Python y declarativo/funcional en Haskell), con el fin de comparar sus diferencias en cuanto a claridad, abstracción, manejo de estado, mutabilidad de estructuras y eficiencia algorítmica, destacando cómo cada enfoque resuelve el mismo problema desde perspectivas opuestas.
---
## Como ejecutar el codigo de Phyton

- Este codigo se realizo mediante google colab por lo cual es NECESARIO ejecutarlo desde ahi para que no ocurra ni un tipo de error de compilacion.
- O en su defecto mirar el codigo en el siguiente link: https://colab.research.google.com/drive/1vb2bltGB9j9J3D3QWw4ZCLZjicprkX0e?usp=sharing

---
## Solución imperativa (Python)
El código se encuentra en el archivo **`Phyton_parcial.py`**.  
Implementa el enfoque **imperativo** con listas mutables e inserciones ordenadas paso a paso.
---

## Solucion declarativa (Haskell)
El código se encuentra en el archivo **`declarativo1.hs`**.  
Implementa el enfoque **declarativo** utilizando listas inmutables y la función `sortBy` para ordenar según los criterios.

---
##  Como compilar el codigo de Hazkell

Primero compila el archivo en GHC:

```bash
ghc declarativo1.hs -o declarativo
```
O bien, cargar el archivo directamente en GHCi:
```bash
ghci declarativo1.hs
```

## Como ejecutarlo
Ejecuta el programa compilado con:

```bash
./declarativo
```
O bien, cargar el archivo directamente en GHCi:
```bash
ghci declarativo1.hs
```
