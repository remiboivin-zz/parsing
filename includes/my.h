#ifndef _MY_H_
#define _MY_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <libmy.h>
#include <string.h>


/* typedef struct	s_AI */
/* { */
/*   char		**verbes; */
/*   char		**sujets; */
/*   char		**complements; */
/*   char		*sujet_phrase; */
/*   char		*verbe_phrase; */
/*   char		*complement_phrase; */
/* }		t_AI; */

typedef struct	t_datas t_datas;

struct  t_datas
{
  char		*verbes; /* le verbe de la phrase */
  char		*sujets; /* le sujet de la phrase */
  char		*complements; /* le complement de la phrase */
  char		*pronom;      /*  pour vérifier la conjugaison du verbe */
  char		*terminaison; /*  terminaison du verbe pour pouvoir checker la congugaison de celui-ci */
  t_datas	*next; /* elements suivant */
};

typedef struct	s_list1
{
  t_datas	*first;
}		t_list1;

int		cmd();			/* src/cmd.c */
int		check_verbe_list(t_list1 *list, char **tab); /* vérifie si le verbe entré est reconnu. src/check_list.c */
int		check_verbe_G1(t_list1 *list, char *str);    /*  Vérifie la conjugaison des verbes du premier groupe */
int		check_verbe_G2(t_list1 *list, char *str);    /* Vérifie la conjugaison des verbes du seconds groupe */
int		check_conjugaison(t_list1 *list, char *buff); /*  Récupère les valeurs retournées par check_verbe_G1 et check_verbe_G2 */
int		check_complements_list(t_list1 *list, char **tab);
/* t_AI		*init(t_AI *AI);		/\* Initialiise la structure AI. src/init.c *\/ */

t_list1		*init_list();	/* Initialise la liste chainée qui contiendra les datas. src/init_list.c */

t_datas		*deleteNode (t_datas * L, char *val);

/* void		get_verbes(t_AI *AI);	/\* récupère les verbes dans datas/verbes. src/gets.c *\/ */
/* void		get_sujets(t_AI *AI);	/\* récupère les sujets dans datas/sujets. src/gets.c *\/ */
void	        del_list(t_list1 *list); /* Détruit le contenu de la liste chainée list. src/my_list.c */
void		get_verbe_list();	/* Récupère les verbes. src/gets_list.c */
void		aff_list1(t_list1 *list); /* Affiche la liste chainée list. src/my_list.c */
void		add_list(t_list1 *list, char *str); /* Ajoute les datas dans la liste chainée list. src/my_list.c */
void		add_list_tem(t_list1 *list, char **str); /* Ajoute la terminaison des verbes dans la liste chainée list. src/my_list.c */
void		add_list_pronom(t_list1 *list, char **tab); /* Ajoute la terminaison des verbes dans la liste chainée list. src/my_list.c */
void		aff_list_pronom(t_list1 *list); /* Affiche les terminaison des verbes de la liste chainée list */
void		aff_list_term(t_list1 *list); /* Affiche les terminaison des verbes de la liste chainée list */
void		add_list_complements(t_list1 *list, char *str); /* Ajoute les complements à la liste chainée list */
void		get_complements_list(t_list1 *list);
void		aff_list_complements(t_list1 *list);

t_datas		*del_verbe_list(t_datas *datas, char *str);

#endif
