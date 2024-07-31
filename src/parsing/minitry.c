#include "../../inc/minitry.h"

int read_the_input(char **envp)
{
    char *input;
    t_data  *data;

    while (1)
    {
        input = readline("gib comand pliz> ");
        if (!strlen(input))
            continue;
        data = malloc (sizeof(t_data));
        if (!data)
            return (1);
	//	data.tab = retrieve_cmd(input); doesnt compile for the moment 
		test_env(data, input); //do not worry, simple tests that wont disturb your workflow :)
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
    read_the_input(envp);
    return (0);
}
