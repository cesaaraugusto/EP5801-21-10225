# Name of the executable to be generated #
TARGET_EXECUTABLE := main

# Directories for organizing files #
BUILD_DIR := ./build

# Directories for executable file #
BIN_DIR := $(BUILD_DIR)/bin

# Source directories #
SRC_DIR := ./src

# Directories for sensor source files #
VECTORS_DIR := $(SRC_DIR)/vectors

# Compiler
CC := gcc

# C Files
C_FILES := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(VECTORS_DIR)/*.c)

# Object Files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(C_FILES))

# Build Steps #
$(BIN_DIR)/$(TARGET_EXECUTABLE): $(OBJ_FILES)
	@mkdir -p $(dir $@)
	$(CC) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $^ -o $@

.PHONY: clean
clean:
	@if [ -d $(BUILD_DIR) ]; then rm -r $(BUILD_DIR); fi