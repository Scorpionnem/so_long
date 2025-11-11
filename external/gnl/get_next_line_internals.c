/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line_internals.c						  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mbatty <mewen.mewen@hotmail.com>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/02/15 12:41:17 by mbatty			#+#	#+#			 */
/*   Updated: 2025/02/15 12:45:49 by mbatty		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line_internal.h"

void	*alloc_error(int *error)
{
	(*error) = 1;
	return (NULL);
}

static void	ft_bzerognl(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *) s;
	while (n--)
		*str++ = '\0';
}

void	*ft_callocgnl(size_t nmemb, size_t size)
{
	char	*str;

	if ((unsigned long long)nmemb * size > 4294967295)
		return (NULL);
	if (nmemb < 1 || size < 1)
	{
		nmemb = 0;
		size = 0;
	}
	str = malloc(nmemb * size);
	if (str == NULL)
		return (NULL);
	ft_bzerognl(str, nmemb * size);
	return (str);
}
