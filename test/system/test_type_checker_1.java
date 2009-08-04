// test that type checker correctly reports all type errors
// operators: =
// type: int boolean

class Main
{
  public static void main(String[] args)
  {
    System.out.println(1);
  }
}

class A
{
  public int a()
  {
    // variables
    int i1;
    boolean b1;

    // ok
    i1 = 1;

    // bad
    i1 = true;
    i1 = false;

    // bad
    b1 = 1;

    // ok
    b1 = true;
    b1 = false;

    return 0;
  }
}
