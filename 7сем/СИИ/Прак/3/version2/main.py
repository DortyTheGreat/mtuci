import numpy as np
import matplotlib.pyplot as plt
import os

OUT_DIR = "./"

def task1_sum_matvecs(input_file, matrices_key='matrices', vectors_key='vectors', out_file=None):
    data = np.load(input_file)
    A = data[matrices_key]
    V = data[vectors_key]
    if V.ndim == 3:
        V = V.reshape(V.shape[0], V.shape[1])
    p = A.shape[0]
    res = np.zeros(A.shape[1], dtype=np.result_type(A, V))
    for i in range(p):
        res += A[i].dot(V[i])
    if out_file:
        np.save(out_file, res)
    return res

def task2_vector_to_binary_matrix(input_file, vec_key='vector', out_file=None, bit_order='msb'):
    data = np.load(input_file)
    v = np.asarray(data[vec_key]).astype(np.int64).flatten()
    if v.size == 0:
        mat = np.zeros((0,0), dtype=np.uint8)
    else:
        max_val = np.max(np.abs(v))
        if np.any(v < 0):
            num_bits = int(np.floor(np.log2(max_val)) + 2) if max_val>0 else 2
        else:
            num_bits = int(np.floor(np.log2(max_val)) + 1) if max_val>0 else 1
        num_bits = max(1, num_bits)
        if np.any(v < 0):
            unsigned = (v + (1 << num_bits)) & ((1 << num_bits) - 1)
        else:
            unsigned = v.copy()
        arr = unsigned.astype(np.uint64)
        shift_positions = np.arange(num_bits-1, -1, -1, dtype=np.uint64)
        bits = ((arr[:, None] >> shift_positions) & np.uint64(1)).astype(np.uint8)
        if bit_order == 'lsb':
            bits = bits[:, ::-1]
        mat = bits
    if out_file:
        np.save(out_file, mat)
    return mat

def task3_unique_rows(input_file, mat_key='matrix', out_file=None):
    data = np.load(input_file)
    M = data[mat_key]
    uniq = np.unique(M, axis=0)
    if out_file:
        np.save(out_file, uniq)
    return uniq

def task4_random_normal_stats(M, N, seed=0, out_prefix=None):
    rng = np.random.default_rng(seed)
    mat = rng.standard_normal((M,N))
    means = mat.mean(axis=0)
    variances = mat.var(axis=0)
    if out_prefix is None:
        out_prefix = os.path.join(OUT_DIR, "task4")
    for i in range(M):
        plt.figure()
        plt.hist(mat[i], bins='auto')
        fname = f"{out_prefix}_row{i}.png"
        plt.title(f"Row {i} histogram")
        plt.xlabel("Value")
        plt.ylabel("Frequency")
        plt.savefig(fname)
        plt.close()
    np.save(os.path.join(OUT_DIR, "task4_matrix.npy"), mat)
    np.save(os.path.join(OUT_DIR, "task4_means.npy"), means)
    np.save(os.path.join(OUT_DIR, "task4_vars.npy"), variances)
    return mat, means, variances, [f"{out_prefix}_row{i}.png" for i in range(M)]

def task5_chessboard(M, N, a, b, out_file=None):
    mat = np.fromfunction(lambda i,j: np.where(((i+j)%2)==0, a, b), (M,N))
    if out_file:
        np.save(out_file, mat)
    return mat

def task6_circle_image(height, width, radius, color=(255,255,255), out_file=None):
    img = np.zeros((height, width, 3), dtype=np.uint8)
    cy = (height - 1) / 2.0
    cx = (width - 1) / 2.0
    yy, xx = np.ogrid[:height, :width]
    dist2 = (yy - cy)**2 + (xx - cx)**2
    mask = dist2 <= radius*radius
    col = np.array(color)
    if col.max() <= 1.0:
        col = (col * 255).astype(np.uint8)
    else:
        col = col.astype(np.uint8)
    img[mask] = col
    if out_file:
        np.save(out_file, img)
        try:
            plt.imsave(out_file.replace('.npy', '.png'), img)
        except Exception:
            pass
    return img

def task7_standardize_tensor(input_file, tensor_key='tensor', out_file=None):
    data = np.load(input_file)
    T = data[tensor_key].astype(np.float64)
    mu = T.mean()
    sigma = T.std()
    if sigma == 0:
        res = T - mu
    else:
        res = (T - mu) / sigma
    if out_file:
        np.save(out_file, res)
    return res

