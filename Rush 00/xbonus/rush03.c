/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:17:39 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/13 22:34:36 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	control(void)
{
	char	*str;
	int		i;

	i = 0;
	str = "less than or equal to zero";
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	printline(int y)
{
	ft_putchar('B');
	y--;
	while (--y > 0)
		ft_putchar(' ');
	if (y == 0)
		ft_putchar('B');
	ft_putchar('\n');
}

void	printedge(int y, char start, char mid, char end)
{
	ft_putchar(start);
	y--;
	while (--y > 0)
		ft_putchar(mid);
	if (y == 0)
		ft_putchar(end);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	row;

	if (x <= 0 || y <= 0)
	{
		control();
		return ;
	}
	printedge(x, 'A', 'B', 'C');
	row = 1;
	while (++row < y)
	{
		printline(x);
	}
	if (row == y)
		printedge(x, 'A', 'B', 'C');
}
