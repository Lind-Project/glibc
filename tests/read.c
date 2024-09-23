#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("test.txt", O_RDONLY);
    
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char buffer[128];
    ssize_t bytes_read;

    bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    
    if (bytes_read == -1) {
        perror("Error reading file");
        return 1;
    }

    buffer[bytes_read] = '\0';

    printf("Read %ld bytes: %s\n", bytes_read, buffer);

    return 0;
}
