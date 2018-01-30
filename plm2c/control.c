

#include "all_headers.h" 

/*
 *	Control directives list
 */
RESERVED_WORD_t control_directives[] = {
#ifdef	USE_ALL_CONTROLS
	"CODE",		C_CODE,
	"CO",		C_CODE,
	"NOCODE",	C_NOCODE,
	"NOCO",		C_NOCODE,
	"COND",		C_COND,
	"NOCOND",	C_NOCOND,
	"DEBUG",	C_DEBUG,
	"DB",		C_DEBUG,
	"NODEBUG",	C_NODEBUG,
	"NODB",		C_NODEBUG,
	"EJECT",	C_EJECT,
	"EJ",		C_EJECT,
#endif
	"IF",		C_IF,
	"ELSEIF",	C_ELSEIF,
	"ELSE",		C_ELSE,
	"ENDIF",	C_ENDIF,
	"INCLUDE",	C_INCLUDE,
	"IC",		C_INCLUDE,
#ifdef	USE_ALL_CONTROLS
	"INTERFACE",	C_INTERFACE,
	"ITF",		C_INTERFACE,
	"LEFTMARGIN",	C_LEFTMARGIN,
	"LM",		C_LEFTMARGIN,
	"LIST",		C_LIST,
	"LI",		C_LIST,
	"NOLIST",	C_NOLIST,
	"NOLI",		C_NOLIST,
	"OBJECT",	C_OBJECT,
	"OJ",		C_OBJECT,
	"NOOBJECT",	C_NOOBJECT,
	"NOOJ",		C_NOOBJECT,
	"OPTIMIZE",	C_OPTIMIZE,
	"OT",		C_OPTIMIZE,
	"OVERFLOW",	C_OVERFLOW,
	"OV",		C_OVERFLOW,
	"NOOVERFLOW",	C_NOOVERFLOW,
	"NOOV",		C_NOOVERFLOW,
	"PAGELENGTH",	C_PAGELENGTH,
	"PL",		C_PAGELENGTH,
	"PAGEWIDTH",	C_PAGEWIDTH,
	"PW",		C_PAGEWIDTH,
	"PAGING",	C_PAGING,
	"PI",		C_PAGING,
	"NOPAGING",	C_NOPAGING,
	"NOPI",		C_NOPAGING,
	"PRINT",	C_PRINT,
	"PR",		C_PRINT,
	"NOPRINT",	C_NOPRINT,
	"NOPR",		C_NOPRINT,
	"RAM",		C_RAM,
	"ROM",		C_ROM,
	"SAVE",		C_SAVE,
	"SA",		C_SAVE,
	"RESTORE",	C_RESTORE,
	"RS",		C_RESTORE,
#endif
	"SET",		C_SET,
	"RESET",	C_RESET,
#ifdef	USE_ALL_CONTROLS
	"SMALL",	C_SMALL,
	"SM",		C_SMALL,
	"COMPACT",	C_COMPACT,
	"CP",		C_COMPACT,
	"MEDIUM",	C_MEDIUM,
	"MD",		C_MEDIUM,
	"LARGE",	C_LARGE,
	"LA",		C_LARGE,
	"SUBTITLE",	C_SUBTITLE,
	"ST",		C_SUBTITLE,
	"SYMBOLS",	C_SYMBOLS,
	"SB",		C_SYMBOLS,
	"NOSYMBOLS",	C_NOSYMBOLS,
	"NOSB",		C_NOSYMBOLS,
	"TITLE",	C_TITLE,
	"TT",		C_TITLE,
	"TYPE",		C_TYPE,
	"TY",		C_TYPE,
	"NOTYPE",	C_NOTYPE,
	"NOTY",		C_NOTYPE,
	"XREF",		C_XREF,
	"XR",		C_XREF,
	"NOXREF",	C_NOXREF,
	"NOXR",		C_NOXREF,
	"INTVECTOR",	C_INTVECTOR,
	"IV",		C_INTVECTOR,
	"NOINTVECTOR",	C_NOINTVECTOR,
	"NOIV",		C_NOINTVECTOR,
	"MOD86",	C_MOD86,
	"MOD186",	C_MOD186,
	"WORD16",	C_WORD16,
	"W16",		C_WORD16,
	"WORD32",	C_WORD32,
	"W32",		C_WORD32,
#endif
		/* End of list */
	"",		END_OF_FILE
};

extern	char	*text_buffer;
extern	char	*text_ptr;

/*
 *	Parse a control directive.
 *	Handles:		Abbreviation:
 *		$INCLUDE	$IC
 *		$SET
 *		$RESET
 *		$IF
 *		$ELSE
 *		$ELSEIF
 *		$ENDIF
 */
void parse_control()
{
	TOKEN_t		ctl_token, token;
	int		token_class;
	RESERVED_WORD_t	*word_ptr;
	char		include_file[128], *include_ptr;

	token_class = get_token(&ctl_token);
	if (token_class != IDENTIFIER) {
		control_error("Invalid directive");
		return;
	}

	for (word_ptr = &control_directives[0]; word_ptr->token != END_OF_FILE;
			word_ptr++) {
	    if ((strlen(word_ptr->name) == ctl_token.token_length) &&
		!strncmp(word_ptr->name, ctl_token.token_start,
				ctl_token.token_length)) {
		switch (word_ptr->token) {

		case C_INCLUDE :
			token_class = get_token(&token);
			if (token_class != LEFT_PAREN) {
				control_error("'(' expected");
				return;
			}
				/* Copy and send file name (up to ')') */
			include_ptr = include_file;
			while (*text_ptr != ')') {
				if ((*text_ptr >= 'A') && (*text_ptr <= 'Z'))
						/* Convert to lower case */
					*include_ptr++ = *text_ptr++ + ' ';
				else
					*include_ptr++ = *text_ptr++;
			}
			*include_ptr++ = '\0';

				/* Skip ')' */
			text_ptr++;

				/* Parse include file */
			cvt_file(include_file);

				/* Convert .plm to .c */
			if (strcmp(include_ptr - 5, "plm")) {
				(void) strcpy(include_ptr - 5, ".c");
				include_ptr -= 2;
			}

			out_to_start();
			out_str("#include");
			out_must_white(&token);
			out_char('"');
			out_str(include_file);

			out_char('"');
			return;

		default :
			control_error("Non-supported directive");
			return;
		}
	    }
	}

	control_error("Invalid directive");
}

