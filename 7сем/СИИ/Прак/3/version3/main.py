'''
Это задание - настоящий файловый ужас.
Аккуратнее, прога создаст много файлов. Входных демо-файлов и Выходных файлов. 
'''

import numpy as np
import matplotlib.pyplot as plt
import os
from typing import List, Tuple, Optional

def generate_default_input(filename: str, task_num: int):
    """Генерация входных файлов по умолчанию"""
    if task_num == 1:
        # Для задачи 1: p=3, n=2
        p, n = 3, 2
        matrices = [np.random.randint(0, 10, (n, n)) for _ in range(p)]
        vectors = [np.random.randint(0, 10, (n, 1)) for _ in range(p)]
        np.savez(filename, p=p, n=n, matrices=matrices, vectors=vectors)
    
    elif task_num == 2:
        # Для задачи 2: вектор чисел
        data = np.array([1, 2, 3, 4, 5])
        np.save(filename, data)
    
    elif task_num == 3:
        # Для задачи 3: матрица с повторяющимися строками
        data = np.array([[1, 2, 3], [4, 5, 6], [1, 2, 3], [7, 8, 9]])
        np.save(filename, data)
    
    elif task_num == 4:
        # Для задачи 4: размеры матрицы
        data = np.array([5, 4])  # M=5, N=4
        np.save(filename, data)
    
    elif task_num == 5:
        # Для задачи 5: параметры для шахматной матрицы
        data = np.array([4, 5, 1, 10])  # M=4, N=5, a=1, b=10
        np.save(filename, data)
    
    elif task_num == 6:
        # Для задачи 6: параметры круга
        data = np.array([50, 50, 20, 255, 0, 0])  # width, height, radius, r, g, b
        np.save(filename, data)
    
    elif task_num == 7:
        # Для задачи 7: тензор для стандартизации
        data = np.random.rand(3, 4, 5)
        np.save(filename, data)
    
    elif task_num == 8:
        # Для задачи 8: матрица и параметры выделения
        matrix = np.random.randint(0, 10, (6, 6))
        params = np.array([2, 3, 3, 3, -1])  # row, col, height, width, fill
        np.savez(filename, matrix=matrix, params=params)
    
    elif task_num == 9:
        # Для задачи 9: матрица для поиска мод
        data = np.random.randint(0, 5, (4, 6))
        np.save(filename, data)
    
    elif task_num == 10:
        # Для задачи 10: изображение и веса каналов
        image = np.random.randint(0, 255, (10, 10, 3))
        weights = np.array([0.3, 0.6, 0.1])
        np.savez(filename, image=image, weights=weights)

def get_input_filename(task_num: int) -> str:
    """Получить правильное имя входного файла с учетом расширения"""
    base_name = f'input{task_num}'
    
    # Проверяем, существует ли файл с расширением .npy
    npy_file = f'{base_name}.npy'
    if os.path.exists(npy_file):
        return npy_file
    
    # Проверяем, существует ли файл с расширением .npz
    npz_file = f'{base_name}.npz'
    if os.path.exists(npz_file):
        return npz_file
    
    # Если файл не существует, возвращаем базовое имя
    # (расширение будет добавлено при генерации)
    return base_name

def task1_matrix_vector_sum(input_file: str = None, output_file: str = 'output1.npy'):
    """Задача 1: Сумма произведений матриц на векторы"""
    if input_file is None:
        input_file = get_input_filename(1)
    
    if not os.path.exists(input_file) and not os.path.exists(input_file + '.npz'):
        generate_default_input(input_file, 1)
        input_file = get_input_filename(1)  # Обновляем имя файла после генерации
    
    # Загружаем данные с учетом расширения
    if input_file.endswith('.npz'):
        data = np.load(input_file, allow_pickle=True)
    else:
        data = np.load(input_file, allow_pickle=True)
    
    # Обрабатываем разные форматы данных
    if 'p' in data:
        p, n = data['p'], data['n']
        matrices = data['matrices']
        vectors = data['vectors']
    else:
        # Если данные в другом формате, используем значения по умолчанию
        p, n = 3, 2
        matrices = [np.random.randint(0, 10, (n, n)) for _ in range(p)]
        vectors = [np.random.randint(0, 10, (n, 1)) for _ in range(p)]
    
    result = np.zeros((n, 1))
    for i in range(p):
        result += matrices[i] @ vectors[i]
    
    np.save(output_file, result)
    return result

def task2_binary_matrix(input_file: str = None, output_file: str = 'output2.npy'):
    """Задача 2: Преобразование вектора в матрицу бинарных представлений"""
    if input_file is None:
        input_file = get_input_filename(2)
    
    if not os.path.exists(input_file) and not os.path.exists(input_file + '.npy'):
        generate_default_input(input_file, 2)
        input_file = get_input_filename(2)
    
    numbers = np.load(input_file)
    
    # Определяем максимальное количество битов
    max_num = np.max(numbers)
    num_bits = int(np.ceil(np.log2(max_num + 1)))
    
    # Создаем матрицу бинарных представлений
    binary_matrix = np.zeros((len(numbers), num_bits), dtype=int)
    
    for i, num in enumerate(numbers):
        binary_repr = [int(bit) for bit in bin(num)[2:].zfill(num_bits)]
        binary_matrix[i] = binary_repr
    
    np.save(output_file, binary_matrix)
    return binary_matrix

