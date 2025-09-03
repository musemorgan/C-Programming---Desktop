#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef struct complex {
  double re;
  double im;
} complex;

complex c_add(complex z1, complex z2) {
  complex res;
  res.re = z1.re + z2.re;
  res.im = z1.im + z2.im;
  return res;
}

complex c_mul(complex z1, complex z2) {
  complex res;
  res.re = z1.re * z2.re - z1.im * z2.im;
  res.im = z1.re * z2.im + z1.im * z2.re;
  return res;
}

complex c_inv(complex z) {
  complex res;
  double n2 = z.re * z.re + z.im * z.im;
  if (n2 > 0) {
    res.re = z.re / n2;
    res.im = z.im / n2;
  } else {
    res.re = INFINITY;
    res.im = 0;
  }
  return res;
}

complex c_exp(complex z) {
  complex res;
  res.re = exp(z.re) * cos(z.im);
  res.im = exp(z.re) * sin(z.im);
  return res;
}

typedef struct color {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} color;

color complex_to_color(complex z) {
  color res = {0};
  if (isinf(z.re) || isnan(z.re) || isinf(z.im)
      || isnan(z.im)) {
    res.r = 255;
    res.g = 255;
    res.b = 255;
    return res;
  }

  double arg = atan2(z.im, z.re);
  double mag = z.re * z.re + z.im * z.im;
  double lum = 0.5 + atan(0.5 + 0.3 * log(mag)) / M_PI;
  
  double sat = 1;
  
  double hue = arg * 180 / M_PI;
  if (hue < 0) hue += 360;

  double chr = (1 - fabs(2 * lum - 1)) * sat;
  
  double x   = chr * (1 - pow(fabs(fmod(hue / 60, 2) - 1), 1.7));
  
  double r1, g1, b1;
  if (hue < 60) {
    r1 = chr; g1 = x; b1 = 0;
  } else if (hue < 120) {
    r1 = x; g1 = chr; b1 = 0;
  } else if (hue < 180) {
    r1 = 0; g1 = chr; b1 = x;    
  } else if (hue < 240) {
    r1 = 0; g1 = x; b1 = chr;
  } else if (hue < 300) {
    r1 = x; g1 = 0; b1 = chr;
  } else {
    r1 = chr; g1 = 0; b1 = x;
  }

  double m = lum - chr / 2;
  double r2 = r1 + m;
  double g2 = g1 + m;
  double b2 = b1 + m;
  res.r = (uint8_t) (r2 * 255);
  res.g = (uint8_t) (g2 * 255);
  res.b = (uint8_t) (b2 * 255);
  return res;  
}

void make_plot(double xl, double xh, double yl, double yh,
	       int resolution, complex(*f)(complex, void*),
	       void* arg, char* outfile) {
  FILE *out = fopen(outfile, "wb");
  int width = floor((xh - xl) * resolution) + 1;
  int height = floor((yh - yl) * resolution) + 1;
  fprintf(out, "P6\n%d %d\n255\n", width, height);
  for (int j = 0; j < height; j++) {
    for (int i = 0; i < width; i++) {
      double x = xl + (1.0 * i / resolution);
      double y = yh - (1.0 * j / resolution);
      complex z = {.re = x, .im = y};      
      complex w = f(z, arg);
      color c = complex_to_color(w);
      fputc(c.r, out);
      fputc(c.g, out);
      fputc(c.b, out);
    }
  }
  
  fclose(out);
}

complex identity(complex c, void* arg) {
  return c;
}

complex power(complex c, void* arg) {
  int n = *((int *) arg);
  if (n < 0) {
    c = c_inv(c);
    n *= -1;
  }
  complex r = {.re = 1, .im = 0};
  for (int i = 0; i < n; i++) {
    r = c_mul(r, c);
  }
  
  return r;
}

complex essential(complex c, void* arg) {
  return c_exp(c_inv(c_mul(c, c)));
}

complex tripole(complex c, void* arg) {
  complex minus_1 = {.re = -1, .im = 0};
  complex x = c_add(c_mul(c, (c_mul(c, c))), minus_1);
  return c_inv(c_mul(x, c_mul(x, x)));
}

complex mystery(complex c, void* arg) {
  int n = *((int *) arg);
  complex res = {0};
  for (int i = 0; i < n; i++) {
    res = c_add(c_mul(res, res), c);
  }
  return res;
}

complex mcount(complex c, void* arg) {
  int n = *((int *) arg);
  complex x = {0};
  int i;
  for (i = 0; i < n; i++) {
    if (x.re * x.re + x.im * x.im > 4) break;
    x = c_add(c_mul(x, x), c);
  }

  if (i == n) {
    complex res = {.re = 0, .im = 0};
    return res;
  } else {
    complex a = {.re = log(log(i)), .im = (i / 3) * M_PI};
    return c_exp(a);
  }
}

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Usage: ./hueplot <function> [<arg>]\n");
    return 1;
  }
  
  int n = argc > 2 ? atoi(argv[2]) : 1;
  complex(*f)(complex, void*);
  f = NULL;
  if (strcmp(argv[1], "identity") == 0)
    f = identity;
  if (strcmp(argv[1], "mystery") == 0)
    f = mystery;
  if (strcmp(argv[1], "power") == 0)
    f = power;
  if (strcmp(argv[1], "tripole") == 0)
    f = tripole;
  if (strcmp(argv[1], "mcount") == 0)
    f = mcount;
  if (strcmp(argv[1], "essential") == 0)
    f = essential;
  if (!f) {
    printf("Unrecognized function name %s\n", argv[1]);
  }
  
  make_plot(-2, 2, -1.5, 1.5, 1000, f, &n,
	    "out.ppm");
  return 0;
}
