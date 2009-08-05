// 13 subclasses of Expression
// 4 cases each of CallExpression and IdentifierExpression
// 19 * 19 = 361 possible combinations
// 6 * 6 = 36 valid combinations

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
    int[] a;
    int i;
    boolean b;

    a = new int[1];
    i = 1;
    b = true;

    // BinaryBooleanExpression
    System.out.println((true && true) + (true && true));
    System.out.println((true && true) + (1 + 1));
    System.out.println((true && true) + true);
    System.out.println((true && true) + this.a());
    System.out.println((true && true) + this.b());
    System.out.println((true && true) + this.i());
    System.out.println((true && true) + this.o());
    System.out.println((true && true) + (1 < 1));
    System.out.println((true && true) + a);
    System.out.println((true && true) + b);
    System.out.println((true && true) + i);
    System.out.println((true && true) + o);
    System.out.println((true && true) + a.length);
    System.out.println((true && true) + a[0]);
    System.out.println((true && true) + 1);
    System.out.println((true && true) + new int[1]);
    System.out.println((true && true) + new Test());
    System.out.println((true && true) + this);
    System.out.println((true && true) + (!true));

    // BinaryIntExpression
    System.out.println((1 + 1) + (true && true));
    System.out.println((1 + 1) + (1 + 1));         // ok
    System.out.println((1 + 1) + true);
    System.out.println((1 + 1) + this.a());
    System.out.println((1 + 1) + this.b());
    System.out.println((1 + 1) + this.i());        // ok
    System.out.println((1 + 1) + this.o());
    System.out.println((1 + 1) + (1 < 1));
    System.out.println((1 + 1) + a);
    System.out.println((1 + 1) + b);
    System.out.println((1 + 1) + i);               // ok
    System.out.println((1 + 1) + o);
    System.out.println((1 + 1) + a.length);        // ok
    System.out.println((1 + 1) + a[0]);            // ok
    System.out.println((1 + 1) + 1);               // ok
    System.out.println((1 + 1) + new int[1]);
    System.out.println((1 + 1) + new Test());
    System.out.println((1 + 1) + this);
    System.out.println((1 + 1) + (!true));

    // BooleanLiteral
    System.out.println(true + (true && true));
    System.out.println(true + (1 + 1));
    System.out.println(true + true);
    System.out.println(true + this.a());
    System.out.println(true + this.b());
    System.out.println(true + this.i());
    System.out.println(true + this.o());
    System.out.println(true + (1 < 1));
    System.out.println(true + a);
    System.out.println(true + b);
    System.out.println(true + i);
    System.out.println(true + o);
    System.out.println(true + a.length);
    System.out.println(true + a[0]);
    System.out.println(true + 1);
    System.out.println(true + new int[1]);
    System.out.println(true + new Test());
    System.out.println(true + this);
    System.out.println(true + (!true));

    // CallExpression, array
    System.out.println(this.a() + (true && true));
    System.out.println(this.a() + (1 + 1));
    System.out.println(this.a() + true);
    System.out.println(this.a() + this.a());
    System.out.println(this.a() + this.b());
    System.out.println(this.a() + this.i());
    System.out.println(this.a() + this.o());
    System.out.println(this.a() + (1 < 1));
    System.out.println(this.a() + a);
    System.out.println(this.a() + b);
    System.out.println(this.a() + i);
    System.out.println(this.a() + o);
    System.out.println(this.a() + a.length);
    System.out.println(this.a() + a[0]);
    System.out.println(this.a() + 1);
    System.out.println(this.a() + new int[1]);
    System.out.println(this.a() + new Test());
    System.out.println(this.a() + this);
    System.out.println(this.a() + (!true));

    // CallExpression, boolean
    System.out.println(this.b() + (true && true));
    System.out.println(this.b() + (1 + 1));
    System.out.println(this.b() + true);
    System.out.println(this.b() + this.a());
    System.out.println(this.b() + this.b());
    System.out.println(this.b() + this.i());
    System.out.println(this.b() + this.o());
    System.out.println(this.b() + (1 < 1));
    System.out.println(this.b() + a);
    System.out.println(this.b() + b);
    System.out.println(this.b() + i);
    System.out.println(this.b() + o);
    System.out.println(this.b() + a.length);
    System.out.println(this.b() + a[0]);
    System.out.println(this.b() + 1);
    System.out.println(this.b() + new int[1]);
    System.out.println(this.b() + new Test());
    System.out.println(this.b() + this);
    System.out.println(this.b() + (!true));

    // CallExpression, int
    System.out.println(this.i() + (true && true));
    System.out.println(this.i() + (1 + 1));         // ok
    System.out.println(this.i() + true);
    System.out.println(this.i() + this.a());
    System.out.println(this.i() + this.b());
    System.out.println(this.i() + this.i());        // ok
    System.out.println(this.i() + this.o());
    System.out.println(this.i() + (1 < 1));
    System.out.println(this.i() + a);
    System.out.println(this.i() + b);
    System.out.println(this.i() + i);               // ok
    System.out.println(this.i() + o);
    System.out.println(this.i() + a.length);        // ok
    System.out.println(this.i() + a[0]);            // ok
    System.out.println(this.i() + 1);               // ok
    System.out.println(this.i() + new int[1]);
    System.out.println(this.i() + new Test());
    System.out.println(this.i() + this);
    System.out.println(this.i() + (!true));

    // CallExpression, object
    System.out.println(this.o() + (true && true));
    System.out.println(this.o() + (1 + 1));
    System.out.println(this.o() + true);
    System.out.println(this.o() + this.a());
    System.out.println(this.o() + this.b());
    System.out.println(this.o() + this.i());
    System.out.println(this.o() + this.o());
    System.out.println(this.o() + (1 < 1));
    System.out.println(this.o() + a);
    System.out.println(this.o() + b);
    System.out.println(this.o() + i);
    System.out.println(this.o() + o);
    System.out.println(this.o() + a.length);
    System.out.println(this.o() + a[0]);
    System.out.println(this.o() + 1);
    System.out.println(this.o() + new int[1]);
    System.out.println(this.o() + new Test());
    System.out.println(this.o() + this);
    System.out.println(this.o() + (!true));

    // ComparisonExpression
    System.out.println((1 < 1) + (true && true));
    System.out.println((1 < 1) + (1 + 1));
    System.out.println((1 < 1) + true);
    System.out.println((1 < 1) + this.a());
    System.out.println((1 < 1) + this.b());
    System.out.println((1 < 1) + this.i());
    System.out.println((1 < 1) + this.o());
    System.out.println((1 < 1) + (1 < 1));
    System.out.println((1 < 1) + a);
    System.out.println((1 < 1) + b);
    System.out.println((1 < 1) + i);
    System.out.println((1 < 1) + o);
    System.out.println((1 < 1) + a.length);
    System.out.println((1 < 1) + a[0]);
    System.out.println((1 < 1) + 1);
    System.out.println((1 < 1) + new int[1]);
    System.out.println((1 < 1) + new Test());
    System.out.println((1 < 1) + this);
    System.out.println((1 < 1) + (!true));

    // IdentifierExpression, array
    System.out.println(a + (true && true));
    System.out.println(a + (1 + 1));
    System.out.println(a + true);
    System.out.println(a + this.a());
    System.out.println(a + this.b());
    System.out.println(a + this.i());
    System.out.println(a + this.o());
    System.out.println(a + (1 < 1));
    System.out.println(a + a);
    System.out.println(a + b);
    System.out.println(a + i);
    System.out.println(a + o);
    System.out.println(a + a.length);
    System.out.println(a + a[0]);
    System.out.println(a + 1);
    System.out.println(a + new int[1]);
    System.out.println(a + new Test());
    System.out.println(a + this);
    System.out.println(a + (!true));

    // IdentifierExpression, boolean
    System.out.println(b + (true && true));
    System.out.println(b + (1 + 1));
    System.out.println(b + true);
    System.out.println(b + this.a());
    System.out.println(b + this.b());
    System.out.println(b + this.i());
    System.out.println(b + this.o());
    System.out.println(b + (1 < 1));
    System.out.println(b + a);
    System.out.println(b + b);
    System.out.println(b + i);
    System.out.println(b + o);
    System.out.println(b + a.length);
    System.out.println(b + a[0]);
    System.out.println(b + 1);
    System.out.println(b + new int[1]);
    System.out.println(b + new Test());
    System.out.println(b + this);
    System.out.println(b + (!true));

    // IdentifierExpression, int
    System.out.println(i + (true && true));
    System.out.println(i + (1 + 1));         // ok
    System.out.println(i + true);
    System.out.println(i + this.a());
    System.out.println(i + this.b());
    System.out.println(i + this.i());        // ok
    System.out.println(i + this.o());
    System.out.println(i + (1 < 1));
    System.out.println(i + a);
    System.out.println(i + b);
    System.out.println(i + i);               // ok
    System.out.println(i + o);
    System.out.println(i + a.length);        // ok
    System.out.println(i + a[0]);            // ok
    System.out.println(i + 1);               // ok
    System.out.println(i + new int[1]);
    System.out.println(i + new Test());
    System.out.println(i + this);
    System.out.println(i + (!true));

    // IdentifierExpression, object
    System.out.println(o + (true && true));
    System.out.println(o + (1 + 1));
    System.out.println(o + true);
    System.out.println(o + this.a());
    System.out.println(o + this.b());
    System.out.println(o + this.i());
    System.out.println(o + this.o());
    System.out.println(o + (1 < 1));
    System.out.println(o + a);
    System.out.println(o + b);
    System.out.println(o + i);
    System.out.println(o + o);
    System.out.println(o + a.length);
    System.out.println(o + a[0]);
    System.out.println(o + 1);
    System.out.println(o + new int[1]);
    System.out.println(o + new Test());
    System.out.println(o + this);
    System.out.println(o + (!true));

    // IntArrayLengthExpression
    System.out.println(a.length + (true && true));
    System.out.println(a.length + (1 + 1));         // ok
    System.out.println(a.length + true);
    System.out.println(a.length + this.a());
    System.out.println(a.length + this.b());
    System.out.println(a.length + this.i());        // ok
    System.out.println(a.length + this.o());
    System.out.println(a.length + (1 < 1));
    System.out.println(a.length + a);
    System.out.println(a.length + b);
    System.out.println(a.length + i);               // ok
    System.out.println(a.length + o);
    System.out.println(a.length + a.length);        // ok
    System.out.println(a.length + a[0]);            // ok
    System.out.println(a.length + 1);               // ok
    System.out.println(a.length + new int[1]);
    System.out.println(a.length + new Test());
    System.out.println(a.length + this);
    System.out.println(a.length + (!true));

    // IntArraySubscriptExpression
    System.out.println(a[0] + (true && true));
    System.out.println(a[0] + (1 + 1));         // ok
    System.out.println(a[0] + true);
    System.out.println(a[0] + this.a());
    System.out.println(a[0] + this.b());
    System.out.println(a[0] + this.i());        // ok
    System.out.println(a[0] + this.o());
    System.out.println(a[0] + (1 < 1));
    System.out.println(a[0] + a);
    System.out.println(a[0] + b);
    System.out.println(a[0] + i);               // ok
    System.out.println(a[0] + o);
    System.out.println(a[0] + a.length);        // ok
    System.out.println(a[0] + a[0]);            // ok
    System.out.println(a[0] + 1);               // ok
    System.out.println(a[0] + new int[1]);
    System.out.println(a[0] + new Test());
    System.out.println(a[0] + this);
    System.out.println(a[0] + (!true));

    // IntLiteral
    System.out.println(1 + (true && true));
    System.out.println(1 + (1 + 1));         // ok
    System.out.println(1 + true);
    System.out.println(1 + this.a());
    System.out.println(1 + this.b());
    System.out.println(1 + this.i());        // ok
    System.out.println(1 + this.o());
    System.out.println(1 + (1 < 1));
    System.out.println(1 + a);
    System.out.println(1 + b);
    System.out.println(1 + i);               // ok
    System.out.println(1 + o);
    System.out.println(1 + a.length);        // ok
    System.out.println(1 + a[0]);            // ok
    System.out.println(1 + 1);               // ok
    System.out.println(1 + new int[1]);
    System.out.println(1 + new Test());
    System.out.println(1 + this);
    System.out.println(1 + (!true));

    // NewIntArrayExpression
    System.out.println(new int[1] + (true && true));
    System.out.println(new int[1] + (1 + 1));
    System.out.println(new int[1] + true);
    System.out.println(new int[1] + this.a());
    System.out.println(new int[1] + this.b());
    System.out.println(new int[1] + this.i());
    System.out.println(new int[1] + this.o());
    System.out.println(new int[1] + (1 < 1));
    System.out.println(new int[1] + a);
    System.out.println(new int[1] + b);
    System.out.println(new int[1] + i);
    System.out.println(new int[1] + o);
    System.out.println(new int[1] + a.length);
    System.out.println(new int[1] + a[0]);
    System.out.println(new int[1] + 1);
    System.out.println(new int[1] + new int[1]);
    System.out.println(new int[1] + new Test());
    System.out.println(new int[1] + this);
    System.out.println(new int[1] + (!true));

    // NewObjectExpression
    System.out.println(new Test() + (true && true));
    System.out.println(new Test() + (1 + 1));
    System.out.println(new Test() + true);
    System.out.println(new Test() + this.a());
    System.out.println(new Test() + this.b());
    System.out.println(new Test() + this.i());
    System.out.println(new Test() + this.o());
    System.out.println(new Test() + (1 < 1));
    System.out.println(new Test() + a);
    System.out.println(new Test() + b);
    System.out.println(new Test() + i);
    System.out.println(new Test() + o);
    System.out.println(new Test() + a.length);
    System.out.println(new Test() + a[0]);
    System.out.println(new Test() + 1);
    System.out.println(new Test() + new int[1]);
    System.out.println(new Test() + new Test());
    System.out.println(new Test() + this);
    System.out.println(new Test() + (!true));

    // ThisExpression
    System.out.println(this + (true && true));
    System.out.println(this + (1 + 1));
    System.out.println(this + true);
    System.out.println(this + this.a());
    System.out.println(this + this.b());
    System.out.println(this + this.i());
    System.out.println(this + this.o());
    System.out.println(this + (1 < 1));
    System.out.println(this + a);
    System.out.println(this + b);
    System.out.println(this + i);
    System.out.println(this + o);
    System.out.println(this + a.length);
    System.out.println(this + a[0]);
    System.out.println(this + 1);
    System.out.println(this + new int[1]);
    System.out.println(this + new Test());
    System.out.println(this + this);
    System.out.println(this + (!true));

    // UnaryBooleanExpression
    System.out.println((!true) + (true && true));
    System.out.println((!true) + (1 + 1));
    System.out.println((!true) + true);
    System.out.println((!true) + this.a());
    System.out.println((!true) + this.b());
    System.out.println((!true) + this.i());
    System.out.println((!true) + this.o());
    System.out.println((!true) + (1 < 1));
    System.out.println((!true) + a);
    System.out.println((!true) + b);
    System.out.println((!true) + i);
    System.out.println((!true) + o);
    System.out.println((!true) + a.length);
    System.out.println((!true) + a[0]);
    System.out.println((!true) + 1);
    System.out.println((!true) + new int[1]);
    System.out.println((!true) + new Test());
    System.out.println((!true) + this);
    System.out.println((!true) + (!true));

    return 0;
  }
}
