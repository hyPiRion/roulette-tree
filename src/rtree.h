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

#ifndef RTREE_H
#define RTREE_H

#include <stdbool.h>
#include <stdint.h>

typedef struct RTreeNode {
  bool red;
  void *data;
  double fit, tot;
  uint32_t len[2];
  double link_sum[2];
  struct RTreeNode *link[2];
} RTreeNode;

typedef struct {
  RTreeNode *root;
} RTree;

RTree *rtree_create();
void rtree_destroy(RTree *rt);

void rtree_add(RTree *rt, void *elt_ptr, double fitness);

void *rtree_rget(RTree *rt);
void *rtree_rpop(RTree *rt);

uint32_t rtree_size(RTree *rt);
double rtree_total_fitness(RTree *rt);

#ifdef RTREE_DEBUG

int rb_check(RTreeNode *root);
double total_fit_check(RTree *rt);
double fit_check(RTreeNode *root);

void rtree_preorder(RTree *rt);

void rtree_to_dot(RTree *rt, char *loch);

#endif

#endif