def task3_unique_rows(input_file: str = None, output_file: str = 'output3.npy'):
    """Задача 3: Уникальные строки матрицы"""
    if input_file is None:
        input_file = get_input_filename(3)
    
    if not os.path.exists(input_file) and not os.path.exists(input_file + '.npy'):
        generate_default_input(input_file, 3)
        input_file = get_input_filename(3)
    
    matrix = np.load(input_file)
    
    # Используем numpy.unique с axis=0 для поиска уникальных строк
    unique_rows = np.unique(matrix, axis=0)
    
    np.save(output_file, unique_rows)
    return unique_rows

def task4_normal_matrix_histogram(input_file: str = None, output_file: str = 'output4.npy'):
    """Задача 4: Нормальное распределение и гистограммы"""
    if input_file is None:
        input_file = get_input_filename(4)
    
    if not os.path.exists(input_file) and not os.path.exists(input_file + '.npy'):
        generate_default_input(input_file, 4)
        input_file = get_input_filename(4)
    
    dimensions = np.load(input_file)
    M, N = dimensions[0], dimensions[1]
    
    # Создаем матрицу с нормальным распределением
    matrix = np.random.normal(0, 1, (M, N))
    
    # Вычисляем мат. ожидание и дисперсию для каждого столбца
    means = np.mean(matrix, axis=0)
    variances = np.var(matrix, axis=0)
    
    # Строим гистограммы для каждой строки
    fig, axes = plt.subplots(M, 1, figsize=(10, 2*M))
    if M == 1:
        axes = [axes]
    
    for i in range(M):
        axes[i].hist(matrix[i], bins=10, alpha=0.7, edgecolor='black')
        axes[i].set_title(f'Histogram for row {i+1}')
        axes[i].set_xlabel('Value')
        axes[i].set_ylabel('Frequency')
    
    plt.tight_layout()
    plt.savefig('histograms.png')
    plt.close()
    
    # Сохраняем результаты
    results = {
        'matrix': matrix,
        'means': means,
        'variances': variances
    }
    np.savez(output_file.replace('.npy', ''), **results)
    
    return matrix, means, variances

def task5_chess_matrix(input_file: str = None, output_file: str = 'output5.npy'):
    """Задача 5: Шахматная матрица"""
    if input_file is None:
        input_file = get_input_filename(5)
    
    if not os.path.exists(input_file) and not os.path.exists(input_file + '.npy'):
        generate_default_input(input_file, 5)
        input_file = get_input_filename(5)
    
    params = np.load(input_file)
    M, N, a, b = params[0], params[1], params[2], params[3]
    
    # Создаем шахматную матрицу
    matrix = np.zeros((M, N))
    
    for i in range(M):
        for j in range(N):
            if (i + j) % 2 == 0:
                matrix[i, j] = a
            else:
                matrix[i, j] = b
    
    np.save(output_file, matrix)
    return matrix

def task6_circle_image(input_file: str = None, output_file: str = 'output6.npy'):
    """Задача 6: Изображение круга"""
    if input_file is None:
        input_file = get_input_filename(6)
    
    if not os.path.exists(input_file) and not os.path.exists(input_file + '.npy'):
        generate_default_input(input_file, 6)
        input_file = get_input_filename(6)
    
    params = np.load(input_file)
    width, height, radius, r, g, b = params
    
    # Создаем черный фон
    image = np.zeros((height, width, 3), dtype=np.uint8)
    
    # Центр изображения
    center_x, center_y = width // 2, height // 2
    
    # Рисуем круг
    for y in range(height):
        for x in range(width):
            if (x - center_x)**2 + (y - center_y)**2 <= radius**2:
                image[y, x] = [r, g, b]
    
    np.save(output_file, image)
    return image

def task7_standardize_tensor(input_file: str = None, output_file: str = 'output7.npy'):
    """Задача 7: Стандартизация тензора"""
    if input_file is None:
        input_file = get_input_filename(7)
    
    if not os.path.exists(input_file) and not os.path.exists(input_file + '.npy'):
        generate_default_input(input_file, 7)
        input_file = get_input_filename(7)
    
    tensor = np.load(input_file)
    
    # Вычисляем мат. ожидание и СКО
    mean = np.mean(tensor)
    std = np.std(tensor)
    
    # Стандартизируем
    standardized_tensor = (tensor - mean) / std
    
    np.save(output_file, standardized_tensor)
    return standardized_tensor

