'''
Хз, но почему-то ffmpeg не конвертиурет как мне нужно.
Тут точно какая-то беда с форматами...
'''



import numpy as np
from PIL import Image
import sys

def compare_images_pixel_by_pixel(image1_path, image2_path, max_differences_to_show=20):
    """
    Сравнивает два изображения попиксельно и показывает первые различия
    """
    try:
        # Загружаем изображения
        img1 = Image.open(image1_path)
        img2 = Image.open(image2_path)
        
        # Проверяем размеры
        if img1.size != img2.size:
            print(f"❌ Размеры изображений различаются:")
            print(f"{image1_path}: {img1.size}")
            print(f"{image2_path}: {img2.size}")
            return False
        
        width, height = img1.size
        print(f"Размер изображения: {width} x {height} пикселей")
        
        # Конвертируем в градации серого для надежности
        img1 = img1.convert('L')
        img2 = img2.convert('L')
        
        # Преобразуем в numpy массивы
        arr1 = np.array(img1)
        arr2 = np.array(img2)
        
        print(f"\nТип данных {image1_path}: {arr1.dtype}")
        print(f"Тип данных {image2_path}: {arr2.dtype}")
        print(f"Диапазон значений {image1_path}: [{arr1.min()}, {arr1.max()}]")
        print(f"Диапазон значений {image2_path}: [{arr2.min()}, {arr2.max()}]")
        
        # Попиксельное сравнение
        diff = arr1 != arr2
        diff_count = np.sum(diff)
        total_pixels = arr1.size
        
        print("\n" + "="*60)
        if diff_count == 0:
            print("✅ Изображения идентичны!")
            return True
        else:
            print(f"❌ Изображения различаются в {diff_count} пикселях из {total_pixels}")
            print(f"Процент различий: {(diff_count/total_pixels)*100:.4f}%")
            
            # Показываем первые различия
            print("\n" + "="*60)
            print(f"Первые {min(max_differences_to_show, diff_count)} различающихся пикселей:")
            print("Координаты (x,y) | Значение в 1-м | Значение во 2-м | Разница")
            print("-"*60)
            
            shown = 0
            for y in range(height):
                for x in range(width):
                    if diff[y, x]:  # если пиксели различаются
                        val1 = arr1[y, x]
                        val2 = arr2[y, x]
                        print(f"({x:4d}, {y:4d})   |     {val1:3d}      |      {val2:3d}      |   {abs(val1-val2):3d}")
                        shown += 1
                        if shown >= max_differences_to_show:
                            break
                if shown >= max_differences_to_show:
                    break
            
            # Статистика различий
            diff_indices = np.where(diff)
            diff_values1 = arr1[diff_indices]
            diff_values2 = arr2[diff_indices]
            abs_diffs = np.abs(diff_values1 - diff_values2)
            
            print("\n" + "="*60)
            print("Статистика по различиям:")
            print(f"Минимальная разница: {abs_diffs.min()}")
            print(f"Максимальная разница: {abs_diffs.max()}")
            print(f"Средняя разница: {abs_diffs.mean():.2f}")
            print(f"Медианная разница: {np.median(abs_diffs):.2f}")
            
            # Распределение различий
            unique_diffs, counts = np.unique(abs_diffs, return_counts=True)
            print("\nРаспределение величин различий:")
            for diff_val, count in zip(unique_diffs, counts):
                percentage = (count / diff_count) * 100
                print(f"Разница в {diff_val:2d}: {count:6d} пикселей ({percentage:.2f}%)")
            
            return False
            
    except FileNotFoundError as e:
        print(f"❌ Ошибка: Файл не найден - {e}")
        return False
    except Exception as e:
        print(f"❌ Ошибка при обработке изображений: {e}")
        return False

def compare_with_tolerance(image1_path, image2_path, tolerance=1, max_differences_to_show=20):
    """
    Сравнивает изображения с допустимым отклонением и показывает первые различия
    """
    try:
        img1 = Image.open(image1_path).convert('L')
        img2 = Image.open(image2_path).convert('L')
        
        width, height = img1.size
        arr1 = np.array(img1, dtype=np.int16)
        arr2 = np.array(img2, dtype=np.int16)
        
        # Вычисляем абсолютную разницу
        abs_diff = np.abs(arr1 - arr2)
        
        # Проверяем с учетом допуска
        within_tolerance = abs_diff <= tolerance
        pixels_outside_tolerance = np.sum(~within_tolerance)
        total_pixels = arr1.size
        
        print(f"\n{'='*60}")
        print(f"Сравнение с допуском ±{tolerance}:")
        
        if pixels_outside_tolerance == 0:
            print(f"✅ Все пиксели в пределах допуска!")
            return True
        else:
            print(f"❌ {pixels_outside_tolerance} пикселей вне допуска из {total_pixels}")
            print(f"Максимальное отклонение: {abs_diff.max()}")
            
            # Показываем первые пиксели вне допуска
            print(f"\nПервые {min(max_differences_to_show, pixels_outside_tolerance)} пикселей вне допуска:")
            print("Координаты (x,y) | Значение в 1-м | Значение во 2-м | Отклонение")
            print("-"*60)
            
            shown = 0
            outside_tolerance = ~within_tolerance
            for y in range(height):
                for x in range(width):
                    if outside_tolerance[y, x]:
                        val1 = arr1[y, x]
                        val2 = arr2[y, x]
                        diff = abs_diff[y, x]
                        print(f"({x:4d}, {y:4d})   |     {val1:3d}      |      {val2:3d}      |    {diff:3d}")
                        shown += 1
                        if shown >= max_differences_to_show:
                            break
                if shown >= max_differences_to_show:
                    break
            
            return False
            
    except Exception as e:
        print(f"❌ Ошибка: {e}")
        return False

def show_image_headers(image_path):
    """Показывает содержимое заголовка изображения"""
    try:
        with open(image_path, 'rb') as f:
            # Читаем первые 100 байт для анализа
            header = f.read(100)
            
            print(f"\nЗаголовок файла {image_path}:")
            print("-"*40)
            
            # Пробуем декодировать как текст (для P2/P3 форматов)
            try:
                text_part = header.decode('ascii')
                # Показываем первые несколько строк
                lines = text_part.split('\n')[:5]
                for i, line in enumerate(lines):
                    if i < 3:  # Первые 3 строки
                        print(f"Строка {i+1}: {line[:50]}")
            except:
                pass
            
            # Показываем в шестнадцатеричном виде
            print("\nПервые 32 байта в HEX:")
            hex_bytes = ' '.join(f'{b:02x}' for b in header[:32])
            print(hex_bytes)
            
    except Exception as e:
        print(f"Не удалось прочитать заголовок: {e}")

# Основная программа
if __name__ == "__main__":
    image1 = "ffmpeg.ppm"
    image2 = "output_gray.pgm"
    
    print("="*60)
    print("ПОПИКСЕЛЬНОЕ СРАВНЕНИЕ ИЗОБРАЖЕНИЙ")
    print("="*60)
    
    # Показываем информацию о заголовках
    show_image_headers(image1)
    show_image_headers(image2)
    
    # Точное сравнение
    result = compare_images_pixel_by_pixel(image1, image2, max_differences_to_show=30)
    
    # Сравнение с допуском
    print("\n" + "="*60)
    compare_with_tolerance(image1, image2, tolerance=5, max_differences_to_show=30)