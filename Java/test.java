public class test {
    public boolean isPalindrome(int x) {
        if (x < 0) 
            return false;
        else if(x < 10)
            return true;
        
        int divisor = 1;
        int first, last;
        
        while (x/divisor <= 10) {
            divisor *= 10;
        }
        
        first = x / divisor;
        last = x % divisor;

        System.out.println(Integer.toString(x));
        
        if(first == last)
            return true && isPalindrome((x - first*divisor)/10);
        else
            return false;
    }
    public static void main(String[] args) {
        System.out.println("Hello World!");
    }
}