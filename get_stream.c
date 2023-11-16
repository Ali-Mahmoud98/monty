#include "monty.h"
/**
 * get_stream_failed - handle failure in getting stream.
 * @fileName: name of file.
*/
void get_stream_failed(char *fileName)
{
    dprintf(stderr, "Error: Can't open file %s\n", fileName);
    free_args();
    exit(EXIT_FAILURE);
}
/**
 * get_stream - get stream from file.
 * @fileName: name of file.
*/
void get_stream(char *fileName)
{
    int fd;

    fd = open(fileName, O_RDONLY);
    if (fd == -1)
        get_stream_failed(fileName);
    arguments->stream = fdopen(fd, "r");
    if (arguments->stream == NULL)
    {
        close(fd);
        get_stream_failed(fileName);
    }
}
