/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:19:34 by dpeck             #+#    #+#             */
/*   Updated: 2018/09/18 15:54:13 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char		*result;
	const char	*psrc;
	char		*pdest;

	result = (char *)malloc(ft_strlen(str) + 1);
	psrc = str;
	pdest = result;
	if (result == NULL)
	{
		free(result);
		return (NULL);
	}
	while (*psrc)
	{
		*pdest = *psrc;
		pdest++;
		psrc++;
	}
	*pdest = '\0';
	return (result);
}
