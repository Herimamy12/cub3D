/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 22:31:57 by nherimam          #+#    #+#             */
/*   Updated: 2024/11/19 10:17:44 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7000
# endif

char	*ft_strjoin(char *stash, char *buff);
void	*ft_calloc(size_t BUFFS, size_t szofcar);
char	*ft_createstash(int fd, char *stash);
char	*ft_createline(char *stash);
char	*ft_restash(char *stash);
char	*get_next_line(int fd);
long	ft_atol(const char *nptr);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char const *s, char c);
int		ft_count_word(char const *s, char c);
int		ft_isdigit(int c);
int		ft_strcmp(char *cmd, char *set);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(char *old, char *str);

#endif
