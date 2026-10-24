/* file_creator_sys.c */
#include <fcntl.h>    // open(), O_WRONLY, O_CREAT, O_TRUNC
#include <stdio.h>    // perror()
#include <unistd.h>   // write(), close()
#include <string.h>   // strlen()

int main() {
    const char *text = "Hello from Operating Systems class!\n";
    const char *message = "File created successfully!\n";
    int file = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644  );

    if(file == -1){
        perror("open");
        return 1;
    }
    write(file, text, strlen(text));
    close(file);
    write(STDOUT_FILENO, message, strlen(message));

    return 0;
}