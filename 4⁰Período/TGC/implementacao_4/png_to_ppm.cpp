#include "graph.cpp"
#include "union_find.cpp"
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#define K  5000

using namespace std; struct Pixel {
    int x;
    int y;
    int R;
    int G;
    int B;
};

struct Image {
    int width;
    int height;
    int max_color;
    vector<vector<struct Pixel>> pixel_matrix;
};
double intensity(Pixel p) {
    return (p.R + p.G + p.B) / 3.0;
}

// Função para calcular a "distância" entre dois pixels com base nas intensidades
double intensity_distance(Pixel p1, Pixel p2) {
    double intensity1 = intensity(p1);
    double intensity2 = intensity(p2);
    return fabs(intensity1 - intensity2);  // Diferença absoluta entre as intensidades
}

// Função para ler o arquivo PPM

// Função para calcular a distância Euclidiana entre dois pixels
struct Image *read_file(string filename) {
    struct Image *image = new struct Image;
    string magic_number;
    ifstream file(filename, ios::binary);  // Abrir o arquivo em modo binário

    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << filename << endl;
        return nullptr;
    }

    file >> magic_number;
    if (magic_number != "P3" && magic_number != "P6" && magic_number != "P2" && magic_number != "P5") {
        cerr << "Formato do arquivo não é suportado: " << magic_number << endl;
        return nullptr;
    }

    file >> image->width >> image->height >> image->max_color;
    file.ignore(); // Ignorar o caractere de nova linha após o cabeçalho

    image->pixel_matrix.resize(image->height, vector<Pixel>(image->width));

    if (magic_number == "P3") {
        // Para o formato P3 (texto)
        for (int i = 0; i < image->height; i++) {
            for (int j = 0; j < image->width; j++) {
                file >> image->pixel_matrix[i][j].R >> image->pixel_matrix[i][j].G >> image->pixel_matrix[i][j].B;
                image->pixel_matrix[i][j].x = i;
                image->pixel_matrix[i][j].y = j;
            }
        }
    } else if (magic_number == "P6") {
        // Para o formato P6 (binário)
        for (int i = 0; i < image->height; i++) {
            for (int j = 0; j < image->width; j++) {
                unsigned char rgb[3];
                file.read(reinterpret_cast<char*>(rgb), 3); // Lê 3 bytes (R, G, B)
                image->pixel_matrix[i][j].R = rgb[0];
                image->pixel_matrix[i][j].G = rgb[1];
                image->pixel_matrix[i][j].B = rgb[2];
                image->pixel_matrix[i][j].x = i;
                image->pixel_matrix[i][j].y = j;
            }
        }
    } else if (magic_number == "P2") {
        // Para o formato P2 (PGM texto)
        for (int i = 0; i < image->height; i++) {
            for (int j = 0; j < image->width; j++) {
                int gray;
                file >> gray;
                image->pixel_matrix[i][j].R = gray;
                image->pixel_matrix[i][j].G = gray;
                image->pixel_matrix[i][j].B = gray;
                image->pixel_matrix[i][j].x = i;
                image->pixel_matrix[i][j].y = j;
            }
        }
    } else if (magic_number == "P5") {
        // Para o formato P5 (PGM binário)
        for (int i = 0; i < image->height; i++) {
            for (int j = 0; j < image->width; j++) {
                unsigned char gray;
                file.read(reinterpret_cast<char*>(&gray), 1); // Lê 1 byte
                image->pixel_matrix[i][j].R = gray;
                image->pixel_matrix[i][j].G = gray;
                image->pixel_matrix[i][j].B = gray;
                image->pixel_matrix[i][j].x = i;
                image->pixel_matrix[i][j].y = j;
            }
        }
    }

    file.close();
    return image;
}
double euclidian_distance(Pixel p1, Pixel p2) {
    return sqrt(pow(p1.R - p2.R, 2) + pow(p1.G - p2.G, 2) + pow(p1.B - p2.B, 2) + pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Função para converter a imagem para um grafo
Graph convert_image_to_graph(struct Image image) {
    Graph g = Graph(image.height * image.width);

    for (int i = 0; i < image.height; i++) {
        for (int j = 0; j < image.width; j++) {
            int current_vertex = i * image.width + j;
            Pixel current_pixel = image.pixel_matrix[i][j];
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if (di == 0 && dj == 0)
                        continue; // Ignorar o próprio pixel

                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < image.height && nj >= 0 && nj < image.width) {
                        int neighbor_vertex = ni * image.width + nj;
                        Pixel neighbor_pixel = image.pixel_matrix[ni][nj];
                        double weight = euclidian_distance(current_pixel, neighbor_pixel);
                        if(weight<120)
                        g.add_edge(current_vertex, neighbor_vertex, weight);
                    }
                }
            }
        }
    }
    return g;
}
double Mint(UnionFind uf, int u, int v)
{
    int rootU = uf.find(u);
    int rootV = uf.find(v);
    return min(uf.Int[rootU] + (double)K/uf.component_size[rootU], uf.Int[rootV] + (double)K/uf.component_size[rootV]);

}

