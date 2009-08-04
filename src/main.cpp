#include <string>

FILE *ast_file = NULL;
FILE *irt_file = NULL;
std::string ast_filename;
std::string irt_filename;
std::string out_filename;

int main(int argc, char *argv[])
{
  int opt;
  while((opt = getopt(argc, argv, "Aa:Ii:o:")) != -1)
  {
    switch(opt)
    {
      case 'A': // print AST to stdout (default none)
        ast_file = stdout;
        break;
      case 'a': // print AST to file:
        ast_filename = optarg;
        break;
      case 'I': // print IRT to stdout (default none)
        irt_file = stdout;
        break;
      case 'i': // print IRT to file:
        irt_filename = optarg;
        break;
      case 'o': // save output in file: (default a.out?)
        out_filename = optarg;
        break;
      default:
        exit(1);
    }
  }
  argc -= optind;
  argv += optind;

  // remainder of argv is input files

  return 0;
}
