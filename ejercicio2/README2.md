# Ejercicio 2 - Gestion dinamica de estudiantes en C
---
## Objetivo
Implementar un sistema en C para gestionar estudiantes de manera dinamica y eficiente, optimizando el uso de memoria mediante `malloc` y `free`, asegurando que cada registro ocupe solo el espacio necesario y evitando desperdicio innecesario

---

## Compilacion y ejecucion en C

Para compilar el programa en C se usa `gcc` (GNU Compiler Collection).

1. Abrir la terminal en la carpeta donde esta el archivo `Ejercicio_2c.c`.  
2. Ejecutar el siguiente comando para compilar:  

   ```bash
   gcc Ejercicio_2c.c -o ejercicio2
   ```
3. Para ejecutar el programa, usar:
    ```bash
    ./ejercicio2
    ```
---
## Implementacion
El codigo esta en el archivo **`main.c`** e incluye:
- Una estructura `Student` con punteros dinamicos para nombre, apellido y notas.  
- Funciones para crear y liberar estudiantes.  
- Un contenedor dinamico `Vec` que gestiona el conjunto de estudiantes.  
- Operaciones para agregar, eliminar por ID y compactar la memoria.  
---
## Paradigma aplicado
Este ejercicio refleja el paradigma **imperativo**:
- Se gestiona el estado de manera explicita (crear, eliminar, compactar).  
- Se usan estructuras mutables (`struct`, arreglos dinamicos).  
- El control del flujo y de la memoria lo realiza paso a paso el programador.

---
## Archivos
- `main.c`: implementacion completa del sistema.  
- `README.md`: explicacion y documentacion del ejercicio.  
