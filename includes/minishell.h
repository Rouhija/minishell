/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:33:38 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/06 15:25:18 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** -------- HEADERS --------
*/

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>

/*
** -------- MACROS --------
*/

char	**g_env;

/*
** -------- TYPEDEFS --------
*/

# define BUF_SIZE 4096
# define SH_UNSET "/*deleted*/"

/*
** -------- FUNCTIONS --------
*/

int		exec_cmd(char **cmd);
int		echo_builtin(char **args);
int		cd_builtin(char **args);
int		display_env(void);
int		find_env(char *var);
int		setenv_builtin(char **cmd);
int		unsetenv_builtin(char **args);
int		recover_builtin(char **args);

char	*get_env(char *var);
char	**realloc_arr(size_t size);
char	*parse_path(char *cwd);

void	set_env(char *key, char *value);
void	init_env(int ac, char **av, char **env);
void	read_input(char **input);
void	exit_shell(int reason);
void	parent_signal_handler(int signo);
void	child_signal_handler(int signo);
void	display_prompt(void);

#endif
