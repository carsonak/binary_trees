CC := gcc
TESTS_DIR := tests
TESTS_BIN_DIR = $(TESTS_DIR)/bin

BINARY_TREE_PREFIX := binary_tree_
BST_PREFIX := bst_
AVL_PREFIX := avl_
# Common prerequisites
BINARY_TREE_PRINT := $(shell ls $(BINARY_TREE_PREFIX)print/*.c)
BASIC_FILES = $(BINARY_TREE_PRINT) 0-$(BINARY_TREE_PREFIX)node.c
DELETION_FILES := 3-$(BINARY_TREE_PREFIX)delete.c
INSERTION_FILES := 2-$(BINARY_TREE_PREFIX)insert_right.c 1-$(BINARY_TREE_PREFIX)insert_left.c
BINARY_TREE_BASICS = $(BASIC_FILES) $(DELETION_FILES) $(INSERTION_FILES)

ARR_BST := 112-array_to_bst.c
BASIC_BST_FILES = 111-$(BST_PREFIX)insert.c $(BASIC_FILES) $(DELETION_FILES)

ARR_AVL := 122-array_to_avl.c
BASIC_AVL_FILES = 121-$(AVL_PREFIX)insert.c 14-$(BINARY_TREE_PREFIX)balance.c  103-$(BINARY_TREE_PREFIX)rotate_left.c  104-$(BINARY_TREE_PREFIX)rotate_right.c $(BASIC_FILES) $(DELETION_FILES)

C_STANDARD := --std=gnu89
SANITIZERS := -fsanitize=address,undefined
WARN_FLAGS := -Wall -Werror -Wextra -pedantic
DEBUG_FLAGS := -fno-omit-frame-pointer -g3
OPTIMISATION := -Og
CFLAGS = $(C_STANDARD) $(WARN_FLAGS) $(SANITIZERS) $(DEBUG_FLAGS) $(OPTIMISATION)

.PHONY: clean
clean:
	@$(RM) -vrd $(TESTS_BIN_DIR)

$(TESTS_BIN_DIR):
	mkdir -p $@

$(TESTS_BIN_DIR)/test_binary_tree_print: $(BASIC_BST_FILES) $(ARR_BST) 124-sorted_array_to_avl.c $(DELETION_FILES) $(TESTS_DIR)/test_binary_tree_print.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/test_%: $(BASIC_BST_FILES) $(ARR_BST) $(DELETION_FILES) $(TESTS_DIR)/test_%.c %.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%node: $(BASIC_FILES) $(TESTS_DIR)/%main.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%insert_left: $(BASIC_FILES) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)insert_left.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%insert_right: $(BASIC_FILES) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)insert_right.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%delete: $(filter-out %delete.c,$(BINARY_TREE_BASICS)) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)delete.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%is_leaf: $(BINARY_TREE_BASICS) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)is_leaf.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%is_root: $(BINARY_TREE_BASICS) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)is_root.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%preorder: $(BINARY_TREE_BASICS) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)preorder.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%inorder: $(BINARY_TREE_BASICS) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)inorder.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%postorder: $(BINARY_TREE_BASICS) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)postorder.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%height: $(BINARY_TREE_BASICS) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)height.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%depth: $(BINARY_TREE_BASICS) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)depth.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%size: $(BINARY_TREE_BASICS) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)size.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%leaves: $(BINARY_TREE_BASICS) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)leaves.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%nodes: $(BINARY_TREE_BASICS) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)nodes.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%balance: $(BINARY_TREE_BASICS) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)balance.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%is_full: $(BINARY_TREE_BASICS) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)is_full.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%is_perfect: $(filter-out %insert_left.c,$(BINARY_TREE_BASICS)) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)is_perfect.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%sibling: $(BINARY_TREE_BASICS) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)sibling.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%uncle: $(BINARY_TREE_BASICS) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)uncle.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%ancestor: C_STANDARD:=--std=c99
$(TESTS_BIN_DIR)/%ancestor: $(BINARY_TREE_BASICS) $(TESTS_DIR)/%main.c %binary_trees_ancestor.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%levelorder: $(BINARY_TREE_BASICS) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)levelorder.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%is_complete: $(BINARY_TREE_BASICS) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)is_complete.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%rotate_left: $(BINARY_TREE_BASICS) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)rotate_left.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%rotate_right: $(BINARY_TREE_BASICS) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)rotate_right.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%is_bst: $(BINARY_TREE_BASICS) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)is_bst.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%insert: $(filter-out %$(BST_PREFIX)insert.c,$(BASIC_BST_FILES)) $(TESTS_DIR)/%main.c %$(BST_PREFIX)insert.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%array_to_bst: $(BASIC_BST_FILES) $(TESTS_DIR)/%main.c %array_to_bst.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%search: $(BASIC_BST_FILES) $(ARR_BST) $(TESTS_DIR)/%main.c %$(BST_PREFIX)search.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%remove: $(BASIC_BST_FILES) $(ARR_BST) $(TESTS_DIR)/%main.c %$(BST_PREFIX)remove.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%is_avl: $(BINARY_TREE_BASICS) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)is_avl.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%insert: $(filter-out %$(AVL_PREFIX)insert.c,$(BASIC_AVL_FILES)) $(TESTS_DIR)/%main.c %$(AVL_PREFIX)insert.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%array_to_avl: $(BASIC_AVL_FILES) $(TESTS_DIR)/%main.c %array_to_avl.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%remove: $(BASIC_AVL_FILES) $(ARR_AVL) $(TESTS_DIR)/%main.c %$(AVL_PREFIX)remove.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%sorted_array_to_avl: C_STANDARD:=--std=c99
$(TESTS_BIN_DIR)/%sorted_array_to_avl: $(BINARY_TREE_BASICS) $(TESTS_DIR)/%main.c %sorted_array_to_avl.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%is_heap: $(BINARY_TREE_BASICS) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)is_heap.c | $(TESTS_BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^
