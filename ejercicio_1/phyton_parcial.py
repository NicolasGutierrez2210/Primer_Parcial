class Estudiantes:
    def __init__(self, nombre, nota):
        self.nombre = nombre
        self.nota = nota

estudiantes = []

def agregar_estudiante(nombre, nota):
    estudiante = Estudiantes(nombre, nota)
    pos = 0
    while pos < len(estudiantes):

        if estudiantes[pos].nota > nota:
            pos += 1


        elif estudiantes[pos].nota == nota and estudiantes[pos].nombre < nombre:
            pos += 1
        else:
            break
    estudiantes.insert(pos, estudiante)

def mostrar_estudiantes():
    for estudiante in estudiantes:
        print(f"Nombre: {estudiante.nombre}, Nota: {estudiante.nota}")


agregar_estudiante("Nicolas", 2)
agregar_estudiante("Coco", 5)
agregar_estudiante("Nante", 3)
agregar_estudiante("Dodo", 3)
agregar_estudiante("Beto", 3)

mostrar_estudiantes()
