// this code was produced by chatgpt
// this is pseudo-code so possible that wont compile
//
//Pour créer un shell minimal (minishell) tel que décrit, la première étape est de bien comprendre comment parser l'input utilisateur. Voici un guide pour structurer ce projet, en particulier pour le parsing de l'input.
/*Étapes pour parser l'input utilisateur

    Lire l'input utilisateur :
        Utiliser la fonction readline pour obtenir l'input utilisateur.
        Gérer l'historique des commandes avec add_history.

    Tokenisation :
        Diviser l'input en tokens (mots, opérateurs, etc.).
        Utiliser des règles pour identifier les différents types de tokens : mots (WORDS), opérateurs (OPERATORS), redirections, etc.

    Gestion des guillemets :
        Identifier et gérer les guillemets simples (') et doubles (").
        S'assurer que les contenus entre guillemets soient traités comme une seule unité (token).

    Arbre syntaxique (Abstract Syntax Tree - AST) :
        Construire un arbre syntaxique pour représenter la structure des commandes.
        Les nœuds de cet arbre peuvent représenter des commandes simples, des pipelines, des redirections, etc.

Détail de la tokenisation

La tokenisation consiste à diviser l'input en éléments plus petits, appelés tokens. Voici une approche pour le faire :
Types de tokens

    WORD : Toute séquence de caractères qui n'est pas un opérateur.
    OPERATOR : Caractères spéciaux comme |, <, >, >>, <<.
    QUOTES : Gérer les contenus entre ' et ".
	*/

 typedef enum {
    WORD,
    OPERATOR,
    SINGLE_QUOTE,
    DOUBLE_QUOTE,
    HEREDOC,
    APPEND
} TokenType;

typedef struct s_token {
    TokenType type;
    char *value;
    struct s_token *next;
} Token;

Token *tokenize(char *input) {
    Token *head = NULL;
    Token *current = NULL;

    while (*input) {
        if (isspace(*input)) {
            input++;
            continue;
        }

        Token *new_token = malloc(sizeof(Token));
        if (*input == '|') {
            new_token->type = OPERATOR;
            new_token->value = strndup(input, 1);
            input++;
        } else if (*input == '>') {
            if (*(input + 1) == '>') {
                new_token->type = APPEND;
                new_token->value = strndup(input, 2);
                input += 2;
            } else {
                new_token->type = OPERATOR;
                new_token->value = strndup(input, 1);
                input++;
            }
        } else if (*input == '<') {
            if (*(input + 1) == '<') {
                new_token->type = HEREDOC;
                new_token->value = strndup(input, 2);
                input += 2;
            } else {
                new_token->type = OPERATOR;
                new_token->value = strndup(input, 1);
                input++;
            }
        } else if (*input == '\'') {
            new_token->type = SINGLE_QUOTE;
            char *end = strchr(input + 1, '\'');
            if (!end) {
                fprintf(stderr, "Erreur : guillemet non fermé\n");
                free(new_token);
                return NULL;
            }
            new_token->value = strndup(input, end - input + 1);
            input = end + 1;
        } else if (*input == '"') {
            new_token->type = DOUBLE_QUOTE;
            char *end = strchr(input + 1, '"');
            if (!end) {
                fprintf(stderr, "Erreur : guillemet non fermé\n");
                free(new_token);
                return NULL;
            }
            new_token->value = strndup(input, end - input + 1);
            input = end + 1;
        } else {
            char *end = input;
            while (*end && !isspace(*end) && !strchr("|><'", *end)) {
                end++;
            }
            new_token->type = WORD;
            new_token->value = strndup(input, end - input);
            input = end;
        }

        if (!head) {
            head = new_token;
            current = new_token;
        } else {
            current->next = new_token;
            current = new_token;
        }
    }

    return head;
}
}
