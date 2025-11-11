/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line_utils.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mbatty <mewen.mewen@hotmail.com>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/17 10:08:19 by mbatty			#+#	#+#			 */
/*   Updated: 2025/02/15 12:49:14 by mbatty		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlengnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_joinfreegnl(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (0);
	dest = ft_callocgnl((ft_strlengnl(s1)
				+ ft_strlengnl(s2) + 2), sizeof(char));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	free(s1);
	dest[i + j] = '\0';
	return (dest);
}

int	ft_strchrgnl(char *s, int c)
{
	int	i;
	int	len;

	len = ft_strlengnl(s);
	i = 0;
	while (i <= len)
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}
