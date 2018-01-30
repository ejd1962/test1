
#ifndef _CONTEXT_H_
#define _CONTEXT_H_



int find_member_symbol
( 
   TOKEN_t		*symbol 
,  DECL_MEMBER_t	*decl_ptr 
,  DECL_ID_t		**decl_id 
);


int find_list_symbol
(
   TOKEN_t		 *symbol 
,  DECL_MEMBER_t  *decl_ptr  
,  DECL_MEMBER_t  **decl_found 
,  DECL_ID_t		 **decl_id 
);


int find_symbol( 
   TOKEN_t		*symbol 
,  DECL_MEMBER_t	**decl_found 
,  DECL_ID_t		**decl_id 
);


void add_to_context
( 
   DECL_MEMBER_t	*decl
);


void add_decl_to_context
(
   DECL_t	*decl
);


void new_context
( 
   int	type 
,  TOKEN_t	*name 
);


void pop_context
(
);


void init_context
(
);

#endif // _CONTEXT_H_

