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

typedef int (*RBTCompareCb)(RBTData key1, RBTData key2);
typedef void (*RBTFreeCb)(RBTNode *node);
typedef void (*RBTPrintCb)(RBTNode *node);

typedef struct RBT {
	struct RBTNode *root;
	RBTCompareCb compare_cb;
	RBTFreeCb free_cb;
	RBTPrintCb print_cb;
}RBT;

extern int tt_rbt_init(RBT *tree, RBTCompareCb compare_cb, RBTPrintCb print_cb, RBTFreeCb free_cb);
extern int tt_rbt_insert(RBT *tree, RBTData key, RBTData value);
extern RBTNode *tt_rbt_search(const RBT tree, RBTData key);
extern int tt_rbt_delete(RBT *tree, RBTData key);
extern void tt_rbt_print(const RBT tree);
extern void tt_rbt_destroy(RBT *tree);

#ifdef  __cplusplus
}
#endif

#endif

