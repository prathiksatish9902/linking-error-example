#include <stdio.h>

// Function prototypes (but no definitions in the file)
int add(int a, int b);       // Error 1: add() function declared but not defined
float multiply(float x, float y); // Error 2: multiply() function declared but not defined

extern int globalVariable;   // Error 3: globalVariable is declared extern but not defined anywhere
extern void undefinedFunction(); // Error 4: undefinedFunction() declared but not defined

void callExternalFunction();  // Error 5: callExternalFunction() declared but not defined

int main() {
    // Error 6: Trying to use the undeclared and undefined function subtract()
    int result = subtract(10, 5);

    // Error 7: Referencing undefined variable externalVar
    int value = externalVar;

    // Error 8: Calling a function from an external library (like `math`) without linking it
    double power = pow(2, 3);

    // Error 9: Undefined reference to a global structure
    struct Person person;
    person.age = 25;

    // Error 10: Undefined external array reference
    extern int arr[10];
    printf("Array element: %d\n", arr[0]);

    return 0;
}

{
//
link_error.c: In function ‘main’:
link_error.c:14:18: warning: implicit declaration of function ‘subtract’ [-Wimplicit-function-declaration]
   14 |     int result = subtract(10, 5);
      |                  ^~~~~~~~
link_error.c:17:17: error: ‘externalVar’ undeclared (first use in this function)
   17 |     int value = externalVar;
      |                 ^~~~~~~~~~~
link_error.c:17:17: note: each undeclared identifier is reported only once for each function it appears in
link_error.c:20:20: warning: implicit declaration of function ‘pow’ [-Wimplicit-function-declaration]
   20 |     double power = pow(2, 3);
      |                    ^~~
link_error.c:2:1: note: include ‘<math.h>’ or provide a declaration of ‘pow’
    1 | #include <stdio.h>
  +++ |+#include <math.h>
    2 | 
link_error.c:20:20: warning: incompatible implicit declaration of built-in function ‘pow’ [-Wbuiltin-declaration-mismatch]
   20 |     double power = pow(2, 3);
      |                    ^~~
link_error.c:20:20: note: include ‘<math.h>’ or provide a declaration of ‘pow’
link_error.c:23:19: error: storage size of ‘person’ isn’t known
   23 |     struct Person person;
      |                   ^~~~~~
//
}
