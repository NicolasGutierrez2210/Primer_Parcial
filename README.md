# Parcial primer corte- Ejercicios 

## Ejercicio 1 – Ordenamiento de estudiantes

## Enunciado  
- Tienes una lista de estudiantes con sus calificaciones en un examen final.  
El objetivo es ordenar la lista en orden **descendente por calificación** y, en caso de empate, **alfabéticamente por nombre**.  
Se deben implementar dos enfoques que representen diferentes paradigmas de programación: **imperativo** y **declarativo**.  
---
## Objetivo:
- Implementar un sistema de ordenamiento de estudiantes utilizando dos paradigmas de programación distintos (imperativo en Python y declarativo/funcional en Haskell), con el fin de comparar sus diferencias en cuanto a claridad, abstracción, manejo de estado, mutabilidad de estructuras y eficiencia algorítmica, destacando cómo cada enfoque resuelve el mismo problema desde perspectivas opuestas.
---
## Como ejecutar el codigo de Phyton

- Este codigo se realizo mediante google colab por lo cual es NECESARIO ejecutarlo desde ahi para que no ocurra ni un tipo de error de compilacion.
- O en su defecto mirar el codigo en el siguiente link: https://colab.research.google.com/drive/1vb2bltGB9j9J3D3QWw4ZCLZjicprkX0e?usp=sharing

---
## Solución imperativa (Python)
- El código se encuentra en el archivo **`Phyton_parcial.py`**.  
Implementa el enfoque **imperativo** con listas mutables e inserciones ordenadas paso a paso.
---

## Solucion declarativa (Haskell)
- El código se encuentra en el archivo **`declarativo1.hs`**.  
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

---

## Análisis comparativo

### Claridad y legibilidad
- **Imperativo (Python):** El Codigo es mas extenso y explicito; muestra paso a paso el proceso de insercion. Es Facil de seguir si se quiere entender el “como”.
- **Declarativo (Haskell):** Codigo es conciso y expresivo; el criterio de orden esta en una sola expresión. Se centra en el “que”.

### Expresividad y abstraccion
- **Python:**  Hay bajo nivel de abstraccion; control manual de bucles e inserciones.
- **Haskell:** Hay alto nivel; se abstrae en funciones puras y composicion de comparadores.

### Estructuras de datos
- **Python:**  Las listas son mutables, modificadas en cada insercion.
- **Haskell:** Listas inmutables; cada insercion devuelve una nueva lista ordenada.

### Manejo de estado
- **Python:** Estado compartido y cambiante en la lista global.
- **Haskell:** Estado explicito mediante funciones que retornan nuevas listas.

### Mantenimiento y extensión
- **Python:** Para agregar nuevas reglas de orden hay que modificar la logica del bucle.
- **Haskell:** Basta con añadir otra función de comparación a la composicion.

### Eficiencia
- **Python (insercion ordenada):** Cada insercion cuesta O(n); para muchas inserciones → O(n²).  
- **Haskell (`sortBy`):** Cada ordenamiento cuesta O(n log n). Si se insertan muchos estudiantes, conviene acumularlos y ordenar una sola vez.

---

## Conclusion
Ambos enfoques cumplen el objetivo, pero muestran diferencias claras de paradigma:
- **Imperativo (Python):** controla el *proceso* de ordenación paso a paso, usando mutabilidad y estado compartido.  
- **Declarativo/Funcional (Haskell):** expresa directamente el *criterio de orden*, trabaja con inmutabilidad y funciones puras, logrando mayor concisión y mantenibilidad.  

