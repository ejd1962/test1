

#include "all_headers.h"


/*
 *	Memory allocation and deallocation routines.
 */

/*
 *	Allocate memory
 */
char *get_mem
(
   unsigned int	size
)
{
	char	*malloc_ptr;
	void	*malloc();

	if ((malloc_ptr = (char *)malloc(size)) == NULL) {
		parse_error("Out of memory");
		exit(1);
	}
	return malloc_ptr;
}

/*
 *	Generate a new context.
 */
void get_context_ptr
(
   CONTEXT_t	**context
)
{
	*context = (CONTEXT_t *) get_mem(sizeof(CONTEXT_t));
	(*context)->decl_head = NULL;
	(*context)->next_context = NULL;
}

/*
 *	Malloc memory for a TOKEN.
 */
void get_token_ptr
(
   TOKEN_t	**token
)
{
	*token = (TOKEN_t *) get_mem(sizeof(TOKEN_t));
}

/*
 *	Malloc memory for a DECL_ID.
 */
void get_var_ptr
(
   DECL_ID_t	**var
)
{
	*var = (DECL_ID_t *) get_mem(sizeof(DECL_ID_t));
	(*var)->name = NULL;
	(*var)->based_name = NULL;
	(*var)->next_var = NULL;
	(*var)->is_ext_at = FALSE;
}

/*
 *	Free a linked list of variables.
 */
void free_var_list
(
   DECL_ID_t	*list_ptr
)
{
	DECL_ID_t	*next_ptr;

	while (list_ptr) {
		if (list_ptr->name)
			free( (char *) list_ptr->name);
		if (list_ptr->based_name)
			free( (char *) list_ptr->based_name);
		next_ptr = list_ptr->next_var;
		free((char *) list_ptr);
		list_ptr = next_ptr;
	}
}

/*
 *	Malloc space for a DECL_MEMBER structure and return pointer.
 */
void get_element_ptr
(
   DECL_MEMBER_t	**element
)
{
	DECL_MEMBER_t	*el_ptr;

		/* Malloc space for element */
	el_ptr = (DECL_MEMBER_t *) get_mem(sizeof(DECL_MEMBER_t));

		/* Init pointers */
	el_ptr->name_list = NULL;
	el_ptr->literal = NULL;
#ifdef PARSE_LITERALS
	el_ptr->literal_token = NULL;
#endif
	el_ptr->array_bound = NULL;
	el_ptr->type = NULL;
	el_ptr->struct_list = NULL;
	el_ptr->at_ptr = NULL;
	el_ptr->init_ptr = NULL;
	el_ptr->next_member = NULL;

	el_ptr->attributes = NONE;
	el_ptr->initialization = NONE;

	*element = el_ptr;
}

/*
 *	Free a DECL_MEMBER list.
 */
void free_decl_list
(
   DECL_MEMBER_t	*element
)
{
	DECL_MEMBER_t	*el_ptr;

	while (element) {
		if (element->name_list)
			free_var_list(element->name_list);
		if (element->literal)
			free((char *) element->literal);
		if (element->array_bound)
			free((char *) element->array_bound);
		if (element->type)
			free((char *) element->type);
		if (element->struct_list)
			free_decl_list(element->struct_list);
		if (element->at_ptr)
			free(element->at_ptr);

		el_ptr = element->next_member;
		free((char *) element);
		element = el_ptr;
	}
}

/*
 *	Malloc space for a procedure parameter
 */
void get_param_ptr
(
   PARAM_LIST_t	**param
)
{
	*param = (PARAM_LIST_t *) get_mem(sizeof(PARAM_LIST_t));
	(*param)->next_param = NULL;
}

/*
 *	Free parameter list
 */
void free_param_list
(
   PARAM_LIST_t	*param_list
)
{
	PARAM_LIST_t	*param_ptr;

	while (param_list) {
		param_ptr = param_list->next_param;
		free((char *) param_list);
		param_list = param_ptr;
	}
}

/*
 *	Malloc space for a DECLARE statement
 */
void get_decl_ptr
(
   DECL_t	**decl
)
{
	*decl = (DECL_t *) get_mem(sizeof(DECL_t));
	(*decl)->decl_list = NULL;
	(*decl)->next_decl = NULL;
}

/*
 *	Free DECL list
 */
void free_decl
(
   DECL_t	*decl_list
)
{
	DECL_t	*decl_ptr;

	while (decl_list) {
		decl_ptr = decl_list->next_decl;
#ifdef FREE_DECL_TOKEN
		if (decl_list->decl_token)
			free((char *) decl_list->decl_token);
#endif
		if (decl_list->decl_list)
			free_decl_list(decl_list->decl_list);
		free((char *) decl_list);
		decl_list = decl_ptr;
	}
}


