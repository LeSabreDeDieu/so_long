# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 16:28:59 by sgabsi            #+#    #+#              #
#    Updated: 2024/05/17 13:10:33 by sgabsi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

# Directories
SRC_SUBDIR	=	images/player images init utils
SRCDIR		=	./src
INCDIR		=	./include
LIBDIR		=	./lib
OBJDIR		=	obj

# Sources
# image_player
SRC_IMAGES_P_DIR	=	player
SRC_IMAGES_P_LIST	=	set_player_down.c 	\
						set_player_left.c 	\
						set_player_right.c	\
						set_player_up.c
SRC_IMAGES_P		=	$(addprefix $(SRC_IMAGES_P_DIR)/, $(SRC_IMAGES_P_LIST))

# images
SRC_IMAGES_DIR		=	images
SRC_IMAGES_LIST		=	print_images.c 		\
						print_objects.c 	\
						set_enemy_image.c	\
						set_images.c		\
						$(SRC_IMAGES_P)
SRC_IMAGES			=	$(addprefix $(SRC_IMAGES_DIR)/, $(SRC_IMAGES_LIST))


# init
SRC_INIT_DIR		=	init
SRC_INIT_LIST		=	init_img.c 			\
						init_minilib.c 
SRC_INIT			=	$(addprefix $(SRC_INIT_DIR)/, $(SRC_INIT_LIST))

# utils
SRC_UTILS_DIR		=	utils
SRC_UTILS_LIST		=	animation.c			\
						count_char.c		\
						error.c 			\
						math.c				\
						mob_mouv.c			\
						on_settings_utils.c	\
						on_settings_utils2.c	\
						on_settings.c		\
						parsing_utils.c		\
						parsing.c			\
						print_step.c		\
						refresh_map.c		\
						utils_2.c			\
						utils.c				\
						win_lose.c
SRC_UTILS			=	$(addprefix $(SRC_UTILS_DIR)/, $(SRC_UTILS_LIST))

SRC_LIST			=	$(SRC_IMAGES)		\
						$(SRC_INIT)			\
						$(SRC_UTILS)		\
						so_long.c
SRC					=	$(addprefix $(SRCDIR)/, $(SRC_LIST))

# Objects
OBJ_SUBDIRS	=	$(SRC_SUBDIR:%=$(OBJDIR)/%)
OBJ			=	$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Libraries
LIBFT_DIR 	=	$(LIBDIR)/libft
LIBFT 		=	$(LIBFT_DIR)/libft.a
MLX_DIR		=	$(LIBDIR)/minilibx-linux
MLX			=	$(MLX_DIR)/libmlx_Linux.a

# Output
NAME		=	so_long

# Compiler
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -MMD
OPTIONS		=	-I $(INCDIR) -I $(LIBFT_DIR)/includes -I $(MLX_DIR)
LFLAGS		=	-L $(LIBFT_DIR) -L $(MLX_DIR) -lft -lmlx -lX11 -lXext -lm

# Progress bar
COUNT		=	1
TOTAL_FILES	=	$(shell find $(SRCDIR) -type f -name "*.c" | wc -l)

# Colors
RED			=	\033[0;31m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
NC			=	\033[0m
KL			=	\033[K

#################
##  TARGETS    ##
#################

all: check

compile: pre_comp $(LIBFT) $(MLX) $(NAME)

check:
	@if [ -f "$(NAME)" ] && [ -z "$(shell find $(SRCDIR) -type f -name "*.c" -newer $(NAME) 2>/dev/null)" ] && [ -z "$(shell find $(SRCDIR) -type f -name "*.h" -newer $(NAME) 2>/dev/null)" ]; then \
		echo "$(YELLOW)********* Rien à faire - Tout est à jour *********$(NC)"; \
	else \
		make -s compile; \
	fi

pre_comp:
	@echo "$(YELLOW)********* Début de la compilation du programme $(NAME) *********$(NC)"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(OPTIONS) $(LFLAGS) -o $@
	@echo -e "\r$(GREEN)********* Compilation terminée avec succès! *********$(NC)$(KL)"
	@echo "$(GREEN)********* L'executable $(NAME) a été créée. *********$(NC)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(OPTIONS) -c $< -o $@
	@printf "$(NC)\rCompiling files: [%-50s] %3d%% (%d/%d) %s$(KL)" \
		"$(shell printf '=%.0s' $$(seq 1 $$(($(COUNT) * 50 / $(TOTAL_FILES)))))" \
		$$(($(COUNT) * 100 / $(TOTAL_FILES))) \
		$(COUNT) \
		$(TOTAL_FILES) \
		$<
	$(eval COUNT=$(shell echo $$(($(COUNT)+1))))

$(LIBFT):
	@make -sC $(LIBFT_DIR)

$(MLX):
	@make -sC $(MLX_DIR)

clean:
	@rm -rf $(OBJDIR)
	@make -sC $(LIBFT_DIR) clean
	@make -sC $(MLX_DIR) clean
	@echo "$(YELLOW)********* Suppression des fichiers objets *********$(NC)"

fclean: clean
	@rm -f $(NAME)
	@make -sC $(LIBFT_DIR) fclean
	@echo "$(RED)********* Suppression de l'executable $(NAME) *********$(NC)"

re: fclean compile

norminette:
	@echo "$(YELLOW)********* Exécution de norminette *********$(NC)"
	@norminette src/ include/ lib/libft | grep -B 1 -e "Error" || echo "Tous les fichiers ont passé le check norminette !"

.PHONY: check compile all clean fclean re norminette