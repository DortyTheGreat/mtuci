import numpy as np
import os

def generate_matrices(rows_a, cols_a, cols_b, filename_a='A.txt', filename_b='B.txt', filename_c='C.txt'):
    """
    Генерирует матрицы A (rows_a x cols_a), B (cols_a x cols_b) и C = A * B,
    затем сохраняет их в текстовые файлы.
    
    Параметры:
    rows_a (int): количество строк матрицы A
    cols_a (int): количество столбцов матрицы A (также строк матрицы B)
    cols_b (int): количество столбцов матрицы B
    filename_a (str): имя файла для матрицы A
    filename_b (str): имя файла для матрицы B
    filename_c (str): имя файла для матрицы C
    """
    
    # Устанавливаем seed для воспроизводимости (опционально)
    np.random.seed(42)
    
    # Генерируем матрицы A и B со случайными числами
    A = np.random.rand(rows_a, cols_a) * 10  # Умножаем на 10 для чисел от 0 до 10
    B = np.random.rand(cols_a, cols_b) * 10
    
    # Вычисляем произведение матриц
    C = np.dot(A, B)
    
    # Функция для сохранения матрицы в файл
    def save_matrix(matrix, rows, cols, filename):
        with open(filename, 'w') as f:
            # Записываем количество строк и столбцов
            f.write(f"{rows}\n")
            f.write(f"{cols}\n")
            
            # Записываем элементы матрицы
            for i in range(rows):
                row_str = ' '.join([f"{matrix[i][j]:.6f}" for j in range(cols)])
                f.write(row_str + ('\n' if i < rows-1 else ''))
    
    # Сохраняем матрицы в файлы
    save_matrix(A, rows_a, cols_a, filename_a)
    save_matrix(B, cols_a, cols_b, filename_b)
    save_matrix(C, rows_a, cols_b, filename_c)
    
    print(f"Матрицы успешно сгенерированы и сохранены в файлы:")
    print(f"  {filename_a} (размер: {rows_a} x {cols_a})")
    print(f"  {filename_b} (размер: {cols_a} x {cols_b})")
    print(f"  {filename_c} (размер: {rows_a} x {cols_b})")
    
    # Выводим первые несколько строк для проверки
    print(f"\nПервые 3 строки матрицы {filename_a}:")
    print(A[:min(3, rows_a)])
    
    return A, B, C

def read_and_verify(filename):
    """
    Читает матрицу из файла и возвращает её для проверки
    """
    with open(filename, 'r') as f:
        rows = int(f.readline().strip())
        cols = int(f.readline().strip())
        
        matrix = []
        for _ in range(rows):
            row = list(map(float, f.readline().strip().split()))
            matrix.append(row)
    
    return np.array(matrix), rows, cols

# Пример использования
if __name__ == "__main__":
    # Параметры матриц
    ROWS_A = 2000
    COLS_A = 2500
    COLS_B = 1500
    
    # Генерируем матрицы
    A, B, C = generate_matrices(ROWS_A, COLS_A, COLS_B, 'bigA.txt', 'bigB.txt', 'bigC.txt')
    
    # Проверяем, что файлы созданы и читаются
    print("\nПроверка чтения файлов:")
    
    A_read, r_a, c_a = read_and_verify('bigA.txt')
    print(f"A.txt: {r_a} x {c_a}")
    
    B_read, r_b, c_b = read_and_verify('bigB.txt')
    print(f"B.txt: {r_b} x {c_b}")
    
    C_read, r_c, c_c = read_and_verify('bigC.txt')
    print(f"C.txt: {r_c} x {c_c}")
    
    # Проверяем правильность умножения
    print(f"\nПроверка умножения:")
    print(f"Максимальная разница между C и A*B: {np.max(np.abs(C - np.dot(A, B))):.2e}")