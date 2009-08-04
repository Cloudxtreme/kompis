// test that type checker correctly reports all type errors
// array

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
    int[] a1;
    int[] a2;
    int i1;
    int i2;
    boolean b1;

    a1 = new int[1];
    i1 = 1;
    i2 = 2;
    b1 = true;

    // new[]
    a2 = new int[new int[1]]; // bad
    a2 = new int[a1];         // bad
    a2 = new int[true];       // bad
    a2 = new int[b1];         // bad
    a2 = new int[1];          // ok
    a2 = new int[i2];         // ok (last, or rest of test will break)

    // []=
    a2[0] = 1;          // ok
    a2[i1] = 1;         // ok
    i1[0] = 1;          // bad self
    b1[0] = 1;          // bad self
    a2[true] = 1;       // bad index
    a2[b1] = 1;         // bad index
    a2[new int[1]] = 1; // bad index
    a2[a1] = 1;         // bad index
    a2[0] = true;       // bad rvalue
    a2[0] = b1;         // bad rvalue
    a2[0] = new int[1]; // bad rvalue
    a2[0] = a1;         // bad rvalue

    // []
    System.out.println(a2[0]);            // ok
    System.out.println(i1[0]);            // bad self
    System.out.println(b1[0]);            // bad self
    System.out.println(a2[true]);         // bad index
    System.out.println(a2[b1]);           // bad index
    System.out.println(a2[new int[1]]);   // bad index
    System.out.println(a2[a1]);           // bad index

    // length
    System.out.println(a2.length);  // ok
    System.out.println(i1.length);  // bad self
    System.out.println(b1.length);  // bad self

    return 0;
  }
}
