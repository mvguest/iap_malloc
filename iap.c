#include <stdlib.h>
#include "headers/iap.h"

int iap_malloc(t_pool* pool, size_t sialign, size_t align, size_t count) {
    size_t total_size = sialign * count;

    void* buffer = NULL;
    if (posix_memalign(&buffer, sialign, total_size) != 0) {
        return -1;
    }

    pool->buffer = buffer;
    pool->block_size = sialign;
    pool->alignment = align;
    pool->capacity = count;
    pool->used = 0;

    return 0;
}

void iap_pclose(t_pool* pool) {
    if (pool->buffer != NULL) {
        free(pool->buffer);
        pool->buffer = NULL;
    }
    pool->block_size = 0;
    pool->alignment  = 0;
    pool->capacity   = 0;
    pool->used       = 0;
}
