import glob, os
def solucion_correcta():
    os.chdir(r"D:\Dev\Tareas_Online\Estructuras_Datos\Tarea_1\Pregunta_1\solucion")

    solucion = dict()
    for file in glob.glob("*.out"):
        file_object  = open(file, "r") 
        solucion[file] = []
        for linea in file_object:
            solucion[file].append((linea.strip().split()))

        file_object.close()

    os.chdir(r"D:\Dev\Tareas_Online\Estructuras_Datos\Tarea_1\Pregunta_1")

    for file in glob.glob("*.out"):
        resultados = []
        file_object = open(file, "r")
        i = 0
        for linea in file_object:
            if solucion[file][i] != (linea.strip().split()) and linea != "":
                return False
            i += 1
    return True

if solucion_correcta():
    print("Wenarda")
else:
    print("La re ctmmm")