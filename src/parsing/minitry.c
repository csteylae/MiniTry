#include "../../inc/minitry.h"

static	t_shell	*init_data(void)
{
	t_shell *data;

	data = malloc(sizeof(*data));
	if (!data)
	{
		ft_putstr_fd("error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	data->tab = NULL;
	data->env = NULL;
	data->tab_size = 0;
	return (data);
}

int read_the_input(char **envp)
{
    char *input;
    t_shell  *data;

	data = init_data();
	data->env = init_env(envp);
    while (1)
    {
        input = readline("gib comand pliz> ");
        if (!strlen(input))
            continue;
		add_history(input);
	//	data.tab = retrieve_cmd(input); doesnt compile for the moment 
	//	if data == null -> continue
		test_env(data, input); // simple tests that wont disturb your workflow :)
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
