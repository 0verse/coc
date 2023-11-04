#include "coc.h"

    usage(u8* prog)
{
    println("%s runit <filename.co>      / build and run the program",   prog);
    println("%s build <filename.co>      / build the program",           prog);
    println("%s trans <filename.co>      / translate co file to c file", prog);
    println("%s clean <filenema.co>      / clean up generated c file",   prog);
}

    trans(u8* arg2)
{
    u8 cmd[100] = "./cocc.sh ";
    strcat(cmd, arg2);
    system(cmd);
}

    u8* build(u8* arg1, u8* arg2)
{
    u8* fname;
    (fname = strrchr(arg2, '/')) ? ++fname : (fname = arg2);
    fname[strlen(fname)-1] = '\0';

    u8 remcmd[100] = "rm ";

        if (strcmp(arg1, "clean") == 0)
    {
        strcat(remcmd, fname);
        strcat(remcmd, " ");
    }

    u8 bldcmd[100] = "gcc -Wno-implicit-int ";

        if ((strcmp(arg1, "build") == 0) || (strcmp(arg1, "runit") == 0))
    {
        strcat(bldcmd, fname);
    }

    fname[strlen(fname)-2] = '\0';

        if (strcmp(arg1, "clean") == 0)
    {
        strcat(remcmd, fname);
        println("> %s", remcmd);
        system(remcmd);
    }

        if ((strcmp(arg1, "build") == 0) || (strcmp(arg1, "runit") == 0))
    {
        strcat(bldcmd, " -o ");
        strcat(bldcmd, fname);

        system(bldcmd);
    }

        if (strcmp(arg1, "runit") == 0)
    {
        u8 runcmd[100] = "./";
        strcat(runcmd, fname);
        system(runcmd);
    }
}

    i32 main(i32 argc,u8 *argv[])
{

        if (argc < 3)
    {
        println("> not enough argument\n> see usage:");
        usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    u8* prog = strdup(argv[0]);
    u8* arg1 = strdup(argv[1]);
    u8* arg2 = strdup(argv[2]);

    assert( prog != NULL && arg1 != NULL && arg2 != NULL);

        if (strcmp(arg1, "-h") == 0)
    {
        usage(prog);
        exit(EXIT_FAILURE);
    }

        if (access(arg2, F_OK) != 0)
    {
            println("> %s: file does not exist", arg2)
            exit(EXIT_FAILURE);
    }

        if (strcmp(arg1, "runit") == 0)
    {
        trans(arg2);
        build(arg1, arg2);
    }
        else if (strcmp(arg1, "build") == 0)
    {
        trans(arg2);
        build(arg1, arg2);
    }
        else if (strcmp(arg1, "trans") == 0)
    {
        trans(arg2);
    }
        else if (strcmp(arg1, "clean") == 0)
    {
        build(arg1, arg2);
    }
        else
    {
        println("> unable to determine argument: %s", arg1)
        exit(EXIT_FAILURE);
    }

    free(prog);
    free(arg1);
    free(arg2);

    exit(EXIT_SUCCESS);
}
