
/**
* DLL Export Define
* - This is a define for building this library as a DLL or as a static library
* - The syntax and meaning of this will be covered in class when we are covering
*   building a math library
**/
#ifdef MATH_DLL_BUILD
#define DLLEXPORT __declspec(dllexport)
#elif MATH_DLL
#define DLLEXPORT __declspec(dllimport)
#else
#define DLLEXPORT 
#endif

#include <math.h>
#include "Vector2.h"
#include "Vector3.h"
#include "Matrix3.h"
#include "SimpleMaths.h"


// TODO: reference additional headers your program requires here
