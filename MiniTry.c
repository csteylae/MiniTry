int read_the_input()
{
    char *input;

    while (1)
    {
        input = readline("feed me please> ");
        if (!ft_strlen(input))
            continue;
        add_history(input);
        free(input);
    }
}

int main(int ac, char* av, char **envp)
{
    read_the_input();
}