Pixel HSLToHex(int h, double s, double l) {
    // Chroma (C) é a diferença entre a maior e menor intensidade possível
    double C = (1 - fabs(2 * l - 1)) * s;
    
    // X é a segunda maior intensidade
    double X = C * (1 - fabs(fmod(h / 60.0, 2) - 1));
    
    // m é o valor que se soma para ajustar a luminosidade
    double m = l - C / 2;
    
    // Inicializa as variáveis r, g, b
    double r = 0, g = 0, b = 0;

    // Dependendo da faixa do valor de h (Hue), determinamos os valores de r, g, b
    if (h >= 0 && h < 60) {
        r = C; g = X; b = 0;
    } else if (h >= 60 && h < 120) {
        r = X; g = C; b = 0;
    } else if (h >= 120 && h < 180) {
        r = 0; g = C; b = X;
    } else if (h >= 180 && h < 240) {
        r = 0; g = X; b = C;
    } else if (h >= 240 && h < 300) {
        r = X; g = 0; b = C;
    } else {
        r = C; g = 0; b = X;
    }

    // Ajuste para a luminosidade (adicionando m)
    r += m; g += m; b += m;

    // Converter para 0-255 e garantir que o valor final esteja entre 0 e 255
    int R = static_cast<int>(fmin(fmax(r * 255, 0), 255));
    int G = static_cast<int>(fmin(fmax(g * 255, 0), 255));
    int B = static_cast<int>(fmin(fmax(b * 255, 0), 255));

    return { R, G, B };
}

std::vector<Pixel> generateSegmentedPixels(int numPixels) {
    std::vector<Pixel> pixels;
    pixels.reserve(numPixels);

    // Semente para geração de números aleatórios
    std::srand(time(nullptr));

    for (int i = 0; i < numPixels; ++i) {
        Pixel pixel;

        // Gerar valores aleatórios para R, G, B entre 0 e 255
        pixel.R = std::rand() % 256;
        pixel.G = std::rand() % 256;
        pixel.B = std::rand() % 256;

        pixels.push_back(pixel);
    }

    return pixels;
}


void saveSegmentedImage(const string& outputFilename, vector<vector<int>>& segments, Image& image) {
    // Gerar cores para a segmentação
    vector<Pixel> colors = generateSegmentedPixels(image.width*image.height);

    // Pintar os pixels de acordo com a segmentação
    for (int index = 0; index < segments.size(); ++index) {
        for (int v : segments[index]) {
            int i = v / image.width;  // Calcula a linha
            int j = v % image.width;  // Calcula a coluna

            if (i >= 0 && i < image.height && j >= 0 && j < image.width) {
                image.pixel_matrix[i][j] = colors[index];
            }
        }
    }

    // Salvar a imagem como arquivo PPM
    ofstream outFile(outputFilename + ".ppm", ios::binary);
    if (!outFile.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << outputFilename + ".ppm" << endl;
        return;
    }

    // Escrever cabeçalho PPM
    outFile << "P3\n";
    outFile << image.width << " " << image.height << "\n";
    outFile << "255\n";

    // Escrever dados dos pixels
    for (int i = 0; i < image.height; ++i) {
        for (int j = 0; j < image.width; ++j) {
            Pixel& pixel = image.pixel_matrix[i][j];
            outFile << pixel.R << " " << pixel.G << " " << pixel.B << " ";
        }
        outFile << "\n";
    }

    outFile.close();
    cout << "Imagem salva como: " << outputFilename << ".ppm" << endl;
}

