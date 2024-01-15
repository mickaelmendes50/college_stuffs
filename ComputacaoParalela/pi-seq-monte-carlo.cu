#include <iostream>
#include <curand_kernel.h>

__global__ void monteCarloPI(unsigned int *count, unsigned int N) {
    unsigned int tid = threadIdx.x + blockIdx.x * blockDim.x;
    unsigned int seed = clock() + tid;

    curandState state;
    curand_init(seed, tid, 0, &state);

    unsigned int local_count = 0;

    for (unsigned int i = 0; i < N; ++i) {
        double x = curand_uniform_double(&state);
        double y = curand_uniform_double(&state);

        if (x*x + y*y >= 1.0) {
            local_count++;
        }
    }

    atomicAdd(count, local_count);
}

int main() {
    unsigned int N = 1000000;  // Total de iterações
    unsigned int *d_count, h_count;

    // Alocando espaço na GPU para o resultado
    cudaMalloc(&d_count, sizeof(unsigned int));
    cudaMemcpy(d_count, &h_count, sizeof(unsigned int), cudaMemcpyHostToDevice);

    // Configurando a execução com uma única thread
    dim3 blocks(ceil(N / 1024.0), 1, 1);
    dim3 threads(1024, 1, 1);

    // Chamando o kernel CUDA
    monteCarloPI<<<blocks, threads>>>(d_count, N);

    // Copiando o resultado de volta para a CPU
    cudaMemcpy(&h_count, d_count, sizeof(unsigned int), cudaMemcpyDeviceToHost);

    // Liberando a memória na GPU
    cudaFree(d_count);

    // Calculando PI
    double pi = 4 * (N - h_count) / static_cast<double>(N);
    std::cout << "PI = " << pi << std::endl;

    return 0;
}
