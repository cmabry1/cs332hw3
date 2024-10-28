#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
void count_words_and_print_info(const char *filepath) {
    struct stat file_stat;
    if (stat(filepath, &file_stat) == -1) {
        perror("Could not get file size");
        exit(EXIT_FAILURE);
    }
    printf("File: %s\n", filepath);
    printf("Size: %ld bytes\n", file_stat.st_size);
    const char *ext = strrchr(filepath, '.');
    if (ext && strcmp(ext, ".txt") == 0) {
        FILE *file = fopen(filepath, "r");
        if (!file) {
            perror("Could not open file");
            exit(EXIT_FAILURE);
        }

        int word_count = 0;
        char word[256];
        while (fscanf(file, "%s", word) == 1) {
            word_count++;
        }
        printf("Words: %d\n", word_count);
        fclose(file);
    }
}
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    DIR *dir = opendir(argv[1]);
    if (!dir) {
        perror("Could not open directory");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            pid_t pid = fork();
            if (pid == -1) {
                perror("Failed to fork");
                exit(EXIT_FAILURE);
            } else if (pid == 0) { 
                char filepath[1024];
                snprintf(filepath, sizeof(filepath), "%s/%s", argv[1], entry->d_name);
                count_words_and_print_info(filepath);
                exit(EXIT_SUCCESS);
            }
        }
    }

    while (wait(NULL) > 0);
    closedir(dir);
    return 0;
}
