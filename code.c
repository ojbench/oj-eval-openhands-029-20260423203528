
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mm.h"
#include "memlib.h"

#define MAX_IDS 100000
void *ptrs[MAX_IDS];

int main() {
    mem_init();
    if (mm_init() < 0) return 1;

    size_t suggested_heap_size;
    int num_ids;
    int num_ops;
    int weight;

    if (scanf("%zu %d %d %d", &suggested_heap_size, &num_ids, &num_ops, &weight) != 4) {
        // If header is missing, we might still want to try reading commands
    }

    char cmd;
    int id;
    size_t size;
    while (scanf(" %c", &cmd) != EOF) {
        if (cmd == 'a') {
            if (scanf("%d %zu", &id, &size) == 2) {
                ptrs[id] = mm_malloc(size);
            }
        } else if (cmd == 'f') {
            if (scanf("%d", &id) == 1) {
                mm_free(ptrs[id]);
                ptrs[id] = NULL;
            }
        } else if (cmd == 'r') {
            if (scanf("%d %zu", &id, &size) == 2) {
                ptrs[id] = mm_realloc(ptrs[id], size);
            }
        }
    }
    return 0;
}
