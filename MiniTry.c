int read_the_input()
{
    char *cmd;

    while (1)
    {
        cmd = readline("prompt> ");
        add_history(cmd);
    }
}

//pour les cas ou il faut garder les espaces (entre des ""), chopper la string et changer la valeur ascii des espaces de 32 a -32 pour qu'ils soient skip dans le parsing d'apres

int main(int ac, char* av, char **envp)
{
    read_the_input();
}
