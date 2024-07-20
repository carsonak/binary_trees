CC := gcc
CFLAGS := -Wall -Werror -Wextra -pedantic -std=gnu89 -g3
T_DIR := tests
BTREE := binary_tree_
COMMON_PREREQUISITES := $(BTREE)print.c 0-$(BTREE)node.c 2-$(BTREE)insert_right.c 1-$(BTREE)insert_left.c

clean:
	@$(RM) -v $(shell find $(T_DIR) ! -name "*.c" -a -type f)

$(T_DIR)/%node: $(BTREE)print.c $(T_DIR)/%main.c %$(BTREE)node.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%insert_left: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)insert_left.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%insert_right: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)insert_right.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%delete: $(filter-out %insert_left.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)delete.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%is_leaf: $(filter-out %insert_left.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)is_leaf.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%is_root: $(filter-out %insert_left.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)is_root.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%preorder: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)preorder.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%inorder: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)inorder.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%postorder: $(filter %node.c %print.c,$(COMMON_PREREQUISITES)) $(T_DIR)/%main.c %$(BTREE)postorder.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%height: $(COMMON_PREREQUISITES) $(T_DIR)/%main.c %$(BTREE)height.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%depth: $(COMMON_PREREQUISITES) $(T_DIR)/%main.c %$(BTREE)depth.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%size: $(COMMON_PREREQUISITES) $(T_DIR)/%main.c %$(BTREE)size.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%leaves: $(COMMON_PREREQUISITES) $(T_DIR)/%main.c %$(BTREE)leaves.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%nodes: $(COMMON_PREREQUISITES) $(T_DIR)/%main.c %$(BTREE)nodes.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%balance: $(COMMON_PREREQUISITES) $(T_DIR)/%main.c %$(BTREE)balance.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%is_full: $(COMMON_PREREQUISITES) $(T_DIR)/%main.c %$(BTREE)is_full.c
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean
