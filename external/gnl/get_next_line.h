/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.h									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mbatty <mewen.mewen@hotmail.com>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/17 10:08:22 by mbatty			#+#	#+#			 */
/*   Updated: 2025/02/15 12:59:13 by mbatty		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*ft_joinfreegnl(char *s1, char *s2);
int		ft_strlengnl(char *str);
char	*get_next_line(int fd, int *allocerror);
void	*ft_callocgnl(size_t nmemb, size_t size);
int		size_to_nl(char	*str);
int		ft_strchrgnl(char *s, int c);
void	*alloc_error(int *error);

#endif
