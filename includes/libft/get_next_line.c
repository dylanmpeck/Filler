/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:41:35 by dpeck             #+#    #+#             */
/*   Updated: 2018/10/15 19:50:13 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		handle_extra_bytes(char **line, char **temp, int ret)
{
	int		len;
	char	*str;

	len = 0;
	if (*temp)
	{
		if (ft_strchr(*temp, '\n'))
		{
			while ((*temp)[len] != '\n')
				len++;
			*line = ft_strsub(*temp, 0, len);
			str = ft_strdup(&(*temp)[len + 1]);
			ft_strdel(&*temp);
			*temp = ft_strsub(str, 0, ft_strlen(str));
			ft_strdel(&str);
			return (1);
		}
		if (ret == 0 && *temp != NULL)
		{
			*line = ft_strsub(*temp, 0, ft_strlen(*temp));
			ft_strdel(&*temp);
			return (1);
		}
	}
	return (0);
}

void	append_strings(char *buf, char **temp)
{
	char	*str;

	if (*temp == NULL)
	{
		str = ft_strnew(1);
		*temp = ft_strjoin(str, buf);
		ft_strdel(&str);
	}
	else
	{
		str = ft_strjoin(*temp, buf);
		ft_strdel(&*temp);
		*temp = ft_strsub(str, 0, ft_strlen(str));
		ft_strdel(&str);
	}
}

int		create_new_line(char **line, char *buf, char **temp, int ret)
{
	int			len;
	char		*str;
	char		*nextl;

	len = 0;
	if (handle_extra_bytes(line, temp, ret))
		return (1);
	while (buf[len] != '\n' && buf[len])
		len++;
	if (buf[len] == '\n')
	{
		str = ft_strsub(buf, 0, len);
		nextl = (*temp == NULL) ? (ft_strsub(str, 0, ft_strlen(str))) :
									(ft_strjoin(*temp, str));
		ft_strdel(&str);
		ft_strdel(&*temp);
		*line = ft_strsub(nextl, 0, ft_strlen(nextl));
		ft_strdel(&nextl);
		if (len != BUFF_SIZE)
			*temp = ft_strsub(buf, len + 1, ft_strlen(buf + len + 1));
		return (1);
	}
	if (buf[len] == '\0')
		append_strings(buf, temp);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	static char	*temp = NULL;

	ret = 0;
	if (temp)
	{
		if (ft_strchr(temp, '\n'))
			if (create_new_line(line, buf, &temp, ret))
				return (1);
	}
	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (create_new_line(line, buf, &temp, ret))
			return (1);
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (temp == NULL || *temp == '\0'))
		return (0);
	return (create_new_line(line, buf, &temp, ret));
}
