class Main
{
  public static void main(String[] args)
  {
    System.out.println((new Foo()).foo());
  }
}

class Foo
{
  public int foo() {
    int[] a;

    a = new int[17 + 4711];
    a[42] = 1;
    System.out.println(a[42]);
    System.out.println(this.bar()[10 * 10 - 100]);
    return 3;
  }

  public int[] bar() {
    int[] b;
    b = new int[10];
    b[0] = 2;
    return b;
  }
}
