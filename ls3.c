#include        <stdio.h>
#include        <sys/types.h>
#include        <dirent.h>
#include        <sys/stat.h>
#include        <pwd.h>
#include        <grp.h>
#include        "funcheads.h"



char *uid_to_name( uid_t );
char *gid_to_name( gid_t );

main(int ac, char *av[])
{
        if ( ac == 1 )
                do_ls( "." );
        else{
                chdir(av[1]); //THIS IS THE ONLY THING I EDITED TO MAKE THIS PROGRAM WORK
                while ( --ac ){
                        printf("%s:\n", *++av );
                        do_ls( *av );
                }
        }
}

