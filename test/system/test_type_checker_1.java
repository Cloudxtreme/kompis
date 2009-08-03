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
    int i2;
    int i3;
    boolean b1;
    boolean b2;
    boolean b3;

    // initial values
    i1 = 1;
    i2 = 2;
    b1 = true;
    b2 = false;

    // test +

    // integer literals
    // ok
    i3 = 1 + 2;

    // integer variables
    // ok
    i3 = i1 + i2;

    // integer literal + integer variable
    // ok
    i3 = 1 + i2;
    i3 = i1 + 2;

    // boolean literals
    // bad, both operands of + must be integer literals or variables
    i3 = true + true;
    i3 = true + false;
    i3 = false + true;
    i3 = false + false;

    // boolean variables
    // bad, both operands of + must be integer literals or variables
    i3 = b1 + b2;

    // boolean literals + boolean variable
    // bad, both operands of + must be integer literals or variables
    i3 = true + b2;
    i3 = false + b2;
    i3 = b1 + true;
    i3 = b1 + false;

    // integer literals + boolean literal
    // bad, both operands of + must be integer literals or variables
    i3 = 1 + true;
    i3 = 1 + false;
    i3 = true + 2;
    i3 = false + 2;

    // integer variable + boolean literal
    // bad, both operands of + must be integer literals or variables
    i3 = i1 + true;
    i3 = i1 + false;
    i3 = true + i2;
    i3 = false + i2;

    // integer variable + boolean variable
    // bad, both operands of + must be integer literals or variables
    i3 = i1 + b2;
    i3 = b1 + i2;

    // test -

    // integer literals
    // ok
    i3 = 1 - 2;

    // integer variables
    // ok
    i3 = i1 - i2;

    // integer literal - integer variable
    // ok
    i3 = 1 - i2;
    i3 = i1 - 2;

    // boolean literals
    // bad, both operands of - must be integer literals or variables
    i3 = true - true;
    i3 = true - false;
    i3 = false - true;
    i3 = false - false;

    // boolean variables
    // bad, both operands of - must be integer literals or variables
    i3 = b1 - b2;

    // boolean literals - boolean variable
    // bad, both operands of - must be integer literals or variables
    i3 = true - b2;
    i3 = false - b2;
    i3 = b1 - true;
    i3 = b1 - false;

    // integer literals - boolean literal
    // bad, both operands of - must be integer literals or variables
    i3 = 1 - true;
    i3 = 1 - false;
    i3 = true - 2;
    i3 = false - 2;

    // integer variable - boolean literal
    // bad, both operands of - must be integer literals or variables
    i3 = i1 - true;
    i3 = i1 - false;
    i3 = true - i2;
    i3 = false - i2;

    // integer variable - boolean variable
    // bad, both operands of - must be integer literals or variables
    i3 = i1 - b2;
    i3 = b1 - i2;

    // test *

    // integer literals
    // ok
    i3 = 1 * 2;

    // integer variables
    // ok
    i3 = i1 * i2;

    // integer literal * integer variable
    // ok
    i3 = 1 * i2;
    i3 = i1 * 2;

    // boolean literals
    // bad, both operands of * must be integer literals or variables
    i3 = true * true;
    i3 = true * false;
    i3 = false * true;
    i3 = false * false;

    // boolean variables
    // bad, both operands of * must be integer literals or variables
    i3 = b1 * b2;

    // boolean literals * boolean variable
    // bad, both operands of * must be integer literals or variables
    i3 = true * b2;
    i3 = false * b2;
    i3 = b1 * true;
    i3 = b1 * false;

    // integer literals * boolean literal
    // bad, both operands of * must be integer literals or variables
    i3 = 1 * true;
    i3 = 1 * false;
    i3 = true * 2;
    i3 = false * 2;

    // integer variable * boolean literal
    // bad, both operands of * must be integer literals or variables
    i3 = i1 * true;
    i3 = i1 * false;
    i3 = true * i2;
    i3 = false * i2;

    // integer variable * boolean variable
    // bad, both operands of * must be integer literals or variables
    i3 = i1 * b2;
    i3 = b1 * i2;

    // test &&

    // integer literals
    // bad, both operands of && must be boolean literals or variables
    b3 = 1 && 2;

    // integer variables
    // bad, both operands of && must be boolean literals or variables
    b3 = i1 && i2;

    // integer literal && integer variable
    // bad, both operands of && must be boolean literals or variables
    b3 = 1 && i2;
    b3 = i1 && 2;

    // boolean literals
    // ok
    b3 = true && true;
    b3 = true && false;
    b3 = false && true;
    b3 = false && false;

    // boolean variables
    // ok
    b3 = b1 && b2;

    // boolean literals && boolean variable
    // ok
    b3 = true && b2;
    b3 = false && b2;
    b3 = b1 && true;
    b3 = b1 && false;

    // integer literals && boolean literal
    // bad, both operands of && must be boolean literals or variables
    b3 = 1 && true;
    b3 = 1 && false;
    b3 = true && 2;
    b3 = false && 2;

    // integer variable && boolean literal
    // bad, both operands of && must be boolean literals or variables
    b3 = i1 && true;
    b3 = i1 && false;
    b3 = true && i2;
    b3 = false && i2;

    // integer variable && boolean variable
    // bad, both operands of && must be boolean literals or variables
    b3 = i1 && b2;
    b3 = b1 && i2;

    return 0;
  }
}
