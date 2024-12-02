/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:04:33 by tiade-al          #+#    #+#             */
/*   Updated: 2024/11/29 19:36:39 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*cmd;
	int		here_doc;

	cmd = NULL;
	if (argc < 5)
	{
		write(2, "Error: Wrong number of arguments\n", 33);
		return (0);
	}
	here_doc = here_doc_checker(argv);
	if (!here_doc)
		is_file_valid(argv);
	cmd = command_checker((argc - here_doc), (argv + here_doc), \
			path_divider(envp), here_doc);
	set_pipes(cmd);
	child_creation(cmd, envp);
	free_cmd(cmd);
	return (0);
}
