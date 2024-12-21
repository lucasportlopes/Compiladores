int main() {
  int a = 3;
  int b;
  b = a;
  int c;
  c = a + b;
  if(c > 5) {
    c = c + 1;
  }else {
    c = c + 2;
  }
  a = 1;
  return c;
}
