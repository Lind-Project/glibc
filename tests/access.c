#include <stdio.h>
#include <unistd.h>

int main() {
    const char *filename = "/home/lind-wasm/lind-wasm-tests/open.txt";
  
    if (access(filename, R_OK) == 0) {
        printf("File '%s' exists and is readable.\n", filename);
    } else {
       
	perror("Error checking file access");
        return 1;
    }

    return 0;
}
