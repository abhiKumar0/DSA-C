import java.util.Stack;
// import java.lang.String;

public class StackDSA {

  static int parenthesis(String str) {
    Stack sc = new Stack();
    
    for (int i = 0; i<str.length(); i++) {
      if (str.charAt(i) === "(") {
        sc.push("(");
      }
    }

    return 0;
  };
  public static void main(String[] args) {
    String str = "(3+2*(54/9)-6)";

  }
} 