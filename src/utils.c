/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:51:25 by yuboktae          #+#    #+#             */
/*   Updated: 2023/05/31 17:20:27 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static double	parse_fraction(const char *str)
{
	double	res;
	double	fraction;

	res = 0.0;
	fraction = 0.1;
	while (*str >= 48 && *str <= 57)
	{
		res = res + fraction * (*str - '0');
		fraction *= 0.1;
		str++;
	}
	return (res);
}

double	ft_atof(const char *str)
{
	int		sign;
	double	res;

	sign = 1;
	res = 0.0;
	while (*str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		res = res * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		res += parse_fraction(str);
	}
	return (res * sign);
}

void	ft_putendl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if ((!s1 || !s2) && !n)
		return (0);
	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

int	is_float(const char *str)
{
	int	dot;
	int	digit;

	dot = 0;
	digit = 0;
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (*str != '\0')
	{
		if (*str >= 48 && *str <= 57)
			digit = 1;
		else if (*str == '.' && !dot)
			dot = 1;
		else
			return (0);
		str++;
	}
	if (!digit)
		return (0);
	return (1);
}
