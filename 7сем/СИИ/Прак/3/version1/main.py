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

p, n = 4, 5
mats = np.stack([np.arange(n*n).reshape(n,n) + i*100 for i in range(p)])
vecs = np.stack([np.arange(n) + i for i in range(p)])
np.savez(os.path.join(demo_dir, "task1_inputs.npz"), matrices=mats, vectors=vecs)
res1 = task1_sum_matvecs(os.path.join(demo_dir, "task1_inputs.npz"), out_file=os.path.join(OUT_DIR, "task1_result.npy"))

vec = np.array([0,1,2,3,10,255,-1,-5])
np.savez(os.path.join(demo_dir, "task2_inputs.npz"), vector=vec)
res2 = task2_vector_to_binary_matrix(os.path.join(demo_dir, "task2_inputs.npz"), out_file=os.path.join(OUT_DIR, "task2_result.npy"))

M = np.array([[1,2,3],[1,2,3],[4,5,6],[1,2,3]])
np.savez(os.path.join(demo_dir, "task3_inputs.npz"), matrix=M)
res3 = task3_unique_rows(os.path.join(demo_dir, "task3_inputs.npz"), out_file=os.path.join(OUT_DIR, "task3_result.npy"))

mat4, means4, vars4, hist_files = task4_random_normal_stats(5, 10, seed=42, out_prefix=os.path.join(OUT_DIR, "task4_hist"))

res5 = task5_chessboard(6,7, a=1, b=0, out_file=os.path.join(OUT_DIR, "task5_result.npy"))

img6 = task6_circle_image(200, 300, radius=60, color=(0.2, 0.7, 0.9), out_file=os.path.join(OUT_DIR, "task6_image.npy"))

tensor7 = np.arange(24).reshape(2,3,4).astype(np.float32)
np.savez(os.path.join(demo_dir, "task7_inputs.npz"), tensor=tensor7)
res7 = task7_standardize_tensor(os.path.join(demo_dir, "task7_inputs.npz"), out_file=os.path.join(OUT_DIR, "task7_result.npy"))

mat8 = np.arange(25).reshape(5,5)
np.savez(os.path.join(demo_dir, "task8_inputs.npz"), matrix=mat8)
res8 = task8_extract_patch(os.path.join(demo_dir, "task8_inputs.npz"), center=(0,0), patch_size=(3,3), fill=-1, out_file=os.path.join(OUT_DIR, "task8_patch.npy"))

mat9a = np.array([[1,2,2,3],[5,5,5,2],[1,1,2,1],[7,7,7,0]])
np.savez(os.path.join(demo_dir, "task9_inputs.npz"), matrix=mat9a)
res9 = task9_most_frequent_per_row(os.path.join(demo_dir, "task9_inputs.npz"), out_file=os.path.join(OUT_DIR, "task9_result.npy"))

H,W,C = 20, 30, 3
img10 = np.random.randint(0,256,(H,W,C)).astype(np.uint8)
weights = np.array([0.299, 0.587, 0.114])
np.savez(os.path.join(demo_dir, "task10_inputs.npz"), image=img10, weights=weights)
res10 = task10_weighted_channels(os.path.join(demo_dir, "task10_inputs.npz"), out_file=os.path.join(OUT_DIR, "task10_result.npy"))

print("Demo inputs saved to:", demo_dir)
print("Outputs saved to:", OUT_DIR)
print("Files created (sample):")
for fname in sorted(os.listdir(OUT_DIR)):
    print("-", fname)

print("Task1 result shape:", res1.shape)
print("Task2 result shape:", res2.shape)
print("Task3 unique rows shape:", res3.shape)
print("Task4 means shape:", means4.shape, "vars shape:", vars4.shape)
print("Task5 chessboard shape:", res5.shape)
print("Task6 image shape:", img6.shape)
print("Task7 result shape:", res7.shape)
print("Task8 patch shape:", res8.shape)
print("Task9 result:", res9)
print("Task10 result shape:", res10.shape)
