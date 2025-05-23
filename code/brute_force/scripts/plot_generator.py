
import os
import matplotlib.pyplot as plt

def leer_mediciones(ruta_archivo):
    tamanos = []
    tiempos = []
    with open(ruta_archivo, 'r', encoding='utf-8') as f:
        for linea in f:
            linea = linea.strip()
            if not linea or linea.startswith('#'):
                continue
            partes = linea.split(',')
            if len(partes) != 2:
                continue
            try:
                n = int(partes[0].strip())
                t = float(partes[1].strip())
            except ValueError:
                continue
            tamanos.append(n)
            tiempos.append(t)
    return tamanos, tiempos

def main():
    script_dir = os.path.dirname(os.path.abspath(__file__))
    ruta = os.path.normpath(os.path.join(script_dir, os.pardir, 'data', 'measurements', 'measurements.txt'))

    x, y = leer_mediciones(ruta)

    carpeta_plots = os.path.join(script_dir, os.pardir, 'data', 'plots')
    os.makedirs(carpeta_plots, exist_ok=True)

    plt.figure()
    plt.plot(x, y, label="Fuerza bruta", linewidth=2, marker='o')
    plt.xlabel("Tamaño de entrada (n)")
    plt.ylabel("Tiempo de ejecución (s)")
    plt.title("Fuerza bruta: tiempo vs tamaño de entrada")
    plt.grid(True)
    plt.legend()

    salida = os.path.join(carpeta_plots, "brute_force_plot.png")
    plt.savefig(salida)

if __name__ == "__main__":
    main()

