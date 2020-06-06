/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:59:04 by ismelich          #+#    #+#             */
/*   Updated: 2020/06/02 14:42:42 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <float.h>
# include <stdarg.h>
# include <limits.h>

/*
** Define Font Color
*/

# define BLACK				"\033[0:30m"
# define BOLD_BLACK			"\033[1:30m"
# define RED 				"\033[0;31m"
# define BOLD_RED 			"\033[1;31m"
# define GREEN 				"\033[0;32m"
# define BOLD_GREEN 		"\033[1;32m"
# define YELLOW 			"\033[0;33m"
# define BOLD_YELLOW 		"\033[01;33m"
# define BLUE 				"\033[0;34m"
# define BOLD_BLUE 			"\033[1;34m"
# define MAGENTA 			"\033[0;35m"
# define BOLD_MAGENTA 		"\033[1;35m"
# define CYAN 				"\033[0;36m"
# define BOLD_CYAN 			"\033[1;36m"
# define WHITE				"\033[0:37m"
# define BOLD_WHITE			"\033[1:37m"
# define RESET 				"\033[0m"

/*
** Define Background Color
*/

# define BG_BLACK			"\033[0:40m"
# define BG_BOLD_BLACK		"\033[1:40m"
# define BG_RED 			"\033[0;41m"
# define BG_BOLD_RED 		"\033[1;41m"
# define BG_GREEN 			"\033[0;42m"
# define BG_BOLD_GREEN 		"\033[1;42m"
# define BG_YELLOW 			"\033[0;43m"
# define BG_BOLD_YELLOW 	"\033[1;43m"
# define BG_BLUE 			"\033[0;44m"
# define BG_BOLD_BLUE 		"\033[1;44m"
# define BG_MAGENTA 		"\033[0;45m"
# define BG_BOLD_MAGENTA 	"\033[1;45m"
# define BG_CYAN 			"\033[0;46m"
# define BG_BOLD_CYAN 		"\033[1;46m"
# define BG_WHITE			"\033[0:47m"
# define BG_BOLD_WHITE		"\033[1:47m"

/*
** Defined Macros
*/

# define H					1
# define HH					2
# define L					3
# define LL					4
# define J					5
# define Z					6
# define CAPL				7
# define POSITIVE			8
# define NEGATIVE			9
# define FCONVERSION		"cspdiouxXf%"
# define FFLAGS				"#-+ .*0123456789hljz"
# define ASYMBOLS			"cspdiouxXf%#-+ .*0123456789hLljz"
# define BUFF_SIZE          32
# define FD_SIZE            4864

typedef struct	s_struct
{
	int		i;
	int		len;
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		hash;
	int		precision;
	int		width;
	int		length;
	int		n_print;
	int		precision_dot;
	char	*format;
}				t_struct;

typedef struct	s_fstruct
{
	char		*s1;
	char		*s2;
	char		c;
	char		sign;
	int			sign_int;
	int			before_dec_nbr;
	int			hash;
	int			dot;
	int			zeros;
	int			precisionadd;
	int			padding;
	long double	i;
	long double	flt;
	int			precision;
}				t_fstruct;

char			find_char(t_struct *f);
char			*ft_strdup(const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strncat(char *dest, const char *src, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strstr(const char *str, const char *search_string);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strnew(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strcpy(char *dest, const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_strndup(const char *str, size_t len);
char			*ft_itoa(int n);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_toupper_str(char *str, int len);
char			*ft_itoa_base_upper(intmax_t value, intmax_t base);
int				ft_words_counter(char *str);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_isspace(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isprint(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_isblank(int c);
int				ft_islower(int c);
int				ft_isupper(int c);
int				par1(const char *format, t_struct *list, va_list ap, int pos);
int				par2(t_struct *f, int position, const char *format, va_list ap);
int				unbr_len(uintmax_t n, int base);
int				snbr_len(intmax_t n, int base);
int				ft_printf(const char *format, ...);
int				get_next_line(const int fd, char **line);
int				ft_nbrlen(int_fast64_t value, int base);
void			ft_putchar(char c);
void			ft_putstr(char const *str);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *str, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl(char const *str);
void			ft_putendl_fd(char const *str, int fd);
void			*ft_memset(void *str, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *str1, const void *str2, size_t n);
void			*ft_memccpy(void *str1, const void *str2, int c, size_t n);
void			*ft_memmove(void *str1, const void *str2, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			error(void);
void			w_start(const char *format, t_struct *f, va_list ap);
void			modifie(const char *format, t_struct *f, va_list ap);
void			initialize(t_struct *list);
void			write_zeros(int n);
void			write_blank(int n);
void			display_char(t_struct *f, va_list ap);
void			convert(char c, va_list ap, t_struct *f);
void			display_str(t_struct *f, va_list ap);
void			display_uint(t_struct *f, va_list ap);
void			display_pointer(t_struct *f, va_list ap, int hex);
void			display_hex(t_struct *f, va_list ap, char x);
void			display_octal(t_struct *f, va_list ap);
void			display_string(t_struct *f, va_list ap);
void			display_int(t_struct *f, va_list ap, int sign, intmax_t n);
void			aligned_right_flt(t_struct *f, t_fstruct g);
void			aligned_left_flt(t_struct *f, t_fstruct g);
void			display_float(t_struct *f, va_list ap);
void			re_initialize(t_struct *list);
void			percent_case(t_struct *f);
size_t			ft_strlcat(char *dest, const char *src, size_t destsize);
size_t			ft_strlen(const char *str);
int				ft_abs(int n);
char			*ft_itoa_base(uintmax_t value, uintmax_t base);

#endif
