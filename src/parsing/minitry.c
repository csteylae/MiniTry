#include "../../inc/minitry.h"

static	t_shell	init_shell(char **envp)
{
	t_shell shell;

	shell.tab = NULL;
	shell.env = init_env(envp);
	shell.error = 0;
	if (!shell.env)
		exit_error(&shell, "malloc");
	shell.tab_size = 0;
	return (shell);
}

int read_the_input(char **envp)
{
    char *input;
    t_shell  shell;

	shell = init_shell(envp);
    while (1)
    {
        input = readline("gib comand pliz> ");
        if (!ft_strlen(input))
            continue;
	//	shell.tab = retrieve_cmd(input); doesnt compile for the moment 
		test_env(&shell, input); // simple tests that wont disturb your workflow :)
		add_history(input);
        free(input);
    }
	free_shell(&shell);
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

