#include "../../inc/minitry.h"

void	exit_error(t_data *data, char *error_msg)
{
	perror(error_msg);
	free_data(data);
	exit(EXIT_FAILURE);
}
