def newtons_method(x0, nmax, e, t):
    for _ in range(nmax):
        fx = f(x0)
        fp = f_prime(x0)

        if abs(fp) < e:
            break

        x1 = x0 - fx / fp

        if abs(x1 - x0) <= t:
            return x1

        x0 = x1                         

    return None