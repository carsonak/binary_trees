CC := gcc
CFLAGS := -Wall -Werror -Wextra -pedantic -std=gnu89 -g
T_DIR := tests
BTREE := binary_tree_

clean:
	@$(RM) -v $(shell find $(T_DIR) ! -name "*.c" -a -type f)

$(T_DIR)/%node: $(BTREE)print.c $(T_DIR)/%main.c %$(BTREE)node.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%left: 0-binary_tree_node.c $(BTREE)print.c $(T_DIR)/%main.c %$(BTREE)left.c
	$(CC) $(CFLAGS) $^ -o $@

$(T_DIR)/%right: 0-binary_tree_node.c $(BTREE)print.c $(T_DIR)/%main.c %$(BTREE)right.c
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean
