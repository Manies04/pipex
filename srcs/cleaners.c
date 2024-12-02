/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:03:25 by tiade-al          #+#    #+#             */
/*   Updated: 2024/11/27 16:04:01 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_cmd(t_cmd *cmd)
{
	int	i;
	int	j;

	j = -1;
	while (++j <= cmd[0].process_nb)
	{
		i = 0;
		while (cmd[j].arg[i] != NULL)
		{
			if (cmd[j].arg[i])
				free(cmd[j].arg[i]);
			i++;
		}
		if (cmd[j].arg)
			free(cmd[j].arg);
		if (j != 0 && cmd[j].path)
			free(cmd[j].path);
	}
	free(cmd);
}

void	free_and_exit(t_cmd *cmd)
{
	perror("Error");
	free_cmd(cmd);
	exit(0);
}
void	free_paths(char **paths)
{
	int	i;

	if (paths)
	{
		i = -1;
		while (paths[++i])
		{
			if (i == 0)
				free((paths[i] - 5));
			else
				free(paths[i]);
		}
		free(paths);
	}
}
