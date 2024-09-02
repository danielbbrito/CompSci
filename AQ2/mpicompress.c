#include <mpi.h>
#include <zlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int zcompress (unsigned char *in, size_t in_size, unsigned char *out, size_t out_size)
{

// Inicializa o stream
z_stream stream;
stream.zalloc = Z_NULL;
stream.zfree = Z_NULL;
stream.opaque Z_NULL;

if (deflateInit(&stream, Z_DEFAULT_COMPRESSION) != Z_OK)
{
    return 0;
}

stream.avail_in = in_size;
stream.next_in = in;

stream.avail_out = out_size;
stream.next_out = out;

if (deflate(&stream, Z_FINISH) != Z_STREAM_END)
{
    deflateEnd(&stream);
    return 0;      
}          

out_size = stream.total_out;
deflateEnd(&stream);

return 1;
}

int main(int argc, char *argv[])
{
    int rank, size;
    MPI_File infile, outfile;
    MPI_Status status;
    MPI_Offset file_size;
    unsigned char *inbuf, *outbuf;
    int chunk_size, inbuf_size, outbuf_size;
    MPI_Init(&arge, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI File open(MPI_COMM_WORLD, argv[1], MPI_MODE_RDONLY, MPI_INFO_NULL, &infile);
    MPI File_get_size (infile, &file_size);
    chunk_size = (file_size + size - 1)/size;
    inbuf_size = chunk_size;
    outbuf_size = compressBound (inbuf_size);
    inbuf = (unsigned char *)malloc(inbuf_size);
    outbuf = (unsigned char *)malloc(outbuf_size);
    MPI_File_read_at(infile, rank * chunk_size, inbuf, inbuf_size, MPI_BYTE, &status);
    MPI_File_close (&infile);
    MPI_Barrier (MPI_COMM_WORLD);
    double start = MPI Wtime();

    if (zcompress(inbuf, inbuf_size, outbuf, outbuf_size)==0)
    {
        printf("Falha na compressão em %d\n", rank);
        MPI_Finalize();
        return 1;
    }

    double end = MPI_Wtime();
    double time = end - start;
    MPI_File_open(MPI_COMM_WORLD, argv[2], MPI_MODE_WRONLY | MPI_MODE_CREATE, MPI_INFO_NULL, & outfile);
    MPI_File_write_at(outfile, rank outbuf_size, outbuf, outbuf_size, MPI_BYTE, &status);
    MPI_File_close(& outfile);
    free(inbuf);
    free(outbuf);
    MPI_Finalize();

    if (rank == 0)
        printf("Compressão finalizada em %lf s\n", time);
        
    return 0;
}
