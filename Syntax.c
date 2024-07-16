int check_open_quotes(char *str, char c)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] = c)
        {
            while (str++ != '\0')
            {
                if (str[i] = c)
                    return (0);
            }
            return (1);
        }
        str++;
    }
    return (0);
}

int error_fct()
{
    write (1, "SYNTAX ERROR\n", 13);
    return (1);
}

int check_syntax(char *input)
{
    if (check_open_quotes(input, '\"') || check_open_quotes(input, '\''))
        return (1);
    while (input)
    {
        if (input == '\"' || input == '\'')
        {
            input++;
            while (input != '\"' || input != '\'')
                input++;
        }

    }
    //check pas de doubles pipes hors quotes
    return (0);
}