def task8_extract_patch(input_file, mat_key='matrix', center=(0,0), patch_size=(3,3), fill=0, out_file=None):
    data = np.load(input_file)
    M = data[mat_key]
    ph, pw = patch_size
    ch, cw = center
    half_h = ph // 2
    half_w = pw // 2
    top = ch - half_h
    bottom = ch + (ph - half_h)
    left = cw - half_w
    right = cw + (pw - half_w)
    patch = np.full((ph,pw), fill, dtype=M.dtype)
    src_top = max(0, top)
    src_left = max(0, left)
    src_bottom = min(M.shape[0], bottom)
    src_right = min(M.shape[1], right)
    dst_top = src_top - top
    dst_left = src_left - left
    dst_bottom = dst_top + (src_bottom - src_top)
    dst_right = dst_left + (src_right - src_left)
    patch[dst_top:dst_bottom, dst_left:dst_right] = M[src_top:src_bottom, src_left:src_right]
    if out_file:
        np.save(out_file, patch)
    return patch

def task9_most_frequent_per_row(input_file, mat_key='matrix', out_file=None):
    data = np.load(input_file)
    M = data[mat_key]
    result = []
    for row in M:
        if row.size == 0:
            result.append(np.nan)
            continue
        vals, counts = np.unique(row, return_counts=True)
        max_count = counts.max()
        candidates = vals[counts == max_count]
        result.append(candidates.min())
    res = np.array(result)
    if out_file:
        np.save(out_file, res)
    return res

def task10_weighted_channels(input_file, image_key='image', weights_key='weights', out_file=None):
    data = np.load(input_file)
    img = data[image_key]
    w = np.asarray(data[weights_key]).astype(np.float64).flatten()
    if img.ndim != 3:
        raise ValueError("image must be (H,W,C)")
    if img.shape[2] != w.size:
        raise ValueError("weights length must equal numChannels")
    res = np.tensordot(img, w, axes=([2],[0]))
    if out_file:
        np.save(out_file, res)
    return res

# Demo inputs
demo_dir = os.path.join(OUT_DIR, "demo_inputs")
os.makedirs(demo_dir, exist_ok=True)

print("=" * 60)
print("ДЕМОНСТРАЦИЯ РЕЗУЛЬТАТОВ ЗАДАЧ")
print("=" * 60)

# Task 1
print("\n" + "="*50)
print("ЗАДАЧА 1: Сумма матрично-векторных произведений")
print("="*50)
p, n = 4, 5
mats = np.stack([np.arange(n*n).reshape(n,n) + i*100 for i in range(p)])
vecs = np.stack([np.arange(n) + i for i in range(p)])
np.savez(os.path.join(demo_dir, "task1_inputs.npz"), matrices=mats, vectors=vecs)
res1 = task1_sum_matvecs(os.path.join(demo_dir, "task1_inputs.npz"), out_file=os.path.join(OUT_DIR, "task1_result.npy"))

print("Матрицы (первые 2 из 4):")
for i in range(min(2, p)):
    print(f"Матрица {i}:\n{mats[i]}")
print("\nВекторы (первые 2 из 4):")
for i in range(min(2, p)):
    print(f"Вектор {i}: {vecs[i]}")
print(f"\nРезультат (сумма произведений): {res1}")
print(f"Размер результата: {res1.shape}")

# Task 2
print("\n" + "="*50)
print("ЗАДАЧА 2: Вектор в бинарную матрицу")
print("="*50)
vec = np.array([0,1,2,3,10,255,-1,-5])
np.savez(os.path.join(demo_dir, "task2_inputs.npz"), vector=vec)
res2 = task2_vector_to_binary_matrix(os.path.join(demo_dir, "task2_inputs.npz"), out_file=os.path.join(OUT_DIR, "task2_result.npy"))

print(f"Исходный вектор: {vec}")
print(f"Бинарная матрица (форма {res2.shape}):")
print(res2)

# Task 3
print("\n" + "="*50)
print("ЗАДАЧА 3: Уникальные строки матрицы")
print("="*50)
M = np.array([[1,2,3],[1,2,3],[4,5,6],[1,2,3]])
np.savez(os.path.join(demo_dir, "task3_inputs.npz"), matrix=M)
res3 = task3_unique_rows(os.path.join(demo_dir, "task3_inputs.npz"), out_file=os.path.join(OUT_DIR, "task3_result.npy"))

print("Исходная матрица:")
print(M)
print("Уникальные строки:")
print(res3)
print(f"Размер результата: {res3.shape}")

# Task 4
print("\n" + "="*50)
print("ЗАДАЧА 4: Статистика нормального распределения")
print("="*50)
mat4, means4, vars4, hist_files = task4_random_normal_stats(5, 10, seed=42, out_prefix=os.path.join(OUT_DIR, "task4_hist"))

print("Матрица (первые 2 строки):")
print(mat4[:2])
print(f"Средние по столбцам: {means4}")
print(f"Дисперсии по столбцам: {vars4}")
print(f"Размер матрицы: {mat4.shape}")
print(f"Размер средних: {means4.shape}")
print(f"Размер дисперсий: {vars4.shape}")

# Task 5
print("\n" + "="*50)
print("ЗАДАЧА 5: Шахматная доска")
print("="*50)
res5 = task5_chessboard(6,7, a=1, b=0, out_file=os.path.join(OUT_DIR, "task5_result.npy"))

