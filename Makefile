CC := gcc
CFLAGS := -Wall -Werror -Wextra -pedantic -std=gnu89 -g
T_DIR := tests
BTREE := binary_tree_

clean:
	@$(RM) -v $(shell find $(T_DIR) ! -name "*.c" -a -type f)

$(T_DIR)/%node: $(BTREE)print.c $(T_DIR)/%main.c %$(BTREE)node.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%insert_left: 0-binary_tree_node.c $(BTREE)print.c $(T_DIR)/%main.c %$(BTREE)insert_left.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%insert_right: 0-binary_tree_node.c $(BTREE)print.c $(T_DIR)/%main.c %$(BTREE)insert_right.c
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean
