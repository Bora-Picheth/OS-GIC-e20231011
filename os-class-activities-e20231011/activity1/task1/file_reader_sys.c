/* file_reader_sys.c */
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    char buffer[256];
    int file = open("output.txt", O_RDONLY);

    if (file == -1) {
        perror("open");
        return 1;
    }

    ssize_t bytes_read;
    while ((bytes_read = read(file, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytes_read);
    }
    close(file);
    return 0;
}