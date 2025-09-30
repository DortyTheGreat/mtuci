#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> adaptiveExponentialSpacing(double start, double end, int count, double minStep) {
    std::vector<double> result;
    if (count <= 1) {
        result.push_back(start);
        return result;
    }

    double ratio = std::pow(end / start, 1.0 / (count - 1));

    result.push_back(start);
    double prev = start;

    for (int i = 1; i < count; ++i) {
        double expVal = start * std::pow(ratio, i);

        // Проверка на минимальный шаг
        if (expVal - prev < minStep) {
            double linearVal = prev + minStep;
            // Если ушли за пределы end, то "притягиваем" к end
            if (linearVal > end) linearVal = end;
            result.push_back(linearVal);
            prev = linearVal;
        } else {
            result.push_back(expVal);
            prev = expVal;
        }
    }

    return result;
}

std::vector<double> adaptiveExponentialSpacing(double start, double end, int count, double minStep) {
    std::vector<double> result;
    if (count <= 1) {
        result.push_back(start);
        return result;
    }

    double ratio = std::pow(end / start, 1.0 / (count - 1));

    result.push_back(start);
    double prev = start;

    for (int i = 1; i < count; ++i) {
        double expVal = start * std::pow(ratio, i);

        // Проверка на минимальный шаг
        if (expVal - prev < minStep) {
            double linearVal = prev + minStep;
            // Если ушли за пределы end, то "притягиваем" к end
            if (linearVal > end) linearVal = end;
            result.push_back(linearVal);
            prev = linearVal;
        } else {
            result.push_back(expVal);
            prev = expVal;
        }
    }

    return result;
}

int main() {
    double start = 1, end = 1000;
    int count = 10;
    double minStep = 50;

    std::vector<double> values = adaptiveExponentialSpacing(start, end, count, minStep);

    for (double v : values) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    std::vector<double> values2 = adaptiveExponentialSpacing(start, end, count, 0);

    for (double v : values2) {
        std::cout << v << " ";
    }
    std::cout << std::endl;


    return 0;
}
