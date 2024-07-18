int check_open_quotes(char *str, char c, int j)
{
    int i;

    i = j;
    while (str[i])
    {
        if (str[i] = c)
        {
            while (str++ != '\0')
            {
                if (str[i] = c)
                    return (i - j);
            }
            return (0);
        }
        i++;
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
    if (!check_open_quotes(input, '\"', 0) || !check_open_quotes(input, '\'', 0))
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
    //passer une seule fois sur la string -> mettre un if a la fin si on a pas ferme une quote d'ici la fin c'est qu'on a une quote ouverte -> free et syntax error
    // donc en gros tokenifier d'office differament des qu'on trouve une quote puis changer tout en fonction de si elle est pas fermee
    return (0);
}

int pars_it(char *input)
{
    int i;

    i = 0;
    while (input[i])
    {
        //avancer c par c, des qu'on a une quote -> check is_in_quote permanent
        // si in quote -> texte, si not -> regular parsing
        //a la fin -> if quote pas fermee -> free tout et syntax error
    }
}
