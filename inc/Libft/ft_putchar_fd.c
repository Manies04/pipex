/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 01:08:39 by tiade-al          #+#    #+#             */
/*   Updated: 2024/04/21 12:16:55 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief Outputs the character c to the given file descriptor.
 * @param c: The character to output.
 * @param fd: The file descriptor on which to write.
 * @return None.
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
