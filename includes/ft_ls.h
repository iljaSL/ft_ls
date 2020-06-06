/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 10:31:05 by ismelich          #+#    #+#             */
/*   Updated: 2020/06/02 14:49:26 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/includes/libft.h"
# include <dirent.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include <limits.h>
# include <stdio.h>

/*
** SIX_MONTHS -> older than 6 months - year, month and day.
** younger than 6 months - month, day and time.
*/

# define PATH_MAX 		1024
# define FLAGS 			"latrRG"
# define SIX_MONTHS 	15768000
# define D				10

typedef struct	s_ls
{
	struct stat	stat;
	char		*file_name;
	char		*invalid_fname;
	char		*dir_path;
	int			slash_index;
	struct s_ls	*next;
}				t_ls;

typedef struct	s_flags
{
	bool		l : 1;
	bool		a : 1;
	bool		t : 1;
	bool		r : 1;
	bool		cap_r : 1;
	bool		cap_g : 1;
}				t_flags;

typedef struct	s_var
{
	int			i;
	int			tmp_i;
	int			str_len;
	bool		valid_dir;
	bool		new_line;
	bool		dbl_break;
}				t_var;

typedef	struct	s_info
{
	t_flags	flags;
	t_var	var;
	bool	skip_print;
	bool	print_path;
	bool	no_dt_sl;
	char	**argv;
	int		argc;
	int		pad_size;
	int		pad_nlink;
	int		total_blocks;
}				t_info;

bool			set_flags(t_info *info);
bool			is_flag_valid(char c);
int				get_count(t_ls *ls);
int				recursive_call(t_ls *tmp_ls, t_info *info);
int				find_last_slash(char *filepth_with_slash);
int				gather_flags(t_info *info, int i, int j);
char			*ft_strsub_start_end(char *dest, char *src, int start, int end);
char			*ft_strsub_ls(char *dest, char *src, int start);
void			padding_and_blocks(t_ls *ls, int *pad_nlink, int *pad_size);
void			one_arg(t_ls *ls, t_info *info, char *dir_path_str);
void			perm_denied(char *str);
void			merge_sort(t_ls **head_ref, t_info *info);
void			long_format(struct stat meta, char *fn, t_info *info);
void			file_is_link(char *link_str, char *ls_fn, char *str);
void			del_fname(t_ls **head_ref);
void			print_fn(t_ls *ls, t_info *info);
void			parse(t_ls *ls, t_info *info);
void			initialize_tinfo(t_info *info);
void			process_invalid_file(t_ls *ls, t_info *info);
void			front_back_split(t_ls *src, t_ls **front_ref, t_ls **back_ref);
void			sort_merge_invalid_file(t_ls **head_ref);
void			print_invalidfn(t_ls *ls);
void			process_dir(t_ls *ls, t_info *info);
void			process_valid_file(t_ls *ls, t_info *info);
void			check_flag_option(t_info *info, int i, int j);
void			false_dash_usage(t_ls *ls, t_info *info);
void			collect_flags(t_info *info, char c);
void			exit_false_option(char c);
t_ls			*store_fn_i(t_ls *ls, char *fname, int index);
t_ls			*sorted_merge_time(t_ls *a, t_ls *b);
t_ls			*sorted_merge_time_rev(t_ls *a, t_ls *b);
t_ls			*append_slash(t_ls *new_ls, t_ls *tmp_ls, char *path);
t_ls			*create(char *valid_file_pth);
t_ls			*store_fn(t_ls *ls, char *fn);
t_ls			*store_inner_file_rec(t_ls *tmp_ls, t_info *info, DIR *dir);
t_ls			*store_root_files(t_ls *ls, t_info *info, char *dir_str);
t_ls			*msorted_invalid_fn(t_ls *a, t_ls *b);

#endif
