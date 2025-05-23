
import random
import string
import os

def palabra_aleatoria(longitud: int) -> str:
    return ''.join(random.choice(string.ascii_uppercase) for _ in range(longitud))

def generar_inputs(nombre_archivo_input: str = 'inputs.txt', casos: int = 5, min_len: int = 1, max_len: int = 20) -> None:

    carpeta_input = os.path.join(os.path.dirname(__file__), os.pardir, 'data', 'dynamic_programming_input')
    os.makedirs(carpeta_input, exist_ok=True)
    ruta_archivo = os.path.join(carpeta_input, nombre_archivo_input)

    with open(ruta_archivo, 'w', encoding='utf-8') as f:
        f.write(f"{casos}\n")
        for _ in range(casos):
            len_s = random.randint(min_len, max_len)
            len_t = random.randint(min_len, max_len)
            s = palabra_aleatoria(len_s)
            t = palabra_aleatoria(len_t)
            f.write(f"{len_s} {s}\n")
            f.write(f"{len_t} {t}\n")

if __name__ == '__main__':
    generar_inputs(nombre_archivo_input='inputs.txt', casos=4, min_len=20, max_len=20)