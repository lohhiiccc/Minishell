SRCDIR = srcs/
ATOIDIR = atoi_familly/
CHAINEDDIR = chained/
MEMDIR = mem/
PUT_FDDIR = put_fd/
STRDIR = str/
WHODIR = who/
VECTORDIR = vector/
PRINTFDIR = printf/


SRCATOI = ft_atoi \
		  ft_itoa \
		  ft_itoa_base

SRCCHAINED = ft_lstadd_back \
			 ft_lstadd_front \
			 ft_lstclear \
			 ft_lstdelone \
			 ft_lstiter \
			 ft_lstlast \
			 ft_lstnew \
			 ft_lstsize

SRCMEM = ft_bzero \
		 ft_calloc \
		 ft_memchr \
		 ft_memcmp \
		 ft_memcpy \
		 ft_memmove \
		 ft_memset \
		 ft_null_alloc \
		 ft_free_tab

SRCPUTFD = 	ft_putchar_fd \
			ft_putfloat_fd \
			ft_putnbr_fd \
			ft_putstr_fd

SRCSTR = ft_count_word \
		 ft_split \
		 ft_strchr \
		 ft_strdup \
		 ft_striteri \
		 ft_strjoin \
		 ft_strlcat \
		 ft_strlcpy \
		 ft_strlen \
		 ft_strmapi \
		 ft_strncmp \
		 ft_strnstr \
		 ft_strrchr \
		 ft_strtrim \
		 ft_substr \
		 ft_tolower \
		 ft_toupper \
		 ft_strfjoin \
		 ft_strstrfjoin \
		 ft_strcdup \
		 ft_strndup \
		 ft_strcmp

SRCWHO = ft_isalnum \
		 ft_isalpha \
		 ft_isascii \
		 ft_isdigit \
		 ft_isprint

SRCVECTOR = ft_vector_add \
			ft_vector_init \
			ft_vector_resize \
			ft_vector_trim \
			ft_vector_free \
			ft_vector_delete_elem \
			ft_vector_get \
			ft_vector_add_ptr \
			ft_vector_iteri \
			ft_vector_iteri_fd \
			ft_vector_print_int \
			ft_vector_print_str \
			ft_vector_print_str_fd \
			ft_vector_add_n \
			ft_vector_insert

SRCPRINTF = ft_dprintf \
			put_add \
			put_char \
			put_int \
			put_low_hex \
			put_up_hex \
			put_str \
			put_unsigned \
			ft_printf \
			ft_sprintf \
			put_str_free

SRCS = $(addprefix $(SRCDIR)$(ATOIDIR), $(addsuffix .c, $(SRCATOI))) \
	   $(addprefix $(SRCDIR)$(CHAINEDDIR), $(addsuffix .c, $(SRCCHAINED))) \
	   $(addprefix $(SRCDIR)$(MEMDIR), $(addsuffix .c, $(SRCMEM))) \
	   $(addprefix $(SRCDIR)$(PUT_FDDIR), $(addsuffix .c, $(SRCPUTFD))) \
	   $(addprefix $(SRCDIR)$(STRDIR), $(addsuffix .c, $(SRCSTR))) \
	   $(addprefix $(SRCDIR)$(WHODIR), $(addsuffix .c, $(SRCWHO))) \
	   $(addprefix $(SRCDIR)$(VECTORDIR), $(addsuffix .c, $(SRCVECTOR))) \
	   $(addprefix $(SRCDIR)$(PRINTFDIR), $(addsuffix .c, $(SRCPRINTF))) 
