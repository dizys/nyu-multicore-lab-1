#include <stdio.h>
#include <stdlib.h>

#define MAX_BIN_NUM 50
#define MAX_THREAD_NUM 100

void print_help(char* executable);

int get_bin_index(double num, int bin_num) {
    return (int)(num * bin_num / 100.0);
}

int main(int argc, char *argv[])
{
    char* executable = argv[0];
    if (argc != 4) {
        printf("Error: invalid arguments\n\n");
        print_help(executable);
        return 1;
    }
    char* bin_count_str = argv[1];
    char* thread_count_str = argv[2];
    char* file_name = argv[3];

    FILE* fp = fopen(file_name, "r");

    if (fp == NULL) {
        printf("Error: cannot create file %s\n", file_name);
        return 1;
    }

    int bin_count = atoi(bin_count_str);
    int thread_count = atoi(thread_count_str);

    if (bin_count <= 0 || bin_count > MAX_BIN_NUM) {
        printf("Error: invalid bin count %s\n", bin_count_str);
        return 1;
    }

    if (thread_count <= 0 || thread_count > MAX_THREAD_NUM) {
        printf("Error: invalid thread count %s\n", thread_count_str);
        return 1;
    }

    int num_count = 0;
    fscanf(fp, "%d", &num_count);

    double nums[num_count];
    for (int i = 0; i < num_count; i++) {
        fscanf(fp, "%lf", &nums[i]);
    }

    fclose(fp);

    int bin_counter[bin_count];
    for (int i = 0; i < bin_count; i++) {
        bin_counter[i] = 0;
    }

    for (int i = 0; i < num_count; i++) {
        int bin_index = get_bin_index(nums[i], bin_count);
        bin_counter[bin_index]++;
    }

    for (int i = 0; i < bin_count; i++) {
        printf("bin[%d]=%d\n", i, bin_counter[i]);
    }
}


void print_help(char* executable)
{
    printf("usage: %s b t filename\n\n", executable);
    printf("A sequential version of histagram statistics counter.\n\n");
    printf("positional arguments:\n");
    printf("  b          the number of bins, 0 < b <= %d\n", MAX_BIN_NUM);
    printf("  t          the number of threads, 0 < t <= %d\n", MAX_THREAD_NUM);
    printf("  filename   the name of the text file that contains the floating point numbers\n");
}
