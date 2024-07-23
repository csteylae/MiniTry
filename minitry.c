#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

int read_the_input()
{
    char *input;

    while (1)
    {
        input = readline("feed me please> ");
        if (!strlen(input))
            continue;
        add_history(input);
        free(input);
    }
    return (0);
}

int main(int ac, char **av, char **envp)
{
    (void)av;
	(void)envp;

    if (ac != 1)
        return (1);
    read_the_input();
    return (0);
}
