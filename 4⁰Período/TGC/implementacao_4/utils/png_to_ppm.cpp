
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

void convertPngToPpm(const std::string& inputImage, const std::string& outputImage) {
    // Carregar a imagem de entrada (PNG)
    cv::Mat image = cv::imread(inputImage, cv::IMREAD_COLOR);
    if (image.empty()) {
        std::cerr << "Erro ao carregar a imagem!" << std::endl;
        return;
    }

    // Salvar a imagem no formato PPM
    if (!cv::imwrite(outputImage, image)) {
        std::cerr << "Erro ao salvar a imagem!" << std::endl;
        return;
    }

    std::cout << "Imagem convertida com sucesso!" << std::endl;
}

int main(int argc, char** argv) {
    // Verificar se o número de argumentos é suficiente
    if (argc != 3) {
        std::cerr << "Uso: " << argv[0] << " <inputImage> <outputImage>" << std::endl;
        return -1;
    }

    // Obter os parâmetros da linha de comando
    std::string inputImage = argv[1];
    std::string outputImage = argv[2];

    // Chamar a função de conversão
    convertPngToPpm(inputImage, outputImage);

    return 0;
}
