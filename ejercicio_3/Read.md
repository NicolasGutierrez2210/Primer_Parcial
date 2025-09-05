# Ejercicio 3 – Calculo Lambda en Haskell

## 🎯 Objetivo
Implementar el calculo del **promedio de una lista de n numeros** utilizando **notacion de calculo lambda** en Haskell.

---

## 📖 Descripcion
El calculo lambda es una herramienta matematica que describe la computacion desde un enfoque **funcional** y **declarativo**.  
En este ejercicio, se va a definir una funcion en notacion lambda que toma una lista de numeros y devuelve su promedio.

- **Notacion lambda matematica:**

\[
\lambda xs.\; \frac{(\text{foldr}\; (+)\; 0\; xs)}{(\text{length}\; xs)}
\]

- **Implementacion en Haskell:**  
El codigo implementado se encuentra en el archivo **`lambda_has.hs`**.  
Este programa:
1. Solicita al usuario ingresar una lista de numeros.  
2. Convierte la entrada en una lista de `Double`.  
3. Aplica la funcion lambda para calcular el promedio.  
4. Muestra el resultado en pantalla.  
5. Maneja el caso en que la lista este vacia (para evitar division por cero).  

---

## ⚙️ Compilacion y ejecucion

### Compilar
En la terminal, estando en la carpeta del archivo `lambda_has.hs`:

```bash
ghc lambda_has.hss -o lambda
```
### Ejecutar
En la terminal, estando en la carpeta del archivo `lambda_has.hs`:
```bash
./lambda
```


