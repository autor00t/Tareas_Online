import glob, os

def solucion_correcta():
    os.chdir(r"D:\Dev\Tareas_Online\Estructuras_Datos\Tarea_1\Pregunta_1\solucion")

    solucion = dict()
    for file in glob.glob("*.out"):
        file_object  = open(file, "r") 
        solucion[file] = []
        for linea in file_object:
            linea = linea.strip().split()
            solucion[file].append(linea)

        file_object.close()

    os.chdir(r"D:\Dev\Tareas_Online\Estructuras_Datos\Tarea_1\Pregunta_1")

    for file in glob.glob("*.out"):
        file_object = open(file, "r")
        for linea in file_object:
            linea = linea.strip().split()
            if linea not in solucion[file] and linea != "":
                return False
            del(solucion[file][solucion[file].index(linea)])
        if solucion[file] != []:
            return False
    return True

if solucion_correcta():
    print("Wenarda")
else:
    print("La re ctmmm")
