.PHONY: clean all

CFLAGS = -Wall -g -O0
targets = main
sources = main.c ./SequentialList/SeqList.c

BUILD_DIR = build

objects = $(sources:%.c=$(BUILD_DIR)/%.o)

all: $(targets)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BUILD_DIR)/SequentialList

$(targets): $(objects)
	@gcc $(CFLAGS) $(objects) -o $(BUILD_DIR)/$@
	@echo "make done"
	@$(BUILD_DIR)/$@

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	@gcc $(CFLAGS) -c $< -o $@ 

clean:
	@rm -rf $(BUILD_DIR)
