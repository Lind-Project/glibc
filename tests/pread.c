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

    off_t offset = 5;
    bytes_read = pread(fd, buffer, sizeof(buffer) - 1, offset);
    
    if (bytes_read == -1) {
        perror("Error reading file with pread");
        return 1;
    }

    buffer[bytes_read] = '\0';

    printf("Read %ld bytes from offset %ld: %s\n", bytes_read, offset, buffer);

    close(fd);

    return 0;
}
