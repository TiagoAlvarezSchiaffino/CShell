/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_expand_files.c                                           	          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/30 18:00:51 by Tiago                   /   (_____/      */
/*   Updated: 2024/06/14 07:30:32 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/**
 * @brief Get the dir object
 * 
 * @param path Path of the dir
 * @return DIR* object
 */
DIR	*ms_get_dir(char *path)
{
	DIR	*dir;

	dir = opendir(path);
	free(path);
	return (dir);
}

/**
 * @brief Store the files in linked list format. Reads through every file name
 * and checks whether it is valid according to the argument. If it is, store the
 * file name into a linked list
 * 
 * @param entity Dirent from readdir
 * @param dir Directory object
 * @param arg Argument to check if a file name is valid
 * @param file_name File name of the first valid file if there's one
 * @return t_list * Head of the filename's linked list.
 */
static t_list	*get_files_lst(struct dirent *entity, DIR *dir,
	char *arg, char *file_name)
{
	t_list	*current;
	t_list	*head;

	current = ft_lstnew(ft_calloc(1, sizeof(char *)));
	head = current;
	ft_memcpy(current->content, &file_name, sizeof(char *));
	entity = readdir(dir);
	while (entity != NULL)
	{
		file_name = ft_strdup(entity->d_name);
		if (ms_is_valid(file_name, arg))
		{
			current->next = ft_lstnew(ft_calloc(1, sizeof(char *)));
			current = current->next;
			ft_memcpy(current->content, &file_name, sizeof(char *));
		}
		else
			free(file_name);
		entity = readdir(dir);
	}
	closedir(dir);
	ms_lstsort(&head);
	return (head);
}

/**
 * @brief Get the files from dir object. Checks through every file name for the
 * first node. If reached NULL and no suitable file was found, return NULL, else
 * returns the head of the file name linked list
 * 
 * @param arg Argument to check if a file name is valid
 * @return t_list * Head of the filename's linked list, NULL if there are no
 * valid files
 */
t_list	*ms_get_files_from_dir(char *arg)
{
	DIR					*dir;
	struct dirent		*entity;
	char				*file_name;

	dir = ms_get_dir(getcwd(NULL, 0));
	entity = readdir(dir);
	while (entity != NULL)
	{
		file_name = ft_strdup(entity->d_name);
		if (ms_is_valid(file_name, arg) == 0)
			entity = readdir(dir);
		else
			break ;
		free(file_name);
	}
	if (entity == NULL)
	{
		closedir(dir);
		return (NULL);
	}
	return (get_files_lst(entity, dir, arg, file_name));
}