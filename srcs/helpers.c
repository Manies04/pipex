/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:04:47 by tiade-al          #+#    #+#             */
/*   Updated: 2024/12/01 23:50:11 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/**@brief This function is used to open the file given as param to check if it's valid or not.
 * @param **argv: The param given to the main function.
 * @return If valid does nothing, else exit.
 */
void	is_file_valid(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(0);
	else
		close(fd);
	
}
/**@brief This function is used to check if here_doc is present in the argv.
 * @param **argv: The param given to the main function.
 * @return int: 1 if here_doc is present, 0 if not.
 */
int	here_doc_checker(char **argv)
{
	int	spotted;
	int	len;

	spotted = 0;
	len = ft_strlen(argv[1]);

	if (len == 8 && ft_strncmp(argv[1], "here_doc", 8) == 0)
		spotted = 1;
	return(spotted);
}
/**@brief This function is used to divide the param given "envp" into a list of paths.
 * @param **envp: The param given to the main function.
 * @return char**: A list of paths so the cmd can be executed.
*/
char	**path_divider(char **envp)
{
	char	**path;
	int		i;

	path = NULL;
	i = -1;
	if (!envp)
		return (NULL);
	while (envp[++i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			path = ft_split(envp[i], ':');
			if (!path)
				exit(0);
			path[0] = (path[0] + 5);//advances "PATH=" to the first path.
			break;
		}
	}
	return(path);
}

/**@brief This function opens safely a file if it fails it exits the program cleaning the memory.
 * @param file: The file to be opened.
 * @param flags: The flags to be used to open the file.
 * @param perms: The permissions to be used to open the file.
 * @param cmd: The commands
 * @return int: The file descriptor.
 */
int	safe_open(const char *file, int flags, int perms, t_cmd *cmd)
{
	int	fd;

	fd = open(file, flags, perms);
	if (fd == -1)
	{
		perror("Error opening file");
		free_and_exit(cmd);
	}
	return(fd);
}

/**@brief This function closes total_pipes_amount - 1 since the last iteration of the loop failed to create the pipe before.
 * @param cmd: The commands
 * @param total_pipes_amount: The total amount of iterations of the loop that created the pipes.
 * @return void
 */
void	close_pipes(t_cmd *cmd, int total_pipes_amount)
{
	int	i;

	i = -1;
	while (++i < total_pipes_amount)
	{
		close(cmd[i].fd[0]);
		close(cmd[i].fd[1]);
	}
}
