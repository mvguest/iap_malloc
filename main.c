#include <stdio.h>
#include <stdint.h>
#include "headers/iap.h"
#include "iap.c"

int main(int argc, char *argv[]) {
    double x;

    t_pool pool = {0};
    size_t align = iap_alignof(x);
    size_t size_align = iap_sialign(sizeof(x), align);

    printf("Align of x: %zu\n", align);
    printf("Size of the block for x (based on his align): %zu\n", size_align);

    int pool_malloc = iap_malloc(&pool, size_align, align, 100);

    if (pool_malloc != 0) {
        printf("Memory allocation error");
    }

    printf("%p\n", &pool_malloc);
    printf("%zu\n", sizeof(&pool_malloc));

    for (size_t i = 0; i < pool.capacity; i++) {
        printf("Block %zu address: %p\n", i, (void*)((uint8_t*)pool.buffer + i * pool.block_size));
    }

    iap_pclose(&pool);

    return 0;
}
