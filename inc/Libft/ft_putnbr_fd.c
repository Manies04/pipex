/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:15:55 by tiade-al          #+#    #+#             */
/*   Updated: 2024/04/24 11:30:04 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief Outputs the integer n to the given file descriptor.
 * @param n: The integer to output.
 * @param fd: The file descriptor on which to write.
 * @return None.
*/
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}
/*int main(void) 
{
	int num = 12345; // Test number
	int fd = 1; // STDOUT_FILENO

	// Call the ft_putnbr_fd function to print the number
	ft_putnbr_fd(num, fd);

	// Print a newline character
	ft_putchar_fd('\n', fd);

	return 0;
}*/