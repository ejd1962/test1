
#ifndef _STRUCT_H_
#define _STRUCT_H_

#define PARSE_LITERALS

/*
 *	Format of a token returned by get_token().
 */
typedef struct TOKEN_t TOKEN_t ;
struct TOKEN_t {
		/* Class of token (see below) */
	int	token_class;
		/* Type of token (see below) */
	int	token_type;
		/* Converted token name (when applicable) */
	char	token_name[MAX_TOKEN_LENGTH];
		/* Pointer to start of token in text_buffer */
	char	*token_start;
		/* Number of characters token_start points to */
	int	token_length;
		/* Pointer to start of white space in text_buffer */
	char	*white_space_start;
		/* Pointer to char after end of white space in text_buffer */
	char	*white_space_end;
#ifdef LINKED_TOKENS
		/* Pointer for use in linked list */
	TOKEN_t	*next_token;
#endif
} ;

/*
 *	Format of a procedure parameter list
 */
typedef struct PARAM_LIST_t PARAM_LIST_t ;
struct PARAM_LIST_t {
		/* Parameter name */
	TOKEN_t    	 param;
		/* Pointer for use in linked list */
	PARAM_LIST_t *next_param;
} ;

/*
 *	Format of a variable in a DECLARE statement.
 */
typedef struct DECL_ID_t DECL_ID_t ;
struct DECL_ID_t {
		/* Variable name */
	TOKEN_t	    *name;
		/* BASED identifier token */
	TOKEN_t	    *based_name;
		/* If declared AT in another module */
	BOOLEAN_t	is_ext_at;
		/* Pointer for use in linked list */
	DECL_ID_t   *next_var;
} ;

/*
 *	Format of an element in a DECLARE statement.
 */
typedef struct DECL_MEMBER_t DECL_MEMBER_t ;
struct DECL_MEMBER_t {
		/* Linked list of identifiers of designated type */
	DECL_ID_t	*name_list;
		/* LITERALLY string */
	char	*literal;
#ifdef PARSE_LITERALS
		/* Parsed LITERAL token */
	TOKEN_t	*literal_token;
#endif
		/* Array bound token */
	TOKEN_t	*array_bound;
		/* Type of variable (INTEGER, WORD, LABEL, LITERALLY, etc.) */
	TOKEN_t	*type;
		/* Attributes (NONE, EXTERNAL or PUBLIC) */
	int	attributes;
		/* Initialization attribute (NONE, INITIAL or DATA) */
		/* If PROCEDURE, DATA if has parameters */
	int	initialization;
		/* Pointer to linked list of structure elements */
	DECL_MEMBER_t *struct_list;
		/* Pointer to parsed AT expression */
	char	*at_ptr;
		/* Pointer in text_buffer to start of INITIAL/DATA values */
	char	*init_ptr;
		/* Pointer for use in linked list */
	DECL_MEMBER_t *next_member;
} ;

/*
 *	Format of a DECLARE statement.
 */
typedef struct DECL_t DECL_t ;
struct DECL_t {
		/* DECLARE token */
	TOKEN_t		    *decl_token;
		/* Linked list of DECL_MEMBERs */
	DECL_MEMBER_t	*decl_list;
		/* Pointer for use in linked list */
	DECL_t	        *next_decl;
} ;

/*
 *	Format of a context element
 */
typedef struct CONTEXT_t CONTEXT_t ;
struct CONTEXT_t {
		/* Type of context (MODULE, PROCEDURE or DO) */
	int	            context_type;
		/* Name of module or procedure */
	TOKEN_t	        *context_name;
		/* Pointer to linked list of declaration members */
	DECL_MEMBER_t	*decl_head;
		/* Pointer for use in linked list */
	CONTEXT_t	    *next_context;
} ;


/*
 *	Format of a PL/M identifier equivalent
 */
typedef struct CVT_ID_t CVT_ID_t  ;
struct CVT_ID_t {
	char	*id_name;
	char	*new_id;
} ;


/*
 *	Format of a PL/M reserved word
 */
typedef struct RESERVED_WORD_t RESERVED_WORD_t ;
struct RESERVED_WORD_t {
	char	*name;
	int	    token;
} ;

/*
 *	Format of a PL/M reserved operator
 */
typedef struct RESERVED_OPERATOR_t RESERVED_OPERATOR_t ;
struct RESERVED_OPERATOR_t {
	char	*operator;
	char	*cvt_operator;
	int	    name;
};

#endif // _STRUCT_H_
