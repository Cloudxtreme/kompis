// Identifier = Expression

class Main
{
  public static void main(String[] args)
  {
    System.out.println(1);
  }
}

class Test
{
  public int test()
  {
    int[] a1;
    int[] a2;
    boolean b1;
    boolean b2;
    int i1;
    int i2;
    Test o1;
    Test o2;

    a1 = new int[1];
    b1 = true;
    i1 = 1;
    o1 = new Test();

    // assignment to array variable
    a2 = (true && true);
    a2 = (1 + 1);
    a2 = true;
    a2 = this.a();        // ok
    a2 = this.b();
    a2 = this.i();
    a2 = this.o();
    a2 = (1 < 1);
    a2 = a1;              // ok
    a2 = b1;
    a2 = i1;
    a2 = o1;
    a2 = a1.length;
    a2 = a1[0];
    a2 = 1;
    a2 = new int[1];      // ok
    a2 = new Test();
    a2 = this;
    a2 = (!true);

    // assignment to boolean variable
    b2 = (true && true);  // ok
    b2 = (1 + 1);
    b2 = true;            // ok
    b2 = this.a();
    b2 = this.b();        // ok
    b2 = this.i();
    b2 = this.o();
    b2 = (1 < 1);         // ok
    b2 = a1;
    b2 = b1;              // ok
    b2 = i1;
    b2 = o1;
    b2 = a1.length;
    b2 = a1[0];
    b2 = 1;
    b2 = new int[1];
    b2 = new Test();
    b2 = this;
    b2 = (!true);         // ok

    // assignment to int variable
    i2 = (true && true);
    i2 = (1 + 1);         // ok
    i2 = true;
    i2 = this.a();
    i2 = this.b();
    i2 = this.i();        // ok
    i2 = this.o();
    i2 = (1 < 1);
    i2 = a1;
    i2 = b1;
    i2 = i1;              // ok
    i2 = o1;
    i2 = a1.length;       // ok
    i2 = a[0];            // ok
    i2 = 1;               // ok
    i2 = new int[1];
    i2 = new Test();
    i2 = this;
    i2 = (!true);

    // assignment to object variable
    o2 = (true && true);
    o2 = (1 + 1);
    o2 = true;
    o2 = this.a();
    o2 = this.b();
    o2 = this.i();
    o2 = this.o();        // ok
    o2 = (1 < 1);
    o2 = a1;
    o2 = b1;
    o2 = i1;
    o2 = o1;              // ok
    o2 = a1.length;
    o2 = a[0];
    o2 = 1;
    o2 = new int[1];
    o2 = new Test();      // ok
    o2 = this;            // ok
    o2 = (!true);

    // assignment to unbound variable
    x = (true && true);
    x = (1 + 1);
    x = true;
    x = this.a();
    x = this.b();
    x = this.i();
    x = this.o();
    x = (1 < 1);
    x = a1;
    x = b1;
    x = i1;
    x = o1;
    x = a1.length;
    x = a[0];
    x = 1;
    x = new int[1];
    x = new Test();
    x = this;
    x = (!true);

    return 0;
  }

  public int[] a()
  {
    return new int[1];
  }

  public boolean b()
  {
    return true;
  }

  public int i()
  {
    return 1;
  }

  public Test o()
  {
    return new Test();
  }
}
