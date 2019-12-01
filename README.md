# fractol
A basic fractol rendering project. Contains mandlebrot, julia, and burningship fractols with variable zoom, RGB base values, and permutations of depth. To run this project, run make in the parent directory, then run using ./fractol [fractol type].

Controls:

	-Right and left mouse click (or scroll wheel) to zoom on mouse
	-'Q' 'W' 'E' to increase 'R' 'G' and 'B' color values respectively
	-'A' 'S' 'D' to decrease 'R' 'G' and 'B' color values respectively
	-'+' and '-' to increase and decrease depth iterations by 5
	-'[' and ']' to increase and decrease depth iterations by 1
	-tab to toggle between fractols

To Do:

	-add multithreading
	-add more fractols
	-add color gradients between fractol depth
