#include <stdio.h>
#include <string.h>

#include "strutil.h"

int main()
{
    char buffer[128];
    char buffer2[128];

    strcpy( buffer, "Esto ES UNA prueba" );

    printf( "Cadena original: '%s'\n", buffer );

    strtolower( buffer );
    printf( "Cadena: '%s'\n", buffer );

    strtoupper( buffer );
    printf( "Cadena: '%s'\n", buffer );

    strsubstring( buffer, buffer2, 0, 4 );
    printf( "Subcadena: '%s'\n", buffer2 );

    printf( "Posición de '%s' en '%s': %d\n",
            buffer2, buffer, strpos( buffer, buffer2 )
    );

    printf( "Posición de 'ES' en '%s': %d\n",
            buffer, strpos( buffer, " ES " )
    );

    printf( "Posición de '%s' en '%s': %d\n",
            buffer, buffer2, strpos( buffer2, buffer )
    );

    printf( "Posición de NULL en '%s': %d\n",
            buffer, strpos( buffer, NULL )
    );

    strinsert( "NO ", buffer, 5 );
    printf( "Insertando NO queda: '%s'\n", buffer );

    strsubstring( buffer, buffer2, 100, 4 );
    printf( "Subcadena: '%s'\n", buffer2 );

    strsubstring( buffer, buffer2, 5, 2 );
    printf( "Subcadena: '%s'\n", buffer2 );

    strsubstring( buffer, buffer2, 5, 200 );
    printf( "Subcadena: '%s'\n", buffer2 );

    printf( "Buffer es '%s'\n", buffer );

    strdel( buffer, 4, 3 );
    printf( "Quitando 3 de 4, queda '%s'\n", buffer );

    strreplace( buffer, "S", "Z" );
    printf( "Reemplazando S por Z, queda '%s'\n", buffer );

    strreplace( buffer, "UNA", "OTRA" );
    printf( "Reemplazando UNA por OTRA, queda '%s'\n", buffer );

    strclear( buffer2 );
    int i = 0;
    for(; i < strlen( buffer ); ++i) {
        strconcatchar( buffer2, buffer[ i ] );
        printf( "%s\n", buffer2 );
    }

    return 0;
}
