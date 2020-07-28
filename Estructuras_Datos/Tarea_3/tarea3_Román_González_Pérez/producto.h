#ifndef PRODUCTO_H_
#define PRODUCTO_H_

typedef int tipoClave;

typedef struct {
    char nombre_producto[31];
    int precio;
} tipoInfoProducto;

typedef struct {
    tipoClave clave;
    tipoInfoProducto info;
    int vacio;
} ranuraProducto;

typedef struct {
    int M;
    ranuraProducto* HT;
} dictProducto;

void initProducto(dictProducto* D, int m);
/*****
* void initProducto.
******
* Inicializa un diccionario.
******
* Input:
* dictProducto* D: Puntero a un struct tipo dictProducto.
* int m: entero que representa el largo del diccionario.
* .......
******
* Returns:
* void: esta función no retorna nada en sí, solo crea un diccionario vacío.
*****/
int hashInsertProducto(dictProducto *D, tipoClave K, char* nombre_producto, int precio);
/*****
* int hashInsertProducto.
******
* Inserta un producto en la tabla hash.
******
* Input:
* dictProducto* D : Puntero a un struct tipo dictProducto.
* tipoClave k: Entero de la clave del producto.
* nombre_producto: Puntero al string del nombre del producto.
* precio: Entero del precio del producto.
* .......
******
* Returns:
* Retorno tipo int, donde el retorno de 1 indica que se insertó en la tabla y retorno 0 indica que no se logró insertar.
*****/
int hashPositionProducto(dictProducto *D, tipoClave k);
/*****
* int hashPositionProducto.
******
* Dado un diccionario y una clave, retorna la posición en la que esta se encuentra.
******
* Input:
* dictProducto *D: Puntero a un struct tipo dictProducto.
* tipoClave k: Entero de la clave del producto.
* .......
******
* Returns:
* int, retorna la posición dada la clave.
*****/
char* hashSearchProductoNombre(dictProducto *D, int pos);
/*****
* char* hashSearchProductoNombre
******
* Dado un diccionario y una posición, retorna el nombre del producto asociado a esta.
******
* Input:
* dictProducto *D: Puntero a un struct tipo dictProducto.
* int pos: entero que representa la posición en el arreglo.
* .......
******
* Returns:
* char*: retorna el nombre del producto.    
*****/
int hashSearchProductoPrecio(dictProducto *D, int pos);
/*****
* int hashSearchProductoPrecio
******
* Dada un diccionario ingresado y una posición, retorna el precio del producto asociado a esta.
******
* Input:
* dictProducto *D: Puntero a un struct tipo dictProducto.
* int pos: entero que representa la posición en el arreglo.
* .......
******
* Returns:
* int: retorna el precio del producto.
*****/
int h(tipoClave k, int m);
/*****
* int h.
******
* Primera función de hashing.
******
* Input:
* tipoClave k: Entero de la clave del producto.
* int m: largo del arreglo.
* .......
******
* Returns:
* int, retorna la posición a cambiar mediante las funciones "h2" y "p".
*****/
long h2(tipoClave k);
/*****
* long h2.
******
* Segunda función de hashing.
******
* Input:
* tipoClave k: Entero de la clave del producto.
* .......
******
* Returns:
* long, retorna valor cambiado de K para usarse en la función "p".
*****/
long p(tipoClave k, int i);
/*****
* long p
******
* Haciendo uso de la función h2 y de la posición, cambia el valor de esta última.
******
* Input:
* tipoClave k: Entero de la clave del producto.
* i: Entero correspondiente a la posición actual.
* .......
******
* Returns:
* long, retorna un cambio en la posición.
*****/
void clearProducto(dictProducto* D);
/*****
* void clearProducto.
******
* Libera la memoria del diccionario Producto.
******
* Input:
* dictProducto *D: Puntero a un struct tipo dictProducto.
* .......
******
* Returns:
* void, esta función no retorna nada, solo borra el diccionario y libera la memoria ocupada por él.
*****/

#endif