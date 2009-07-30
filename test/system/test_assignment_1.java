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
    int i;
    i = 0; // This used to trigger a bug in how statement lists are parsed.
    return 0;
  }
}
