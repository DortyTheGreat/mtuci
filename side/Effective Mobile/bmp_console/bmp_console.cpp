#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdint>
#include <windows.h>

class BMPImage {
private:
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    std::vector<uint8_t> data;
    std::string filename;
    int rowSize;
    int padding;
    int bytesPerPixel;

public:
    bool load(const std::string& fname) {
        filename = fname;
        std::ifstream in(fname, std::ios::binary);
        if (!in) {
            std::cerr << "Error opening file: " << fname << std::endl;
            return false;
        }

        in.read(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
        in.read(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));

        if (fileHeader.bfType != 0x4D42 || (infoHeader.biBitCount != 24 && infoHeader.biBitCount != 32)) {
            std::cerr << "Unsupported BMP format. Only 24-bit or 32-bit BMP supported." << std::endl;
            return false;
        }

        bytesPerPixel = infoHeader.biBitCount / 8;
        rowSize = ((infoHeader.biWidth * bytesPerPixel + 3) / 4) * 4;
        padding = rowSize - (infoHeader.biWidth * bytesPerPixel);
        int imageSize = rowSize * abs(infoHeader.biHeight);

        data.resize(imageSize);
        in.seekg(fileHeader.bfOffBits, std::ios::beg);
        in.read(reinterpret_cast<char*>(data.data()), imageSize);
        in.close();
        return true;
    }

    void display() const {
        for (int y = 0; y < abs(infoHeader.biHeight); ++y) {
            for (int x = 0; x < infoHeader.biWidth; ++x) {
                uint8_t* pixel = getPixelPtr(x, y);
                if (isBlack(pixel)) std::cout << '#';
                else if (isWhite(pixel)) std::cout << ' ';
                else std::cout << '?'; // For debugging
            }
            std::cout << '\n';
        }
    }

    void drawLine(int x1, int y1, int x2, int y2) {
        // Bresenham's line algorithm
        int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
        int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
        int err = dx + dy;

        while (true) {
            setPixel(x1, y1, 0, 0, 0); // draw black
            if (x1 == x2 && y1 == y2) break;
            int e2 = 2 * err;
            if (e2 >= dy) { err += dy; x1 += sx; }
            if (e2 <= dx) { err += dx; y1 += sy; }
        }
    }

    void drawX() {
        int w = infoHeader.biWidth;
        int h = abs(infoHeader.biHeight);
        drawLine(0, 0, w - 1, h - 1);
        drawLine(0, h - 1, w - 1, 0);
    }

    bool save(const std::string& outName) const {
        std::ofstream out(outName, std::ios::binary);
        if (!out) {
            std::cerr << "Failed to open output file.\n";
            return false;
        }

        out.write(reinterpret_cast<const char*>(&fileHeader), sizeof(fileHeader));
        out.write(reinterpret_cast<const char*>(&infoHeader), sizeof(infoHeader));
        out.write(reinterpret_cast<const char*>(data.data()), data.size());
        out.close();
        return true;
    }

private:
    uint8_t* getPixelPtr(int x, int y) const {
        int height = abs(infoHeader.biHeight);
        int row = infoHeader.biHeight > 0 ? (height - 1 - y) : y;
        return const_cast<uint8_t*>(&data[row * rowSize + x * bytesPerPixel]);
    }

    void setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b) {
        uint8_t* p = getPixelPtr(x, y);
        p[0] = b;
        p[1] = g;
        p[2] = r;
        if (bytesPerPixel == 4) p[3] = 255;
    }

    bool isBlack(uint8_t* p) const {
        return p[0] == 0 && p[1] == 0 && p[2] == 0;
    }

    bool isWhite(uint8_t* p) const {
        return p[0] == 255 && p[1] == 255 && p[2] == 255;
    }
};


int main() {
    std::string inputFile, outputFile;
    std::cout << ">> Enter input BMP file name: ";
    std::getline(std::cin, inputFile);

    BMPImage image;
    if (!image.load(inputFile)) return 1;

    std::cout << "\nOriginal image:\n";
    image.display();

    image.drawX();

    std::cout << "\nImage with X drawn:\n";
    image.display();

    std::cout << ">> Enter output BMP file name: ";
    std::getline(std::cin, outputFile);
    if (!image.save(outputFile)) return 1;

    std::cout << "Image saved to " << outputFile << "\n";
    return 0;
}
