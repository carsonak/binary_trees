CC := gcc
TESTS_DIR := tests
TESTS_BIN_DIR = $(TESTS_DIR)/bin

BINARY_TREE_PREFIX := binary_tree_
BST_PREFIX := bst_
AVL_PREFIX := avl_
# Common prerequisites
BASIC_FILES := $(BINARY_TREE_PREFIX)print.c 0-$(BINARY_TREE_PREFIX)node.c
DELETION_FILES := 3-$(BINARY_TREE_PREFIX)delete.c
INSERTION_FILES := 2-$(BINARY_TREE_PREFIX)insert_right.c 1-$(BINARY_TREE_PREFIX)insert_left.c
BINARY_TREE_BASICS = $(BASIC_FILES) $(DELETION_FILES) $(INSERTION_FILES)

ARR_BST := 112-array_to_bst.c
BASIC_BST_FILES := 111-$(BST_PREFIX)insert.c $(BASIC_FILES)

ARR_AVL := 122-array_to_avl.c
BASIC_AVL_FILES := 121-$(AVL_PREFIX)insert.c 14-$(BINARY_TREE_PREFIX)balance.c  103-$(BINARY_TREE_PREFIX)rotate_left.c  104-$(BINARY_TREE_PREFIX)rotate_right.c $(BASIC_FILES)

C_STANDARD := --std=gnu89
SANITIZERS := -fsanitize=address,undefined
WARN_FLAGS := -Wall -Werror -Wextra -pedantic
DEBUG_FLAGS := -fno-omit-frame-pointer -g3
OPTIMISATION := -Og
CFLAGS = $(C_STANDARD) $(WARN_FLAGS) $(SANITIZERS) $(DEBUG_FLAGS) $(OPTIMISATION)

.PHONY: clean
clean:
	@$(RM) -vrb $(TESTS_BIN_DIR)

$(TESTS_BIN_DIR)/test_%: $(BASIC_BST_FILES) $(ARR_BST) $(DELETION_FILES) $(TESTS_DIR)/test_%.c %.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%node: $(BASIC_FILES) $(TESTS_DIR)/%main.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%insert_left: $(BASIC_FILES) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)insert_left.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%insert_right: $(BASIC_FILES) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)insert_right.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%delete: $(filter-out %delete.c,$(BINARY_TREE_BASICS)) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)delete.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%is_leaf: $(filter-out %delete.c,$(BINARY_TREE_BASICS)) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)is_leaf.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%is_root: $(filter-out %delete.c,$(BINARY_TREE_BASICS)) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)is_root.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%preorder: $(filter-out %delete.c,$(BINARY_TREE_BASICS)) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)preorder.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%inorder: $(filter-out %delete.c,$(BINARY_TREE_BASICS)) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)inorder.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%postorder: $(filter-out %delete.c,$(BINARY_TREE_BASICS)) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)postorder.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%height: $(filter-out %delete.c,$(BINARY_TREE_BASICS)) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)height.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%depth: $(filter-out %delete.c,$(BINARY_TREE_BASICS)) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)depth.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%size: $(filter-out %delete.c,$(BINARY_TREE_BASICS)) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)size.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%leaves: $(filter-out %delete.c,$(BINARY_TREE_BASICS)) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)leaves.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%nodes: $(filter-out %delete.c,$(BINARY_TREE_BASICS)) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)nodes.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%balance: $(filter-out %delete.c,$(BINARY_TREE_BASICS)) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)balance.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%is_full: $(filter-out %delete.c,$(BINARY_TREE_BASICS)) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)is_full.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%is_perfect: $(filter-out %insert_left.c,$(BINARY_TREE_BASICS)) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)is_perfect.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%sibling: $(BASIC_FILES) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)sibling.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%uncle: $(BASIC_FILES) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)uncle.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%ancestor: C_STANDARD:=--std=c99
$(TESTS_BIN_DIR)/%ancestor: $(BASIC_FILES) $(DELETION_FILES) $(TESTS_DIR)/%main.c %binary_trees_ancestor.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%levelorder: $(BASIC_FILES) $(DELETION_FILES) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)levelorder.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%is_complete: $(BASIC_FILES) $(DELETION_FILES) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)is_complete.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%rotate_left: $(BASIC_FILES) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)rotate_left.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%rotate_right: $(BASIC_FILES) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)rotate_right.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%is_bst: $(BASIC_FILES) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)is_bst.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%insert: $(BASIC_FILES) $(TESTS_DIR)/%main.c %$(BST_PREFIX)insert.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%array_to_bst: $(BASIC_BST_FILES) $(TESTS_DIR)/%main.c %array_to_bst.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%search: $(BASIC_BST_FILES) $(TESTS_DIR)/%main.c %$(BST_PREFIX)search.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%remove: $(BASIC_BST_FILES) $(ARR_BST) $(DELETION_FILES) $(TESTS_DIR)/%main.c %$(BST_PREFIX)remove.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%is_avl: $(BASIC_FILES) $(TESTS_DIR)/%main.c %$(BINARY_TREE_PREFIX)is_avl.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%insert: $(filter-out %$(AVL_PREFIX)insert.c,$(BASIC_AVL_FILES)) $(DELETION_FILES) $(TESTS_DIR)/%main.c %$(AVL_PREFIX)insert.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%array_to_avl: $(BASIC_AVL_FILES) $(DELETION_FILES) $(TESTS_DIR)/%main.c %array_to_avl.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%remove: $(BASIC_AVL_FILES) $(ARR_AVL) $(DELETION_FILES) $(TESTS_DIR)/%main.c %$(AVL_PREFIX)remove.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS_BIN_DIR)/%sorted_array_to_avl: C_STANDARD:=--std=c99
$(TESTS_BIN_DIR)/%sorted_array_to_avl: $(BASIC_FILES) $(DELETION_FILES) $(TESTS_DIR)/%main.c %sorted_array_to_avl.c
	$(CC) $(CFLAGS) -o $@ $^
