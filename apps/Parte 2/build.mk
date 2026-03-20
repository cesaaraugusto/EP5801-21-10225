# Name of the executable to be generated #
TARGET_EXECUTABLE := main

# Directories for organizing files #
BUILD_DIR := ./build

# Directories for executable file #
BIN_DIR := $(BUILD_DIR)/bin

# Source directories #
SRC_DIR := ./src

# Get directories based on source file structures #
DIRECTORIES := $(shell find $(SRC_DIR) -type d)
DIRECTORIES_FLAGS := $(addprefix -I,$(DIRECTORIES))

# Compiler and Assembler files #
C_SRC_FILES := $(shell find -name '*.c')
ASM_SRC_FILES := $(shell find -name '*.asm')

# Generate Object files from source files names #
C_OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(C_SRC_FILES))
ASM_OBJS := $(patsubst $(SRC_DIR)/%.asm, $(BUILD_DIR)/%.o, $(ASM_SRC_FILES))

# Grou object files #
ALL_OBJS := $(C_OBJS) $(ASM_OBJS)

# Build Steps #
$(BIN_DIR)/$(TARGET_EXECUTABLE): $(ALL_OBJS)
	@mkdir -p $(dir $@)
	gcc $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	gcc -c $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.asm
	@mkdir -p $(dir $@)
	nasm -f elf64 $< -o $@

.PHONY: clean
clean:
	@if [ -d $(BUILD_DIR) ]; then rm -r $(BUILD_DIR); fi