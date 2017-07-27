/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 15:32:09 by jaleman           #+#    #+#             */
/*   Updated: 2016/11/02 15:32:11 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** Header files dependencies.
*/

# include <errno.h>
# include <wchar.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <sys/types.h>

/*
** Attributes for printed text.
*/

# define FT_RESET			(0)
# define FT_BOLD			(1)
# define FT_DIM				(2)
# define FT_ITALICS			(3)
# define FT_UNDERLINE		(4)
# define FT_REVERSE			(7)
# define FT_HIDDEN			(8)
# define FT_STROKE			(9)

/*
** Colors for printed text.
*/

# define FT_BLACK			(0)
# define FT_RED				(1)
# define FT_GREEN			(2)
# define FT_YELLOW			(3)
# define FT_BLUE			(4)
# define FT_MAGENTA			(5)
# define FT_CYAN			(6)
# define FT_WHITE			(7)

/*
** Macros for the limits of the variables.
*/

# define FT_CHAR_BIT		(8)
# define FT_MB_LEN_MAX		(1)
# define FT_SCHAR_MIN		(-128)
# define FT_SCHAR_MAX		(127)
# define FT_UCHAR_MAX		(255)
# define FT_CHAR_MIN		(-128)
# define FT_CHAR_MAX		(127)
# define FT_SHRT_MIN		(-32768)
# define FT_SHRT_MAX		(32767)
# define FT_USHRT_MAX		(65535)
# define FT_INT_MIN			(-2147483648)
# define FT_INT_MAX			(2147483647)
# define FT_LONG_MIN		(-9223372036854775808)
# define FT_LONG_MAX		(9223372036854775807)
# define FT_ULONG_MAX		(18446744073709551615)

/*
** Macro math constants.
*/

# define FT_M_E				(2.71828182845904523540)
# define FT_M_LOG2E			(1.44269504088896340740)
# define FT_M_LOG10E		(0.43429448190325182765)
# define FT_M_LN2			(0.69314718055994530942)
# define FT_M_LN10			(2.30258509299404568402)
# define FT_M_PI			(3.14159265358979323846)
# define FT_M_PI_2			(1.57079632679489661923)
# define FT_M_PI_4			(0.78539816339744830962)
# define FT_M_1_PI			(0.31830988618379067154)
# define FT_M_2_PI			(0.63661977236758134308)
# define FT_M_2_SQRTPI		(1.12837916709551257390)
# define FT_M_SQRT2			(1.41421356237309504880)
# define FT_M_SQRT1_2		(0.70710678118654752440)

/*
** Macro functions.
*/

# define FT_LO(num)			((num) & 0x00FF)
# define FT_HI(num)			(((num) & 0xFF00) >> 8)
# define FT_MIN(x, y)		(x) < (y) ? (x) : (y)
# define FT_MAX(x, y)		(x) > (y) ? (x) : (y)
# define FT_ABS(x)			(((x) < 0) ? -(x) : (x))
# define FT_SIZE(a)			(sizeof(a) / sizeof(a[0]))
# define FT_SWAP(a, b)		({a ^= b; b ^= a; a ^= b;})
# define FT_SQUARE(x)		(x * x)
# define FT_CUBE(x)			(x * x * x)
# define FT_BIT(x)			(1 << (x))
# define FT_STRCMP(A, o, B)	(ft_strcmp((A), (B)) o 0)
# define FT_MEMCMP(A, o, B)	(ft_memcmp((A), (B)) o 0)





# define BUFF_SIZE			(1)
# define MAX_FD				(1024 + 1)
# define GNL_RET_VAL(ret)	(ret > 0 ? 1 : ret)




/*
** List of globlal variables.
*/

# ifndef GLOBAL_VAR
#  define GLOBAL_VAR

static const unsigned long	g_mask01;
static const unsigned long	g_mask80;

# endif

/*
** Define the bool typedef to use for older compilers.
*/

typedef enum		e_bool
{
	FALSE = 0,
	TRUE = 1
}					t_bool;

/*
** Define the structure called t_list, for ft_lst* function.
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Define the structure called t_stack, for ft_stck* function.
*/

typedef struct		s_stack
{
	double			value;
	struct s_stack	*next;
}					t_stack;


/*
** Function prototypes.
*/

int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_isspace(int c);

void		ft_lst_rec_free(t_list *first);

void		ft_lstforeach(t_list *lst, void (*f)());
t_list		*ft_lstpush(t_list *first, void *item);
void		ft_memdel(void **ap);

int			ft_putstr_fd(char const *s, int fd);
int			ft_putchar_fd(char c, int fd);
int			ft_putendl_fd(char const *s, int fd);

void		ft_puterror_fd(char const *msg, int ret, int fd);
char		*ft_strchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_strdel(char **as);
char		*ft_strdup(const char *s1);
int			ft_strequ(char const *s1, char const *s2);
size_t		ft_strlchr(const char *str, int c);
size_t		ft_strlen(const char *s);
char		*ft_strsub(char const *s, unsigned int start, size_t len);

int			get_next_line(int const fd, char **line);

char		*ft_strnew(size_t size);

char		*ft_strcpy(char *dst, const char *src);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strjoin(char const *s1, char const *s2);

#endif
