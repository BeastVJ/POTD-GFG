class Solution:
	def getLPSLength(self, s):
		arr=[1]
		md=10**9+7
		num=31
		for i in range(1,len(s)+1):
		    arr.append((num*arr[-1])%md)
	    
	    l,r=0,len(s)-1
	    lstind=-1
	    hash1,hash2=0,0
	    while l<len(s)-1:
	        hash1=(hash1*31)%md
	        num1=ord(s[l])-ord('a')
	        hash1=(hash1+num1)%md
	        
	        num2=ord(s[r])-ord('a')
	        hash2=(hash2+(num2*arr[len(s)-r-1])%md)%md
	        
	        if hash1==hash2:
	            lstind=l
	        
	        l+=1
	        r-=1
        
        return lstind+1