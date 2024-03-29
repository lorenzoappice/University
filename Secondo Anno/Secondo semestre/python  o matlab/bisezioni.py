from numpy import *

def bisezioni(f, a, b, tol, itmax):
    """
    Metodo delle successive bisezioni
    
    Parametri input:
    f: funzione di cui ricercare uno zero alpha
    [a,b]: intervallo di lavoro
    tol: precisione richiesta
    
    Parametri output:
    alpha: approssimazione dello zero di f
    """
    fa = f1(a)
    fb = f1(b)
    if fa*fb > 0:
        print("Errore: f(a) e f(b) hanno lo stesso segno")
    it = 0 
    alpha = 0 
    while b-a > tol and it<itmax:
        it = it+1
        c = (a+b)/2
        fc = f(c)
        if fc == 0:
            alpha = c
            return
        elif fa*fc < 0:
            b = c
            fb = fc
        else:
            a = c
            fa = fc
    if b-a > tol:
        print ('precisione non raggiunta')
    return alpha 

def f1(x):
    y = x - cos(x)
    return y

