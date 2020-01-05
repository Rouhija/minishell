/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:33:38 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/05 16:17:59 by srouhe           ###   ########.fr       */
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

/*
** -------- FUNCTIONS --------
*/

int		display_env(void);
int		find_env(char *var);
char	*get_env(char *var);
int		setenv_builtin(char **cmd);
void	set_env(char *key, char *value);
int		unsetenv_builtin(char **args);
char	**realloc_arr(size_t size);
char		*parse_path(char *cwd);
void	read_input(char **input);
void	init_env(int ac, char **av, char **env);
void	exit_shell(int reason);
void	parent_signal_handler(int signo);
void	child_signal_handler(int signo);
void	display_prompt(void);
int		exec_cmd(char **cmd);
int		echo_builtin(char **args);
int		cd_builtin(char **args);

#endif
