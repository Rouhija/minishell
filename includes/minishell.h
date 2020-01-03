/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:33:38 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/03 19:38:53 by srouhe           ###   ########.fr       */
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

/*
** -------- FUNCTIONS --------
*/

int		env_len(char **env);
int		display_env(void);
int		find_env(char *var);
int		setenv_builtin(char **cmd);
int		unsetenv_builtin(char **args);
void	init_env(int ac, char **av, char **env);
void	exit_shell(int reason);
void	signal_handler(int signo);
void	sub_signal_handler(int signo);
void	display_prompt(void);
int		exec_cmd(char **cmd);
int		echo_builtin(char **args);

#endif
