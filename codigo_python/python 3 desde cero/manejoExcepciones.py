while(True):
    try:
        n = float(input("Introduzca un número: "))
        m = float(input("Divisor: "))
        print("{}/{}={}".format(n,m,n/m))
        if n == None or m == None:
            raise ValueError("Error, no se permiten valores nulos")
    
    except TypeError:
        print("No se puede dividir por una cadena, ingrese un número")
    except ZeroDivisionError:
        print("No se puede dividir por cero")
    
    except ValueError:
        print("Error desde la excepcion!")
    else:
        print("Exito")
        break
    finally:
        print("Iteracion completada") # esto se ejecuta pase lo que pase 