/*
 * Copyright (c) 2013 Jean Niklas L'orange. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef LINKED_ROULETTE_H
#define LINKED_ROULETTE_H
#include <stdint.h>

typedef struct ll {
  void *car;
  double fitness;
  struct ll *cdr;
} linked_ll;

typedef struct {
  linked_ll *lptr;
  uint32_t length;
  double tot_fitness;
} linked_t;

linked_t *linked_create();
void linked_destroy(linked_t *root);

void linked_add(linked_t *root, void *elt_ptr, double fitness);

void *linked_rget(linked_t *root);
void *linked_rpop(linked_t *root);

uint32_t linked_length(linked_t *root);
double linked_total_fitness(linked_t *root);
#endif
