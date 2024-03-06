public class Main {
    public static void main(String[] args) {
        int X = 1;
        while (X != 0) {
            String s = MyIO.readString();
            int n = s.length();
            int count = 0;

                for (int i = 0; i < n / 2; i++) {
                  if(s.charAt(i)=='F'&& s.charAt(i+1)=='I'&& s.charAt(i+2)=='M'){
                    X = 0;
                    break;
                  }
                    if (s.charAt(i) == s.charAt(n - 1 - i)) {
                        count++; 
                    } else {
                        MyIO.println("NAO");
                        break; 
                    }
                }

                if (count == n / 2) {
                    MyIO.println("SIM");
                }
            }
        
    }
}
