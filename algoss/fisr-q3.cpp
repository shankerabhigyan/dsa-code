// this is an implementation of the fast inverse square root algorithm
// ** Sources **
// https://www.youtube.com/watch?v=p8u_k2LIZyo&ab_channel=Nemean
// https://en.wikipedia.org/wiki/Fast_inverse_square_root
// ***************
// tldr : earlier, in computer graphics, inverse square root operation(on the square of a euclidean norm of a vector)
// .. was widely used to compute angle of incidences and reflections for lighting and shading simulating. 
// .. At the time, floating point division was an expensive operation and there was no specialised hardware for the use case.
// .. An in use method was to make an approximation and refine it to an acceptable value of error using a lookup table.
// .. The fast inverse square root algorithm bypassed the division step and delivered better performance.
// .. It was popularised through the source code of an FPS game named Quake III Arena.
// This algorithm is 4x faster than computing the square root and performing a floating point division to find it's reciprocal. 

#include<bits>
#include<limits>
#include<cstdint>