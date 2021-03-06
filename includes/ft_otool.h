/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 14:39:26 by nfruneau          #+#    #+#             */
/*   Updated: 2015/01/28 12:50:37 by nfruneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OTOOL_H
# define FT_OTOOL_H

# define BLUE "\x1B[34m"
# define CYAN "\x1B[36m"
# define YELLOW "\x1B[33m"
# define MAGENTA "\x1B[35m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define B_YELLOW_BLUE "\x1B[103m\x1B[34m"
# define B_CYAN_BLUE "\x1B[46m\x1B[34m"
# define NORMAL "\x1B[0m"

# include <mach-o/loader.h>

typedef	struct		s_sect
{
	char			*name;
	int				sect_nbr;
	struct s_sect	*next;
}					t_sect;

typedef	struct		s_flag
{
	char			p;
	char			j;
	char			r;
	char			u;
	char			up_u;
}					t_flag;

typedef struct		s_file
{
	char			*name;
	char			type;
	unsigned long	value;
	char			show_addr;
	int				arch;
	struct s_file	*next;
}					t_file;

typedef struct		s_arch
{
	char			*name;
	uint32_t		strx;
	uint32_t		off;
	struct s_arch	*next;
}					t_arch;

typedef struct		s_data
{
	int				arg_nbr;
	t_flag			flag;
	t_sect			*sect;
	t_file			*file;
	t_arch			*arch;
}					t_data;

int					skip_flags(char **argv);
int					arg_nbr(char **argv);
int					ft_otool(char *argv, t_data data);
int					load_arch_64(char *argv, char *ptr, t_data data,
								int display);
int					load_arch_32(char *argv, char *ptr, t_data data,
								int display);
void				load_archive(char *argv, char *ptr, t_data data);
int					load_arch(char *argv, char *ptr, t_data data, int display);
void				free_file(t_file *file);
void				free_sect(t_sect *sect);
void				reset_data(t_data *data);
void				init_data(t_data *data, char **argv);
t_flag				new_flag(void);
t_flag				set_flag(t_flag flag, char c);
t_flag				init_flag(char **argv);
int					is_flag(char c);
int					parse_cmd(char **argv);
int					ft_error(char *s, char *s2);
unsigned long		ft_ullen(unsigned long n);
void				print_addr(long unsigned int addr);
void				ft_putaddr(unsigned long n);
void				sort_rev_ascii(t_file **file, t_file *tmp);
void				sort_ascii(t_file **file, t_file *tmp);
void				no_sort(t_file **file, t_file *tmp);
void				sort_list(t_file **file, t_file *tmp, t_flag flag);
char				read_tab(int i);
char				*ft_itoa_base(int val, int base, int output_size);
int					print_section(struct section_64 *section, char *ptr);
int					add_section(void *lc, t_data *data, char *ptr);
int					get_sect_64(char *ptr, t_data *data);
void				print_addr_32(long unsigned int addr);
int					print_section_32(struct section *section, char *ptr);
int					add_section_32(void *lc, t_data *data, char *ptr);
int					get_sect_32(char *ptr, t_data *data);
int					get_size(char *name);
char				*get_ar_name(char *name);
void				sort_ar(t_arch *arch, t_arch *tmp);
int					handle_ar(char *ptr, t_data *data, uint32_t r_strx,
								uint32_t r_off);
void				print_ar(char *argv, char *ptr, t_data data);
uint32_t			endianness(uint32_t value);
void				handle_fat(char *argv, char *ptr, t_data data);

#endif
