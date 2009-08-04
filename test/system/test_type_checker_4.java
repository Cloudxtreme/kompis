// test that type checker correctly reports all type errors
// features: if while
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
    int i;
    boolean b;
    i = 0;
    b = false;

    // if

    // bad
    if(i) System.out.println(1); else System.out.println(1);

    // ok
    if(b) System.out.println(1); else System.out.println(1);

    // bad
    if(0) System.out.println(1); else System.out.println(1);

    // ok
    if(false) System.out.println(1); else System.out.println(1);

    // while

    // bad
    while(i) System.out.println(1);

    // ok
    while(b) System.out.println(1);

    // bad
    while(0) System.out.println(1);

    // ok
    while(false) System.out.println(1);

    return 0;
  }
}
