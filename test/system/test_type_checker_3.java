// test that type checker correctly reports all type errors
// operators: call
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

    i = this.i();
    i = this.ii(1);
    i = this.ii(true);
    i = this.ib(1);
    i = this.ib(true);
    i = this.iii(1, 1);
    i = this.iii(1, true);
    i = this.iii(true, 1);
    i = this.iii(true, true);
    i = this.iii(1, 1);
    i = this.iii(1, true);
    i = this.iii(true, 1);
    i = this.iii(true, true);
    i = this.iib(1, 1);
    i = this.iib(1, true);
    i = this.iib(true, 1);
    i = this.iib(true, true);
    i = this.ibi(1, 1);
    i = this.ibi(1, true);
    i = this.ibi(true, 1);
    i = this.ibi(true, true);
    i = this.ibb(1, 1);
    i = this.ibb(1, true);
    i = this.ibb(true, 1);
    i = this.ibb(true, true);

    i = this.b();
    i = this.bi(1);
    i = this.bi(true);
    i = this.bb(1);
    i = this.bb(true);
    i = this.bii(1, 1);
    i = this.bii(1, true);
    i = this.bii(true, 1);
    i = this.bii(true, true);
    i = this.bii(1, 1);
    i = this.bii(1, true);
    i = this.bii(true, 1);
    i = this.bii(true, true);
    i = this.bib(1, 1);
    i = this.bib(1, true);
    i = this.bib(true, 1);
    i = this.bib(true, true);
    i = this.bbi(1, 1);
    i = this.bbi(1, true);
    i = this.bbi(true, 1);
    i = this.bbi(true, true);
    i = this.bbb(1, 1);
    i = this.bbb(1, true);
    i = this.bbb(true, 1);
    i = this.bbb(true, true);

    b = this.i();
    b = this.ii(1);
    b = this.ii(true);
    b = this.ib(1);
    b = this.ib(true);
    b = this.iii(1, 1);
    b = this.iii(1, true);
    b = this.iii(true, 1);
    b = this.iii(true, true);
    b = this.iii(1, 1);
    b = this.iii(1, true);
    b = this.iii(true, 1);
    b = this.iii(true, true);
    b = this.iib(1, 1);
    b = this.iib(1, true);
    b = this.iib(true, 1);
    b = this.iib(true, true);
    b = this.ibi(1, 1);
    b = this.ibi(1, true);
    b = this.ibi(true, 1);
    b = this.ibi(true, true);
    b = this.ibb(1, 1);
    b = this.ibb(1, true);
    b = this.ibb(true, 1);
    b = this.ibb(true, true);

    b = this.b();
    b = this.bi(1);
    b = this.bi(true);
    b = this.bb(1);
    b = this.bb(true);
    b = this.bii(1, 1);
    b = this.bii(1, true);
    b = this.bii(true, 1);
    b = this.bii(true, true);
    b = this.bii(1, 1);
    b = this.bii(1, true);
    b = this.bii(true, 1);
    b = this.bii(true, true);
    b = this.bib(1, 1);
    b = this.bib(1, true);
    b = this.bib(true, 1);
    b = this.bib(true, true);
    b = this.bbi(1, 1);
    b = this.bbi(1, true);
    b = this.bbi(true, 1);
    b = this.bbi(true, true);
    b = this.bbb(1, 1);
    b = this.bbb(1, true);
    b = this.bbb(true, 1);
    b = this.bbb(true, true);

    return 0;
  }

  public int i()
  {
    return 1;
  }

  public int ii(int i)
  {
    return 1;
  }

  public int ib(boolean b)
  {
    return 1;
  }

  public int iii(int i, int i)
  {
    return 1;
  }

  public int iib(int i, boolean b)
  {
    return 1;
  }

  public int ibi(boolean b, int i)
  {
    return 1;
  }

  public int ibb(boolean b1, boolean b2)
  {
    return 1;
  }

  public boolean b()
  {
    return true;
  }

  public boolean bi(int i)
  {
    return true;
  }

  public boolean bb(boolean b)
  {
    return true;
  }

  public boolean bii(int i, int i)
  {
    return true;
  }

  public boolean bib(int i, boolean b)
  {
    return true;
  }

  public boolean bbi(boolean b, int i)
  {
    return true;
  }

  public boolean bbb(boolean b1, boolean b2)
  {
    return true;
  }
}
