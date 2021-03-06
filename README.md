
Basically what i have produced to my Cientific Iniciation (from portuguese, Iniciação Científica (_IC_)).

# Studying the generalized rock-paper-scissor model in context of dynamic populations.
## Estudando o modelo generalizado pedra-papel-tesoura no contexto da dinâmica de populações.

_**The most important to say is, this project is in many ways an exploration of my skills as programmer and a bunch of things wont work as like i would intentend to work. So the code i share here is to help criativelly and inspire another people give a try to make their codes as they like to make.**_

I have used the RPS, Lotka-Volterra and May-Leonards models to simulate the competition between 3, 4 and 5 species.

Those i have used Runge-Kutta method is totally based on the solution of Lotka-Volterra equations.

Those i have used Sthocastic method is totally based on random number generation and on the species dynamic, besides spiral ones models have used one boundary conditions thats 
differes from the boundary conditions to the domains ones models; these name are based in the expected result for each one, where spirals models generate spirals and domains 
generates clusters of each specie.

What differs from each boundary condition is, in the Spiral ones each species cannot predate they predator, but in Domain they can.

# About

For a futher undestanding you can read this [article](https://journals.aps.org/pre/abstract/10.1103/PhysRevE.86.036112) where from the main idea comes, or one of 
the followings:

- [The rock–paper–scissors game and the evolution of alternative male strategies](https://www.nature.com/articles/380240a0)
- [Local dispersal promotes biodiversity in a real-life game of rock–paper–scissors](https://www.nature.com/articles/nature00823)
- [Mobility promotes and jeopardizes biodiversity in rock–paper–scissors games](https://www.nature.com/articles/nature06095)
- [Three- and four-state rock-paper-scissors games with diffusion](https://journals.aps.org/pre/abstract/10.1103/PhysRevE.78.031906)
- [Death by starvation in May-Leonard models](https://iopscience.iop.org/article/10.1209/0295-5075/126/68002)

# Execution

To execute you will need gcc (you can see how install [here](https://gcc.gnu.org/install/)), libgsl-dev (which contains the random number generator utilized, you can see how 
install [here](https://www.gnu.org/software/gsl/#downloading)) and gnuplot (you can see how install [here](http://www.gnuplot.info/download.html)). You can change some params in 
header file ([head.h](https://github.com/Gabriel-Marino/marino-ic21-rps/blob/main/head.h)), in header file have too how to compile and execute each simulation separatelly. If 
you wanted to, you can the shell scripts i have made to run every simulation with similar results (i.e. runDomain.sh whil run the three simulation which generate domains 
results) and within compilation and run, the shell script will automatically generates images inside plt folder with gnuplot and the remove every outfile from the simulations. 
If you chose to run each simulation separatelly, i have made gnuplot scripts (which is inside of plt folder) which you can use to generate images as output.

**WIP**

# Contact

If you wanted to, you can contact me by mine email: gcmarino404@gmail.com or [mine twitter](https://twitter.com/gmarinohimself) and you can contact mine advisor/supervisor Professor Breno Ferraz de Oliveira, PhD by his email breno@dfi.uem.br.

# Acknowledgements

I'm really thankful to Professor Breno to acept guide me and to everything he made to me. I'm Thankful to Conselho Nacional de Desenvolvimento Científico e Tecnologico - Fundação Auraucária (CNPq - FA) to support this cientific iniciation. And by last, but not less meaningfull, to my parents which support me everytime and every inciative of mine.

# License

[MIT](https://github.com/Gabriel-Marino/marino-ic21-rps/blob/28ef34b012f86e58ae73f0dba14dfba4eb5aa464/LICENSE)
