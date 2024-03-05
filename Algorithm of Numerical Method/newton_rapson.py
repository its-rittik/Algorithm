def newton_raphson(f, df, x0, tol=0.00001, max_iter=100):
    x = x0
    for i in range(max_iter):
        x_new = x - f(x) / df(x)
        if abs(x_new - x) < tol:
            print(f"Root found after {i+1} iterations.")
            return x_new
        x = x_new
    print(f"Warning: Maximum iterations reached. Last approximation is {x}.")
    return x

if __name__ == "__main__":
    
    f = lambda x: x**2 - 4 +1
    df = lambda x: 2*x     
    x0 = 1.0

    root = newton_raphson(f, df, x0)
    print(f"The root is approximately {round(root,4)}.")