// Salvar imagem segmentada em PGM
void saveSegmentedImagePGM(const string& outputFilename, vector<vector<int>>& segments, Image& image) {
    vector<int> grayscales(segments.size());
    int grayStep = 255 / (segments.size() - 1); // Intervalo entre tons de cinza

    // Gera tons de cinza únicos para cada segmento
    for (int index = 0; index < segments.size(); ++index) {
        grayscales[index] = index * grayStep;
    }

    // Aplica os tons de cinza nos pixels
    for (int index = 0; index < segments.size(); ++index) {
        for (int v : segments[index]) {
            int i = v / image.width;
            int j = v % image.width;

            if (i >= 0 && i < image.height && j >= 0 && j < image.width) {
                int grayValue = grayscales[index];
                image.pixel_matrix[i][j].R = grayValue;
                image.pixel_matrix[i][j].G = grayValue;
                image.pixel_matrix[i][j].B = grayValue;
            }
        }
    }

    ofstream outFile(outputFilename + ".pgm", ios::binary);
    if (!outFile.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << outputFilename + ".pgm" << endl;
        return;
    }

    outFile << "P2\n";
    outFile << image.width << " " << image.height << "\n";
    outFile << "255\n";

    for (int i = 0; i < image.height; ++i) {
        for (int j = 0; j < image.width; ++j) {
            int grayValue = image.pixel_matrix[i][j].R; // Usa apenas o canal R como tons de cinza
            outFile << grayValue << " ";
        }
        outFile << "\n";
    }

    outFile.close();
    cout << "Imagem salva como: " << outputFilename << ".pgm" << endl;
}
void print_segments(const std::vector<std::vector<int>>& segments) {
    std::cout << "Segmentos encontrados:" << std::endl;
    for (int i = 0; i < segments.size(); ++i) {
        std::cout << "Componente " << i + 1 << ": ";
        for (int vertex : segments[i]) {
            std::cout << vertex << " ";
        }
        std::cout << std::endl;
    }
}
inline float pixel_value(Pixel& pixel, char channel) {
    switch (channel) {
        case 'R': return pixel.R;
        case 'G': return pixel.G;
        case 'B': return pixel.B;
        default: return 0;
    }
}

// Função para aplicar a máscara de convolução a um canal específico de um pixel
void convolve_image(std::vector<std::vector<Pixel>>& pixel_matrix, std::vector<float>& mask, char channel) {
    int height = pixel_matrix.size();
    int width = pixel_matrix[0].size();
    int len = mask.size();
    
    // Criação de uma matriz de pixels temporária para armazenar os resultados
    std::vector<std::vector<Pixel>> result_matrix(height, std::vector<Pixel>(width));

    // Aplicar a convolução para cada pixel
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            float sum = mask[0] * pixel_value(pixel_matrix[y][x], channel);
            for (int i = 1; i < len; i++) {
                // Verificar os pixels ao redor e aplicar a máscara
                int prev_x = std::max(x - i, 0);
                int next_x = std::min(x + i, width - 1);
                sum += mask[i] * (pixel_value(pixel_matrix[y][prev_x], channel) + pixel_value(pixel_matrix[y][next_x], channel));
            }

            // Armazenar o resultado na matriz temporária
            if (channel == 'R') result_matrix[y][x].R = std::round(sum);
            if (channel == 'G') result_matrix[y][x].G = std::round(sum);
            if (channel == 'B') result_matrix[y][x].B = std::round(sum);
        }
    }

    // Copiar os resultados de volta para a matriz original
    pixel_matrix = result_matrix;
}
void filterSmallSegments(vector<vector<int>>& segments, int imageWidth, int imageHeight) {
    int minSegmentSize = (imageWidth * imageHeight) /200 ; // 1% da área total
    segments.erase(
        remove_if(segments.begin(), segments.end(),
                  [minSegmentSize](const vector<int>& segment) {
                      return segment.size() < minSegmentSize;
                  }),
        segments.end());
}

// Função para aplicar a máscara de convolução (para os três canais de cor)
void convolve_all_channels(std::vector<std::vector<Pixel>>& pixel_matrix, std::vector<float>& mask) {
    convolve_image(pixel_matrix, mask, 'R');
    convolve_image(pixel_matrix, mask, 'G');
    convolve_image(pixel_matrix, mask, 'B');
}

int main() {
    string filename = "baseball.pgm"; // Nome do arquivo PPM

    Image* image = read_file(filename);
    if (image == nullptr) {
        return -1;
    }

    Graph g = convert_image_to_graph(*image);

    vector<Edge> edges = g.get_edges(); 
    for (const Edge& edge : edges) {
        cout << "Aresta entre " << edge.u<< " e " << edge.v<< " com peso " << edge.weight << endl;
    }
    UnionFind uf = UnionFind(g.size);
    
    for(int i = 0; i<edges.size(); i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        if(uf.find(u) != uf.find(v) && edges[i].weight< Mint(uf, u, v))
        {
            uf.union_by_rank(u, v, edges[i]);
        }
    }
unordered_map<int, vector<int>> components;
    for (int i = 0; i < g.size; ++i) {
        int root = uf.find(i);
        components[root].push_back(i);
    }

    // Extrair os componentes como uma lista de segmentos
    vector<vector<int>> segments;
    for (const auto& component : components) {
        segments.push_back(component.second);
    }

    // Filtrar segmentos pequenos antes de salvar
//    filterSmallSegments(segments, image->width, image->height);
    print_segments(segments);

    // Salvar a imagem segmentada
    saveSegmentedImage("output_segmented", segments, *image);
    saveSegmentedImagePGM("output_segmented_bw", segments, *image);

    delete image;

    return 0;
}
