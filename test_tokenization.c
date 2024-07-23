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
	
Gestion des guillemets :

    Les guillemets simples (') et doubles (") sont traités pour inclure tout le contenu entre les guillemets comme un seul token.

Mots (WORDS) :

    Les séquences de caractères qui ne sont pas des opérateurs ou des espaces sont considérées comme des mots.
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
        } else if (*input == '>') { //    Lorsque le caractère > est trouvé, vérifiez si le caractère suivant est également >. Si c'est le cas, créez un token de type APPEND.
									//    Lorsque le caractère < est trouvé, vérifiez si le caractère suivant est également <. Si c'est le cas, créez un token de type HEREDOC.
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
        } else if (*input == '\'') { //        Identifier et gérer les guillemets simples (') et doubles (").
            new_token->type = SINGLE_QUOTE;
            char *end = strchr(input + 1, '\''); //        S'assurer que les contenus entre guillemets soient traités comme une seule unité (token).
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

/*
Construction de l'arbre syntaxique (AST)

Après la tokenisation, il est nécessaire de construire un AST pour représenter les commandes. Chaque nœud de cet arbre peut représenter :

    Une commande simple
    Une redirection
    Un pipeline

Voici une structure simple pour les nœuds de l'AST :

Voici une structure simple pour les nœuds de l'AST :

c

typedef enum {
    NODE_COMMAND,
    NODE_PIPE,
    NODE_REDIRECTION
} NodeType;

typedef struct s_ast {
    NodeType type;
    char **args; // pour NODE_COMMAND
    struct s_ast *left; // pour les pipelines et les redirections
    struct s_ast *right; // pour les pipelines et les redirections
} ASTNode;

Parsing des tokens en AST

Il faut maintenant écrire un parser qui convertit les tokens en un AST. Voici une fonction de base pour créer des nœuds de commande :

c

ASTNode *parse_command(Token **tokens) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = NODE_COMMAND;
    node->args = malloc(sizeof(char *) * 10); // Taille initiale, à ajuster dynamiquement si nécessaire

    int i = 0;
    while (*tokens && (*tokens)->type == WORD) {
        node->args[i++] = strdup((*tokens)->value);
        *tokens = (*tokens)->next;
    }
    node->args[i] = NULL;

    return node;
}

Conclusion

Ces étapes fournissent une base pour parser l'input utilisateur dans votre projet de minishell. Il reste à compléter le parser pour gérer les pipelines, les redirections, et les autres fonctionnalités spécifiées. Une fois que le parser est complet, vous pouvez implémenter l'exécution des commandes en parcourant l'AST.
*/
