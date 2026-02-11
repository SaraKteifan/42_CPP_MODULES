NAME      = a.out
CXX       = c++
CXXFLAGS  = -Wall -Wextra -Werror -std=c++98

SRC_FILES = main Bureaucrat AForm ShrubberyCreationForm RobotomyRequestForm PresidentialPardonForm
BUILD_DIR = build
SRC       = $(SRC_FILES:=.cpp)
OBJ       = $(addprefix $(BUILD_DIR)/, $(SRC_FILES:=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
