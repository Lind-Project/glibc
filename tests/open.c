#include <fcntl.h>    // For open() and O_* constants
#include <stdio.h>    
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int fd = open("/home/lind-wasm/lind-wasm-tests/open.txt", O_RDONLY);
    
    if (fd == -1) {
        printf("Error opening file");
        return 1;
    }

    char buffer[1024];
    ssize_t bytes_read;

    bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    
    if (bytes_read == -1) {
        perror("Error reading file");
        return 1;
    }

    buffer[bytes_read] = '\0';

    printf("File contents:\n%s\n", buffer);
    //close(fd);
    // At this point, the file is open, but we're not closing it
    // The program will end, and the file will eventually be closed by the OS

    return 0;
}
