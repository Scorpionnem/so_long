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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd, int *allocerror);

#endif
