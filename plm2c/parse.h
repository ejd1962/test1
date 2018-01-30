void get_param_list( 
PARAM_LIST_t	**param_head);


void parse_param_list
( 
   PARAM_LIST_t	 *param_list, 
   DECL_t		**decl_list, 
   DECL_t	    **extra_decl_list
);


void parse_till
(  
   int	type,
   TOKEN_t	*token
);


void parse_till_end
(  
   TOKEN_t	*token
);


void parse_to_end
(
);



void check_eol
(
);



int parse_simple_variable
( 
   TOKEN_t   *token, 
   TOKEN_t   *next_token
);




void out_ident
( 
   TOKEN_t		*ident,
   DECL_MEMBER_t	*decl,
   DECL_ID_t		*decl_id
);



int parse_member
( 
   TOKEN_t		*token,
   DECL_MEMBER_t	*decl,
   DECL_ID_t		*decl_id
);



int parse_variable
( 
   TOKEN_t		*token,
   DECL_MEMBER_t	**var_decl,
   DECL_ID_t		**var_decl_id
);


int check_cvt_id
( 
   TOKEN_t	*token,
   CVT_ID_t	*cvt_id,
   char   	**cvt_string
);



int parse_function
( 
   TOKEN_t	*token
);


int parse_expression
( 
   TOKEN_t	*token
);



void parse_do
( 
   TOKEN_t	*first_token
);


void parse_end
( 
   TOKEN_t	*first_token
);

void parse_if
( 
   TOKEN_t	*first_token
);

void parse_then
(
);


void parse_else
( 
   TOKEN_t	*first_token
);


void parse_goto
( 
   TOKEN_t	*first_token
);



void parse_go
( 
   TOKEN_t	*first_token
);



void parse_call
( 
   TOKEN_t	*first_token
);




void parse_return
( 
   TOKEN_t	*first_token
);


void parse_identifier
( 
   TOKEN_t	*first_token
);



void parse_label
(
);


void parse_eol
( 
   TOKEN_t	*first_token
);


void parse_int_ctl
( 
   TOKEN_t	*first_token
);




void parse_outport
(
);



void parse_output
( 
   TOKEN_t	*first_token
);



void parse_outword
(  
   TOKEN_t	*first_token
);



void parse_outhword
( 
   TOKEN_t	*first_token
);