print("Шахматная доска 6x7:")
print(res5)
print(f"Размер: {res5.shape}")

# Task 6
print("\n" + "="*50)
print("ЗАДАЧА 6: Изображение с кругом")
print("="*50)
img6 = task6_circle_image(200, 300, radius=60, color=(0.2, 0.7, 0.9), out_file=os.path.join(OUT_DIR, "task6_image.npy"))

print(f"Изображение создано с размерами: {img6.shape}")
print(f"Диапазон значений: [{img6.min()}, {img6.max()}]")
print("Первые 5x5 пикселей (канал R):")
print(img6[:5, :5, 0])

# Task 7
print("\n" + "="*50)
print("ЗАДАЧА 7: Стандартизация тензора")
print("="*50)
tensor7 = np.arange(24).reshape(2,3,4).astype(np.float32)
np.savez(os.path.join(demo_dir, "task7_inputs.npz"), tensor=tensor7)
res7 = task7_standardize_tensor(os.path.join(demo_dir, "task7_inputs.npz"), out_file=os.path.join(OUT_DIR, "task7_result.npy"))

print("Исходный тензор:")
print(tensor7)
print("Стандартизованный тензор:")
print(res7)
print(f"Размер: {res7.shape}")
print(f"Среднее стандартизованного: {res7.mean():.6f}")
print(f"Стд. отклонение стандартизованного: {res7.std():.6f}")

# Task 8
print("\n" + "="*50)
print("ЗАДАЧА 8: Извлечение патча")
print("="*50)
mat8 = np.arange(25).reshape(5,5)
np.savez(os.path.join(demo_dir, "task8_inputs.npz"), matrix=mat8)
res8 = task8_extract_patch(os.path.join(demo_dir, "task8_inputs.npz"), center=(0,0), patch_size=(3,3), fill=-1, out_file=os.path.join(OUT_DIR, "task8_patch.npy"))

print("Исходная матрица 5x5:")
print(mat8)
print(f"Патч 3x3 из центра (0,0) с заполнением -1:")
print(res8)
print(f"Размер патча: {res8.shape}")

# Task 9
print("\n" + "="*50)
print("ЗАДАЧА 9: Наиболее частый элемент в строке")
print("="*50)
mat9a = np.array([[1,2,2,3],[5,5,5,2],[1,1,2,1],[7,7,7,0]])
np.savez(os.path.join(demo_dir, "task9_inputs.npz"), matrix=mat9a)
res9 = task9_most_frequent_per_row(os.path.join(demo_dir, "task9_inputs.npz"), out_file=os.path.join(OUT_DIR, "task9_result.npy"))

print("Исходная матрица:")
print(mat9a)
print(f"Наиболее частые элементы (минимальные при ничьей): {res9}")
print(f"Размер результата: {res9.shape}")

# Task 10
print("\n" + "="*50)
print("ЗАДАЧА 10: Взвешенная сумма каналов")
print("="*50)
H,W,C = 20, 30, 3
img10 = np.random.randint(0,256,(H,W,C)).astype(np.uint8)
weights = np.array([0.299, 0.587, 0.114])
np.savez(os.path.join(demo_dir, "task10_inputs.npz"), image=img10, weights=weights)
res10 = task10_weighted_channels(os.path.join(demo_dir, "task10_inputs.npz"), out_file=os.path.join(OUT_DIR, "task10_result.npy"))

print(f"Изображение размером: {img10.shape}")
print(f"Веса каналов: {weights}")
print(f"Результат (первые 5x5 пикселей):")
print(res10[:5, :5])
print(f"Размер результата: {res10.shape}")

print("\n" + "="*60)
print("СВОДНАЯ ИНФОРМАЦИЯ")
print("="*60)
print("Демо входные данные сохранены в:", demo_dir)
print("Выходные данные сохранены в:", OUT_DIR)
print("\nСозданные файлы:")
for fname in sorted(os.listdir(OUT_DIR)):
    if fname.endswith(('.npy', '.png', '.npz')):
        print("-", fname)

print("\n" + "="*60)
print("ПРОВЕРКА РАЗМЕРНОСТЕЙ РЕЗУЛЬТАТОВ")
print("="*60)
print(f"Task1 результат: размер {res1.shape}")
print(f"Task2 результат: размер {res2.shape}")
print(f"Task3 результат: размер {res3.shape}")
print(f"Task4 средние: размер {means4.shape}, дисперсии: размер {vars4.shape}")
print(f"Task5 результат: размер {res5.shape}")
print(f"Task6 результат: размер {img6.shape}")
print(f"Task7 результат: размер {res7.shape}")
print(f"Task8 результат: размер {res8.shape}")
print(f"Task9 результат: размер {res9.shape}")
print(f"Task10 результат: размер {res10.shape}")