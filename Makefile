# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#              #
#    Updated: 2022/11/05 21:53:14 by Yoshihiro K      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************** Section for Macros (Variables) ********************** #
# Product file
NAME_SV		= server
NAME_CL		= client

# Component names
LIBNAME		= libfts

# Enumeration of files
SRC_SV		= sv_main.c sv_daemon.c sv_catcher.c sv_handler.c \
			  sv_inform.c sv_printer.c
SRC_CL		= cl_main.c cl_catcher.c cl_handler.c \
			  cl_printer_err.c cl_printer_ok.c
SRC_COMMON	= 

# Enumeration of directories
SRCDIR		= ./src
#SRCDIR_SV	= $(SRCDIR)$(NAME_SV)/
#SRCDIR_CL	= $(SRCDIR)$(NAME_CL)/
INCDIR		= ./include
LIBDIR		= ./lib
OBJDIR		= ./obj

# Macros to replace and/or integrate
SRCS_SV		= $(addprefix $(SRCDIR)/, $(SRC_SV)) \
			  $(addprefix $(SRCDIR)/, $(SRC_COMMON))
SRCS_CL		= $(addprefix $(SRCDIR)/, $(SRC_CL)) \
			  $(addprefix $(SRCDIR)/, $(SRC_COMMON))
OBJS_SV		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS_SV:.c=.o)))
OBJS_CL		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS_CL:.c=.o)))
DEPS_SV		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS_SV:.c=.d)))
DEPS_CL		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS_CL:.c=.d)))
LIBS		= $(LIBDIR)/$(LIBNAME).a

# Aliases of commands
CC			= cc
RM			= rm

# Command options (flags)
CFLAGS		= -MMD -Wall -Wextra -Werror
DEBUGFLAGS	= -g -ggdb -fsanitize=address \
			  -fstack-usage -fno-omit-frame-pointer
INCLUDES	= -I$(INCDIR)
#LDFLAGS	= -L$(LIBDIR) -l$(LIBS)
RMFLAGS		= -rf

# Redefination when the specific target
ifeq ($(MAKECMDGOALS), debug)
	CFLAGS	+= $(DEBUGFLAGS)
	DEF		= -D DEBUG_MODE=1
endif

# ********************* Section for targets and commands ********************* #
# Phonies
.PHONY: all clean fclean re debug

# Mandatory targets
all: $(NAME)
clean:
	$(MAKE) clean -C $(LIBDIR)
	$(RM) $(RMFLAGS) $(OBJDIR)
fclean: clean
	$(MAKE) fclean -C $(LIBDIR)
	$(RM) $(RMFLAGS) $(NAME_SV) $(NAME_CL)
re: fclean $(OBJDIR) all

# Additional targets
bonus: all
debug: all

# Recipes
$(NAME): $(LIBS) $(NAME_CL) $(NAME_SV)
$(NAME_SV): $(OBJS_SV)
	$(CC) $(CFLAGS) $(OBJS_SV) $(LIBS) -o $(NAME_SV)
$(NAME_CL): $(OBJS_CL)
	$(CC) $(CFLAGS) $(OBJS_CL) $(LIBS) -o $(NAME_CL)
$(LIBS):
	$(MAKE) -C $(LIBDIR)
$(OBJDIR):
	@mkdir -p $@
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(DEF) $(INCLUDES) -o $@ -c $<

# Including and ignore .dep files when they are not found
-include $(DEPS_SV) $(DEPS_CL)

# ******** ******** ******** ******** **** ******** ******** ******** ******** #
