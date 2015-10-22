// strutil.cpp
/*
    Utilidades para la gestión de cadenas.
*/

#include "strutil.h"
#include <string.h>
#include <ctype.h>

void strtoupper(char cadena[])
{
    if ( cadena != NULL ) {
        char * ptr = cadena;

        for(; *ptr != 0; ++ptr) {
            *ptr = toupper( *ptr );
        }
    }
}

void strtolower(char cadena[])
{
    if ( cadena != NULL ) {
        char * ptr = cadena;

        for(; *ptr != 0; ++ptr) {
            *ptr = tolower( *ptr );
        }
    }
}

void strtrim(char cadena[])
{
    if ( cadena != NULL ) {
        static const char * Espacios = " \t\n\r";
        char * fin = cadena + strlen( cadena );
        char * inicioReal;
        char * finReal;

        // Encontrar el inicio real
        for(inicioReal = cadena; strchr( Espacios, *inicioReal ) != NULL; ++inicioReal);

        // Encontrar el fin real
        for(finReal = fin - 1; strchr( Espacios, *finReal ) != NULL; --finReal);

        // Mover el texto
        *( finReal + 1 ) = 0;
        strcpy( cadena, inicioReal );
    }
}

void strsubstring(const char cadena[], char cadena2[], unsigned int pos, unsigned int num)
{
    if ( cadena != cadena2
      && cadena != NULL
      && cadena2 != NULL )
    {
        const char * ptr = cadena;
        unsigned int len = strlen( cadena );
        *cadena2 = 0;
        char * ptrDest = cadena2;

        if ( pos < len ) {
            // Ajustar la longitud a extraer
            if ( num > ( len - pos ) ) {
                num = len - pos;
            }

            ptr += pos;
            for(; ptr != 0 && num > 0; ++ptrDest, ++ptr, --num) {
                *ptrDest = *ptr;
            }

            *ptrDest = 0;
        }
    }
}

int strpos(const char cadena1[], const char cadena2[])
{
    int toret = -1;

    if ( cadena1 != NULL
      && cadena2 != NULL )
    {
        const char * pos = strstr( cadena1, cadena2 );

        if ( pos != NULL ) {
            toret = pos - cadena1;
        }
    }

    return toret;
}

void strinsert(const char cadena1[], char cadena2[], unsigned int pos)
{
    if ( cadena1 != NULL
      && cadena2 != NULL )
    {
        unsigned int tamHueco = strlen( cadena1 );
        int i = strlen( cadena2 );

        if ( pos < (unsigned int) i ) {
            // Situar el final de la cadena de destino
            *( cadena2 + i + tamHueco ) = 0;

            // Crear el hueco en la cadena de destino
            for(--i; (unsigned int) i >= pos; --i) {
                cadena2[ i + tamHueco ] = cadena2[ i ];
            }

            // Copiar la cadena en el hueco
            for(i = 0; i < tamHueco; ++i) {
                cadena2[ pos + i ] = cadena1[ i ];
            }
        }
    }
}

void strdel(char cadena[], unsigned int pos, unsigned int numCars)
{
    if ( cadena != NULL ) {
        unsigned int tam = strlen( cadena );

        if ( pos < tam ) {
            // Calcular el tamaño del hueco
            if ( numCars >= ( tam - pos ) ) {
                *( cadena + pos ) = 0;
            } else {
                // Borrar el hueco
                int i = pos + numCars;

                for(; (unsigned int) i <= tam; ++i) {
                    cadena[ i - numCars ] = cadena[ i ];
                }
            }
        }
    }
}

void strreplace(char cadena1[], const char cadena2[], const char cadena3[])
{
    if ( cadena1 != NULL
      && cadena2 != NULL
      && cadena3 != NULL )
    {
        unsigned int tamCad2 = strlen( cadena2 );
        int pos = strpos( cadena1, cadena2 );

        while( pos >= 0 ) {
            strdel( cadena1, pos, tamCad2 );
            strinsert( cadena3, cadena1, pos );

            pos = strpos( cadena1, cadena2 );
        }
    }
}

void strconcatchar(char cadena[], int ch)
{
    if ( cadena != NULL ) {
        int tam = strlen( cadena );
        *( cadena + tam ) = ch;
        *( cadena + tam + 1 ) = 0;
    }
}

void strclear(char cadena[])
{
    if ( cadena != NULL ) {
        *cadena = 0;
    }
}
