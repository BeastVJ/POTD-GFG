class Solution {
    public int minChar(String s) {
        int n=s.length();
        String original=s;
        String rev=new StringBuilder(s).reverse().toString();
        String str=original+"*"+rev;
        int[] lps=new int[str.length()];
        int i=0,j=1;
        while(j<str.length()){
            if(str.charAt(i)==str.charAt(j)){
                i++;
                lps[j]=i;
                j++;
            }
            else{
                if(i!=0)i=lps[i-1];
                else{
                    lps[j]=0;
                    j++;
                }
            }
        }
        return n-lps[str.length()-1];
    }
}