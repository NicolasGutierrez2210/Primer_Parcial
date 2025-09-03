#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// estructura estudiante
typedef struct {
    char *nombre;       // nombre dinamico
    char *apellido;     // apellido dinamico
    uint8_t edad;       // edad ocupa poco
    uint32_t id;        // id unico
    float *notas;       // array de notas dinamico
    size_t n_notas;     // cantidad de notas
} Student;

// duplica cadenas con malloc
char* xstrdup(const char* s) {
    char* p = malloc(strlen(s) + 1); // reservo memoria exacta
    if (p) strcpy(p, s);             // se copia el contenido
    return p;
}

// crea estudiante nuevo
Student* student_new(const char* nombre, const char* apellido, uint8_t edad, uint32_t id, float* notas, size_t n_notas) {
    Student* st = malloc(sizeof(Student)); // reservo memoria para el struct
    st->nombre = xstrdup(nombre);          // guardo nombre exacto
    st->apellido = xstrdup(apellido);      // guardo apellido exacto
    st->edad = edad;
    st->id = id;
    st->n_notas = n_notas;
    st->notas = malloc(n_notas * sizeof(float)); // reservo espacio para las notas
    for (size_t i = 0; i < n_notas; i++) st->notas[i] = notas[i]; // copio notas
    return st;
}

// libera estudiante
void student_free(Student* st) {
    free(st->nombre);    // libero nombre
    free(st->apellido);  // libero apellido
    free(st->notas);     // libero notas
    free(st);            // libero struct
}


typedef struct {
    Student** data;   // array dinamico de punteros a estudiantes
    size_t n;        
    size_t cap;       
    size_t holes;     
} Vec;

// inicializa vector
void vec_init(Vec* v) {
    v->data = NULL;   // sin memoria al inicio
    v->n = v->cap = v->holes = 0; // todo en cero
}

// agrega estudiante
void vec_add(Vec* v, Student* st) {
    if (v->n == v->cap) {                              // si no hay espacio
        v->cap = v->cap ? v->cap * 2 : 4;              // duplico o inicio en 4
        v->data = realloc(v->data, v->cap * sizeof(Student*)); // pide mas memoria
    }
    v->data[v->n++] = st; 
}

// elimina por id
void vec_remove_by_id(Vec* v, uint32_t id) {
    for (size_t i = 0; i < v->n; i++) {
        if (v->data[i] && v->data[i]->id == id) { // encuentro id
            student_free(v->data[i]);             // libero memoria del estudiante
            v->data[i] = NULL;                    
            v->holes++;                           
            // recorto si el hueco esta al final
            while (v->n > 0 && v->data[v->n - 1] == NULL) {
                v->n--;      // reduzco cantidad
                v->holes--;  // reduzco huecos
            }
            return;
        }
    }
}

// compacta la memoria
void vec_compact(Vec* v) {
    size_t j = 0; // nuevo indice
    for (size_t i = 0; i < v->n; i++) {
        if (v->data[i]) {        // si no es hueco
            v->data[j++] = v->data[i]; // se mueve hacia adelante
        }
    }
    v->n = j;        // nueva cantidad real
    v->holes = 0;    // sin huecos
    // realloc seguro
    Student** tmp = realloc(v->data, v->n * sizeof(Student*));
    if (tmp) {       // si realloc funciono
        v->data = tmp;
        v->cap = v->n;
    }
}

// libera todo el vector
void vec_free(Vec* v) {
    for (size_t i = 0; i < v->n; i++) {
        if (v->data[i]) student_free(v->data[i]); // libero cada estudiante
    }
    free(v->data); // libero array de punteros
}

// imprime estudiantes
void print_students(Vec* v) {
    for (size_t i = 0; i < v->n; i++) {
        Student* st = v->data[i];
        if (!st) continue; // salto huecos
        printf("ID:%u %s %s, edad:%u notas:", st->id, st->nombre, st->apellido, st->edad);
        for (size_t j = 0; j < st->n_notas; j++) {
            printf(" %.1f", st->notas[j]); // muestro cada nota
        }
        printf("\n");
    }
}

// programa principal
int main() {
    Vec v; vec_init(&v); // inicializo contenedor

    float notas1[] = {4.5, 3.2, 5.0};
    float notas2[] = {3.0, 2.5};
    float notas3[] = {5.0};

    vec_add(&v, student_new("Nico", "Perez", 20, 1, notas1, 3));
    vec_add(&v, student_new("Coco", "Lopez", 22, 2, notas2, 2));
    vec_add(&v, student_new("Dodo", "Martinez", 19, 3, notas3, 1));

    printf("Estudiantes iniciales:\n");
    print_students(&v);

    vec_remove_by_id(&v, 2); // se elimina a Coco

    printf("\nDespues de eliminar:\n");
    print_students(&v);

    vec_compact(&v); // compacto memoria

    printf("\nDespues de compactar:\n");
    print_students(&v);

    vec_free(&v); // libero todo
    return 0;
}
