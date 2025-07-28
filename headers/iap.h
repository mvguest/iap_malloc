#include <stddef.h>

#ifndef IAP_H
#define IAP_H

#define iap_alignof(var) __alignof__(__typeof__(var))

typedef struct {
    void*   buffer;
    size_t  block_size;
    size_t  alignment;
    size_t  capacity;
    size_t  used;
} t_pool;

static inline size_t iap_sialign(size_t size, size_t alignment) {
    return (size + alignment - 1) & ~(alignment - 1);
}

#endif // IAP_H

