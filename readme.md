# Part I: Class design

Overload all appropriate operators for the classes from P2:   jumpPrime and duelingJP  
The class (type) definitions are the same EXCEPT now may encapsulate a 3-digit number
as well as those of 4 or more digits.

A primary design goal is to streamline manipulation of jumpPrime and duelingJP objects.

**Comparison** should be widely supported for all types.

**Addition MUST** be supported consistently for both types: you decide the meaning and
extent.

Consider, for example, if it is reasonable to: add  a duelingJP  to a duelingJP?  a
jumpPrime  to a duelingJP? a jumpPrime to a jumpPrime?   etc.

Determine the ripple effect(s) of supporting addition, including mixed-mode, short-cut
assignment and pre & post increment. Make reasonable design decisions so that your
classes satisfy the stated goals, communicate assumptions and use, and yield clear and
maintainable software

Clearly, many, many details are missing.  You must use operator overloading.

**Use ProgrammingByContract to specify:**  
pre and post conditions; interface, implementation and class invariants.   
Intent of operator overloading should be well-documented

# Part II: Driver
Design a functionally decomposed driver to demonstrate program requirements.   
Clearly specify the intent and structure of your driver
You should have arrays of distinct objects, initialized appropriately, i.e.
random distribution of objects with arbitrary, initial, reasonable values  
meaningful values for non-arbitrary initial values, etc.  
do NOT use vectors, lists, etc.    