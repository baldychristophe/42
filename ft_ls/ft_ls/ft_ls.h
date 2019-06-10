/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 16:54:29 by cbaldy            #+#    #+#             */
/*   Updated: 2016/01/06 16:04:59 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <time.h>
# include <sys/xattr.h>
# include <stdlib.h>
# include <pwd.h>
# include <grp.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <sys/ioctl.h>

# define OPT_PATH 1
# define OPT_A 2
# define OPT_L 4
# define OPT_MINR 8
# define OPT_T 16
# define OPT_R 32
# define OPT_UN 64
# define OPT_U 128
# define OPT_S 256
# define OPT_MINF 512

int						g_option;
int						g_flag;
int						g_link;

typedef struct			s_fi_list
{
	const char			*name;
	char				*mode;
	int					nb_links;
	char				*proprio;
	char				*groupe;
	int					taille;
	long				time_st;
	int					block;
	char				*link;
	int					device;
	struct s_fi_list	*next;
	struct s_fi_list	*previous;
}						t_fi_list;

typedef struct			s_type_list
{
	unsigned char		type_nu;
	char				*type_abr;
}						t_type_list;

typedef struct			s_opt_list
{
	char				opt_char;
	int					opt_nu;
}						t_opt_list;

void					ft_putstr(char const *s);
void					ft_putchar(char c);
char					*ft_strnew(size_t size);
char					*ft_strjoin(char const *s1, char const *s2);
void					ft_putnbr(int n);
t_fi_list				**ft_construct_list(char *path_name);
void					ft_lprint(t_fi_list **begin, char *path);
char					*ft_strsub(char const *s, unsigned int start,
				size_t len);
void					ft_putendl(char const *s);
char					*ft_itoa(int n);
size_t					ft_strlen(const char *var);
int						ft_power(int nb, int power);
int						ft_read_opt(int argc, char **argv);
char					**ft_read_path(int argc, char **argv);
void					*ft_memalloc(size_t size);
char					**ft_time_sort_dir(char **dir);
char					**ft_reverse_dir(char **dir);
char					**ft_sort_dir(char **dir);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strdup(const char *s1);
int						ft_recursive(char *path_name);
int						ft_nb_chiffre(int nb);
t_fi_list				**ft_sort_list(t_fi_list **begin);
int						ft_type_dir(char *path);
char					**ft_sort_type_dir(char **dir);
char					*ft_strrchr(const char *s, int c);
t_fi_list				**ft_non_open_file(char *path);
void					ft_put_old_date(long st);
void					ft_pushback_list(t_fi_list **begin, t_fi_list *new);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *str, int fd);
char					**ft_sort_errno(char **dir);
int						ft_errno(char *path);
char					*ft_bit_analysis(char *str, unsigned int mode);
int						*ft_dev_space(t_fi_list **begin, int *tab);
int						ft_is_link(char *path);
void					ft_col_print(t_fi_list **begin);
int						ft_direct_path(char **dir);
t_fi_list				**ft_sort_list_size(t_fi_list **begin);
void					ft_swap_list(t_fi_list **begin, t_fi_list *tmp,
				t_fi_list *tmp_bis);

#endif
