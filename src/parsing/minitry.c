#include "../../inc/minitry.h"

static	t_data	init_data(char **envp)
{
	t_data data;

	data.tab = NULL;
	data.env = init_env(envp);
	data.error = 0;
	if (!data.env)
		exit_error(&data, "malloc");
	data.tab_size = 0;
	return (data);
}

int read_the_input(char **envp)
{
    char *input;
    t_data  data;

	data = init_data(envp);
    while (1)
    {
        input = readline("gib comand pliz> ");
        if (!ft_strlen(input))
            continue;
	//	data.tab = retrieve_cmd(input); doesnt compile for the moment 
		test_env(&data, input); // simple tests that wont disturb your workflow :)
		add_history(input);
        free(input);
    }
	free_data(&data);
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

