CC := gcc
CFLAGS := -Wall -Werror -Wextra -pedantic -std=gnu89 -g3
T_DIR := tests
BTREE := binary_tree_
BST := bst_
COMMON_PREREQUISITES := $(BTREE)print.c 0-$(BTREE)node.c 2-$(BTREE)insert_right.c 1-$(BTREE)insert_left.c 3-$(BTREE)delete.c 111-$(BST)insert.c 112-array_to_bst.c

clean:
	@$(RM) -v $(shell find $(T_DIR) ! -name "*.c" -a -type f)

$(T_DIR)/%node: $(BTREE)print.c $(T_DIR)/%main.c %$(BTREE)node.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%insert_left: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)insert_left.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%insert_right: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)insert_right.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%delete: $(filter-out %insert_left.c %delete.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)delete.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%is_leaf: $(filter-out %insert_left.c %delete.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)is_leaf.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%is_root: $(filter-out %insert_left.c %delete.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)is_root.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%preorder: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)preorder.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%inorder: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)inorder.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%postorder: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)postorder.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%height: $(filter-out %delete.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)height.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%depth: $(filter-out %delete.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)depth.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%size: $(filter-out %delete.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)size.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%leaves: $(filter-out %delete.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)leaves.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%nodes: $(filter-out %delete.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)nodes.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%balance: $(filter-out %delete.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)balance.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%is_full: $(filter-out %delete.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)is_full.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%is_perfect: $(filter-out %insert_left.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)is_perfect.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%sibling: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)sibling.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%uncle: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)uncle.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%ancestor: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)ancestor.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%levelorder: $(filter %node.c %print.c %delete.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)levelorder.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%is_complete: $(filter %node.c %print.c %delete.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)is_complete.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%rotate_left: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)rotate_left.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%rotate_right: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)rotate_right.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%is_bst: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)is_bst.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%insert: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BST)insert.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%array_to_bst: $(filter %node.c %print.c %insert.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %array_to_bst.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%search: $(filter %print.c %node.c %insert.c %array_to_bst.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BST)search.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%remove: $(filter %print.c %node.c %insert.c %array_to_bst.c %delete.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BST)remove.c
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean
