/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_internal.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:13:44 by mbatty            #+#    #+#             */
/*   Updated: 2025/11/11 10:14:39 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_INTERNAL_H
# define GET_NEXT_LINE_INTERNAL_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "get_next_line.h"

char	*ft_joinfreegnl(char *s1, char *s2);
int		ft_strlengnl(char *str);
void	*ft_callocgnl(size_t nmemb, size_t size);
int		size_to_nl(char	*str);
int		ft_strchrgnl(char *s, int c);
void	*alloc_error(int *error);

#endif
