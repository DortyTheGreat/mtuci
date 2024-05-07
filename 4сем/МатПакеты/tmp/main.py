from sympy.plotting import plot
from sympy import symbols, interpolate

# Define symbols
x = symbols('x')
xs, ys, txy = symbols('xs, ys, txy')

# Define data points
ys = [-5, 4, 6, -3, -8]
xs = [-5, -4, -3, 0, 1]

# Plot the data points
pmar1 = plot(0, markers=[{'args': [xs, ys, "o"]}],
             xlabel='xs', ylabel='ys', xlim=(-7,3), ylim=(-9,7))

for power in range(5):

    # Interpolate the data points
    int1 = interpolate([(x1, y1) for x1, y1 in zip(xs[0:power+1], ys[0:power+1])], x)
    pint1 = plot(int1, markers=[{"args": [xs, ys, "o"]}],
                 xlim=(-7,3), ylim=(-9,7))
    display(int1)