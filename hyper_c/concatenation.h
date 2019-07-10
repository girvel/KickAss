//
// Created by nik on 11.07.19.
//

#ifndef KICKASS_CONCATENATION_H
#define KICKASS_CONCATENATION_H

#define CONCAT(X, Y) X##_##Y
#define _(X, Y) CONCAT(X, Y)

#define CONCAT3(X, Y, Z) X##_##Y##_##Z
#define __(X, Y, Z) CONCAT3(X, Y, Z)

#endif //KICKASS_CONCATENATION_H
