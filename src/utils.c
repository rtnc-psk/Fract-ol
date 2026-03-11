/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 utils.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: rprasopk <rprasopk@student.42bangkok.com>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/03/08 04:57:56 by rprasopk		   #+#	  #+#			  */
/*	 Updated: 2026/03/08 04:57:56 by rprasopk		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../include/fractol.h"

static double	get_decimal_part(const char *str, int i)
{
	double	res;
	double	frac;

	res = 0.0;
	frac = 1.0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10.0) + (str[i] - '0');
		frac *= 10.0;
		i++;
	}
	return (res / frac);
}

double	ft_atof(const char *str)
{
	int		i;
	double	sign;
	double	res;

	i = 0;
	sign = 1.0;
	res = 0.0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1.0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		res += get_decimal_part(str, i + 1);
	return (res * sign);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}

void	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
