
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

def regresion_lineal(xs, ys):
    n = len(xs)
    mean_x = sum(xs)/n
    mean_y = sum(ys)/n
    cov = sum((x-mean_x)*(y-mean_y) for x,y in zip(xs,ys)) / n
    var = sum((x-mean_x)**2 for x in xs) / n
    m = cov / var
    b = mean_y - m*mean_x
    return m, b

def main():
    script_dir = os.path.dirname(os.path.abspath(__file__))
    ruta_med = os.path.normpath(os.path.join(script_dir, os.pardir, 'data', 'measurements', 'measurements.txt'))

    xs, ys = leer_mediciones(ruta_med)

    m, b = regresion_lineal(xs, ys)

    x_min, x_max = min(xs), max(xs)
    x_fit = [x_min + i*(x_max-x_min)/99 for i in range(100)]
    y_fit = [m*x + b for x in x_fit]

    carpeta_plots = os.path.join(script_dir, os.pardir, 'data', 'plots')
    os.makedirs(carpeta_plots, exist_ok=True)

    plt.figure(figsize=(8,6))
    plt.scatter(xs, ys, marker='x', label='Mediciones')
    plt.plot(x_fit, y_fit)
    plt.xlabel("Tamaño de entrada (n)")
    plt.ylabel("Tiempo de ejecución (s)")
    plt.title("Programación Dinámica: tiempo vs tamaño de entrada")
    plt.grid(True)
    plt.legend()

    salida = os.path.join(carpeta_plots, "dynamic_programming_plot.png")
    plt.savefig(salida)

if __name__ == "__main__":
    main()