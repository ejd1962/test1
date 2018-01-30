#ifndef _MEM_H_
#define _MEM_H_



#ifdef IBMPC
//#include <alloc.h>
#include <stdlib.h>
#endif
#include "misc.h"
#include "defs.h"
#include "cvt.h"
#include "struct.h"

/*
 *	Memory allocation and deallocation routines.
 */

/*
 *	Allocate memory
 */
char *get_mem
(
   unsigned int	size
);


void get_context_ptr
(
   CONTEXT_t	**context
);


void get_token_ptr
(
   TOKEN_t	**token
);


void get_var_ptr
(
   DECL_ID_t	**var
);


void free_var_list
(
   DECL_ID_t	*list_ptr
);


void get_element_ptr
(
   DECL_MEMBER_t	**element
);

void free_decl_list
(
   DECL_MEMBER_t	*element
);

void get_param_ptr
(
   PARAM_LIST_t	**param
);


void free_param_list
(
   PARAM_LIST_t	*param_list
);


void get_decl_ptr
(
   DECL_t	**decl
);


void free_decl
(
   DECL_t	*decl_list
);

#endif // _MEM_H_
