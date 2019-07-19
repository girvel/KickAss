//
// Created by nik on 18.07.19.
//

#ifndef KICKASS_MATH_H
#define KICKASS_MATH_H

#define MIN(A, B) ((A) > (B) ? (B) : (A))
#define MAX(A, B) ((A) < (B) ? (B) : (A))

#define MEDIAN(A, B, C) (\
    (A) > (B) \
     ? ( (B) > (C) ? (B) : MIN(A, C) ) \
     : ( (B) < (C) ? (B) : MAX(A, C) ))

#define MAKE_MIN(A, B) A = MIN(A, B);

#define MAKE_MEDIAN(A, B, C) A = MEDIAN(A, B, C);

#endif //KICKASS_MATH_H
