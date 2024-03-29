/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: myNeuralNetworkFunction.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 29-Oct-2021 11:26:57
 */

/* Include Files */
#include "myNeuralNetworkFunction.h"
#include "myNeuralNetworkFunction_emxutil.h"
#include "myNeuralNetworkFunction_types.h"
#include <math.h>

/* Function Definitions */
/*
 * MYNEURALNETWORKFUNCTION neural network simulation function.
 *
 *  Auto-generated by MATLAB, 29-Oct-2021 11:23:33.
 *
 *  [y1] = myNeuralNetworkFunction(x1) takes these arguments:
 *    x = Qx2 matrix, input #1
 *  and returns:
 *    y = Qx1 matrix, output #1
 *  where Q is the number of samples.
 * Arguments    : emxArray_real_T *x1
 *                emxArray_real_T *b_y1
 * Return Type  : void
 */
void myNeuralNetworkFunction(emxArray_real_T *x1, emxArray_real_T *b_y1)
{
  static const double dv[20] = { -4.346993421423007, 1.9557938069189233,
    0.62036036048869514, -1.6304632911973373, 4.3419578360517335,
    4.3279714738168167, -2.6252527521344442, 0.60126170876011742,
    -3.4354134298407573, -4.1666416002057414, 1.1046181937397592,
    3.9752364642879106, -4.3168833962023836, 4.11180405202368,
    0.86407708123562954, -0.93478696085198276, -3.5285862457971287,
    -4.3871135453223777, -2.7897768286646687, 0.43705930818721883 };

  static const double b_a[10] = { 4.3874033890831861, -3.4381151805371988,
    -2.655854085395565, 1.3010577772859695, -0.49195232629506142,
    0.49105081658221483, -1.5346151946922835, 2.4566381209390511,
    -3.4451009368110683, -4.6423460170763393 };

  static const double dv1[10] = { -0.26009329866996184, -0.19394026636989503,
    0.76549789513192545, 0.51746313674288291, -0.21128150652107269,
    0.182153655969851, -0.035699501921829691, -0.13058764652867139,
    -0.24036708929628697, -0.41454871323945908 };

  emxArray_real_T *a;
  emxArray_real_T *a1;
  emxArray_real_T *b_x1;
  emxArray_real_T *r;
  emxArray_real_T *r1;
  emxArray_real_T *xp1;
  double s;
  int Q;
  int acoef;
  int csz_idx_1;
  int i;
  int j;
  int k;
  int n;
  emxInit_real_T(&b_x1, 2);

  /*  ===== NEURAL NETWORK CONSTANTS ===== */
  /*  Input 1 */
  /*  Layer 1 */
  /*  Layer 2 */
  /*  ===== SIMULATION ======== */
  /*  Dimensions */
  Q = x1->size[0];

  /*  samples */
  /*  Input 1 */
  i = b_x1->size[0] * b_x1->size[1];
  b_x1->size[0] = x1->size[1];
  b_x1->size[1] = x1->size[0];
  emxEnsureCapacity_real_T(b_x1, i);
  csz_idx_1 = x1->size[0];
  for (i = 0; i < csz_idx_1; i++) {
    acoef = x1->size[1];
    for (n = 0; n < acoef; n++) {
      b_x1->data[n + b_x1->size[0] * i] = x1->data[i + x1->size[0] * n];
    }
  }

  i = x1->size[0] * x1->size[1];
  x1->size[0] = b_x1->size[0];
  x1->size[1] = b_x1->size[1];
  emxEnsureCapacity_real_T(x1, i);
  csz_idx_1 = b_x1->size[0] * b_x1->size[1];
  for (i = 0; i < csz_idx_1; i++) {
    x1->data[i] = b_x1->data[i];
  }

  emxFree_real_T(&b_x1);
  emxInit_real_T(&xp1, 2);

  /*  ===== MODULE FUNCTIONS ======== */
  /*  Map Minimum and Maximum Input Processing Function */
  i = xp1->size[0] * xp1->size[1];
  xp1->size[0] = 2;
  xp1->size[1] = x1->size[1];
  emxEnsureCapacity_real_T(xp1, i);
  if (x1->size[1] != 0) {
    acoef = (x1->size[1] != 1);
    i = x1->size[1] - 1;
    for (k = 0; k <= i; k++) {
      csz_idx_1 = acoef * k;
      xp1->data[2 * k] = x1->data[x1->size[0] * csz_idx_1];
      xp1->data[2 * k + 1] = x1->data[(x1->size[0] != 1) + x1->size[0] *
        csz_idx_1] - 405.0;
    }
  }

  emxInit_real_T(&a, 2);
  i = a->size[0] * a->size[1];
  a->size[0] = 2;
  a->size[1] = xp1->size[1];
  emxEnsureCapacity_real_T(a, i);
  csz_idx_1 = xp1->size[0] * xp1->size[1];
  for (i = 0; i < csz_idx_1; i++) {
    a->data[i] = xp1->data[i];
  }

  csz_idx_1 = xp1->size[1];
  i = xp1->size[0] * xp1->size[1];
  xp1->size[0] = 2;
  xp1->size[1] = csz_idx_1;
  emxEnsureCapacity_real_T(xp1, i);
  if (csz_idx_1 != 0) {
    acoef = (a->size[1] != 1);
    i = csz_idx_1 - 1;
    for (k = 0; k <= i; k++) {
      csz_idx_1 = acoef * k;
      xp1->data[2 * k] = a->data[2 * csz_idx_1] * 0.00275103163686382;
      xp1->data[2 * k + 1] = a->data[2 * csz_idx_1 + 1] * 2.86475492021658E-5;
    }
  }

  i = a->size[0] * a->size[1];
  a->size[0] = 2;
  a->size[1] = xp1->size[1];
  emxEnsureCapacity_real_T(a, i);
  csz_idx_1 = xp1->size[0] * xp1->size[1];
  for (i = 0; i < csz_idx_1; i++) {
    a->data[i] = xp1->data[i];
  }

  csz_idx_1 = xp1->size[1];
  i = xp1->size[0] * xp1->size[1];
  xp1->size[0] = 2;
  xp1->size[1] = csz_idx_1;
  emxEnsureCapacity_real_T(xp1, i);
  if (csz_idx_1 != 0) {
    acoef = (a->size[1] != 1);
    i = csz_idx_1 - 1;
    for (k = 0; k <= i; k++) {
      csz_idx_1 = acoef * k;
      xp1->data[2 * k] = a->data[2 * csz_idx_1] + -1.0;
      xp1->data[2 * k + 1] = a->data[2 * csz_idx_1 + 1] + -1.0;
    }
  }

  emxFree_real_T(&a);
  emxInit_real_T(&a1, 2);

  /*  Layer 1 */
  i = a1->size[0] * a1->size[1];
  a1->size[0] = 10;
  a1->size[1] = Q;
  emxEnsureCapacity_real_T(a1, i);
  for (acoef = 0; acoef < Q; acoef++) {
    csz_idx_1 = acoef * 10;
    for (k = 0; k < 10; k++) {
      a1->data[csz_idx_1 + k] = b_a[k];
    }
  }

  emxInit_real_T(&r, 2);
  n = xp1->size[1];
  i = r->size[0] * r->size[1];
  r->size[0] = 10;
  r->size[1] = xp1->size[1];
  emxEnsureCapacity_real_T(r, i);
  for (j = 0; j < n; j++) {
    csz_idx_1 = j * 10;
    acoef = j << 1;
    for (i = 0; i < 10; i++) {
      r->data[csz_idx_1 + i] = dv[i] * xp1->data[acoef] + dv[i + 10] * xp1->
        data[acoef + 1];
    }
  }

  emxFree_real_T(&xp1);

  /*  Sigmoid Symmetric Transfer Function */
  csz_idx_1 = a1->size[0] * a1->size[1];
  i = a1->size[0] * a1->size[1];
  a1->size[0] = 10;
  emxEnsureCapacity_real_T(a1, i);
  for (i = 0; i < csz_idx_1; i++) {
    a1->data[i] = -2.0 * (a1->data[i] + r->data[i]);
  }

  emxFree_real_T(&r);
  csz_idx_1 = 10 * a1->size[1];
  for (k = 0; k < csz_idx_1; k++) {
    a1->data[k] = exp(a1->data[k]);
  }

  csz_idx_1 = a1->size[0] * a1->size[1];
  i = a1->size[0] * a1->size[1];
  a1->size[0] = 10;
  emxEnsureCapacity_real_T(a1, i);
  for (i = 0; i < csz_idx_1; i++) {
    a1->data[i] = 2.0 / (a1->data[i] + 1.0) - 1.0;
  }

  emxInit_real_T(&r1, 2);

  /*  Layer 2 */
  n = a1->size[1];
  i = r1->size[0] * r1->size[1];
  r1->size[0] = 1;
  r1->size[1] = a1->size[1];
  emxEnsureCapacity_real_T(r1, i);
  for (j = 0; j < n; j++) {
    acoef = j * 10;
    s = 0.0;
    for (k = 0; k < 10; k++) {
      s += dv1[k] * a1->data[acoef + k];
    }

    r1->data[j] = s;
  }

  emxFree_real_T(&a1);

  /*  Output 1 */
  i = b_y1->size[0];
  b_y1->size[0] = Q;
  emxEnsureCapacity_real_T(b_y1, i);
  for (i = 0; i < Q; i++) {
    b_y1->data[i] = r1->data[i] + 0.90250288381219;
  }

  emxFree_real_T(&r1);
}

/*
 * File trailer for myNeuralNetworkFunction.c
 *
 * [EOF]
 */
