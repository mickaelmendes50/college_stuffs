#include <iomanip>
#include <iostream>
#include <curand_kernel.h>

__global__ void monteCarloPI(int *count, int N) {
    int tid = threadIdx.x + blockIdx.x * blockDim.x;
    int seed = clock() + tid;

    curandState state;
    curand_init(seed, tid, 0, &state);

    int local_k = 0;

    for (int i = 0; i < N; ++i) {
        // Gerando valor aleatório para os pontos de X e Y
        double x = curand_uniform_double(&state);
        double y = curand_uniform_double(&state);

        // Se o ponto não está dentro da área, incrementamos k
        if (x * x + y * y >= 1.0) {
            local_k++;
        }
    }

    atomicAdd(count, local_k);
}

int main() {
    // Configurando a precisão do resultado
    std::cout << std::setprecision(10);
	std::cout << std::fixed;

    // Variáveis
    int N = 1000000000;  // Total de iterações: 1.000.000.000
    int k = 0;
    int *device_count;

    // Alocando espaço na GPU para o resultado
    cudaMalloc(&device_count, sizeof(int));
    cudaMemcpy(device_count, &k, sizeof(int), cudaMemcpyHostToDevice);

    // Chamando o kernel CUDA
    monteCarloPI<<<1, 1>>>(device_count, N);

    // Copiando o resultado de volta para a CPU
    cudaMemcpy(&k, device_count, sizeof(int), cudaMemcpyDeviceToHost);

    // Liberando a memória na GPU
    cudaFree(device_count);

    // Calculando PI
    double M = N - k; // valor de pontos na área
    double pi = 4 * M / static_cast<double>(N);
    std::cout << "PI = " << pi << std::endl;

    return 0;
}
