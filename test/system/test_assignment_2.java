class Main
{
  public static void main(String[] args)
  {
    // The main node may only have one statement, so we use a statement list.
    // This used to trigger a bug in how statement lists are parsed.
    {
      i = 0; // This is valid syntactically, but not semantically.
    }
  }
}
