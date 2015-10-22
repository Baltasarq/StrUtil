// strutil.h
/*
    Utilidades para manejo de cadenas
*/


#ifndef STRUTIL_H_INCLUDED
#define STRUTIL_H_INCLUDED

/**
    Pasar cadena a mayúsculas
    @param cadena Vector de caracteres a convertir
*/
void strtoupper(char cadena[]);

/**
    Pasar cadena a minúsculas
    @param cadena Vector de caracteres a convertir
*/
void strtolower(char cadena[]);

/**
    Eliminar espacios precedentes y posteriores
    @param cadena Vector de caracteres a convertir
*/
void strtrim(char cadena[]);

/**
    Concatena un carácter a una cadena
    @param cadena Vector de caracteres a añadirle un carácter
    @param ch El carácter a añadir
*/
void strconcatchar(char cadena[], int ch);

/**
    Elimina todo el contenido de una cadena
    @param cadena Vector de caracteres a eliminar su contenido
*/
void strclear(char cadena[]);


/**
    Obtener una subcadena de otra. cadena y bufdest no pueden ser la misma
    cadena
    @param pos Posición inicial
    @param num Número de caracteres a extraer
    @param cadena Vector de caracteres del que obtener la subcadena
    @param bufdest Vector de caracteres donde almacena la subcadena
*/

void strsubstring(const char cadena[], char bufdest[], unsigned int pos, unsigned int num);

/**
    Busca una cadena (cadena2), dentro de otra (cadena1)
    @param cadena1 Vector de caracteres en el que buscar
    @param cadena2 Cadena a buscar
    @return la posición de la segunda cadena en la primera, o -1
*/
int strpos(const char cadena1[], const char cadena2[]);

/**
    Inserta una cadena (cadena1), dentro de otra (cadena2), en pos.
    Nótese que cadena2 sale modificada de la llamada a esta función.
    @param cadena1 Vector de caracteres a insertar
    @param cadena2 Cadena en donde insertar
*/
void strinsert(const char cadena1[], char cadena2[], unsigned int pos);

/**
    Borra una subcadena dentro de otra, marcada por una posición y longitud
    @param pos Posición inicial
    @param num Número de caracteres a eliminar
    @param cadena Vector de caracteres en el que borrar
*/
void strdel(char cadena[], unsigned int pos, unsigned int numCars);

/**
    Reemplaza en cadena1 las ocurrencias de cadena2 por cadena3
    @note Si cadena3 contiene a cadena2, entra en bucle infinito
    @param cadena1 La cadena donde se va a reemplazar
    @param cadena2 La cadena que se va a buscar
    @param cadena3 La cadena por la que se va a reemplazar
*/

void strreplace(char cadena1[], const char cadena2[], const char cadena3[]);

#endif // STRUTIL_H_INCLUDED
