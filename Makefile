# Executable name
TARGET			:=	beard
# Window title - remember to escape special characters (inc. spaces)
WINDOW_TITLE 	:=	beard-vm

# Compiler / Linker
COMPILER		:=	gcc
LINKER 			:=	gcc

# Compiler flags
CFLAGS			:=	-Wall -Wextra -ansi -pedantic -std=c99 -Werror

# Linker flags for both release and debug builds
LD_FLAGS		:=	-Wl,-rpath,. -O3
LD_FLAGS_DEBUG	:=	-Wl,-rpath,. -O0 -ggdb -pg

# Defines for both release and debug builds - remember to escape characters
DEFINES			:= 	-DNAME_VERSION=\"$(WINDOW_TITLE)\"
DEFINES_DEBUG	:=	-DNAME_VERSION=\"$(WINDOW_TITLE)\ DEBUG\" -DDEBUG

# Include directories
INCLUDES		:=	-Isrc -Iinc

# Linking directories
LINKS			:= 	
# Linked libraries
LIBRARIES 		:=

# Source files, without the path (assumed only one source dir exists)
SRC_FILES		:= 	BeardMain.c \
					Functions.c

# Directory pathnames
OBJ_DIR			:= 	obj/
SRC_DIR			:= 	src/
BIN_DIR			:=	bin/

# Figuring out the names for .o files
OBJ_FILES		:=	$(addsuffix .o, $(basename $(SRC_FILES)))
OBJ_FILES		:=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

all:
	@echo "Available targets: release, debug"

release: $(BIN_DIR)$(TARGET)
	@strip $(BIN_DIR)$(TARGET)

# Assign the proper flags and defines for the debug build
debug: LD_FLAGS	:= $(LD_FLAGS_DEBUG)
debug: DEFINES 	:= $(DEFINES_DEBUG)
debug: $(BIN_DIR)$(TARGET)

# Linking target
$(BIN_DIR)$(TARGET): _makedirs $(OBJ_FILES)
	$(LINKER) -o $(BIN_DIR)$(TARGET) $(OBJ_FILES) $(LIBRARIES) $(LINKS) $(LD_FLAGS) $(SDL_LD_FLAGS)

# Compile target
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(COMPILER) $(CFLAGS) $(SDL_CFLAGS) $(INCLUDES) $(DEFINES) -g -o $@ -c $<

# Create varios directories as needed
_makedirs:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR)

clean: 
	rm -fr $(OBJ_DIR) $(BIN_DIR)$(TARGET)* $(BIN_DIR)gmon*

run: all
	@cd $(BIN_DIR) && ./$(TARGET)

# Runs the debugger, requires debug build
run_gdb: debug
	@cd $(BIN_DIR) && gdb ./$(TARGET)

info:
	@echo "TARGET:		$(BIN_DIR)$(TARGET)"
	@echo "SRC_FILES:	$(SRC_FILES)"
	@echo "OBJ_FILES:	$(OBJ_FILES)"
	@echo "LINKS:		$(LINKS)"
	@echo "LIBRARIES:	$(LIBRARIES)"
