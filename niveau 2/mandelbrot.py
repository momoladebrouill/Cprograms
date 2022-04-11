def mandelbrot(N_iteration,sizex,sizey):
  for x in range(sizex):
    for y in range(sizey):
# Compute the mandelbrot sequence for the point c = (c_r, c_i) with start value z = (z_r, z_i)
      z = complex(0,0)
# Rescale to fit the drawing screen 320x222
      c = complex(3.5*x/(sizex-1)-2.5,
       -2.5*y/(sizey-1)+1.25)
      i = 0
      while (i < N_iteration) and abs(z) < 2:
        i = i + 1
        z = z*z+c
# Choose the color of the dot from the Mandelbrot sequence
      val = i/N_iteration
      if val>.5:
          print("*",end="")
      else:
          print(" ",end='')
    print()

mandelbrot(10,50,75)
