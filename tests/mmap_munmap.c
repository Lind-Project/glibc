#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
    size_t page_size = getpagesize();

    void *addr = mmap(NULL, page_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    
    if (addr == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }
    
    printf("Memory allocated at address: %p\n", addr);

   
    if (munmap(addr, page_size) == -1) {
        perror("munmap failed");
        return 1;
    }
    
    printf("Memory successfully unmapped\n");

    return 0;
}
