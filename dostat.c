#include        <stdio.h>
#include        <sys/types.h>
#include        <dirent.h>
#include        <sys/stat.h>

void dostat( char *filename )
{
        struct stat info;

        if ( stat(filename, &info) == -1 )              /* cannot stat   */
                perror( filename );                     /* say why       */
        else                                    /* else show info        */
                show_file_info( filename, &info );
}
~
~
~
~
~
~
~
~
~
~
~
