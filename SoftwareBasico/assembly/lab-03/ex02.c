int  a = 3;
long b = 7;

void ex02() {
  if (a) {
    if (b < 5) {
       b = (a << 1) + (a * b);
    }
    else {
       a = b ^ 0x1FL;
    }
  }
}
