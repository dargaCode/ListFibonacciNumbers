#include <stdio.h>
#include <cs50.h>

// printf ANSI colors
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

// constants
#define MAX_FIB_COUNT 75

// prototypes
bool is_valid_input(int argc, string argv[]);
void generate_fibs(long long fibs[], int fib_count);
void print_array(long long data[], int len);

int main(int argc, string argv[])
{
    // bad input
    if (!is_valid_input(argc, argv))
    {
        printf(COLOR_RED);
        printf("Usage: fibonacci <Count of nums (1 to %i)>\n", 
            MAX_FIB_COUNT);
        printf(COLOR_RESET);
        // failure
        return 1;
    }
    // good input
    int fib_count = atoi(argv[1]);
    long long fibs[fib_count];
    generate_fibs(fibs, fib_count);
    print_array(fibs, fib_count);

    // success
    return 0;
}

bool is_valid_input(int argc, string argv[])
{
    // require a single arg for count of fib numbers
    if (argc != 2)
    {
        return false;
    }
    // is the arg valid?
    int fib_count = atol(argv[1]);
    if (fib_count < 1 || fib_count > MAX_FIB_COUNT)
    {
        return false;
    }
    return true;
}

void generate_fibs(long long fibs[], int fib_count)
{
    printf("Print %i Fibonacci numbers! \n", fib_count);

    fibs[0] = (long long)0;
    fibs[1] = (long long)1;

    // head start at index 2
    for (int i = 2; i < fib_count; i++)
    {
        fibs[i] = fibs[i - 1] + fibs[i - 2];
    }
}

void print_array(long long data[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%lld\n", data[i]);
    }
    printf("\n");
}
