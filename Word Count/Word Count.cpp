#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char* argv[]) {
    // 控制参数
    char* parameter = argv[1];
    char* input_file_name = argv[2];

    // 打开文件
    FILE* file = fopen(input_file_name, "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    // 统计字符数或单词数
    int count = 0;
    char ch;
    int is_word = 0;

    if (strcmp(parameter, "-c") == 0) {
        // 统计字符数
        while ((ch = fgetc(file)) != EOF) {
            count++;
        }
        printf("Character count: %d\n", count);
    }
    else if (strcmp(parameter, "-w") == 0) {
        // 统计单词数
        while ((ch = fgetc(file)) != EOF) {
            if (ch == ' ' || ch == '\n' || ch == '  ' || ch == ',') {
                is_word = 0;
            }
            else if (is_word == 0) {
                is_word = 1;
                count++;
            }
        }
        printf("Word count: %d\n", count);
    }
    else {
        printf("Invalid command line argument.\n");
        return 1;
    }

    // 关闭文件
    fclose(file);

    return 0;
}
