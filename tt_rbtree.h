#ifndef __TT_RBTREE_H__
#define __TT_RBTREE_H__

#include <stdint.h>

#ifdef  __cplusplus
extern "C" {
#endif

typedef union RBTData {
	void *ptr;
	int fd;
	uint32_t u32;
	uint64_t u64;
}RBTData;

typedef struct RBTNode {
	RBTData key;
	RBTData value;
	unsigned char is_black;
	struct RBTNode *left;
	struct RBTNode *right;
	struct RBTNode *parent;
}RBTNode;

typedef int (*tt_rbt_compare_cb)(RBTData key1, RBTData key2);
typedef void (*tt_rbt_free_cb)(RBTNode *node);
typedef void (*tt_rbt_print_cb)(RBTNode *node);

typedef struct RBT {
	struct RBTNode *root;
	tt_rbt_compare_cb compare_cb;
	tt_rbt_free_cb free_cb;
	tt_rbt_print_cb print_cb;
}RBT;

extern int tt_rbt_init(RBT *tree, tt_rbt_compare_cb compare_cb, tt_rbt_print_cb print_cb, tt_rbt_free_cb free_cb);
extern int tt_rbt_insert(RBT *tree, RBTData key, RBTData value);
extern RBTNode *tt_rbt_search(const RBT tree, RBTData key);
extern int tt_rbt_delete(RBT *tree, RBTData key);
extern void tt_rbt_print(const RBT tree);
extern void tt_rbt_destroy(RBT *tree);

#ifdef  __cplusplus
}
#endif

#endif

