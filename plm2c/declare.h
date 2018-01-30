void find_right_paren
(
);


void element_copy
(
   DECL_MEMBER_t *src  
,  DECL_MEMBER_t *dest
);


int get_var_list
(
   DECL_ID_t	**list_ptr 
,  TOKEN_t	*sep_token
);



void parse_structure
( 
   DECL_MEMBER_t	**list_ptr 
);

int parse_type
(
   DECL_MEMBER_t	*el_ptr 
,  TOKEN_t		*token
);



int get_element
( 
  DECL_MEMBER_t	**element 
, TOKEN_t		    *token
);



void get_decl_list
( 
   DECL_t	*decl 
);


void parse_declare
( 
   TOKEN_t	*first_token
);