def task8_extract_submatrix(input_file: str = None, output_file: str = 'output8.npy'):
    """Задача 8: Выделение подматрицы"""
    if input_file is None:
        input_file = get_input_filename(8)
    
    if not os.path.exists(input_file) and not os.path.exists(input_file + '.npz'):
        generate_default_input(input_file, 8)
        input_file = get_input_filename(8)
    
    # Загружаем данные с учетом расширения
    if input_file.endswith('.npz'):
        data = np.load(input_file)
    else:
        data = np.load(input_file)
    
    # Обрабатываем разные форматы данных
    if 'matrix' in data:
        matrix = data['matrix']
        params = data['params']
    else:
        # Если данные в другом формате, используем значения по умолчанию
        matrix = np.random.randint(0, 10, (6, 6))
        params = np.array([2, 3, 3, 3, -1])
    
    row, col, sub_h, sub_w, fill_value = params
    row, col, sub_h, sub_w = int(row), int(col), int(sub_h), int(sub_w)
    
    # Вычисляем границы подматрицы
    start_row = row - sub_h // 2
    end_row = start_row + sub_h
    start_col = col - sub_w // 2
    end_col = start_col + sub_w
    
    # Создаем подматрицу с заполнением
    submatrix = np.full((sub_h, sub_w), fill_value)
    
    # Копируем доступные элементы
    for i in range(max(0, start_row), min(matrix.shape[0], end_row)):
        for j in range(max(0, start_col), min(matrix.shape[1], end_col)):
            sub_i = i - start_row
            sub_j = j - start_col
            if 0 <= sub_i < sub_h and 0 <= sub_j < sub_w:
                submatrix[sub_i, sub_j] = matrix[i, j]
    
    np.save(output_file, submatrix)
    return submatrix

def task9_most_frequent_per_row(input_file: str = None, output_file: str = 'output9.npy'):
    """Задача 9: Наиболее частые числа в каждой строке"""
    if input_file is None:
        input_file = get_input_filename(9)
    
    if not os.path.exists(input_file) and not os.path.exists(input_file + '.npy'):
        generate_default_input(input_file, 9)
        input_file = get_input_filename(9)
    
    matrix = np.load(input_file)
    
    result = np.zeros(matrix.shape[0], dtype=matrix.dtype)
    
    for i in range(matrix.shape[0]):
        row = matrix[i]
        unique, counts = np.unique(row, return_counts=True)
        max_count_idx = np.argmax(counts)
        result[i] = unique[max_count_idx]
    
    np.save(output_file, result)
    return result

def task10_weighted_channel_sum(input_file: str = None, output_file: str = 'output10.npy'):
    """Задача 10: Взвешенная сумма каналов изображения"""
    if input_file is None:
        input_file = get_input_filename(10)
    
    if not os.path.exists(input_file) and not os.path.exists(input_file + '.npz'):
        generate_default_input(input_file, 10)
        input_file = get_input_filename(10)
    
    # Загружаем данные с учетом расширения
    if input_file.endswith('.npz'):
        data = np.load(input_file)
    else:
        data = np.load(input_file)
    
    # Обрабатываем разные форматы данных
    if 'image' in data:
        image = data['image']
        weights = data['weights']
    else:
        # Если данные в другом формате, используем значения по умолчанию
        image = np.random.randint(0, 255, (10, 10, 3))
        weights = np.array([0.3, 0.6, 0.1])
    
    # Взвешенная сумма каналов
    result = np.zeros((image.shape[0], image.shape[1]))
    
    for channel in range(image.shape[2]):
        result += image[:, :, channel] * weights[channel]
    
    np.save(output_file, result)
    return result

# Демонстрация работы всех функций
if __name__ == "__main__":
    print("Задача 1:")
    result1 = task1_matrix_vector_sum()
    print(f"Результат: {result1.flatten()}")
    
    print("\nЗадача 2:")
    result2 = task2_binary_matrix()
    print(f"Бинарная матрица:\n{result2}")
    
    print("\nЗадача 3:")
    result3 = task3_unique_rows()
    print(f"Уникальные строки:\n{result3}")
    
    print("\nЗадача 4:")
    matrix, means, variances = task4_normal_matrix_histogram()
    print(f"Мат. ожидания столбцов: {means}")
    print(f"Дисперсии столбцов: {variances}")
    
    print("\nЗадача 5:")
    result5 = task5_chess_matrix()
    print(f"Шахматная матрица:\n{result5}")
    
    print("\nЗадача 6:")
    result6 = task6_circle_image()
    print(f"Изображение круга создано, размер: {result6.shape}")
    
    print("\nЗадача 7:")
    result7 = task7_standardize_tensor()
    print(f"Стандартизированный тензор, среднее: {np.mean(result7):.4f}, СКО: {np.std(result7):.4f}")
    
    print("\nЗадача 8:")
    result8 = task8_extract_submatrix()
    print(f"Подматрица:\n{result8}")
    
    print("\nЗадача 9:")
    result9 = task9_most_frequent_per_row()
    print(f"Наиболее частые числа: {result9}")
    
    print("\nЗадача 10:")
    result10 = task10_weighted_channel_sum()
    print(f"Взвешенная сумма каналов, размер: {result10.shape}")