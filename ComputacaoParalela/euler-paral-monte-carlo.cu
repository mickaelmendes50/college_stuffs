#include <iomanip>
#include <iostream>
#include <curand_kernel.h>
#include <cmath>

__global__ void monteCarloEuler(int *count, int N, unsigned long long seed) {
    int tid = threadIdx.x + blockIdx.x * blockDim.x;
    int total_threads = blockDim.x * gridDim.x;

    curandState state;
    curand_init(seed, tid, 0, &state);

    int local_k = 0;

    // Divida o total de iterações entre todas as threads
    for (int i = tid; i < N; i += total_threads) {
        double x = curand_uniform_double(&state);
        double y = curand_uniform_double(&state);

        // Verificando se está dentro do círculo
        if (x * x + y * y <= 1.0) {
            local_k++;
        }
    }

    // Soma local_k em um único valor usando atomicAdd
    atomicAdd(count, local_k);
}

int main() {
    // Configurando a precisão do resultado
    std::cout << std::setprecision(15);
    std::cout << std::fixed;

    // Variáveis
    int N = 100000000;  // Total de iterações
    int *device_count, *host_count;
    host_count = new int;  // Variável na CPU para receber o resultado

    // Alocando espaço na GPU para o resultado
    cudaMalloc(&device_count, sizeof(int));

    // Configurando a execução com um grande número de blocos e threads por bloco
    dim3 blocks(1024, 1, 1);
    dim3 threads(1024, 1, 1);

    // Semente aleatória única para evitar resultados diferentes a cada execução
    unsigned long long seed = 12345;

    // Chamando o kernel CUDA
    monteCarloEuler<<<blocks, threads>>>(device_count, N, seed);

    // Copiando o resultado de volta para a CPU
    cudaMemcpy(host_count, device_count, sizeof(int), cudaMemcpyDeviceToHost);

    // Liberando a memória na GPU
    cudaFree(device_count);

    // Calculando Euler
    double M_fraction = static_cast<double>(*host_count) / N;
    double euler = 1.0 / M_fraction;
    std::cout << "Euler = " << euler << std::endl;

    delete host_count;

    return 0;
}
