CC := gcc
CFLAGS := -Wall -Werror -Wextra -pedantic -std=gnu89 -g3
TESTS_DIR := tests
BINARY_TREE := binary_tree_
BST := bst_
COMMON_PREREQUISITES := $(BINARY_TREE)print.c 0-$(BINARY_TREE)node.c 2-$(BINARY_TREE)insert_right.c 1-$(BINARY_TREE)insert_left.c 3-$(BINARY_TREE)delete.c 111-$(BST)insert.c 112-array_to_bst.c

.PHONY: clean
clean:
	@$(RM) -v $(shell find $(TESTS_DIR) ! -name "*.c" -a -type f)

$(TESTS_DIR)/%node: $(BINARY_TREE)print.c $(TESTS_DIR)/%main.c %$(BINARY_TREE)node.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%insert_left: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BINARY_TREE)insert_left.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%insert_right: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BINARY_TREE)insert_right.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%delete: $(filter-out %insert_left.c %delete.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BINARY_TREE)delete.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%is_leaf: $(filter-out %insert_left.c %delete.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BINARY_TREE)is_leaf.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%is_root: $(filter-out %insert_left.c %delete.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BINARY_TREE)is_root.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%preorder: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BINARY_TREE)preorder.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%inorder: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BINARY_TREE)inorder.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%postorder: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BINARY_TREE)postorder.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%height: $(filter-out %delete.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BINARY_TREE)height.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%depth: $(filter-out %delete.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BINARY_TREE)depth.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%size: $(filter-out %delete.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BINARY_TREE)size.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%leaves: $(filter-out %delete.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BINARY_TREE)leaves.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%nodes: $(filter-out %delete.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BINARY_TREE)nodes.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%balance: $(filter-out %delete.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BINARY_TREE)balance.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%is_full: $(filter-out %delete.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BINARY_TREE)is_full.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%is_perfect: $(filter-out %insert_left.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BINARY_TREE)is_perfect.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%sibling: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BINARY_TREE)sibling.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%uncle: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BINARY_TREE)uncle.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%ancestor: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BINARY_TREE)ancestor.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%levelorder: $(filter %node.c %print.c %delete.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BINARY_TREE)levelorder.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%is_complete: $(filter %node.c %print.c %delete.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BINARY_TREE)is_complete.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%rotate_left: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BINARY_TREE)rotate_left.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%rotate_right: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BINARY_TREE)rotate_right.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%is_bst: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BINARY_TREE)is_bst.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%insert: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BST)insert.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%array_to_bst: $(filter %node.c %print.c %insert.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %array_to_bst.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%search: $(filter %print.c %node.c %insert.c %array_to_bst.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BST)search.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%remove: $(filter %print.c %node.c %insert.c %array_to_bst.c %delete.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BST)remove.c
	$(CC) $(CFLAGS) $^ -o $@

$(TESTS_DIR)/%is_avl: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(TESTS_DIR)/%main.c %$(BINARY_TREE)is_avl.c
	$(CC) $(CFLAGS) $^ -o $@
