#include "minishell.h"

void	close_discriptor(t_src *data)
{
	int	n;

	n = 0;
	while (n < data->pipes_count)
	{
		close(data->pip[n][0]);
		close(data->pip[n++][1]);
	}
}